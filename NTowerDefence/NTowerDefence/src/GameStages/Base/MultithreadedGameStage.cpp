#include "MultithreadedGameStage.h"


MultithreadedGameStage::MultithreadedGameStage(GameContextPtr gameContext)
{
	this->gameContext = gameContext;
}


MultithreadedGameStage::~MultithreadedGameStage()
{

}

void MultithreadedGameStage::onBegin()
{
	state = GameStageState::ACTIVE;

	drawThread = std::thread(&MultithreadedGameStage::drawWapper, this);
	updateThread = std::thread(&MultithreadedGameStage::updateWrapper, this);
}

void MultithreadedGameStage::onClose()
{
	state = GameStageState::CLOSING;

	drawThread.join();
	updateThread.join();
}

void MultithreadedGameStage::drawWapper()
{
	while (state == GameStageState::ACTIVE)
	{
		draw();

		glfwSwapBuffers(gameContext->window.get()); 
	}
}

void MultithreadedGameStage::updateWrapper()
{
	UpdateContextPtr updateContext = UpdateContextPtr(new UpdateContext());

	updateContext->elapsedTime = 100;

	while (state == GameStageState::ACTIVE)
	{
		update(updateContext);
	}
}

bool MultithreadedGameStage::isClosed()
{
	return state == GameStageState::READY;
}