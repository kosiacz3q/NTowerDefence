#include "MultithreadedGameStage.h"


MultithreadedGameStage::MultithreadedGameStage()
{

}


MultithreadedGameStage::~MultithreadedGameStage()
{

}

void MultithreadedGameStage::onBegin()
{
	drawThread = std::thread(&MultithreadedGameStage::drawWapper, *this);
	updateThread = std::thread(&MultithreadedGameStage::updateWrapper, *this);
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

	}
}

void MultithreadedGameStage::updateWrapper()
{
	while (state == GameStageState::ACTIVE)
	{

	}
}

bool MultithreadedGameStage::isClosed()
{
	return state == GameStageState::READY;
}