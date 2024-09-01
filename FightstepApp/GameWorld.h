#pragma once

#include <box2d/box2d.h>
#include <sfml/Graphics.hpp>
#include "GameComponent.h"

class GameWorld
{
public:
	GameWorld(sf::Texture& playerTexture, sf::Texture& villianTexture, sf::Texture& wallTexture);
	~GameWorld();

	bool handleInput(sf::Event&, sf::Time&);
	void update();
	void render(sf::RenderWindow&);

private:

	b2World _physicsWorld;
	std::vector<GameComponent*> _villianList;
	std::vector<GameComponent*> _walls;
	GameComponent* _player;
};

