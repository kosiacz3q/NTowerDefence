#pragma once

#include <GL\glew.h>


#include <Base\BaseGameObject.h>
#include <Base\IShader.h>


class TriangleObject :
	public BaseGameObject
{
public:
	TriangleObject(IShaderPtr shader);
	virtual ~TriangleObject();

	void draw(DrawingContextPtr drawingContext);
	void update(UpdateContextPtr updateContext);
	void init();

private:
	GLuint vertexArrayId;
	GLuint vertexBufferId;
	GLfloat* vertexBufferData;
	GLuint matrixID;
	IShaderPtr shader;
};

