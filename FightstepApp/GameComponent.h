#pragma once

#include "RenderComponent.h"
#include "PhysicsComponent.h"
#include "InputComponent.h"

enum class ComponentType
{
	PLAYER, ENEMY, VERTICAL_WALL, HORIZONTAL_WALL
};

class GameComponent
{

public:
	GameComponent(sf::Texture&, b2World&, ComponentType, int x, int y);
	~GameComponent();

	void jump();
	void moveLeft();
	void moveRight();

	void handleInput(sf::Event&);
	void update();
	void render(sf::RenderWindow&);

private:
	void _constructVerticalWall(sf::Texture&, b2World&, int x, int y);
	void _constructHorizontalWall(sf::Texture&, b2World&, int x, int y);
	void _constructEnemy(sf::Texture&, b2World&, int x, int y);
	void _constructPlayer(sf::Texture&, b2World&, int x, int y);

	RenderComponent* _renderComponent;
	PhysicsComponent* _physicsComponent;
	InputComponent* _inputComponent;
};

