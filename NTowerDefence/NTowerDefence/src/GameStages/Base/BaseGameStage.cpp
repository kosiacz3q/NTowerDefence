#include "BaseGameStage.h"
#include <GLFW\glfw3.h>

BaseGameStage::BaseGameStage()
{
	drawingContext = std::make_shared<DrawingContext>();
}


BaseGameStage::~BaseGameStage()
{
}



void BaseGameStage::initStage() {
	for (auto object : *container) 
		object.second->init();
	init();
}

void BaseGameStage::drawStage() {
	glClearColor(0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	for (auto object : *container)
		object.second->draw(drawingContext);
	draw();
}

void BaseGameStage::updateStage(UpdateContextPtr context) {
	for (auto object : *container)
		object.second->update(context);
	update(context);
}