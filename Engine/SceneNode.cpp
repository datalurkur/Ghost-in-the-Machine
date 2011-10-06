#include <Base/Log.h>
#include <Engine/SceneNode.h>

const std::string SceneNode::NodeType = "SceneNode";

SceneNode::SceneNode(const std::string &name):
	_name(name), _type(NodeType), _dirty(true), _parent(0)
{}

SceneNode::SceneNode(const std::string &name, const std::string &type):
	_name(name), _type(type), _dirty(true), _parent(0)
{}

SceneNode::~SceneNode() {
	clearRenderables(true);
	NodeMap::iterator itr = _children.begin();
	for(; itr != _children.end(); itr++) {
		delete (itr->second);
	}
	_children.clear();
}

Vector2 SceneNode::getAbsolutePosition() const {
    ASSERT(!_dirty);

    return _absolutePosition;

}
Vector2 SceneNode::getLocalPosition() const {
    ASSERT(!_dirty);

    return _position;
}

void SceneNode::setPosition(const Vector2 &pos) {
	_position = pos;
	flagDirty(Downward);
}

void SceneNode::moveRelative(const Vector2 &pos) {
    _position += pos;
    flagDirty(Downward);
}

const std::string &SceneNode::getName() const {	return _name; }
const std::string &SceneNode::getType() const {	return NodeType; }

void SceneNode::addChild(SceneNode *child) {
	_children[child->getName()] = child;
	child->_parent = this;

    // Bounding boxes need to be recomputed
    flagDirty(Upward);
}

void SceneNode::getNodes(NodeList &list, Frustum *frustum) {
    ASSERT(!_dirty);

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
    ASSERT(!_dirty);

	//Info("SceneNode " << _name << " adding " << _renderables.size() << " renderables to list.");
	list.insert(list.end(), _renderables.begin(), _renderables.end());
}

void SceneNode::addRenderable(Renderable *renderable) {
	_renderables.push_back(renderable);
}

void SceneNode::clearRenderables(bool deleteOnClear) {
	if(deleteOnClear) {
		RenderableList::iterator itr = _renderables.begin();
		for(; itr != _renderables.end(); itr++) {
			delete *itr;
		}
	}
	_renderables.clear();
}

void SceneNode::updateCachedValues() {
	bool needsUpdate = _dirty;

	if(needsUpdate) {
        _dirty = false;

		// Update any values dependent on the parent state
        if(_parent) {
            _absolutePosition = _position + _parent->getAbsolutePosition();
        }

        // Update any values dependent on other local values
        // FIXME - Eventually, these need to be full affine transformations, to deal with rotation
        _affine = Matrix4::MakeTranslation(_position.x, _position.y, 0.0);
        _absoluteAffine = Matrix4::MakeTranslation(_absolutePosition.x, _absolutePosition.y, 0);

        // Update renderable view matrices
        RenderableList::iterator rItr = _renderables.begin();
        for(; rItr != _renderables.end(); rItr++) {
            (*rItr)->setViewMatrix(_absoluteAffine);
        }
    }

	NodeMap::iterator itr = _children.begin();
	for(; itr != _children.end(); itr++) {
		itr->second->updateCachedValues();
	}
    
    if(needsUpdate) {
        // Update any values dependend on child states
        // FIXME - Update bounding boxes here
    }
}

void SceneNode::flagDirty(DirtyPropagation direction) {
	_dirty = true;
	if(direction == Upward) {
        if(_parent) { _parent->flagDirty(direction); }
	} else {
		NodeMap::iterator itr = _children.begin();
		for(; itr != _children.end(); itr++) {
			itr->second->flagDirty(direction);
		}
	}
}
