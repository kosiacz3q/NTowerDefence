#pragma once

#include <string>
#include <gl\glew.h>

#include "Shader.h"

class ShaderLoader
{
public:
	ShaderLoader();
	virtual ~ShaderLoader();

	ShaderPtr LoadShaderFromFile(const std::string& vertexFilePath, const std::string& fragmentFilePath);
};

