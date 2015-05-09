#pragma once

#include <string>
#include <map>
#include <memory>

#include "GL\glew.h"

class TextureManager
{
public:
	TextureManager();
	virtual ~TextureManager();

	void loadTexture(std::string id, std::string path);
	GLuint getTexture(std::string id);

private:
	typedef std::map<std::string,GLuint> ContainerIdTexture;
	typedef std::pair<std::string, GLuint> PairIdTexture;

	ContainerIdTexture textures;
};

typedef std::shared_ptr<TextureManager> TextureManagerPtr;