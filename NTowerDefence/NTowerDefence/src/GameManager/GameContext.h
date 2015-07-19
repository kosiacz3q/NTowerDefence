#pragma once

#include <memory>

#include <Base\BaseGameObject.h>

#include <Shader\Shader.h>
#include <GameStages\GameStageManager.h>
#include <Drawing\WindowManager.h>
#include <Textures\Texture.h>
#include <Models\ModelContainer.h>
#include <Input\KeyBindingsHandler.h>

#include <Input\IKeyboardProcessor.h>
#include <Input\IMouseMovementProcessor.h>
#include <Input\IMouseScrollProcessor.h>

#include <Base\Registerer.h>


class GameContext
{
public:
	GameStageManagerPtr gameStageManager;
	WindowManagerPtr windowHandler;

	TextureManagerPtr textureManager;
	ShaderManagerPtr shaderManager;
	ModelContainersManagerPtr modelManager;
	KeyBindingsHandlerPtr keyBindingsHandler;

	BaseGameObjectsManagerPtr gameObjectsManager;

	std::shared_ptr<Registerer<IKeyboardPocessorPtr> > keyboardRegisterer;
	std::shared_ptr<Registerer<IMouseMovementProcessorPtr> > mouseMovementRegisterer;
	std::shared_ptr<Registerer<IMouseScrollProcessorPtr> > mouseScrollRegisterer;
};

typedef std::shared_ptr<GameContext> GameContextPtr;