#pragma once

#include "InputComponent.h"
#include "Command.h"
#include <SFML/Window/Window.hpp>

class AiInputComponent : public InputComponent
{
public:
	AiInputComponent();
	~AiInputComponent();

	Command* getCommand() override;
	Command* getCommand(sf::Event& event) override;

private:
	int _counter;
	Command* _idleCommand;
	std::vector<Command*> _behaviourSequence;
};

