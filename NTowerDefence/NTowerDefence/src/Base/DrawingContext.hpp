#pragma once

#include <memory>

#include <glm\ext.hpp>

struct DrawingContext
{
	glm::mat4 projection;
	glm::mat4 view;
};


typedef std::shared_ptr<DrawingContext> DrawingContextPtr;