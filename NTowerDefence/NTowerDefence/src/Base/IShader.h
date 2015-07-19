#pragma once


#include <memory>
#include <glm\glm.hpp>

#include <Base/AssetsManager/GenericSharedAssetsManager.h>

class IShader
{
public:

	virtual void activate() = 0;
	virtual int getId() = 0;

	virtual void setMVP(const glm::mat4& model, const glm::mat4& view, const glm::mat4& projection) = 0;
};

typedef std::shared_ptr<IShader> IShaderPtr;
typedef GenericSharedAssetsManager<IShaderPtr> ShaderManager;
typedef std::shared_ptr<ShaderManager> ShaderManagerPtr;