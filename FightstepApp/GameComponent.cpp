#include "GameComponent.h"
#include "DynamicPhysicsComponent.h"
#include "StaticPhysicsComponent.h"

// Pixels per meter. Box2D uses metric units, so we need to define a conversion
#define PPM 30.0F

GameComponent::GameComponent(sf::Texture& texture, b2World& world, ComponentType componentType, int x, int y)
{
	// @TODO : need to create proper entities factories

	switch (componentType)
	{
	case ComponentType::PLAYER:
		_constructPlayer(texture, world, x, y);
		break;
	case ComponentType::ENEMY:
		_constructEnemy(texture, world, x, y);
		break;
	case ComponentType::HORIZONTAL_WALL:
		_constructHorizontalWall(texture, world, x, y);
		break;
	case ComponentType::VERTICAL_WALL:
		_constructVerticalWall(texture, world, x, y);
		break;
	default:
		throw std::runtime_error("Unhandled component type while creating game component.");
	}

}

GameComponent::~GameComponent()
{
	delete _physicsComponent;
	delete _renderComponent;
}

void GameComponent::update()
{
	b2Vec2 pos = _physicsComponent->getPosition();
	_renderComponent->setPosition(pos.x * PPM, pos.y * PPM);
}

void GameComponent::render(sf::RenderWindow& renderWindow)
{
	_renderComponent->render(renderWindow);
}

void GameComponent::_constructVerticalWall(sf::Texture& texture, b2World& world, int x, int y)
{
	_renderComponent = new RenderComponent(texture, 500, 20000, true);
	sf::Vector2f dimensions = _renderComponent->getDimensions();
	_physicsComponent = new StaticPhysicsComponent(world, x, y, dimensions.x, dimensions.y);
}

void GameComponent::_constructHorizontalWall(sf::Texture& texture, b2World& world, int x, int y)
{
	_renderComponent = new RenderComponent(texture, 20000, 500, true);
	sf::Vector2f dimensions = _renderComponent->getDimensions();
	_physicsComponent = new StaticPhysicsComponent(world, x, y, dimensions.x, dimensions.y);
}

void GameComponent::_constructEnemy(sf::Texture& texture, b2World& world, int x, int y)
{
	_renderComponent = new RenderComponent(texture);
	sf::Vector2f dimensions = _renderComponent->getDimensions();
	_physicsComponent = new DynamicPhysicsComponent(world, x, y, dimensions.x, dimensions.y);
}

void GameComponent::_constructPlayer(sf::Texture& texture, b2World& world, int x, int y)
{
	_renderComponent = new RenderComponent(texture);
	sf::Vector2f dimensions = _renderComponent->getDimensions();
	_physicsComponent = new DynamicPhysicsComponent(world, x, y, dimensions.x, dimensions.y);
}
