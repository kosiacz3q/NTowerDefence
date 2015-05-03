#pragma once

#include <memory>

#include <GL/glew.h>

class Shader
{
public:
	Shader(GLuint programId);

	inline GLuint getId()
	{
		return programId;
	}

	virtual ~Shader();

private:
	GLuint programId;
};

typedef std::shared_ptr<Shader> ShaderPtr;