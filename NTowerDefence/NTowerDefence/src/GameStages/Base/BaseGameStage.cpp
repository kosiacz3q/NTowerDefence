#include "BaseGameStage.h"


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
	for (auto object : *container)
		object.second->draw(drawingContext);
	draw();
}

void BaseGameStage::updateStage(UpdateContextPtr context) {
	for (auto object : *container)
		object.second->update(context);
	update(context);
}