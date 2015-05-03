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

	void drawWapper();
	void updateWrapper();
protected:
	typedef MultithreadedGameStage Inherited;

private:
	std::thread drawThread;
	std::thread updateThread;

	GameStageState state;
	GameContextPtr gameContext;
};

