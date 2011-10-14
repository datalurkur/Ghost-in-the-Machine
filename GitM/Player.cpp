#include <GitM/Player.h>

#include <Engine/PhysicsEngine.h>
#include <Resource/MaterialManager.h>

const std::string Player::NodeType = "Player";

Player::Player(const std::string &name):
	Entity(name, NodeType), _speed(0.05),
	_height(1.0), _width(1.0), _playerController(0)
{
    recreateRenderables();
	_playerController = addController<PlayerController,Player>(this);
}

Player::~Player() {
}

void Player::recreateRenderables() {
    clearRenderables();
    addRenderable(Renderable::Sprite(_position, Vector2(_width, _height), 0, MaterialManager::Get("playerMaterial")));
}

void Player::setupPhysics(PhysicsEngine *physics) {
    _physicsController = addController<PhysicsController,PhysicsEngine>(physics);
    recreatePhysicsBody();
}

void Player::recreatePhysicsBody() {
    b2BodyDef bDef;
    b2FixtureDef playerDef, sensorDef;
    b2PolygonShape playerShape, sensorShape;
    b2Body *body;
    b2World *physicsWorld;
    
    physicsWorld = _physicsController->getEngine()->getPhysicsWorld();
  
    // Create the main body
    bDef.type = b2_dynamicBody;
    bDef.fixedRotation = true;
    bDef.position.Set(_position.x, _position.y);
    body = physicsWorld->CreateBody(&bDef);
    body->SetUserData(_physicsController);
    
    // Create the player fixture shape
    // The dimensions passed are the half-extents
    playerShape.SetAsBox(_width / 2.0, _height / 2.0);
    
    // Create the player fixture
    playerDef.shape = &playerShape;
    playerDef.density = 1.0;
    playerDef.friction = 0.3;
    body->CreateFixture(&playerDef);

	// Add the jump sensor
	sensorShape.SetAsBox(_width / 2.0, 0.1, b2Vec2(_position.x, _position.y - ((_height + 0.1) / 2.0)), 0);
	sensorDef.isSensor = true;
	sensorDef.shape = &sensorShape;
	body->CreateFixture(&sensorDef);

    _physicsController->setBody(body);
}

PlayerController *Player::getPlayerController() const {
	return _playerController;
}