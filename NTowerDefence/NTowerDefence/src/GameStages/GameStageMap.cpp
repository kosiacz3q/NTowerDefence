#include "GameStageMap.h"

#include <GameObjects\TriangleObject.h>
#include <GameObjects\CubeObject.h>
#include <GameObjects\TexturedCube.h>

GameStageMap::GameStageMap(GameContextPtr gameContext)
	:gameContext(gameContext)
{
	
	movableCamera = std::make_shared<MovableCamera>(glm::vec3(-3.0f, -3.0f, 3.0f));

	state = GameStageState::NOT_INITIALIZED;
}

GameStageMap::~GameStageMap()
{
}

void GameStageMap::init()
{
	//triangle = BaseGameObjectPtr(new TriangleObject(gameContext->shaderManager->getAsset("simpleProgram")));
	//cube = BaseGameObjectPtr(new CubeObject(gameContext->shaderManager->getAsset("colouringProgram")));
	//texturedCube = BaseGameObjectPtr(new TexturedCube(
	//	gameContext->shaderManager->getAsset("texturingProgram"),
	//	gameContext->textureManager->getAsset("simpleTexture")));

	//model = gameContext->modelManager->getAsset("transparentModel");

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	//drawingContext->projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	drawingContext->projection = glm::perspective(1.f, (float)900 / (float)600, 0.1f, 100.0f);
	
	// Or, for an ortho camera :
	//glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates

	//model1->init();
	//model2->init();

	//gameContext->mouseMovementRegisterer->registerObject("camera", movableCamera);
	gameContext->keyboardRegisterer->registerObject("camera", movableCamera);

	state = GameStageState::READY;
}

void GameStageMap::onBegin()
{
	window = gameContext->windowHandler->getWindow();



	movableCamera->setPosition(glm::vec3(14, 0, 10), glm::vec3(-14, 0, -9.95f), glm::vec3(0, 0, 1));

	state = GameStageState::ACTIVE;
}

void GameStageMap::onClose()
{
	state = GameStageState::READY;

	gameContext->mouseMovementRegisterer->deregisterAll();
}

void  GameStageMap::draw()
{
	glClearColor(0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//triangle->draw(drawingContext);
	//cube->draw(drawingContext);
	//texturedCube->draw(drawingContext);

	//model->draw(drawingContext);
	//drawingContext->view = staticCamera->getViewMatrix();

	//model1->draw(drawingContext);
	//model2->draw(drawingContext);

	glfwSwapBuffers(window);
}

void GameStageMap::update(UpdateContextPtr context)
{
	//model1->update(context),
	drawingContext->view = movableCamera->getViewMatrix();
}
