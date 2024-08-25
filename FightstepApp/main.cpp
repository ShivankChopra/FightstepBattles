#include "MainGame.h"

int main()
{
	std::string assetsBasePath = "C:\\Users\\Shivank Chopra\\Documents\\Projects\\SFML Projects\\assets\\";

	sf::Texture villianTexture;
	villianTexture.loadFromFile(assetsBasePath + "images\\villian.png");

	sf::Texture playerTexture;
	playerTexture.loadFromFile(assetsBasePath + "images\\player.png");

	sf::Texture wallTexture;
	wallTexture.loadFromFile(assetsBasePath + "images\\wall.jpg");

	sf::RenderWindow window(sf::VideoMode(1080, 720), "Fightstep Battles!");

	MainGame game(window, playerTexture, villianTexture, wallTexture);

	game.run();

	return 0;
}