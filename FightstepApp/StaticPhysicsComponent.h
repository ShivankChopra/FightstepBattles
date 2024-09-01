#pragma once

#include "PhysicsComponent.h"

class StaticPhysicsComponent : public PhysicsComponent
{
public:
	StaticPhysicsComponent(b2World&, int x, int y, int width, int height);

	b2Vec2 getPosition() override;

	// not implemented
	void jump() override;
	void moveLeft() override;
	void moveRight() override;

private:
	void _setupBody(b2World&);

	int _width;
	int _height;
	int _posx;
	int _posy;

	b2Body* _body;
};

