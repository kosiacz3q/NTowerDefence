#pragma once

#include <string>

#include "Texture.h"

class TexturesLoader
{
public:
	TexturesLoader();
	virtual ~TexturesLoader();

	TexturePtr loadTexture(std::string path);
};

