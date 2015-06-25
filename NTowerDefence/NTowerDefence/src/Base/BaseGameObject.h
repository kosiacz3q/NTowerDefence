#pragma once

#include "IDrawable.h"
#include "IUpdateable.h"

class BaseGameObject : 
	public IDrawable, 
	public IUpdateable
{
public:
	BaseGameObject();
	virtual ~BaseGameObject();
	virtual void init() = 0;

	void rotate(const float& angle, const glm::vec3& axis)
	{
		modelMatrix = glm::rotate(modelMatrix, angle, axis);
	}

	void tranlate(const glm::vec3& translationVector)
	{
		modelMatrix = glm::translate(modelMatrix, translationVector);
	}

	void translateTo(const glm::vec3& destination)
	{
		modelMatrix = glm::translate(destination);
	}

	void scale(const glm::vec3& scaleVector)
	{
		modelMatrix = glm::scale(modelMatrix, scaleVector);
	}

protected:

	glm::mat4 modelMatrix;
};

typedef std::shared_ptr<BaseGameObject> BaseGameObjectPtr;
