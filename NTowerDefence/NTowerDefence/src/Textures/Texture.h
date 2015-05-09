#pragma once

#include <GL\glew.h>
#include <memory>

class Texture
{
public:
	Texture(GLuint id);
	~Texture();

	GLuint Id;
};

typedef std::shared_ptr<Texture> TexturePtr;