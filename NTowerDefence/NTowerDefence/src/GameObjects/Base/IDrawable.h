#pragma once

#include <memory>

#include "DrawingContext.hpp"

class IDrawable
{
	virtual void draw(DrawingContextPtr drawingContext) = 0;
};

typedef std::shared_ptr<IDrawable> IDrawablePtr;