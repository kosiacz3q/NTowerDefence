#include "StaticCamera.h"

#include <glm\ext.hpp>

StaticCamera::StaticCamera()
{

}

StaticCamera::~StaticCamera()
{

}

void StaticCamera::setPosition(glm::vec3 cameraPos, glm::vec3 direction)
{
	this->cameraPos = cameraPos;
	this->direction = direction;

	float horizontalAngle = 3.14f;

	// Right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f)
		);

	up = glm::cross(right, direction);
}

void StaticCamera::update(float elapsedTime)
{
	//nothing to do
}

glm::mat4x4 StaticCamera::getViewMatrix()
{
	return glm::lookAt(
		cameraPos,           // Camera is here
		cameraPos + direction, // and looks here : at the same position, plus "direction"
		up                  // Head is up (set to 0,-1,0 to look upside-down)
		);
}

void StaticCamera::setUpVector(const glm::vec3& up)
{
	this->up = up;
}
