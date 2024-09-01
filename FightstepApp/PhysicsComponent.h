#pragma once

#include <box2d/box2d.h>

enum class PhysicsType
{
	STATIC, DYNAMIC, KINEMATIC
};

class PhysicsComponent
{
public:
	virtual b2Vec2 getPosition() = 0;

	virtual void jump() = 0;

	virtual void moveLeft() = 0;

	virtual void moveRight() = 0;
};
