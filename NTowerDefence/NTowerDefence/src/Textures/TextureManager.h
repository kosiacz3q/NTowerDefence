#pragma once

#include <string>
#include <map>
#include <memory>
#include <GL\glew.h>

#include "Texture.h"

class TextureManager
{
public:
	TextureManager();
	virtual ~TextureManager();

	void loadTexture(std::string id, std::string path);
	TexturePtr getTexture(std::string id);

private:
	typedef std::map<std::string, TexturePtr> ContainerIdTexture;
	typedef std::pair<std::string, TexturePtr> PairIdTexture;

	ContainerIdTexture textures;
};

typedef std::shared_ptr<TextureManager> TextureManagerPtr;