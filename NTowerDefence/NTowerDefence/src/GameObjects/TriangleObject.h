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

private:
	GLuint vertexArrayId;
	GLuint vertexBufferId;
	GLfloat* gVertexBufferData;
	GLuint matrixID;
	ShaderPtr shader;
};

