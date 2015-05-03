#pragma once

#include <GL\glew.h>

#include "Base\BaseGameObject.h"

class TriangleObject :
	public BaseGameObject
{
public:
	TriangleObject();
	virtual ~TriangleObject();

	void draw(DrawingContextPtr drawingContext);
	void update(UpdateContextPtr updateContext);

private:
	GLuint vertexArrayId;
	GLuint vertexBufferId;
};

