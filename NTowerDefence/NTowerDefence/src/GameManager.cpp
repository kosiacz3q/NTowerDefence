#include "GameManager.h"

#include <stdexcept>
#include <thread>

GameManager::GameManager()
{
	gameContext = GameContextPtr(new GameContext());
	gameContext->gameStageManager = GameStageManagerPtr(new GameStageManager());
	gameContext->shaderManager = ShaderManagerPtr(new ShaderManager());
	gameContext->windowHandler = WindowManagerPtr(new WindowManager());
	gameContext->textureManager = TextureManagerPtr(new TextureManager());
}

GameManager::~GameManager()
{

}

void GameManager::init()
{
	gameContext->windowHandler->init();
}

void GameManager::run()
{
	auto window = gameContext->windowHandler->getWindow();
	auto stageManager = gameContext->gameStageManager;

	do
	{
		stageManager->iterate();
		glfwPollEvents();
		
	} while (
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	if (gameContext->gameStageManager->getActiveStage() != nullptr)
		gameContext->gameStageManager->getActiveStage()->onClose();
}
