#pragma once

#include <memory>

class MouseHandler
{
public:
	MouseHandler();
	virtual ~MouseHandler();
};

typedef std::shared_ptr<MouseHandler> MouseHandlerPtr;