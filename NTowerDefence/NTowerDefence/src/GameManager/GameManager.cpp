#include "GameManager.h"

#include <stdexcept>
#include <thread>

GameManager::GameManager()
{
	gameContex = GameContextPtr(new GameContext());
}

GameManager::~GameManager()
{

}

void GameManager::run()
{
	gameContex->drawingHandler->run();

	while (!gameContex->drawingHandler->isReady())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	auto window = gameContex->drawingHandler->getWindow();

	do
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		glfwPollEvents();
	} while (
		glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	if (gameContex->gameStageManager->getActiveStage() != nullptr)
		gameContex->gameStageManager->getActiveStage()->onClose();

	gameContex->drawingHandler->stop();
}
