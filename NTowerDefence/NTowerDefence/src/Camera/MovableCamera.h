#pragma once

#include <vector>
#include <memory>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Base\ICamera.h>

#include <Input\IKeyboardProcessor.h>
#include <Input\IMouseMovementProcessor.h>
#include <Input\IMouseScrollProcessor.h>
#include <Input\IMouseClickProcessor.h>

// Default MovableCamera values
const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 0.2f;
const GLfloat SENSITIVTY = 0.05f;
const GLfloat ZOOM = 45.0f;

// An abstract MovableCamera class that processes input and calculates the corresponding Eular Angles, Vectors and Matrices for use in OpenGL
class MovableCamera
	: public ICamera
	, public IKeyboardPocessor
	, public IMouseMovementProcessor
	, public IMouseScrollProcessor
	, public IMouseClickProcessor
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
	
	MovableCamera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ);

    // Returns the view matrix calculated using Eular Angles and the LookAt Matrix
	glm::mat4x4 getViewMatrix();

    // Processes input received from any keyboard-like input system. Accepts input parameter in the form of MovableCamera defined ENUM (to abstract it from windowing systems)
	void ProcessKeyboard(ACTIVE_INPUT direction, float deltaTime);

	void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true);
 
	void ProcessMouseScroll(GLfloat yoffset);

	void ProcessMouseClick(int button, int action, int mods);

	void update(float elapsedTime);

	void lookOnTarget(const glm::vec3& target);

	void setPosition(glm::vec3 cameraPos, const glm::vec3& target, const glm::vec3& up);

private:
	void updateMovableCameraVectors();
};

typedef std::shared_ptr<MovableCamera> MovableCameraPtr;
