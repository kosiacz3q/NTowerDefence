#pragma once

#include <vector>
#include <memory>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Base\ICamera.h>
#include <Base\IKeyboardProcessor.h>
#include <Base\IMouseMovementProcessor.h>
#include <Base\IMouseScrollProcessor.h>

// Default MovableCamera values
const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 3.0f;
const GLfloat SENSITIVTY = 0.25f;
const GLfloat ZOOM = 45.0f;

// An abstract MovableCamera class that processes input and calculates the corresponding Eular Angles, Vectors and Matrices for use in OpenGL
class MovableCamera
	: public ICamera
	, public IKeyboardPocessor
	, public IMouseMovementProcessor
	, public IMouseScrollProcessor
{
public:
    // MovableCamera Attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    // Eular Angles
    GLfloat Yaw;
    GLfloat Pitch;
    // MovableCamera options
    GLfloat MovementSpeed;
    GLfloat MouseSensitivity;
    GLfloat Zoom;

    // Constructor with vectors
	MovableCamera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH);
	
	MovableCamera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch);

    // Returns the view matrix calculated using Eular Angles and the LookAt Matrix
	glm::mat4x4 getViewMatrix();

    // Processes input received from any keyboard-like input system. Accepts input parameter in the form of MovableCamera defined ENUM (to abstract it from windowing systems)
	void ProcessKeyboard(ACTIVE_INPUT direction, float deltaTime);

	void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true);
 
	void ProcessMouseScroll(GLfloat yoffset);

	void update(float elapsedTime);

private:
	void updateMovableCameraVectors();
};

typedef std::shared_ptr<MovableCamera> MovableCameraPtr;
