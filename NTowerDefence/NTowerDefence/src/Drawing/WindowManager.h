#pragma once

#include <set>
#include <map>
#include <memory>
#include <thread>


#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <Base\DrawingContext.hpp>

#include <Base\IKeyboardProcessor.h>
#include <Base\IMouseMovementProcessor.h>
#include <Base\IMouseScrollProcessor.h>

#include <Base\Registerer.h>

class WindowManager;
typedef std::shared_ptr<WindowManager> WindowManagerPtr;

class WindowManager
	: public Registerer<IKeyboardPocessorPtr>
	, public Registerer<IMouseMovementProcessorPtr>
	, public Registerer<IMouseScrollProcessorPtr>
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

	void setGlStates();

	GLFWwindow* window;
	DrawingContextPtr drawingContext;

	bool running;
	bool isWindowManagerReady;

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

	static WindowManagerPtr activeWindowManager;
};

