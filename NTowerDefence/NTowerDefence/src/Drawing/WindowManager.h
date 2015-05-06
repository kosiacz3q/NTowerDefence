#pragma once

#include <set>
#include <memory>
#include <thread>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "..\src\GameObjects\Base\IDrawable.h"

class WindowManager
{
public:
	WindowManager();
	virtual ~WindowManager();

	inline GLFWwindow* getWindow()
	{
		return window;
	}

	void init();

private:

	void initGLFW();
	void initGLEW();

	GLFWwindow* window;
	DrawingContextPtr drawingContext;

	bool running;
	bool isWindowManagerReady;
};

typedef std::shared_ptr<WindowManager> WindowManagerPtr;