#pragma once

#include <memory>

#include <GL\glew.h>

#include "Base\BaseGameObject.h"

class CubeObject :
	public BaseGameObject
{
public:
	CubeObject();
	virtual ~CubeObject();

	void draw(DrawingContextPtr drawingContext);
	void update(UpdateContextPtr updateContext);

private:

	GLfloat* g_vertex_buffer_data;
};

typedef std::shared_ptr<CubeObject> CubeObjectPtr;

