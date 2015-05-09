#include "TextureManager.h"

#include <stdexcept>

#include "soil\SOIL.h"

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}

void TextureManager::loadTexture(std::string id, std::string path)
{

	GLuint result = SOIL_load_OGL_texture(
		path.c_str(),
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

	if (result == 0)
		throw std::logic_error("Error while loading texture " + std::string(SOIL_last_result()));

	//GLuint result = loadDDS(path.c_str());

	//GLuint result = loadBMP_custom(path.c_str());
	textures.insert(PairIdTexture(id, TexturePtr(new Texture(result))));
}

TexturePtr TextureManager::getTexture(std::string id)
{
	auto result = textures.find(id);

	if (result == textures.end())
		throw std::logic_error("There is no texture with id " + id);

	return result->second;
}