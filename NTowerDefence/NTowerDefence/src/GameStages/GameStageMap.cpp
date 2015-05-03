#include "GameStageMap.h"


GameStageMap::GameStageMap(GameContextPtr gameContext)
	:Inherited(gameContext)
{
	drawingContext = DrawingContextPtr(new DrawingContext());
}

GameStageMap::~GameStageMap()
{
}

void GameStageMap::init()
{
	triangle = BaseGameObjectPtr(new TriangleObject(gameContext->shaderManager->getShader("simpleProgram")));

	// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	drawingContext->projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	drawingContext->view = glm::lookAt(
		glm::vec3(4, 3, 3), // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
		);

	state = GameStageState::READY;
}

void GameStageMap::onBegin()
{
	Inherited::onBegin();
}

void GameStageMap::onClose()
{
	Inherited::onClose();
}

void  GameStageMap::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	triangle->draw(drawingContext);
}

void GameStageMap::update(UpdateContextPtr context)
{

}
