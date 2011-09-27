#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <Engine/SceneNode.h>

class SceneManager {
public:
    SceneManager();
    ~SceneManager();

	template <typename T>
	void addNode(T *node);

	template <typename T>
	T* getNode(const std::string &name) const;

	template <typename T>
	void deleteNode(const std::string &name);

private:
	SceneNode *_root;
};

template <typename T>
void SceneManager::addNode(T *node) {
}

template <typename T>
T* SceneManager::getNode(const std::string &name) const {
}

template <typename T>
void SceneManager::deleteNode(const std::string &name) {
}

#endif
