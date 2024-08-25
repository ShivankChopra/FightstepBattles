#include "StaticPhysicsComponent.h"

// Pixels per meter. Box2D uses metric units, so we need to define a conversion
#define PPM 30.0F
// SFML uses degrees for angles while Box2D uses radians
#define DEG_PER_RAD 57.2957795F

StaticPhysicsComponent::StaticPhysicsComponent(b2World& world, int x, int y, int width, int height) :
	_posx(x),
	_posy(y),
	_width(width),
	_height(height)
{
	_setupBody(world);
}

b2Vec2 StaticPhysicsComponent::getPosition()
{
	return _body->GetPosition();
}

void StaticPhysicsComponent::_setupBody(b2World& worldRef)
{
	b2BodyDef boxBodyDef;
	boxBodyDef.position.Set(_posx / PPM, _posy / PPM);
	boxBodyDef.type = b2_staticBody;

	b2PolygonShape boxShape;
	boxShape.SetAsBox(_width / 2 / PPM, _height / 2 / PPM); // do check for int/float related issues

	b2FixtureDef fixtureDef;
	fixtureDef.density = 0.1f;
	fixtureDef.friction = 0.7f;
	fixtureDef.restitution = 1.0f;
	fixtureDef.shape = &boxShape;

	_body = worldRef.CreateBody(&boxBodyDef);
	_body->CreateFixture(&fixtureDef);
}
