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

	void init();

	void registerStage(BaseGameStagePtr gameStage);

	void setStage(std::string stageId);

	inline BaseGameStagePtr getActiveStage()
	{
		return actualStage;
	}

private:
	typedef std::map<std::string, BaseGameStagePtr> StagesContainer;
	typedef std::pair<std::string, BaseGameStagePtr> PairIdStage;

	StagesContainer stagesContainer;

	BaseGameStagePtr actualStage;
};

typedef std::shared_ptr<GameStageManager> GameStageManagerPtr;