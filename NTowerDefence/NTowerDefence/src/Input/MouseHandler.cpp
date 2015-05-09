#include "MouseHandler.h"

MouseHandler::MouseHandler(GLFWwindow* window)
	:window(window)
{
	mouseShift = MouseStatePtr(new MouseState());
}

MouseHandler::~MouseHandler()
{
}

void MouseHandler::update()
{
	glfwGetCursorPos(window, &mouseShift->actualPosition.x, &mouseShift->actualPosition.y);

	mouseShift->shift.x = mouseShift->actualPosition.x - lastMousePos.x;
	mouseShift->shift.y = mouseShift->actualPosition.y - lastMousePos.y;

	lastMousePos = mouseShift->actualPosition;
}

MouseStatePtr MouseHandler::getMouseState()
{
	return mouseShift;
}

void MouseHandler::moveToPosition(float x, float y)
{
	glfwSetCursorPos(window, x, y);
}

void MouseHandler::moveToCenter()
{
	int width;
	int height;
	glfwGetWindowSize(window, &width, &height);
	
	glfwSetCursorPos(window, width / 2, height / 2);
}