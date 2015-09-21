#pragma once

#include <memory>

class IMouseClickProcessor
{
public:
	virtual void ProcessMouseClick(int button, int action, int mods) = 0;
};

typedef std::shared_ptr<IMouseClickProcessor> IMouseClickProcessorPtr;