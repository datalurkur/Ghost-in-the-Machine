#ifndef SIMPLEWORLD_H
#define SIMPLEWORLD_H

#include <Engine/World.h>

class Node;

class SimpleWorld: public World {
public:
	SimpleWorld();
	virtual ~SimpleWorld();
    void load();
	void update(int elapsed);

private:  
    Node* addNode(const std::string &name);
    void linkNodes(const std::string &name1, const std::string &name2);
    void linkNodes(Node *node1, Node *node2);
  
private:
    std::map<std::string,Node*> _nodes;
};

#endif
