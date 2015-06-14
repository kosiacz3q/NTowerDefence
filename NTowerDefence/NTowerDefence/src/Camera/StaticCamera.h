#pragma once

#include <glm\glm.hpp>

#include <Base\ICamera.h>

class StaticCamera :
	public ICamera
{
public:
	StaticCamera();
	virtual ~StaticCamera();
	
	void update(float elapsedTime);

	glm::mat4x4 getViewMatrix()
	{
		return viewMatrix;
	}

	void setPosition(glm::vec3 cameraPos, glm::vec3 target);

private:
	glm::mat4 viewMatrix;
};

typedef std::shared_ptr<StaticCamera> StaticCameraPtr;