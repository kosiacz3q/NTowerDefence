#include <stdio.h>
#include <stdlib.h>

#include "Shader\ShaderManager.h"
#include "GameManager\GameManager.h"

#include "GameStages\GameStageMap.h"

int main(void)
{
	GameManagerPtr gameManager = GameManagerPtr(new GameManager());

	gameManager->init();

	GameContextPtr gameContext = gameManager->getGameContext();

	gameContext->shaderManager->loadShader(
		"simpleProgram",
		"shaders/vertex/SimpleVertexShader.vertexshader",
		"shaders/fragment/SimpleFragmentShader.fragmentshader");

	gameContext->gameStageManager->registerStage(BaseGameStagePtr(new GameStageMap(gameContext)));
	gameContext->gameStageManager->requestStageSet("GAME_STAGE_MAP");

	gameManager->run();

	return 0;
}