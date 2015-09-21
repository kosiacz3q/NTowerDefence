#include <stdio.h>
#include <stdlib.h>

#include <Shader\ShaderLoader.h>
#include <Textures\TexturesLoader.h>
#include <Models\ModelLoader.h>
#include <GameObjects\ModelObject.h>

#include <GameManager\GameManager.h>
#include <GameStages\GameStageMap.h>



int main(void)
{
	GameManagerPtr gameManager = GameManagerPtr(new GameManager());

	gameManager->init();

	GameContextPtr gameContext = gameManager->getGameContext();

	gameContext->keyBindingsHandler->setBinding(
	{
		make_pair('W', ACTIVE_INPUT::FORWARD),
		make_pair('w', ACTIVE_INPUT::FORWARD),
		make_pair('S', ACTIVE_INPUT::BACKWARD),
		make_pair('s', ACTIVE_INPUT::BACKWARD),
		make_pair('A', ACTIVE_INPUT::LEFT),
		make_pair('a', ACTIVE_INPUT::LEFT),
		make_pair('D', ACTIVE_INPUT::RIGHT),
		make_pair('d', ACTIVE_INPUT::RIGHT)
	}
	);

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
	/*
	gameContext->textureManager->InsertAsset(
		"simpleTexture",
		texturesLoader.loadTexture("textures/uvtemplate.dds"));*/

	ModelLoader modelLoader;

	/*
	gameContext->modelManager->InsertAsset(
		"transparentModel",
		modelLoader.LoadModel(
			"models/cubes_with_alpha.3DS",
			gameContext->shaderManager->getAsset("modelProgram"))
		);*/

	gameContext->modelManager->InsertAsset(
		"testModel",
		modelLoader.LoadModel(
			//"models/nanosuit/nanosuit.obj",
			//"models/house/house.obj",
			//"models/trees/palmTree/Palm_Tree.obj",
			//"models/trees/Tree1/Tree.obj",
			//"models/trees/datePalm/DatePalm.obj",
			"models/trees/datePalm/DatePalm.3ds"
			//"models/house/house.3ds"
			//"models/rnb0vrhfgoao-tennisball/tennisball.obj"
			//"models/soccerball/soccer ball.3ds"
			)
		);

	gameContext->gameObjectsManager->InsertAsset(
		"fuckingAwesomeTree",
		BaseGameObjectPtr(
			new ModelObject(
				gameContext->modelManager->getAsset("testModel"),
				gameContext->shaderManager->getAsset("workingModelShader")
				))
		);
	auto gameStageMap = make_shared<GameStageMap>(gameContext);


	auto model1 = gameContext->gameObjectsManager->getAsset("fuckingAwesomeTree");
	auto model2 = gameContext->gameObjectsManager->getAsset("fuckingAwesomeTree");
	
	model1->scale(glm::vec3(0.001, 0.001, 0.001));
	model1->translateTo(glm::vec3(0.0f, -14.f, 0.0f));

	model2->scale(glm::vec3(0.001, 0.001, 0.001));
	model2->translateTo(glm::vec3(0.0f, 14.f, 0.0f));

	gameStageMap->registerObject("model1", model1);
	gameStageMap->registerObject("model2", model2);
	gameContext->gameStageManager->registerStage(gameStageMap);
	gameContext->gameStageManager->requestStageSet("GAME_STAGE_MAP");

	gameManager->run();



	return 0;
}