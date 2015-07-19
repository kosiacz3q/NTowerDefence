#pragma once

#include "Base\BaseGameStage.h"
#include <Base\UpdateContext.hpp>
#include <Base\DrawingContext.hpp>
#include <Base\BaseGameObject.h>

#include <GameManager\GameContext.h>


//#include <Camera\StaticCamera.h>
#include <Camera\MovableCamera.h>
#include <Camera\StaticCamera.h>

#include <Models\ModelContainer.h>

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

	StaticCameraPtr staticCamera;
	MovableCameraPtr movableCamera;

	typedef std::set<IDrawablePtr> DrawableContainer;
	DrawableContainer drawableContainer;

	GLFWwindow* window;

	GameContextPtr gameContext;

	const std::string id = "GAME_STAGE_MAP";

	BaseGameObjectPtr model1;
	BaseGameObjectPtr model2;

	GameStageState state;
};

