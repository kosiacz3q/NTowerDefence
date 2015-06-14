#pragma once

#include <GL\glew.h>

class IMouseScrollProcessor
{
	virtual void ProcessMouseScroll(GLfloat yoffset) = 0;
};

