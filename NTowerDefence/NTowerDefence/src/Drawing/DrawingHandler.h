#pragma once

#include <set>
#include <memory>
#include <thread>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "..\src\GameObjects\Base\IDrawable.h"

class DrawingHandler
{
public:
	DrawingHandler();
	virtual ~DrawingHandler();

	inline GLFWwindow* getWindow()
	{
		return window;
	}

	void init();

private:

	void initGLFW();
	void initGLEW();

	

	GLFWwindow* window;
	std::thread drawingThread;

	bool running;

	bool isDrawingHandlerReady;

	DrawingContextPtr drawingContext;
};

typedef std::shared_ptr<DrawingHandler> DrawingHandlerPtr;