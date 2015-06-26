#pragma once

#include <map>
#include <memory>


#include "InputEnum.h"

class KeyBindingsHandler
{
public:
	KeyBindingsHandler();
	~KeyBindingsHandler();

	void setBinding(int code, ACTIVE_INPUT input);

	void setBinding(std::initializer_list<std::pair<int, ACTIVE_INPUT> > inputList);

	ACTIVE_INPUT getBinding(int code);

	void unbindAll();

private:

	typedef std::map<int, ACTIVE_INPUT> BindingsMap;

	BindingsMap bindings;
};


typedef std::shared_ptr<KeyBindingsHandler> KeyBindingsHandlerPtr;

