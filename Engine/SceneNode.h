#ifndef SCENENODE_H
#define SCENENODE_H

#include <Base/Vector2.h>
#include <Base/AABB2.h>
#include <Engine/Frustum.h>
#include <Render/Renderable.h>

class SceneNode;
class SceneManager;
typedef std::map<std::string, SceneNode*> NodeMap;
typedef std::list<SceneNode*> NodeList;

class SceneNode {
public:
	static const std::string NodeType;

	enum DirtyPropagation { Upward, Downward };

public:
	SceneNode(const std::string &name);
	virtual ~SceneNode();

	// Positions
	Vector2 getAbsolutePosition() const;
	Vector2 getLocalPosition() const;

    void setPosition(float x, float y);
	void setPosition(const Vector2 &pos);
    void moveRelative(const Vector2 &pos);
    
    // Dimensions
    Vector2 getDimensions() const;
	void setDimensions(float x, float y);
    void setDimensions(const Vector2 &dim);

    // AABB Information
    const AABB2& getAbsoluteBounds() const;

	// Identifying information
	const std::string &getName() const;
	const std::string &getType() const;

	// Scene heirarchy
	void addChild(SceneNode *child);
    void deleteChild(const std::string &childName);

	// Adds this scene node and its children to the list
	// If frustum is non-null, frustum culling will be performed
	void getNodes(NodeList &list, Frustum *frustum = 0);
	
	// Adds the renderables to the provided list
	virtual void getRenderables(RenderableList &list);

	// Adds a renderable to the scenenode's internal renderable list
	void addRenderable(Renderable *renderable);

	// Clear the renderable list and delete the renderables if flag is set
	void clearRenderables(bool deleteOnClear = true);

	// Regenerate the renderables automatically (on a resize, for example)
	virtual void recreateRenderables() {
		Info("SceneNode regenerating renderables");
	}

protected:
	SceneNode(const std::string &name, const std::string &type);
	
	// Updates any values that are dependent on local state or parent state
	void updateCachedValues();

	// Indicate that cached values should be updated before used
	void flagDirty(DirtyPropagation direction);

protected:
	std::string _name;
	std::string _type;

	Vector2 _position;
	Vector2 _absolutePosition;
    
    Vector2 _dimensions;
    AABB2 _absoluteBounds;

	Matrix4 _affine;
	Matrix4 _absoluteAffine;

	SceneNode *_parent;
	NodeMap _children;

	bool _dirty;

	RenderableList _renderables;
    friend class SceneManager;
};

#endif
