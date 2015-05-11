#pragma once

#include <GL\glew.h>
#include <memory>

#include "..\Base\GenericAssetsManager.h"

class Texture
{
public:
	Texture(GLuint id);
	~Texture();

	GLuint Id;
};

typedef std::shared_ptr<Texture> TexturePtr;
typedef GenericAssetsManager<TexturePtr> TextureManager;
typedef std::shared_ptr<TextureManager> TextureManagerPtr;