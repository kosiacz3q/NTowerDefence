#pragma once

#include <memory>

#include <GL/glew.h>

#include "..\Base\GenericManager.h"

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
typedef GenericManager<ShaderPtr> ShaderManager;
typedef std::shared_ptr<ShaderManager> ShaderManagerPtr;