#pragma once

#include "MovableCamera.h"

MovableCamera::MovableCamera(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch) : 
	Front(glm::vec3(0.0f, 0.0f, -1.0f)), 
	MovementSpeed(SPEED), 
	MouseSensitivity(SENSITIVTY), 
	Zoom(ZOOM),
	Position(position),
	Yaw(yaw),
	Pitch(pitch)
{
	this->updateMovableCameraVectors();
}
    // Constructor with scalar values
MovableCamera::MovableCamera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ) 
	: Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVTY), Zoom(ZOOM)
{
    this->Position = glm::vec3(posX, posY, posZ);
    this->Up = glm::vec3(upX, upY, upZ);
    this->updateMovableCameraVectors();
}

    // Returns the view matrix calculated using Eular Angles and the LookAt Matrix
glm::mat4x4 MovableCamera::getViewMatrix()
{
    return glm::lookAt(
		this->Position, 
		this->Position + this->Front, 
		this->Up);
}

void MovableCamera::update(float elapsedTime)
{

}

// Processes input received from any keyboard-like input system. Accepts input parameter in the form of MovableCamera defined ENUM (to abstract it from windowing systems)
void MovableCamera::ProcessKeyboard(ACTIVE_INPUT direction, float deltaTime)
{
    GLfloat velocity = this->MovementSpeed * deltaTime;

    if (direction == FORWARD)
        this->Position += this->Front * velocity;

    if (direction == BACKWARD)
        this->Position -= this->Front * velocity;

    if (direction == LEFT)
        this->Position -= this->Right * velocity;

    if (direction == RIGHT)
        this->Position += this->Right * velocity;
}

// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void MovableCamera::ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch)
{
    xoffset *= this->MouseSensitivity;
    yoffset *= this->MouseSensitivity;

    this->Yaw   += xoffset;
    this->Pitch += yoffset;

    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (this->Pitch > 89.0f)
            this->Pitch = 89.0f;
        if (this->Pitch < -89.0f)
            this->Pitch = -89.0f;
    }

    // Update Front, Right and Up Vectors using the updated Eular angles
    this->updateMovableCameraVectors();
}

    // Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void MovableCamera::ProcessMouseScroll(GLfloat yoffset)
{
    if (this->Zoom >= 1.0f && this->Zoom <= 45.0f)
        this->Zoom -= yoffset;
    if (this->Zoom <= 1.0f)
        this->Zoom = 1.0f;
    if (this->Zoom >= 45.0f)
        this->Zoom = 45.0f;
}

void MovableCamera::ProcessMouseClick(int button, int action, int mods)
{

}

void MovableCamera::updateMovableCameraVectors()
{
    // Calculate the new Front vector
    //glm::vec3 front;
    //front.x = cos(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
   // front.y = sin(glm::radians(this->Pitch));
  //  front.z = sin(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
   // this->Front = glm::normalize(front);
    // Also re-calculate the Right and Up vector

    this->Up    = glm::normalize(glm::cross(this->Right, this->Front));
}

void MovableCamera::lookOnTarget(const glm::vec3& target)
{
	Front = target - Position;
	Up = glm::vec3(0, 0, 1);
}


void MovableCamera::setPosition(glm::vec3 cameraPos, const glm::vec3& direction, const glm::vec3& up)
{
	this->Position = glm::normalize(cameraPos);
	this->Front = direction;
	Up = up;

	//updateMovableCameraVectors();
}