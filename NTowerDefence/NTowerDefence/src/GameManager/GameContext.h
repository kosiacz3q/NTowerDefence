#pragma once

#include <memory>

#include <Shader\Shader.h>
#include <GameStages\GameStageManager.h>
#include <Drawing\WindowManager.h>
#include <Textures\Texture.h>
#include <Models\Model.h>

class GameContext
{
public:
	GameStageManagerPtr gameStageManager;
	WindowManagerPtr windowHandler;

	TextureManagerPtr textureManager;
	ShaderManagerPtr shaderManager;
	ModelManagerPtr modelManager;
};

typedef std::shared_ptr<GameContext> GameContextPtr;