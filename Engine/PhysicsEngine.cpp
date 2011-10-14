#include <Engine/PhysicsEngine.h>

PhysicsEngine::PhysicsEngine():
    _gravity(0.0, -10.0), _world(0),
    _velocityIterations(6), _positionIterations(2), _stepSize(16) // Roughly 1/60th of a second
{
    _world = new b2World(b2Vec2(_gravity));
    _world->SetContactListener(this);
}

PhysicsEngine::~PhysicsEngine() { 
    delete _world;
    _world = 0;
}

void PhysicsEngine::update(int elapsed) {
    static int leftOver = 0;
    leftOver += elapsed;
    while(leftOver > _stepSize) {
        leftOver -= _stepSize;
        _world->Step(_stepSize / 1000.0f, _velocityIterations, _positionIterations);
    }
}

b2World *PhysicsEngine::getPhysicsWorld() {
    return _world;
}

void PhysicsEngine::destroyObject(b2Body *body) {
    _world->DestroyBody(body);
}

void PhysicsEngine::BeginContact(b2Contact *contact) {
    ContactListenerMap::iterator itr = _contactListeners.begin();
    for(; itr != _contactListeners.end(); itr++) {
        Entity *a, *b;
        a = (Entity*)contact->GetFixtureA()->GetBody()->GetUserData();
        b = (Entity*)contact->GetFixtureA()->GetBody()->GetUserData();
        if(itr->first == a || itr->first == b) {
            itr->second->contactBegins(a, b);
        }
    }   
}

void PhysicsEngine::EndContact(b2Contact *contact) {
    Info("Contact ends");
}

void PhysicsEngine::addContactListenerCondition(Entity *entity, ContactListener *controller) {
    _contactListeners[entity] = controller;
}

void PhysicsEngine::removeContactListenerCondition(Entity *entity) {
    ContactListenerMap::iterator itr = _contactListeners.begin();
    for(; itr != _contactListeners.end(); itr++) {
        if(itr->first == entity) {
            _contactListeners.erase(itr);
            return;
        }
    }
}

b2Body *PhysicsEngine::createStaticBox(const Vector2 &pos, const Vector2 &dim) {
    b2BodyDef def;
    b2PolygonShape shape;
    b2Body *body;
    float halfWidth, halfHeight;
    
    halfWidth = dim.x / 2.0f;
    halfHeight = dim.y / 2.0f;

    // Create the body
    // The position passed is the center
    def.position.Set(pos.x, pos.y);
    body = _world->CreateBody(&def);
    
    // Create the fixture shape
    // The dimensions passed are the half-extents
    shape.SetAsBox(halfWidth, halfHeight);
    
    // Create the fixture
    body->CreateFixture(&shape, 0.0);
    
    return body;
}

b2Body *PhysicsEngine::createDynamicBox(const Vector2 &pos, const Vector2 &dim, float density, float friction, bool canRotate) {
    b2BodyDef bDef;
    b2FixtureDef fDef;
    b2PolygonShape shape;
    b2Body *body;
    float halfWidth, halfHeight;
    
    halfWidth = dim.x / 2.0f;
    halfHeight = dim.y / 2.0f;
    
    // Create the body
    // Set the body as dynamic
    bDef.type = b2_dynamicBody;
    // Can this body rotate?
    if(!canRotate) {
        bDef.fixedRotation = true;
    }
    // The position passed is the center
    bDef.position.Set(pos.x, pos.y);
    body = _world->CreateBody(&bDef);
    
    // Create the fixture shape
    // The dimensions passed are the half-extents
    shape.SetAsBox(halfWidth, halfHeight);
    
    // Create the fixture
    fDef.shape = &shape;
    fDef.density = density;
    fDef.friction = friction;
    body->CreateFixture(&fDef);
    
    return body;
}