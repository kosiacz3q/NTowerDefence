#pragma once

#include <glm\glm.hpp>
#include <memory>

class Camera
{
public:
	Camera();
	virtual ~Camera();

	virtual void update(float elapsedTime) = 0;
	virtual glm::mat4x4 getViewMatrix() = 0;
};

typedef std::shared_ptr<Camera> CameraPtr;