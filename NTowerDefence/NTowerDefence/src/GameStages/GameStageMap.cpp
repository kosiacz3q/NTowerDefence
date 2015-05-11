#include "GameStageMap.h"

#include "..\GameObjects\TriangleObject.h"
#include "..\GameObjects\CubeObject.h"
#include "..\GameObjects\TexturedCube.h"

GameStageMap::GameStageMap(GameContextPtr gameContext)
	:gameContext(gameContext)
{
	drawingContext = DrawingContextPtr(new DrawingContext());

	camera = StaticCameraPtr(new StaticCamera());

	keyboard = KeyboardHandlerPtr(new KeyboardHandler());
	mouse = MouseHandlerPtr(new MouseHandler(gameContext->windowHandler->getWindow()));

	state = GameStageState::NOT_INITIALIZED;
}

GameStageMap::~GameStageMap()
{
}

void GameStageMap::init()
{
	triangle = BaseGameObjectPtr(new TriangleObject(gameContext->shaderManager->getAsset("simpleProgram")));
	cube = BaseGameObjectPtr(new CubeObject(gameContext->shaderManager->getAsset("colouringProgram")));
	texturedCube = BaseGameObjectPtr(new TexturedCube(
		gameContext->shaderManager->getAsset("texturingProgram"),
		gameContext->textureManager->getAsset("simpleTexture")));

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	drawingContext->projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	// Or, for an ortho camera :
	//glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates

	camera->setPosition(glm::vec3(4, 3, 3), glm::vec3(-4, -3, -3));

	state = GameStageState::READY;
}

void GameStageMap::onBegin()
{
	window = gameContext->windowHandler->getWindow();

	triangle->init();
	cube->init();
	texturedCube->init();

	state = GameStageState::ACTIVE;
}

void GameStageMap::onClose()
{
	state = GameStageState::READY;
}

void  GameStageMap::draw()
{
	glClearColor(0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//triangle->draw(drawingContext);
	//cube->draw(drawingContext);
	texturedCube->draw(drawingContext);

	glfwSwapBuffers(window);
}

void GameStageMap::update(UpdateContextPtr context)
{
	drawingContext->view = camera->getViewMatrix();
}
