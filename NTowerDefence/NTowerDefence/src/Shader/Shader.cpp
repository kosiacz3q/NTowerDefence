#include "Shader.h"

#include <glm/ext.hpp>

Shader::Shader(GLuint programId)
{
	this->programId = programId;
}

Shader::~Shader()
{
	glDeleteProgram(programId);
}

void Shader::setMVP(const glm::mat4& model, const glm::mat4& view, const glm::mat4& projection)
{
	glUniformMatrix4fv(glGetUniformLocation(programId, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(programId, "view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(glGetUniformLocation(programId, "model"), 1, GL_FALSE, glm::value_ptr(model));
}

