#pragma once

#include <GL\glew.h>
#include <memory>

#include <Base/AssetsManager/GenericSharedAssetsManager.h>

class Texture
{
public:
	Texture(GLuint id);
	~Texture();

	GLuint Id;
};

typedef std::shared_ptr<Texture> TexturePtr;
typedef GenericSharedAssetsManager<TexturePtr> TextureManager;
typedef std::shared_ptr<TextureManager> TextureManagerPtr;