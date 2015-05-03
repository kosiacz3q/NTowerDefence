#pragma once

#include "..\src\GameManager\GameContext.h"

#include "BaseGameStage.h"
#include "GameStageState.h"

#include <thread>

class MultithreadedGameStage :
	public BaseGameStage
{
public:
	MultithreadedGameStage(GameContextPtr gameContext);
	virtual ~MultithreadedGameStage();

	void onBegin();
	void onClose();
	bool isClosed();

	
protected:
	typedef MultithreadedGameStage Inherited;
	GameContextPtr gameContext;

private:
	void drawWapper();
	void updateWrapper();

	std::thread drawThread;
	std::thread updateThread;

	GameStageState state;
};

