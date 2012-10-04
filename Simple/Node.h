#ifndef NODE_H
#define NODE_H

#include <Engine/Entity.h>
#include <Engine/Controller.h>

class Node: public Entity {
public:
    static const std::string NodeType;

public:
    Node(const std::string &name);
	  virtual ~Node();
    
    void update(int elapsed);
    void computeForces();
    void attract(Node *attractor);
    void repulse(Node * repulsor);
    void addForce(const Vec3f& normal, float magnitude);
    int getWeight();

    void recreateRenderables();
    
    void addRepulsion(Node *repulsor);
    void removeRepulsion(Node *repulsor);
    void addAttraction(Node *attractor);
    void removeAttraction(Node *attractor);
    
private:
    std::map<Node*,bool> _repulsions;
    std::map<Node*,bool> _attractions;
    
    Vec3f _velocity;
    Vec3f _force;
    
    int _weight;
};

#endif