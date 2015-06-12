#pragma once

#include <memory>
#include <string>

#include "GameStageState.h"

#include <Base/UpdateContext.hpp>

class BaseGameStage
{
public:
	BaseGameStage();
	~BaseGameStage();

	virtual void init() = 0;
	
	virtual void onBegin() = 0;

	virtual void draw() = 0;

	virtual void update(UpdateContextPtr context) = 0;

	virtual void onClose() = 0;

	virtual GameStageState getState() = 0;

	virtual std::string getId() = 0;
};

typedef std::shared_ptr<BaseGameStage> BaseGameStagePtr;