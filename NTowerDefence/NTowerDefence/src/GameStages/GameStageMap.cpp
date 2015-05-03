#include "GameStageMap.h"


GameStageMap::GameStageMap(GameContextPtr gameContext)
	:Inherited(gameContext)
{
}


GameStageMap::~GameStageMap()
{
}

void GameStageMap::init()
{
	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	view = glm::lookAt(
		glm::vec3(4, 3, 3), // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
		);
	// Model matrix : an identity matrix (model will be at the origin)
	model = glm::mat4(1.0f);  // Changes for each model !
	// Our ModelViewProjection : multiplication of our 3 matrices
	MVP = projection * view * model; // Remember, matrix multiplication is the other way around

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

}


void GameStageMap::update(UpdateContextPtr context)
{

}

void GameStageMap::onClose()
{

}