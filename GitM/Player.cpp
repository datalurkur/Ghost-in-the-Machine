#include <GitM/Player.h>
#include <GitM/DebugVolume.h>

#include <Engine/PhysicsEngine.h>
#include <Resource/MaterialManager.h>

const std::string Player::NodeType = "Player";

Player::Player(const std::string &name):
	Entity(name, NodeType), _speed(0.05f),
	_playerController(0)
{
	setDimensions(1.0f, 1.0f);
    recreateRenderables();
	_playerController = addController<PlayerController,Player>(this);

	// Debug
	DebugVolume *jumpVolume = new DebugVolume("jumpVolume");
	jumpVolume->setPosition(_position.x, _position.y - ((_dimensions.y + 0.1f) / 2.0f));
	jumpVolume->setDimensions(_dimensions.x / 2.0f, 0.1f);
	addChild(jumpVolume);
}

Player::~Player() {
}

void Player::recreateRenderables() {
    clearRenderables();
    addRenderable(Renderable::Sprite(_position, Vector2(_dimensions.x, _dimensions.y), 0, MaterialManager::Get("playerMaterial")));
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
    playerShape.SetAsBox(_dimensions.x / 2.0f, _dimensions.y / 2.0f);
    
    // Create the player fixture
    playerDef.shape = &playerShape;
    playerDef.density = 1.0f;
    playerDef.friction = 0.3f;
    body->CreateFixture(&playerDef);

	// Add the jump sensor
	sensorShape.SetAsBox(_dimensions.x / 2.0f, 0.1f, b2Vec2(_position.x, _position.y - ((_dimensions.y + 0.1f) / 2.0f)), 0);
	sensorDef.isSensor = true;
	sensorDef.shape = &sensorShape;
	body->CreateFixture(&sensorDef);

    _physicsController->setBody(body);
}

PlayerController *Player::getPlayerController() const {
	return _playerController;
}