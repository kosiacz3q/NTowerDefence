#pragma once

#include <memory>

#include "InputEnum.h"

class IKeyboardPocessor
{
public:
	virtual void ProcessKeyboard(ACTIVE_INPUT direction, float deltaTime) = 0;
};

typedef std::shared_ptr<IKeyboardPocessor> IKeyboardPocessorPtr;

