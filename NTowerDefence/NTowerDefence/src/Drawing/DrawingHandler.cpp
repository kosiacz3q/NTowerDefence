#include "DrawingHandler.h"

#include <stdexcept>

DrawingHandler::DrawingHandler()
{

}

DrawingHandler::~DrawingHandler()
{
	glfwTerminate();
}

void DrawingHandler::init()
{
	initGLFW();
	initGLEW();
}

void DrawingHandler::initGLFW()
{
	if (!glfwInit())
	{
		throw std::logic_error("Failed to initialize GLFW\n");
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "NTowerDefence", NULL, NULL);

	if (window == nullptr)
	{
		glfwTerminate();
		throw std::logic_error("Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.\n");
	}

	glfwMakeContextCurrent(window);
}

void DrawingHandler::initGLEW()
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