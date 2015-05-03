#include "TriangleObject.h"


TriangleObject::TriangleObject()
{
	glGenVertexArrays(1, &vertexArrayId);
	glBindVertexArray(vertexArrayId);

	glGenBuffers(1, &vertexBufferId);

	gVertexBufferData = new GLfloat[]
	{
		-.5f, -.5f, 0.0f,
		.5f, -.5f, 0.0f,
		0.0f, .5f, 0.0f,
	};

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);

	glBufferData(GL_ARRAY_BUFFER, sizeof(gVertexBufferData), gVertexBufferData, GL_STATIC_DRAW);
}


TriangleObject::~TriangleObject()
{
	delete[] gVertexBufferData;
}
