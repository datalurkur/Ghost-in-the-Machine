#include <Base/Log.h>
#include <Engine/SceneNode.h>

const std::string SceneNode::NodeType = "SceneNode";

SceneNode::SceneNode(const std::string &name):
	_name(name), _type(NodeType), _parent(0), _dirty(true)
{}

SceneNode::SceneNode(const std::string &name, const std::string &type):
	_name(name), _type(type), _parent(0), _dirty(true)
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

void SceneNode::setPosition(float x, float y) {
    // Any children dependent on this node will need to update their absolute positions
    _position.x = x;
    _position.y = y;
    flagDirty(Downward);

    // This will change the position of the AABB, so the parent may need to adjust the size of its AABB
    flagDirty(Upward);
}

void SceneNode::setPosition(const Vector2 &pos) {
	setPosition(pos.x, pos.y);
}

Vector2 SceneNode::getDimensions() const {
    return _dimensions;
}

void SceneNode::setDimensions(float x, float y) {
    _dimensions.x = x;
    _dimensions.y = y;

    // Parents will need to update their AABBs
    flagDirty(Upward);
	recreateRenderables();
}

void SceneNode::setDimensions(const Vector2 &dim) {
	setDimensions(dim.x, dim.y);
}

const AABB2& SceneNode::getAbsoluteBounds() const {
    ASSERT(!_dirty);
    return _absoluteBounds;
}

void SceneNode::moveRelative(const Vector2 &pos) {
    setPosition(_position + pos);
}

const std::string &SceneNode::getName() const {	return _name; }
const std::string &SceneNode::getType() const {	return NodeType; }

void SceneNode::addChild(SceneNode *child) {
	_children[child->getName()] = child;
	child->_parent = this;

    // Bounding boxes need to be recomputed
    flagDirty(Upward);
}

void SceneNode::deleteChild(const std::string &childName) {
    NodeMap::iterator itr = _children.find(childName);
    if(itr != _children.end()) {
        delete itr->second;
        _children.erase(itr);
    }
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

        // Update the absolute AABB
        _absoluteBounds = AABB2(
            _absolutePosition - (_dimensions / 2.0f),
            _absolutePosition + (_dimensions / 2.0f)
        );

        // Expand the AABB with the children's bounds
        NodeMap::iterator itr = _children.begin();
        for(; itr != _children.end(); itr++) {
            _absoluteBounds.expand(itr->second->getAbsoluteBounds());
        }
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
