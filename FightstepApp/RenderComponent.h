#pragma once

#include <SFML/Graphics.hpp>

class RenderComponent
{

public:
	RenderComponent(sf::Texture&);

	RenderComponent(sf::Texture&, int width, int height, bool repeatTexture = false);

	void setPosition(int x, int y);

	sf::Vector2f getDimensions();

	void render(sf::RenderWindow&);

private:
	sf::Sprite _sprite;
};

