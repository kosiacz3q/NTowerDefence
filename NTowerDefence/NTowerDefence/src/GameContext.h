#pragma once

#include <memory>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Shader\ShaderManager.h"
#include "GameStages\GameStageManager.h"
#include "Drawing\WindowManager.h"
#include "Textures\TextureManager.h"

typedef std::shared_ptr<GLFWwindow> GLFWwindowPtr;

class GameContext
{
public:
	
	ShaderManagerPtr shaderManager;
	GameStageManagerPtr gameStageManager;
	WindowManagerPtr drawingHandler;
	TextureManagerPtr textureManager;
};

typedef std::shared_ptr<GameContext> GameContextPtr;