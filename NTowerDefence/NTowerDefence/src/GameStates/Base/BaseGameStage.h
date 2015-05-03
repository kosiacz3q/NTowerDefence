#pragma once

#include <memory>
#include <string>

class BaseGameStage
{
public:
	BaseGameStage();
	~BaseGameStage();

	virtual void init() = 0;
	
	virtual void begin() = 0;

	virtual void close() = 0;

	virtual bool isClosed() = 0;

	virtual std::string getId() = 0;
};

typedef std::shared_ptr<BaseGameStage> BaseGameStagePtr;