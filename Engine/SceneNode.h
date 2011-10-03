#ifndef SCENENODE_H
#define SCENENODE_H

#include <Base/Vector2.h>

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
    SceneNode(const std::string &name, const std::string &type);

protected:
	std::string _name;
    std::string _type;

	Vector2 _position;

	SceneNode *_parent;
	NodeMap _children;
};

#endif
