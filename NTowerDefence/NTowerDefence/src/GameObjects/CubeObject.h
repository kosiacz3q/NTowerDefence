#pragma once

#include <memory>

#include <GL\glew.h>

#include <Base\IShader.h>
#include <Base\BaseGameObject.h>

class CubeObject :
	public BaseGameObject
{
public:
	CubeObject(IShaderPtr shader);
	virtual ~CubeObject();

	void draw(DrawingContextPtr drawingContext);
	void update(UpdateContextPtr updateContext);
	void init();

private:
	GLuint vertexArrayId;
	GLuint vertexBufferId;
	GLuint colorBufferId;
	GLfloat* vertexBufferData;
	GLfloat* colorBufferData;
	GLuint matrixID;

	IShaderPtr shader;
};

typedef std::shared_ptr<CubeObject> CubeObjectPtr;

