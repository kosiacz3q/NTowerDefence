#include <stdio.h>
#include <stdlib.h>

#include "Shader\ShaderManager.h"
#include "GameManager\GameManager.h"


#include <glm\glm.hpp>
#include <glm\ext.hpp>
//using namespace glm;

const GLfloat g_vertex_buffer_data[] = {
	-.5f, -.5f, 0.0f,
	.5f, -.5f, 0.0f,
	0.0f, .5f, 0.0f,
};

int main(void)
{
	GameManagerPtr gameManager = GameManagerPtr(new GameManager());
	ShaderManagerPtr shaderManager = ShaderManagerPtr(new ShaderManager());

	shaderManager->loadShader(
		"simpleProgram",
		"shaders/vertex/SimpleVertexShader.vertexshader",
		"shaders/fragment/SimpleFragmentShader.fragmentshader");

	// Get a handle for our "MVP" uniform.
	// Only at initialisation time.
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	do{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);

		// Send our transformation to the currently bound shader,
		// in the "MVP" uniform
		// For each model you render, since the MVP will be different (at least the M part)
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
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

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
	glfwWindowShouldClose(window) == 0);


	glfwTerminate();

	return 0;
}

