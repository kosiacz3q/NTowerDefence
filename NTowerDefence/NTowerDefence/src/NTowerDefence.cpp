#include <stdio.h>
#include <stdlib.h>

#include "Shader\ShaderLoader.h"
#include "Textures\TexturesLoader.h"

#include "GameManager.h"

#include "GameStages\GameStageMap.h"

int main(void)
{
	GameManagerPtr gameManager = GameManagerPtr(new GameManager());

	gameManager->init();

	GameContextPtr gameContext = gameManager->getGameContext();

	ShaderLoader shaderLoader;

	gameContext->shaderManager->InsertAsset(
		"simpleProgram",
		shaderLoader.LoadShaderFromFile(
			"shaders/vertex/SimpleVertexShader.vertexshader",
			"shaders/fragment/SimpleFragmentShader.fragmentshader"
	));

	gameContext->shaderManager->InsertAsset(
		"colouringProgram",
		shaderLoader.LoadShaderFromFile(
			"shaders/vertex/TransformVertexShader.vertexshader",
			"shaders/fragment/ColorFragmentShader.fragmentshader"
	));

	gameContext->shaderManager->InsertAsset(
		"texturingProgram",
		shaderLoader.LoadShaderFromFile(
			"shaders/vertex/TextureVertexShader.vertexshader",
			"shaders/fragment/TextureFragmentShader.fragmentshader"
	));

	TexturesLoader texturesLoader;

	gameContext->textureManager->InsertAsset(
		"simpleTexture",
		texturesLoader.loadTexture("textures/uvtemplate.dds"));

	gameContext->gameStageManager->registerStage(BaseGameStagePtr(new GameStageMap(gameContext)));
	gameContext->gameStageManager->requestStageSet("GAME_STAGE_MAP");

	gameManager->run();

	return 0;
}