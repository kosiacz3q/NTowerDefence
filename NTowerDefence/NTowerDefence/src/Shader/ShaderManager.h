#pragma once

#include <map>
#include <memory>

#include <GL\glew.h>

#include "Shader.h"

class ShaderManager
{
public:
	ShaderManager();
	~ShaderManager();
	
	void loadShader(const std::string& id, const std::string& vertexFilePath, const std::string& fragmentFilePath);

	ShaderPtr getShader(const std::string& id);

private:
	typedef std::map<std::string, ShaderPtr> ShadersContainer;
	typedef std::pair<std::string, ShaderPtr> PairIdShader;

	ShadersContainer shadersContainer;

	GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
};

typedef std::shared_ptr<ShaderManager> ShaderManagerPtr;