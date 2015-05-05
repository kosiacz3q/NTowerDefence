#pragma once

#include <memory>

#include "GameContext.h"

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	inline GameContextPtr getGameContext()
	{
		return gameContext;
	}

	void init();

	void run();

private:

	GameContextPtr gameContext;
};

typedef std::shared_ptr<GameManager> GameManagerPtr;


