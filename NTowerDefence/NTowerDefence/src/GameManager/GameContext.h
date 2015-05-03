#pragma once

#include <memory>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "..\Shader\ShaderManager.h"
#include "..\GameStages\GameStageManager.h"

typedef std::shared_ptr<GLFWwindow> GLFWwindowPtr;

class GameContext
{
public:
	GLFWwindowPtr window;
	ShaderManagerPtr shaderManager;
	GameStageManagerPtr gameStageManager;
};

typedef std::shared_ptr<GameContext> GameContextPtr;