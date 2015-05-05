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

	inline void registerDrawable(IDrawablePtr drawable)
	{
		drawableContainer.insert(drawable);
	}

	inline void unregisterDrawable(IDrawablePtr drawable)
	{
		auto result = drawableContainer.find(drawable);

		if (result != drawableContainer.end())
			drawableContainer.erase(result);
	}

	void run();

	void stop();

	inline DrawingContextPtr getDrawingContext()
	{
		return drawingContext;
	}

	inline GLFWwindow* getWindow()
	{
		return window;
	}

	inline bool isReady()
	{
		return isDrawingHandlerReady;
	}

private:
	
	void internalDrawing();

	void init();

	void initGLFW();
	void initGLEW();

	typedef std::set<IDrawablePtr> DrawableContainer;
	DrawableContainer drawableContainer;

	GLFWwindow* window;
	std::thread drawingThread;

	bool running;

	bool isDrawingHandlerReady;

	DrawingContextPtr drawingContext;
};

typedef std::shared_ptr<DrawingHandler> DrawingHandlerPtr;