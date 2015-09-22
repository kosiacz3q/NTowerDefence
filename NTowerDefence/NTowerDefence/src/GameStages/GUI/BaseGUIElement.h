#pragma once

#include "Base\IDrawable.h"
#include "Base\IUpdateable.h"

class BaseGUIElement : 
	public IDrawable, 
	public IUpdateable
{
public:
	virtual void execute() = 0;

protected:
	bool clickable;
};

typedef std::shared_ptr<BaseGUIElement> BaseGUIElementPtr;