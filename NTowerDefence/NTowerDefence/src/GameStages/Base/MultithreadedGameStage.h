#pragma once
#include "BaseGameStage.h"
#include "GameStageState.h"

#include <thread>

class MultithreadedGameStage :
	public BaseGameStage
{
public:
	MultithreadedGameStage();
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
};

