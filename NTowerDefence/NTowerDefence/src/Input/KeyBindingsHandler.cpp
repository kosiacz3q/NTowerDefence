#include "KeyBindingsHandler.h"



KeyBindingsHandler::KeyBindingsHandler()
{
	bindings = BindingsMap();
}


KeyBindingsHandler::~KeyBindingsHandler()
{
}


void KeyBindingsHandler::setBinding(int code, ACTIVE_INPUT input)
{
	auto result = bindings.find(code);

	if (result != bindings.end())
	{
		result->second = input;
	}
	else
	{
		bindings.insert(std::make_pair(code, input));
	}
}

ACTIVE_INPUT KeyBindingsHandler::getBinding(int code)
{
	auto result = bindings.find(code);

	if (result != bindings.end())
		return result->second;

	return ACTIVE_INPUT::NOT_BINDED;
}

void KeyBindingsHandler::unbindAll()
{
	bindings.clear();
}

void KeyBindingsHandler::setBinding(std::initializer_list<std::pair<int, ACTIVE_INPUT> > inputList)
{
	for each (auto binding in inputList)
	{
		bindings.insert(binding);
	}
}