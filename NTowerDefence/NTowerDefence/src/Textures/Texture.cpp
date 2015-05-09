#include "Texture.h"


Texture::Texture(GLuint id)
	:Id(id)
{
}


Texture::~Texture()
{
	glDeleteTextures(1 ,&Id);
}
