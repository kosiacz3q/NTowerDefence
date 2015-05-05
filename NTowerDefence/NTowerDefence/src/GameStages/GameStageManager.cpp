#include "GameStageManager.h"

GameStageManager::GameStageManager()
{
	stagesContainer = StagesContainer();
	actualStage = nullptr;
	isChangeRequested = false;

	updateContext = UpdateContextPtr(new UpdateContext());
	updateContext->elapsedTime = 100;
}

GameStageManager::~GameStageManager()
{

}

void GameStageManager::registerStage(BaseGameStagePtr gameStage)
{
	gameStage->init();

	stagesContainer.insert(PairIdStage(gameStage->getId(), gameStage));
}

void GameStageManager::requestStageSet(std::string stageId)
{
	if (actualStage)
	{
		isChangeRequested = true;
		requestedStageId = stageId;
	}
	else
	{
		requestedStageId = stageId;
		setStage();
	}
}

void GameStageManager::iterate()
{
	actualStage->update(updateContext);

	actualStage->draw();

	if (isChangeRequested)
	{
		setStage();
	}
}

void GameStageManager::setStage()
{
	if (actualStage)
		actualStage->onClose();

	auto result = stagesContainer.find(requestedStageId);

	if (result == stagesContainer.end())
		throw std::logic_error("There is no stage with ID " + requestedStageId);

	actualStage = result->second;
	actualStage->onBegin();
}