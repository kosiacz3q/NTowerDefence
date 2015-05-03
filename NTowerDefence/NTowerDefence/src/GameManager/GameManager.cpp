#include "GameManager.h"

#include <stdexcept>
#include <thread>

GameManager::GameManager()
{

}

GameManager::~GameManager()
{
	glfwTerminate();
}

void GameManager::initWindow()
{
	initGLFW();
	initGLEW();
}

void GameManager::initGLFW()
{
	if (!glfwInit())
	{
		throw std::logic_error("Failed to initialize GLFW\n");
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	gameContex->window = GLFWwindowPtr(glfwCreateWindow(1024, 768, "NTowerDefence", NULL, NULL));

	if (gameContex->window == NULL)
	{
		glfwTerminate();
		throw std::logic_error("Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.\n");
	}

	glfwMakeContextCurrent(gameContex->window.get());
}

void GameManager::initGLEW()
{
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		throw std::logic_error("Failed to initialize GLEW\n");
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(gameContex->window.get(), GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
}

void GameManager::run()
{
	do
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));

	} while (
		glfwGetKey(gameContex->window.get(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(gameContex->window.get()) == 0);

	gameContex->gameStageManager->getActiveStage()->onClose();
}