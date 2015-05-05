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
		return gameContex;
	}

	void run();

private:

	GameContextPtr gameContex;
};

typedef std::shared_ptr<GameManager> GameManagerPtr;


