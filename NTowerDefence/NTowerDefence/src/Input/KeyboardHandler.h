#pragma once

#include <memory>

class KeyboardHandler
{
public:
	KeyboardHandler();
	virtual ~KeyboardHandler();
};

typedef std::shared_ptr<KeyboardHandler> KeyboardHandlerPtr;