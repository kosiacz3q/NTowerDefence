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

	glm::mat4x4 getViewMatrix();

	void setUpVector(const glm::vec3& up);

	void setPosition(glm::vec3 cameraPos, glm::vec3 target);

private:
	glm::vec3 up;
	glm::vec3 cameraPos;
	glm::vec3 direction;
};

typedef std::shared_ptr<StaticCamera> StaticCameraPtr;