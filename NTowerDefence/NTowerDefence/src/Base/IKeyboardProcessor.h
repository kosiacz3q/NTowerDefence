#pragma once

// Defines several possible options for MovableCamera movement. Used as abstraction to stay away from window-system specific input methods
enum ACTIVE_INPUT
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

class IKeyboardPocessor
{
public:
	virtual void ProcessKeyboard(ACTIVE_INPUT direction, float deltaTime) = 0;

};