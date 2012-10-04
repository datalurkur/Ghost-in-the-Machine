#include <Simple/Node.h>
#include <Resource/MaterialManager.h>

const std::string Node::NodeType = "Node";

#define VELOCITY_DAMPING 0.1f
#define TIME_SCALE 500.0f
#define SPRING_CONSTANT 0.2f
#define ATTRACTION_DISTANCE_SCALE 20.0f
#define REPULSION_DISTANCE_SCALE 40.0f

Node::Node(const std::string &name): Entity(name, NodeType), _velocity(0,0,0), _force(0,0,0), _weight(0) {}

Node::~Node() {
  std::map<Node*,bool>::iterator itr;
  for(itr = _attractions.begin(); itr != _attractions.end(); itr++) { itr->first->removeAttraction(this); }
  for(itr = _repulsions.begin(); itr != _repulsions.end(); itr++) { itr->first->removeRepulsion(this); }
}

void Node::update(int elapsed) {
  std::map<Node*,bool>::iterator itr;
  float time;

  time = ((float)elapsed / TIME_SCALE);
  _velocity += (_force * time * (1.0f - VELOCITY_DAMPING));
  SceneNode::moveRelative(_velocity * time);
  
  for(itr = _attractions.begin(); itr != _attractions.end(); itr++) { itr->second = false; }
  for(itr = _repulsions.begin(); itr != _repulsions.end(); itr++) { itr->second = false; }
  _force = Vec3f(0,0,0);
  
  Entity::update(elapsed);
}

void Node::computeForces() {
  std::map<Node*,bool>::iterator itr;
  for(itr = _attractions.begin(); itr != _attractions.end(); itr++) {
    if(itr->second) { continue; }
    itr->second = true;
    itr->first->attract(this);
  }
  for(itr = _repulsions.begin(); itr != _repulsions.end(); itr++) {
    if(itr->second) { continue; }
    itr->second = true;
    itr->first->repulse(this);
  }
}

void Node::attract(Node *attractor) {
  float distance, attraction_distance;
 
  _attractions[attractor] = true;
  
  distance = (SceneNode::getAbsolutePosition() - attractor->getAbsolutePosition()).length();
  attraction_distance = ATTRACTION_DISTANCE_SCALE * ((_weight + attractor->getWeight())/2.0f);
  
  float magnitude;
  Vec3f normal;

  magnitude = SPRING_CONSTANT * (attraction_distance - distance);
  normal = (SceneNode::getAbsolutePosition() - attractor->getAbsolutePosition());
  normal.normalize();

  addForce(normal, magnitude);
  attractor->addForce(-normal, magnitude);
}

void Node::repulse(Node * repulsor) {
  float distance, repulsion_distance;
  
  _repulsions[repulsor] = true;
  
  distance = (SceneNode::getAbsolutePosition() - repulsor->getAbsolutePosition()).length();
  repulsion_distance = REPULSION_DISTANCE_SCALE * ((_weight + repulsor->getWeight())/2.0f);
  
  // Past a certain distance, don't bother
  if(distance <= repulsion_distance) {
    // Determine spring force
    float magnitude;
    Vec3f normal;
    
    magnitude = SPRING_CONSTANT * (repulsion_distance - distance);
    normal = (SceneNode::getAbsolutePosition() - repulsor->getAbsolutePosition());
    normal.normalize();
   
    repulsor->addForce(normal, magnitude);
    addForce(-normal, magnitude);
  }
}

int Node::getWeight() { return _weight; }

void Node::addForce(const Vec3f& normal, float magnitude) {
  _force += (normal * magnitude);
}

void Node::recreateRenderables() {
    clearRenderables();
    addRenderable(Renderable::Sprite(Vector2<float>(_position.x, _position.y), Vector2<float>(_dimensions.x, _dimensions.y), MaterialManager::Get("node")));
}

void Node::addRepulsion(Node *repulsor) {
    _repulsions[repulsor] = false;
}

void Node::addAttraction(Node *attractor) {
    _attractions[attractor] = false;
    _weight++;
}

void Node::removeRepulsion(Node *repulsor) {
    _repulsions.erase(repulsor);
}

void Node::removeAttraction(Node *attractor) {
    _attractions.erase(attractor);
    _weight--;
}