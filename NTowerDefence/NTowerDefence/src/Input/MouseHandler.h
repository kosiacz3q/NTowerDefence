#pragma once

#include <memory>
#include <GLFW\glfw3.h>

struct MouseState
{
	struct Shift
	{
		double x;
		double y;
		int scroll;
	} shift;

	struct ActualPosition
	{
		double x;
		double y;
	} actualPosition;

	bool LeftButtonClicked;
	bool RightButtonClicked;
};

typedef std::shared_ptr<MouseState> MouseStatePtr;

class MouseHandler
{
public:
	MouseHandler(GLFWwindow* window);
	virtual ~MouseHandler();

	void update();
	void moveToPosition(float x, float y);
	void moveToCenter();

	MouseStatePtr getMouseState();

private:

	MouseState::ActualPosition lastMousePos;

	MouseStatePtr mouseShift;
	GLFWwindow* window;
};

typedef std::shared_ptr<MouseHandler> MouseHandlerPtr;