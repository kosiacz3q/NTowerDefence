#pragma once

#include <GL\glew.h>

#include "..\Shader\Shader.h"

#include "Base\BaseGameObject.h"

class TriangleObject :
	public BaseGameObject
{
public:
	TriangleObject(ShaderPtr shader);
	virtual ~TriangleObject();

	void draw(DrawingContextPtr drawingContext);
	void update(UpdateContextPtr updateContext);
	void init();

private:
	GLuint vertexArrayId;
	GLuint vertexBufferId;
	GLfloat* vertexBufferData;
	GLuint matrixID;
	ShaderPtr shader;
};

