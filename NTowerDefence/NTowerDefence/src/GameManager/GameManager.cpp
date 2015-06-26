#include "GameManager.h"

#include <stdexcept>
#include <thread>

GameManager::GameManager()
{
	gameContext = GameContextPtr(new GameContext());
	gameContext->gameStageManager = GameStageManagerPtr(new GameStageManager());
	gameContext->shaderManager = ShaderManagerPtr(new ShaderManager());

	gameContext->keyBindingsHandler = KeyBindingsHandlerPtr(new KeyBindingsHandler());

	gameContext->windowHandler = WindowManagerPtr(new WindowManager(gameContext->keyBindingsHandler));

	gameContext->keyboardRegisterer = gameContext->windowHandler;
	gameContext->mouseMovementRegisterer = gameContext->windowHandler;
	gameContext->mouseScrollRegisterer = gameContext->windowHandler;

	gameContext->textureManager = TextureManagerPtr(new TextureManager());
	gameContext->modelManager = ModelManagerPtr(new ModelManager());
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
		glfwPollEvents();
		stageManager->iterate();
	} while 
	(
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0
	);

	if (gameContext->gameStageManager->getActiveStage())
	{
		gameContext->gameStageManager->getActiveStage()->onClose();
	}
}
