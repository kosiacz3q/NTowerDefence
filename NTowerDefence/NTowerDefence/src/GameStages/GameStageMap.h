#pragma once

#include "Base\MultithreadedGameStage.h"

#include "..\src\GameObjects\Base\UpdateContext.hpp"
#include "..\src\GameObjects\Base\DrawingContext.hpp"

#include "..\GameObjects\TriangleObject.h"

class GameStageMap : public MultithreadedGameStage
{
public:
	GameStageMap(GameContextPtr gameContext);
	virtual ~GameStageMap();

	void init();

	void onBegin();

	void draw();

	void update(UpdateContextPtr context);

	void onClose();

	inline std::string getId()
	{
		return id;
	}

private:	
	GameStageState state;

	BaseGameObjectPtr triangle;
	
	DrawingContextPtr drawingContext;
	UpdateContextPtr updateContext;

	const std::string id = "GAME_STAGE_MAP";
};

