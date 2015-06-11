#include "WindowManager.h"

#include <stdexcept>

WindowManager::WindowManager()
{

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

void WindowManager::initGLFW()
{
	if (!glfwInit())
	{
		throw std::logic_error("Failed to initialize GLFW\n");
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "NTowerDefence", NULL, NULL);

	if (window == NULL)
	{
		glfwTerminate();
		throw std::logic_error("Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.\n");
	}
	else
	{
		glfwMakeContextCurrent(window);
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