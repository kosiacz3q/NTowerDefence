#include <stdio.h>
#include <stdlib.h>

#include "Shader\ShaderManager.h"
#include "GameManager\GameManager.h"

#include "GameStages\GameStageMap.h"

int main(void)
{
	GameManagerPtr gameManager = GameManagerPtr(new GameManager());
	GameContextPtr gameContext = gameManager->getGameContext();
	
	gameContext->shaderManager = ShaderManagerPtr(new ShaderManager());
	gameContext->gameStageManager = GameStageManagerPtr(new GameStageManager());

	gameContext->gameStageManager->registerStage(BaseGameStagePtr(new GameStageMap(gameContext)));

	gameContext->shaderManager->loadShader(
		"simpleProgram",
		"shaders/vertex/SimpleVertexShader.vertexshader",
		"shaders/fragment/SimpleFragmentShader.fragmentshader");

	gameManager->run();

	return 0;
}