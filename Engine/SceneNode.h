#ifndef SCENENODE_H
#define SCENENODE_H

#include <Base/Vector.h>

class SceneNode;
typedef std::map<std::string, SceneNode*> NodeMap;

class SceneNode {
public:
	static const std::string NodeType;

public:
	SceneNode(const std::string &name);
	virtual ~SceneNode();

	Vector2 getAbsolutePosition() const;
	Vector2 getLocalPosition() const;

	const std::string &getName() const;
	const std::string &getType() const;

	void addChild(SceneNode *child);

protected:
	std::string _name;
	Vector2 _position;

	SceneNode *_parent;
	NodeMap _children;
};

#endif