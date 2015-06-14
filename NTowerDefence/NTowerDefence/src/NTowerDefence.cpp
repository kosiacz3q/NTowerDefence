#include <stdio.h>
#include <stdlib.h>

#include <Shader\ShaderLoader.h>
#include <Textures\TexturesLoader.h>
#include <Models\ModelLoader.h>

#include <GameManager\GameManager.h>
#include <GameStages\GameStageMap.h>


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

	gameContext->shaderManager->InsertAsset(
		"modelProgram",
		shaderLoader.LoadShaderFromFile(
		"shaders/vertex/SimpleModelVertexShader.vertexshader",
		"shaders/fragment/SimpleModelFragmentShader.fragmentshader"
	));
	/*
	gameContext->shaderManager->InsertAsset(
		"simpleModelProgram",
		shaderLoader.LoadShaderFromFile(
		"shaders/vertex/VerySimpleShader.vert",
		"shaders/fragment/VerySimpleShader.frag"
	));*/

	gameContext->shaderManager->InsertAsset(
		"workingModelShader",
		shaderLoader.LoadShaderFromFile(
		"shaders/vertex/WorkingModelShader.vs",
		"shaders/fragment/WorkingModelShader.frag"
	));

	TexturesLoader texturesLoader;

	gameContext->textureManager->InsertAsset(
		"simpleTexture",
		texturesLoader.loadTexture("textures/uvtemplate.dds"));

	ModelLoader modelLoader;

	/*
	gameContext->modelManager->InsertAsset(
		"transparentModel",
		modelLoader.LoadModel(
			"models/cubes_with_alpha.3DS",
			gameContext->shaderManager->getAsset("modelProgram"))
		);*/

	gameContext->modelManager->InsertAsset(
		"houseModel",
		modelLoader.LoadModel(
		"models/nanosuit/nanosuit.obj",
		gameContext->shaderManager->getAsset("workingModelShader"))
	);

	gameContext->gameStageManager->registerStage(BaseGameStagePtr(new GameStageMap(gameContext)));
	gameContext->gameStageManager->requestStageSet("GAME_STAGE_MAP");

	gameManager->run();

	return 0;
}