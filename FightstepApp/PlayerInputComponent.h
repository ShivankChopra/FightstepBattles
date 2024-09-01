#pragma once

#include "InputComponent.h"
#include "Command.h"
#include <SFML/Window/Window.hpp>

class PlayerInputComponent : public InputComponent
{
public:
	PlayerInputComponent();
	~PlayerInputComponent();

	Command* getCommand() override;
	Command* getCommand(sf::Event& event) override;

private:
	Command* _idleCommand;
	Command* _jumpCommand;
	Command* _moveLeftCommand;
	Command* _moveRightCommand;
};
