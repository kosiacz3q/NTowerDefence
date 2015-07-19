#pragma once

#include "Base\BaseGameObject.h"

#include <Base\IShader.h>
#include <Textures\Texture.h>

class TexturedCube :
	public BaseGameObject
{
public:
	TexturedCube(IShaderPtr shader, TexturePtr texture);
	virtual ~TexturedCube();

	void draw(DrawingContextPtr drawingContext);
	void update(UpdateContextPtr updateContext);
	void init();

private:
	GLuint vertexArrayId;
	GLuint vertexBufferId;

	GLfloat* vertexBufferData;
	GLfloat* uvBufferData;

	GLuint matrixID;
	GLuint textureSamplerId;
	GLuint uvBufferId;

	IShaderPtr shader;
	TexturePtr texture;
};

