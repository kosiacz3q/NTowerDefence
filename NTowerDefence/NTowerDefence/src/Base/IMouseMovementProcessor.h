#pragma once

#include <memory>

#include <GL\glew.h>

class IMouseMovementProcessor
{
public:
	virtual void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true) = 0;
};

typedef std::shared_ptr<IMouseMovementProcessor> IMouseMovementProcessorPtr;