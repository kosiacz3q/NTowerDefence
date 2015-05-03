#pragma once

#include "UpdateContext.hpp"
#include "DrawingContext.hpp"

class BaseGameObject
{
public:
	BaseGameObject();
	virtual ~BaseGameObject();

	virtual void draw(DrawingContextPtr drawingContext) = 0;
	virtual void update(UpdateContextPtr updateContext) = 0;
};

