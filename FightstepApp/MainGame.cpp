#include "MainGame.h"
#include "GameComponent.h"
#include "DynamicPhysicsComponent.h"

#include <SFML/System.hpp> // For sf::Clock and sf::Time

MainGame::MainGame(sf::RenderWindow& windowRef, sf::Texture& playerTexture, sf::Texture& villianTexture, sf::Texture& wallTexture) :
	_window(windowRef),
	_playerTexture(playerTexture),
	_villianTexture(villianTexture),
	_wallTexture(wallTexture)

{
	_world = new GameWorld(_playerTexture, _villianTexture, _wallTexture);
}

MainGame::~MainGame()
{
	delete _world;
}

void MainGame::run()
{
	sf::Clock clock;
	sf::Time elapsedTime = sf::Time::Zero;

	while (_window.isOpen())
	{
		sf::Event pollEvent;

		while (_window.pollEvent(pollEvent))
		{
			if (pollEvent.type == sf::Event::Closed)
				_window.close();
		}

		elapsedTime += clock.restart();

		if (elapsedTime.asSeconds() >= 1.618f) // Golden ratio ;-)
		{
			_world->handleInput(pollEvent);
			elapsedTime = sf::Time::Zero;
		}

		_world->update();

		_window.clear();
		_world->render(_window);
		_window.display();
	}
}