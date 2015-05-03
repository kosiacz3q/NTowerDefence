#pragma once

#include <glm\ext.hpp>

#include "Base\MultithreadedGameStage.h"

class GameStageMap : public MultithreadedGameStage
{
public:
	GameStageMap();
	virtual ~GameStageMap();

	void init();

	void onBegin();
	void onClose();

	void draw();
	void update();

	inline std::string getId()
	{
		return id;
	}

private:
	

	glm::mat4 projection;
	glm::mat4 view;
	glm::mat4 model;
	glm::mat4 MVP;
	GameStageState state;

	const std::string id = "GAME_STAGE_MAP";
};

