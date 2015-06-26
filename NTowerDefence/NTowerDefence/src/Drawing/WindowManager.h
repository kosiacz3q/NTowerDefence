#pragma once

#include <set>
#include <map>
#include <memory>
#include <thread>


#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <Base\DrawingContext.hpp>

#include <Input\IKeyboardProcessor.h>
#include <Input\IMouseMovementProcessor.h>
#include <Input\IMouseScrollProcessor.h>
#include <Input\KeyBindingsHandler.h>

#include <Base\Registerer.h>

class WindowManager;
typedef std::shared_ptr<WindowManager> WindowManagerPtr;

class WindowManager
	: public Registerer<IKeyboardPocessorPtr>
	, public Registerer<IMouseMovementProcessorPtr>
	, public Registerer<IMouseScrollProcessorPtr>
{
public:

	WindowManager(KeyBindingsHandlerPtr keyBindingsHandler);
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

	//to jest slabe, mozna wyciagnac caly input handler jako statyczna klase
	//i jakis globalny inkrementator sluzacy do wyciagania okreslonego
	//managera po indeksie
	//ze wzgledu na slaba implementacje obslugi opengla z tymi wiesniackimi
	//wskaznikami do funkcji nie da sie inaczej (chyba)
	static WindowManagerPtr activeWindowManager;
	static KeyBindingsHandlerPtr keyBindingsHandler;
};

