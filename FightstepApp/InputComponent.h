#pragma once

#include "Command.h"
#include <SFML/Window/Window.hpp>

class InputComponent
{
public:
	virtual Command* getCommand() = 0;

	virtual Command* getCommand(sf::Event& event) = 0;
};