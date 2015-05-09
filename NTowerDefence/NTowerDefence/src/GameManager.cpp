#include "GameManager.h"

#include <stdexcept>
#include <thread>

GameManager::GameManager()
{
	gameContext = GameContextPtr(new GameContext());
	gameContext->gameStageManager = GameStageManagerPtr(new GameStageManager());
	gameContext->shaderManager = ShaderManagerPtr(new ShaderManager());
	gameContext->drawingHandler = WindowManagerPtr(new WindowManager());
	gameContext->textureManager = TextureManagerPtr(new TextureManager());
}

GameManager::~GameManager()
{

}

void GameManager::init()
{
	gameContext->drawingHandler->init();
}

void GameManager::run()
{
	auto window = gameContext->drawingHandler->getWindow();
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
