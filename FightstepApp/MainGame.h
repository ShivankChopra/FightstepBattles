#pragma once

#include <SFML/Graphics.hpp>

#include "GameWorld.h"

class MainGame {

public:
	MainGame(sf::RenderWindow&, sf::Texture& playerTexture, sf::Texture& villianTexture, sf::Texture& wallTexture);
	~MainGame();

	void run();

private:
	sf::RenderWindow& _window;
	sf::Texture& _playerTexture;
	sf::Texture& _villianTexture;
	sf::Texture& _wallTexture;

	GameWorld* _world;
};
