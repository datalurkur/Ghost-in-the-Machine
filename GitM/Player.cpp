#include <GitM/Player.h>
#include <GitM/DebugVolume.h>
#include <Engine/PhysicsEngine.h>
#include <Resource/MaterialManager.h>

const std::string Player::NodeType = "Player";

const char Player::PlayerBody = 1,
           Player::JumpSensor = 2;

Player::Player(const std::string &name):
	Mob(name, NodeType),
	_playerController(0)
{}

Player::~Player() {
	_physicsController->getEngine()->removeFixtureContactListener(&JumpSensor);
}

void Player::recreateRenderables() {
    clearRenderables();
    addRenderable(Renderable::Sprite(_position, Vector2(_dimensions.x, _dimensions.y), 0, MaterialManager::Get("playerMaterial")));

	// Debug
    deleteChild("jumpSensor");
	DebugVolume *jumpVolume = new DebugVolume("jumpSensor");
	jumpVolume->setPosition(_position.x + _jumpSensorOffset.x, _position.y + _jumpSensorOffset.y);
	jumpVolume->setDimensions(_jumpSensorDimensions.x, _jumpSensorDimensions.y);
	addChild(jumpVolume);
}

void Player::setupPhysics(PhysicsEngine *physics) {
    _physicsController = addController<PhysicsController,PhysicsEngine>(physics);

	// Add the player controller as a listener for player / jump volume contacts
	physics->addFixtureContactListener(&Player::JumpSensor, _playerController);

    createPhysicsBody();
}

void Player::createPhysicsBody() {
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
    playerShape.SetAsBox(_dimensions.x / 2.0f, _dimensions.y / 2.0f);
    
    // Create the player fixture
    playerDef.shape = &playerShape;
    playerDef.density = 1.0f;
    playerDef.friction = 0.3f;
    player = body->CreateFixture(&playerDef);
	player->SetUserData((void*)&PlayerBody);

	// Add the jump sensor
	sensorShape.SetAsBox(_jumpSensorDimensions.x / 2.0f, _jumpSensorDimensions.y / 2.0f,
		b2Vec2(_jumpSensorOffset.x, _jumpSensorOffset.y), 0);
	sensorDef.isSensor = true;
	sensorDef.shape = &sensorShape;
	sensor = body->CreateFixture(&sensorDef);
	sensor->SetUserData((void*)&JumpSensor);

    _physicsController->setBody(body);
}

void Player::setPlayerController(PlayerController *controller) {
    _playerController = controller;
}

PlayerController *Player::getPlayerController() const {
	return _playerController;
}

Player* Player::DefaultPlayer() {
    Player *player = new Player("defaultPlayer");
    player->setDimensions(0.5f, 1.0f);
    
    player->_maxSpeed = 6.0f;
    player->_accel = 0.02f;
    player->_jumpPower = 3.0f;
    player->_jumpSensorDimensions = Vector2(0.3f, 0.1f);
    player->_jumpSensorOffset = Vector2(0.0f, -0.5f);
    
    PlayerController *controller = player->addController<PlayerController,Player>(player);
    player->setPlayerController(controller);

    player->recreateRenderables();
    return player;
}