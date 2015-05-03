#include "GameStageManager.h"

GameStageManager::GameStageManager()
{
	stagesContainer = StagesContainer();
}

GameStageManager::~GameStageManager()
{

}

void GameStageManager::init()
{

}

void GameStageManager::registerStage(BaseGameStagePtr gameStage)
{
	stagesContainer.insert(PairIdStage(gameStage->getId(), gameStage));
}

void GameStageManager::setStage(std::string stageId)
{
	actualStage->close();

	while (!actualStage->isClosed());
}