#pragma once

enum class CommandType
{
	JUMP, MOVE_LEFT, MOVE_RIGHT, IDLE
};

class Command
{
public:
	Command(CommandType type);

	CommandType getType();

private:
	CommandType _type;
};

