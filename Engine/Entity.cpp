#include <Engine/Entity.h>
#include <GitM/Player.h>

const std::string Entity::NodeType = "Entity";

Entity::Entity(const std::string &name):
	SceneNode(name, NodeType), _pController(0)
{
}

Entity::Entity(const std::string &name, const std::string &type):
	SceneNode(name, type), _pController(0)
{
}

Entity::~Entity() {
    ControllerList::iterator itr = _controllers.begin();
    for(; itr != _controllers.end(); itr++) {
        delete (*itr);
    }
    _controllers.clear();
}

void Entity::update(int elapsed) {
    ControllerList::iterator itr = _controllers.begin();
    for(; itr != _controllers.end(); itr++) {
        (*itr)->update(elapsed);
    }
}

template <>
void Entity::addController<PhysicsEngine>(PhysicsEngine* controlObject) {
    _pController = new PhysicsController(controlObject, this);
    _controllers.push_back(_pController);
}

template <>
void Entity::addController<Player>(Player* player) {
	PlayerController *p = new PlayerController(player);
	player->setPlayerController(p);
	_controllers.push_back(p);
}