#pragma once

#include <memory>

#include <Shader\Shader.h>
#include <GameStages\GameStageManager.h>
#include <Drawing\WindowManager.h>
#include <Textures\Texture.h>
#include <Models\Model.h>

#include <Base\IKeyboardProcessor.h>
#include <Base\IMouseMovementProcessor.h>
#include <Base\IMouseScrollProcessor.h>

#include <Base\Registerer.h>


class GameContext
{
public:
	GameStageManagerPtr gameStageManager;
	WindowManagerPtr windowHandler;

	TextureManagerPtr textureManager;
	ShaderManagerPtr shaderManager;
	ModelManagerPtr modelManager;

	std::shared_ptr<Registerer<IKeyboardPocessorPtr> > keyboardRegisterer;
	std::shared_ptr<Registerer<IMouseMovementProcessorPtr> > mouseMovementRegisterer;
	std::shared_ptr<Registerer<IMouseScrollProcessorPtr> > mouseScrollRegisterer;
};

typedef std::shared_ptr<GameContext> GameContextPtr;