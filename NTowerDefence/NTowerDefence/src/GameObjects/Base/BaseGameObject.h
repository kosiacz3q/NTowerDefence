#pragma once

#include "IDrawable.h"
#include "IUpdateable.h"

class BaseGameObject : public IDrawable, public IUpdateable
{
public:
	BaseGameObject();
	virtual ~BaseGameObject();
};

