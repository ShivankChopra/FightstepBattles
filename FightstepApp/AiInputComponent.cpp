#include "AiInputComponent.h"

AiInputComponent::AiInputComponent() : _counter(0), _idleCommand(new Command(CommandType::IDLE))
{
	_behaviourSequence.push_back(new Command(CommandType::JUMP));
	_behaviourSequence.push_back(new Command(CommandType::MOVE_LEFT));
	_behaviourSequence.push_back(new Command(CommandType::MOVE_RIGHT));
}

AiInputComponent::~AiInputComponent()
{
	delete _idleCommand;

	for (int i = 0; i < _behaviourSequence.size(); i++)
	{
		delete _behaviourSequence[i];
	}
}

Command* AiInputComponent::getCommand()
{
	if (_counter == _behaviourSequence.size())
		_counter = 0; // reset

	return _behaviourSequence[_counter++];
}

Command* AiInputComponent::getCommand(sf::Event& event)
{
	return _idleCommand;
}
