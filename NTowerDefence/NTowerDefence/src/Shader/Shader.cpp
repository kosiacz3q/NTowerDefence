#include "Shader.h"


Shader::Shader(GLuint programId)
{
	this->programId = programId;
}

Shader::~Shader()
{
	glDeleteProgram(programId);
}
