#pragma once

#include <memory>

struct UpdateContext
{
	float elapsedTime;
	float actualTimestamp;
};

typedef std::shared_ptr<UpdateContext> UpdateContextPtr;