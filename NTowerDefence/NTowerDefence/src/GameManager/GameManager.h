#pragma once

#include <memory>


#include <GL\glew.h>
#include <GLFW\glfw3.h>

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();


	void initWindow();

private:
	
	void initGLFW();
	void initGLEW();

	GLFWwindow* window;
};

typedef std::shared_ptr<GameManager> GameManagerPtr;


