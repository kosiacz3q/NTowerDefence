#pragma once

#include <memory>
#include <string>
#include <GameStages\Base\GameStageState.h>
#include <Base/DrawingContext.hpp>
#include <Base/BaseGameObject.h>
#include <Base/UpdateContext.hpp>
#include <Base/Registerer.h>

class BaseGameStage
	: public Registerer<BaseGameObjectPtr>
{
public:
	BaseGameStage();
	~BaseGameStage();

	virtual void initStage() final;

	virtual void drawStage() final;

	virtual void updateStage(UpdateContextPtr context);


	virtual void onBegin() = 0;

	virtual void onClose() = 0;

	virtual GameStageState getState() = 0;

	virtual std::string getId() = 0;


protected:
	DrawingContextPtr drawingContext;
	virtual void init() = 0;

	virtual void draw() = 0;

	virtual void update(UpdateContextPtr context) = 0;
private:
	
};

typedef std::shared_ptr<BaseGameStage> BaseGameStagePtr;