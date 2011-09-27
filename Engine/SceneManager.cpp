#include <Engine/SceneManager.h>

SceneManager::SceneManager() {
	_root = new SceneNode("root");
}

SceneManager::~SceneManager() {
	delete _root;
}