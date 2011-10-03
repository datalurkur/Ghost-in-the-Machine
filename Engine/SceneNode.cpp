#include <Engine/SceneNode.h>

const std::string SceneNode::NodeType = "SceneNode";

SceneNode::SceneNode(const std::string &name):
	_name(name), _type(NodeType), _dirty(true), _parent(0)
{}

SceneNode::SceneNode(const std::string &name, const std::string &type):
	_name(name), _type(type), _dirty(true), _parent(0)
{}

SceneNode::~SceneNode() {
}

Vector2 SceneNode::getAbsolutePosition() const { return _absolutePosition; }
Vector2 SceneNode::getLocalPosition() const { return _position; }

void SceneNode::setPosition(const Vector2 &pos) {
	_position = pos;
	flagDirty(Downward);
}

const std::string &SceneNode::getName() const {	return _name; }
const std::string &SceneNode::getType() const {	return NodeType; }

void SceneNode::addChild(SceneNode *child) {
	_children[child->getName()] = child;
	child->_parent = this;
}

void SceneNode::getNodes(NodeList &list, Frustum *frustum) {
	if(frustum) {
		// Do bounds checking and return early if this node is not within the view frustum
		// FIXME - Actually implement frustum culling
	}
	list.push_back(this);
	NodeMap::iterator itr = _children.begin();
	for(; itr != _children.end(); itr++) {
		itr->second->getNodes(list, frustum);
	}
}

void SceneNode::getRenderables(RenderableList &list) {
	list.insert(list.end(), _renderables.begin(), _renderables.end());
}

void SceneNode::updateCachedValues() {
	if(!_dirty) { return; }

	// Update any values dependent on the parent state
	if(_parent) {
		_absolutePosition = _position + _parent->getAbsolutePosition();
	}

	// Update any values dependent on other local values
	// FIXME - Eventually, these need to be full affine transformations, to deal with rotation
	_affine = Matrix4::MakeTranslation(_position.x, _position.y, 0.0);
	_absoluteAffine = Matrix4::MakeTranslation(_absolutePosition.x, _absolutePosition.y, 0);

	_dirty = false;

	RenderableList::iterator rItr = _renderables.begin();
	for(; rItr != _renderables.end(); rItr++) {
		(*rItr)->setViewMatrix(_absoluteAffine);
	}

	NodeMap::iterator itr = _children.begin();
	for(; itr != _children.end(); itr++) {
		itr->second->updateCachedValues();
	}
}

void SceneNode::flagDirty(DirtyPropagation direction) {
	_dirty = true;
	if(direction == Upward && _parent) {
		_parent->flagDirty(direction);
	} else {
		NodeMap::iterator itr = _children.begin();
		for(; itr != _children.end(); itr++) {
			itr->second->flagDirty(direction);
		}
	}
}
