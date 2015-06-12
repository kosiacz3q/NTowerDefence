#pragma once

#include <memory>

#include "UpdateContext.hpp"

class IUpdateable
{
public:
	virtual void update(UpdateContextPtr updateContext) = 0;
};

typedef std::shared_ptr<IUpdateable> IUpdateablePtr;