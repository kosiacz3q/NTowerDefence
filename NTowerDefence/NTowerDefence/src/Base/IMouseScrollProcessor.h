#pragma once

#include <memory>

#include <GL\glew.h>

class IMouseScrollProcessor
{
	virtual void ProcessMouseScroll(GLfloat yoffset) = 0;
};

typedef std::shared_ptr<IMouseScrollProcessor> IMouseScrollProcessorPtr;