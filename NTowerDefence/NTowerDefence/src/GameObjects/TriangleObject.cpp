#include "TriangleObject.h"

TriangleObject::TriangleObject(ShaderPtr shader)
	:shader(shader)
{

}

TriangleObject::~TriangleObject()
{
	glDeleteBuffers(1, &vertexBufferId);
	glDeleteVertexArrays(1, &vertexArrayId);

	delete[] vertexBufferData;
}

void TriangleObject::init()
{
	glGenVertexArrays(1, &vertexArrayId);
	glBindVertexArray(vertexArrayId);
	
	vertexBufferData = new GLfloat[9]
	{
		-1.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f,
			0.0f, 1.0f, 0.0f
	};

	glGenBuffers(1, &vertexBufferId);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), vertexBufferData, GL_STATIC_DRAW);

	matrixID = glGetUniformLocation(shader->getId(), "MVP");
}

void TriangleObject::draw(DrawingContextPtr drawingContext)
{
	auto model = glm::mat4(1.0f);
	glm::mat4  MVP = drawingContext->projection * drawingContext->view * model; // Remember, matrix multiplication is the other way around

	glUseProgram(shader->getId());
	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	// For each model you render, since the MVP will be different (at least the M part)
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
		);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle

	glDisableVertexAttribArray(0);
}

void TriangleObject::update(UpdateContextPtr updateContext)
{

}