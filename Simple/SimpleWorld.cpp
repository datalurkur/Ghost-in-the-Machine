#include <Simple/SimpleWorld.h>

SimpleWorld::SimpleWorld(): World() {
}

SimpleWorld::~SimpleWorld() {
}

void SimpleWorld::load() {
  addNode("root");

  addNode("branch_a");
  addNode("branch_b");
  linkNodes("root", "branch_a");
  linkNodes("root", "branch_b");
  
  addNode("leaf_a_1");
  addNode("leaf_a_2");
  linkNodes("branch_a", "leaf_a_1");
  linkNodes("branch_a", "leaf_a_2");
  
  addNode("leaf_b_1");
  addNode("leaf_b_2");
  addNode("leaf_b_3");
  linkNodes("branch_b", "leaf_b_1");
  linkNodes("branch_b", "leaf_b_2");
  linkNodes("branch_b", "leaf_b_3");
}

void SimpleWorld::update(int elapsed) {
  EntityList::iterator itr;
  for(itr = _entities.begin(); itr != _entities.end(); itr++) {
    ASSERT(itr->second->getType() == "Node");
    itr->second->computeForces();
  }
	World::update(elapsed);
}

Node* SimpleWorld::addNode(const std::string &name) {
  Node *newNode;
  EntityList::iterator itr;

  newNode  = World::addEntity<Node>(name);
  newNode->setPosition((float)rand()/RAND_MAX,(float)rand()/RAND_MAX,(float)rand()/RAND_MAX);
  
  for(itr = _entities.begin(); itr != _entities.end(); itr++) {
    if(itr->second == newNode) { continue; }
    ASSERT(itr->second->getType() == "Node");
    itr->second->addRepulsion(newNode);
    newNode->addRepulsion(itr->second);
  }
}

void SimpleWorld::linkNodes(const std::string &name1, const std::string &name2) {
  Node *node1, *node2;
  node1 = _entities[name1];
  node2 = _entities[name2];
  linkNodes(node1, node2);
}

void SimpleWorld::linkNodes(Node *node1, Node *node2) {
  node1->removeRepulsion(node2);
  node2->removeRepulsion(node1);
  node1->addAttraction(node2);
  node2->addAttraction(node1);
}