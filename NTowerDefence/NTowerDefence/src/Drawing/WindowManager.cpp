#include "WindowManager.h"

#include <stdexcept>
#include <cstdio>


WindowManagerPtr WindowManager::activeWindowManager = nullptr;
KeyBindingsHandlerPtr WindowManager::keyBindingsHandler = nullptr;

WindowManager::WindowManager(KeyBindingsHandlerPtr keyBindingsHandler)
{
	activeWindowManager = WindowManagerPtr(this);
	WindowManager::keyBindingsHandler = keyBindingsHandler;
}

WindowManager::~WindowManager()
{
	glfwTerminate();
}

void WindowManager::init()
{
	initGLFW();
	initGLEW();
	setGlStates();
}

void initializerCallback(int a, const char * description)
{
	throw std::logic_error(std::string(description));
}

void WindowManager::initGLFW()
{
	glfwSetErrorCallback(initializerCallback);

	if (!glfwInit())
	{
		throw std::logic_error("Failed to initialize GLFW\n");
	}

	glfwSetErrorCallback(nullptr);

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "NTowerDefence", NULL, NULL);

	if (window == NULL)
	{
		glfwTerminate();
		throw std::logic_error("Failed to open GLFW window. If you have an Intel GPU, they are not compatible.\n");
	}
	else
	{
		glfwMakeContextCurrent(window);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

		glfwSetKeyCallback(window, WindowManager::key_callback);
		glfwSetCursorPosCallback(window, WindowManager::mouse_callback);
		glfwSetScrollCallback(window, WindowManager::scroll_callback);
	}
}

void WindowManager::initGLEW()
{
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		throw std::logic_error("Failed to initialize GLEW\n");
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
}

void WindowManager::setGlStates()
{
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
	//glEnable(GL_TEXTURE_2D);

	//glDisable(GL_LIGHTING);
}


void WindowManager::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	auto container = ((Registerer<IKeyboardPocessorPtr>)*activeWindowManager).getContainer();

	for (auto obj : *container)
	{
		obj.second->ProcessKeyboard(keyBindingsHandler->getBinding(key), 1);
	}	
}

bool firstMouse = true;
GLfloat lastX = 400, lastY = 300;

void WindowManager::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	GLfloat xoffset = xpos - lastX;
	GLfloat yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	auto container = ((Registerer<IMouseMovementProcessorPtr>)*activeWindowManager).getContainer();

	for (auto obj : *container)
	{
		obj.second->ProcessMouseMovement(xoffset, yoffset);
	}
}

void WindowManager::mouse_click_callback(GLFWwindow * window, int button, int action, int mods)
{
	auto container = ((Registerer<IMouseClickProcessorPtr>)*activeWindowManager).getContainer();

	for (auto obj : *container)
	{
		obj.second->ProcessMouseClick(button, action, mods);
	}	
	printf("Click");
}

void WindowManager::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	//camera.ProcessMouseScroll(yoffset);
}