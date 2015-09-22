#pragma once

#include <memory>
#include <string>
#include <GameStages\Base\GameStageState.h>
#include <Base/DrawingContext.hpp>
#include <Base/BaseGameObject.h>
#include <Base/UpdateContext.hpp>
#include <Base/Registerer.h>
#include <GameStages\GUI\BaseGUIElement.h>

class BaseGameStage
	: protected Registerer<BaseGameObjectPtr>,
	protected Registerer<BaseGUIElementPtr>
{
public:
	BaseGameStage();
	~BaseGameStage();

	virtual void registerGameObject(std::string id, BaseGameObjectPtr baseGameObject) final;

	virtual void registerBaseGUIElement(std::string id, BaseGUIElementPtr baseGUIElement) final;

	virtual void initStage() final;

	virtual void drawStage() final;

	virtual void drawGUI(UpdateContextPtr context) final;

	virtual void updateStage(UpdateContextPtr context);


	virtual void onBegin() = 0;

	virtual void onClose() = 0;

	virtual GameStageState getState() = 0;

	virtual std::string getId() = 0;


protected:
	
	virtual void init() = 0;

	virtual void draw() = 0;

	virtual void update(UpdateContextPtr context) = 0;

	DrawingContextPtr drawingContext;	

private:
	
};

typedef std::shared_ptr<BaseGameStage> BaseGameStagePtr;