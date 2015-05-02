#pragma once

#include <GL/glew.h>

static class ShaderHandler
{
public:
	static GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
private:
	ShaderHandler();
	~ShaderHandler();
};

