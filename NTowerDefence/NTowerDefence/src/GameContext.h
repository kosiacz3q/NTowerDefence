#pragma once

#include <memory>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "Shader\Shader.h"
#include "GameStages\GameStageManager.h"
#include "Drawing\WindowManager.h"
#include "Textures\Texture.h"

typedef std::shared_ptr<GLFWwindow> GLFWwindowPtr;

class GameContext
{
public:
	GameStageManagerPtr gameStageManager;
	WindowManagerPtr windowHandler;

	TextureManagerPtr textureManager;
	ShaderManagerPtr shaderManager;
};

typedef std::shared_ptr<GameContext> GameContextPtr;