#pragma once

// Std. Includes
#include <vector>

// GL Includes#include <gl\GLU.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Base\ICamera.h>
#include <Base\IKeyboardProcessor.h>
#include <Base\IMouseMovementProcessor.h>
#include <Base\IMouseScrollProcessor.h>

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
	MovableCamera(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch);
	MovableCamera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch);

    // Returns the view matrix calculated using Eular Angles and the LookAt Matrix
	glm::mat4 GetViewMatrix();

    // Processes input received from any keyboard-like input system. Accepts input parameter in the form of MovableCamera defined ENUM (to abstract it from windowing systems)
	void ProcessKeyboard(ACTIVE_INPUT direction, float deltaTime);

	void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch);
 
	void ProcessMouseScroll(GLfloat yoffset);

private:
	void updateMovableCameraVectors();
};
