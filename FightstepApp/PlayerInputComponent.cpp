#include "PlayerInputComponent.h"
#include <SFML/Window.hpp>

PlayerInputComponent::PlayerInputComponent() :
	_idleCommand(new Command(CommandType::IDLE)),
	_jumpCommand(new Command(CommandType::JUMP)),
	_moveLeftCommand(new Command(CommandType::MOVE_LEFT)),
	_moveRightCommand(new Command(CommandType::MOVE_RIGHT))
{}

PlayerInputComponent::~PlayerInputComponent()
{
	delete _idleCommand;
	delete _jumpCommand;
	delete _moveLeftCommand;
	delete _moveRightCommand;
}

Command* PlayerInputComponent::getCommand()
{
	return _idleCommand;
}

Command* PlayerInputComponent::getCommand(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			return _jumpCommand;
		case sf::Keyboard::Left:
			return _moveLeftCommand;
		case sf::Keyboard::Right:
			return _moveRightCommand;
		default:
			return _idleCommand;
		}
	}
	else
	{
		return _idleCommand;
	}
}
