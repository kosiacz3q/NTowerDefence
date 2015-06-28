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
		modelMatrix = glm::scale(glm::mat4(1), modelScale);
		modelMatrix = glm::translate(modelMatrix,destination);
	}

	void scale(const glm::vec3& scaleVector)
	{
		modelScale = scaleVector;

		modelMatrix = glm::scale(modelMatrix, modelScale);
	}

protected:

	glm::vec3 modelScale;

	glm::mat4 modelMatrix;
};

typedef std::shared_ptr<BaseGameObject> BaseGameObjectPtr;
