#include "TexturesLoader.h"

#include <stdexcept>

#include <SOIL\SOIL.h>

TexturesLoader::TexturesLoader()
{
}


TexturesLoader::~TexturesLoader()
{
}

TexturePtr TexturesLoader::loadTexture(std::string path)
{
	GLuint result = SOIL_load_OGL_texture(
		path.c_str(),
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

	if (result == 0)
		throw std::logic_error("Error while loading texture " + std::string(SOIL_last_result()));

	return TexturePtr(new Texture(result));
}