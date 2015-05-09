#pragma once

#include "Base\BaseGameStage.h"

#include "..\GameObjects\Base\UpdateContext.hpp"
#include "..\GameObjects\Base\DrawingContext.hpp"
#include "..\GameContext.h"

#include "..\GameObjects\Base\BaseGameObject.h"

class GameStageMap : public BaseGameStage
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

	inline GameStageState getState()
	{
		return state;
	}

private:	
	BaseGameObjectPtr triangle;
	BaseGameObjectPtr cube;
	BaseGameObjectPtr texturedCube;
	
	DrawingContextPtr drawingContext;
	UpdateContextPtr updateContext;

	typedef std::set<IDrawablePtr> DrawableContainer;
	DrawableContainer drawableContainer;

	GLFWwindow* window;

	GameContextPtr gameContext;

	const std::string id = "GAME_STAGE_MAP";

	GameStageState state;
};

