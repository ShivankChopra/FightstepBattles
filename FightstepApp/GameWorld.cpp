#include "GameWorld.h"

GameWorld::GameWorld(sf::Texture& playerTexture, sf::Texture& villianTexture, sf::Texture& wallTexture) : _physicsWorld(b2Vec2(0, 0.2))
{
	_player = new GameComponent(playerTexture, _physicsWorld, ComponentType::PLAYER, 150, 150);

	_walls.push_back(new GameComponent(wallTexture, _physicsWorld, ComponentType::HORIZONTAL_WALL, 20, 50)); // upper wall
	_walls.push_back(new GameComponent(wallTexture, _physicsWorld, ComponentType::HORIZONTAL_WALL, 20, 500)); // lower wall
	_walls.push_back(new GameComponent(wallTexture, _physicsWorld, ComponentType::VERTICAL_WALL, 20, 20)); // left wall
	_walls.push_back(new GameComponent(wallTexture, _physicsWorld, ComponentType::VERTICAL_WALL, 500, 20)); // right wall

	for (int i = 0; i < 5; i++)
	{
		_villianList.push_back(new GameComponent(villianTexture, _physicsWorld, ComponentType::ENEMY, 150, 100));
	}
}

GameWorld::~GameWorld()
{
	delete _player;

	for (int i = 0; i < _villianList.size(); i++)
	{
		delete _villianList[i];
	}

	for (int i = 0; i < _walls.size(); i++)
	{
		delete _walls[i];
	}
}

void GameWorld::handleInput(sf::Event& event)
{
	_player->handleInput(event);

	for (int i = 0; i < _villianList.size(); i++)
	{
		_villianList[i]->handleInput(event);
	}
}

void GameWorld::update()
{
	_physicsWorld.Step(1 / 60.f, 6, 3);

	_player->update();

	for (int i = 0; i < _walls.size(); i++)
	{
		_walls[i]->update();
	}

	for (int i = 0; i < _villianList.size(); i++)
	{
		_villianList[i]->update();
	}
}

void GameWorld::render(sf::RenderWindow& window)
{
	_player->render(window);

	for (int i = 0; i < _villianList.size(); i++)
	{
		_villianList[i]->render(window);
	}

	for (int i = 0; i < _walls.size(); i++)
	{
		_walls[i]->render(window);
	}
}
