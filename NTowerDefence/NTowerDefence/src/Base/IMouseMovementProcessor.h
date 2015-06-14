#pragma once

#include <GL\glew.h>

class IMouseMovementProcessor
{
public:
	virtual void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch) = 0;
};