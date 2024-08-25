#include "MainGame.h"
#include "GameComponent.h"
#include "DynamicPhysicsComponent.h"

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
	while (_window.isOpen())
	{
		_world->update();

		sf::Event pollEvent;

		while (_window.pollEvent(pollEvent))
		{
			if (pollEvent.type == sf::Event::Closed)
				_window.close();
		}

		_window.clear();
		_world->render(_window);
		_window.display();
	}
}