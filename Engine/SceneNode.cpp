#include <Engine/SceneNode.h>

const std::string SceneNode::NodeType = "SceneNode";

SceneNode::SceneNode(const std::string &name):
	_position(0,0), _name(name) {
}

SceneNode::~SceneNode() {
}

Vector2 SceneNode::getAbsolutePosition() const {
	if(_parent) {
		return _position + _parent->getAbsolutePosition();
	} else {
		return _position;
	}
}

Vector2 SceneNode::getLocalPosition() const {
	return _position;
}

const std::string &SceneNode::getName() const {
	return _name;
}

const std::string &SceneNode::getType() const {
	return NodeType;
}

void SceneNode::addChild(SceneNode *child) {
	_children[child->getName()] = child;
	child->_parent = this;
}