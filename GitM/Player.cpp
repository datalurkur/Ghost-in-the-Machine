#include <GitM/Player.h>
#include <GitM/DebugVolume.h>
#include <GitM/GameConstants.h>
#include <Engine/PhysicsEngine.h>
#include <Resource/MaterialManager.h>

const std::string Player::NodeType = "Player";

Player::Player(const std::string &name):
	Entity(name, NodeType),
	_playerController(0)
{
	setDimensions(PlayerConst::Width, PlayerConst::Height);
    recreateRenderables();
	_playerController = addController<PlayerController,Player>(this);

	// Debug
	DebugVolume *jumpVolume = new DebugVolume("jumpSensor");
	jumpVolume->setPosition(_position.x + PlayerConst::JumpSensorOffsetX, _position.y + PlayerConst::JumpSensorOffsetY);
	jumpVolume->setDimensions(PlayerConst::JumpSensorWidth, PlayerConst::JumpSensorHeight);
	addChild(jumpVolume);
}

Player::~Player() {
	_physicsController->getEngine()->removeFixtureContactListener("jumpSensor");
}

void Player::recreateRenderables() {
    clearRenderables();
    addRenderable(Renderable::Sprite(_position, Vector2(_dimensions.x, _dimensions.y), 0, MaterialManager::Get("playerMaterial")));
}

void Player::setupPhysics(PhysicsEngine *physics) {
    _physicsController = addController<PhysicsController,PhysicsEngine>(physics);

	// Add the player controller as a listener for player / jump volume contacts
	physics->addFixtureContactListener("jumpSensor", _playerController);

    recreatePhysicsBody();
}

void Player::recreatePhysicsBody() {
    b2BodyDef bDef;
    b2FixtureDef playerDef, sensorDef;
    b2PolygonShape playerShape, sensorShape;
    b2Body *body;
	b2Fixture *player, *sensor;
    b2World *physicsWorld;
	PhysicsEngine *engine;

	engine = _physicsController->getEngine();  
    physicsWorld = engine->getPhysicsWorld();
  
    // Create the main body
    bDef.type = b2_dynamicBody;
    bDef.fixedRotation = true;
    bDef.position.Set(_position.x, _position.y);
    body = physicsWorld->CreateBody(&bDef);
	body->SetUserData(this);
    
    // Create the player fixture shape
    // The dimensions passed are the half-extents
    playerShape.SetAsBox(PlayerConst::Width / 2.0f, PlayerConst::Height / 2.0f);
    
    // Create the player fixture
    playerDef.shape = &playerShape;
    playerDef.density = 1.0f;
    playerDef.friction = 0.3f;
    player = body->CreateFixture(&playerDef);
	player->SetUserData("playerBody");

	// Add the jump sensor
	sensorShape.SetAsBox(PlayerConst::JumpSensorWidth / 2.0f, PlayerConst::JumpSensorHeight / 2.0f,
		b2Vec2(PlayerConst::JumpSensorOffsetX, PlayerConst::JumpSensorOffsetY), 0);
	sensorDef.isSensor = true;
	sensorDef.shape = &sensorShape;
	sensor = body->CreateFixture(&sensorDef);
	sensor->SetUserData("jumpSensor");

	// FIXME - I don't like using strings for the fixture IDs, but I don't see what other choice I have, short of finding meaningful pointers to stuff in there

    _physicsController->setBody(body);
}

PlayerController *Player::getPlayerController() const {
	return _playerController;
}