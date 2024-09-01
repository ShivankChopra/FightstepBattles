#include "Command.h"

Command::Command(CommandType type): _type(type)
{}

CommandType Command::getType()
{
	return _type;
}
