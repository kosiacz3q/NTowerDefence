#include <stdio.h>
#include <stdlib.h>

#include "Shader\ShaderManager.h"
#include "GameManager\GameManager.h"

#include "GameStages\GameStageMap.h"

int main(void)
{
	GameManagerPtr gameManager = GameManagerPtr(new GameManager());

	GameContextPtr gameContext = gameManager->getGameContext();
	
	gameContext->drawingHandler = DrawingHandlerPtr(new DrawingHandler());

	gameManager->run();

	gameContext->shaderManager = ShaderManagerPtr(new ShaderManager());
	gameContext->shaderManager->loadShader(
		"simpleProgram",
		"shaders/vertex/SimpleVertexShader.vertexshader",
		"shaders/fragment/SimpleFragmentShader.fragmentshader");

	gameContext->gameStageManager = GameStageManagerPtr(new GameStageManager());

	gameContext->gameStageManager->registerStage(BaseGameStagePtr(new GameStageMap(gameContext)));

	gameContext->gameStageManager->setStage("GAME_STAGE_MAP");

	return 0;
}