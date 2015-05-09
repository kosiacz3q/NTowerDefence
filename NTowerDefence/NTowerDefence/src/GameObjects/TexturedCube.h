#pragma once

#include "Base\BaseGameObject.h"

#include "..\Shader\Shader.h"
#include "..\Textures\Texture.h"

class TexturedCube :
	public BaseGameObject
{
public:
	TexturedCube(ShaderPtr shader, TexturePtr texture);
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

	ShaderPtr shader;
	TexturePtr texture;
};

