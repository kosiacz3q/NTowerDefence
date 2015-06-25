#pragma once

#include <memory>
#include <Base\GenericAssetsManager.h>

#include <GL/glew.h>

#include <glm\glm.hpp>

class Shader
{
public:
	Shader(GLuint programId);

	inline GLuint getId()
	{
		return programId;
	}

	void setMVP(const glm::mat4& model, const glm::mat4& view, const glm::mat4& projection);
	
	inline void activate()
	{
		glUseProgram(programId);
	}

	virtual ~Shader();

private:
	GLuint programId;
};

typedef std::shared_ptr<Shader> ShaderPtr;
typedef GenericAssetsManager<ShaderPtr> ShaderManager;
typedef std::shared_ptr<ShaderManager> ShaderManagerPtr;