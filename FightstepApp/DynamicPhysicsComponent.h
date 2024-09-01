#pragma once

#include "PhysicsComponent.h"

class DynamicPhysicsComponent : public PhysicsComponent
{

public:
	DynamicPhysicsComponent(b2World&, int x, int y, int width, int height);

	b2Vec2 getPosition() override;

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

