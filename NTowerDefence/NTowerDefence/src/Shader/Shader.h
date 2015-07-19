#pragma once

#include <memory>

#include <Base/AssetsManager/GenericSharedAssetsManager.h>
#include <Base\IShader.h>

#include <GL/glew.h>

#include <glm\glm.hpp>

class Shader
	: public IShader
{
public:
	Shader(GLuint programId);

	inline int getId()
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