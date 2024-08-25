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
};
