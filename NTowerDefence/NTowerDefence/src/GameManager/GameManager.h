#pragma once

#include <memory>

#include "GameContext.h"

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();
	void initWindow();

	inline GameContextPtr getGameContext()
	{
		return gameContex;
	}

	void run();

private:
	void initGLFW();
	void initGLEW();

	GameContextPtr gameContex;
};

typedef std::shared_ptr<GameManager> GameManagerPtr;


