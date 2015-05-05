#pragma once

#include "Base\BaseGameStage.h"

#include <memory>
#include <string>
#include <map>

class GameStageManager
{
public:
	GameStageManager();
	virtual ~GameStageManager();

	void registerStage(BaseGameStagePtr gameStage);

	void requestStageSet(std::string stageId);

	inline BaseGameStagePtr getActiveStage()
	{
		return actualStage;
	}

	void iterate();

private:
	typedef std::map<std::string, BaseGameStagePtr> StagesContainer;
	typedef std::pair<std::string, BaseGameStagePtr> PairIdStage;

	StagesContainer stagesContainer;

	BaseGameStagePtr actualStage;

	bool isChangeRequested;

	UpdateContextPtr updateContext;

	std::string requestedStageId;

	void setStage();
};

typedef std::shared_ptr<GameStageManager> GameStageManagerPtr;