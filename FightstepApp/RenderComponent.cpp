#include "RenderComponent.h"

RenderComponent::RenderComponent(sf::Texture& texture)
{
	_sprite.setTexture(texture);
	_sprite.setScale(0.05, 0.05);
}

RenderComponent::RenderComponent(sf::Texture& texture, int width, int height, bool repeatTexture)
{
	texture.setRepeated(repeatTexture);
	_sprite.setTexture(texture);
	_sprite.setTextureRect(sf::IntRect(0, 0, width, height));
	_sprite.setScale(0.05, 0.05);
}

void RenderComponent::setPosition(int x, int y)
{
	_sprite.setPosition(x, y);
}

sf::Vector2f RenderComponent::getDimensions()
{
	return _sprite.getGlobalBounds().getSize();
}

void RenderComponent::render(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(_sprite);
}
