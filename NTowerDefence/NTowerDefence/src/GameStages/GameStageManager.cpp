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
	actualStage->onClose();
	
	auto result = stagesContainer.find(stageId);

	if (result == stagesContainer.end())
		throw std::logic_error("There is no stage with ID " + stageId);

	actualStage = result->second;
}