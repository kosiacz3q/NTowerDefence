#include "BaseGameStage.h"
#include <GLFW\glfw3.h>

BaseGameStage::BaseGameStage()
{
	drawingContext = std::make_shared<DrawingContext>();
}


BaseGameStage::~BaseGameStage()
{
}

void BaseGameStage::registerGameObject(std::string id, BaseGameObjectPtr baseGameObject)
{
	((Registerer<BaseGameObjectPtr>)*this).registerObject(id, baseGameObject);
}

void BaseGameStage::registerBaseGUIElement(std::string id, BaseGUIElementPtr baseGUIElement)
{
	((Registerer<BaseGUIElementPtr>)*this).registerObject(id,baseGUIElement);
}



void BaseGameStage::initStage() {

	auto container = ((Registerer<BaseGameObjectPtr>)*this).getContainer();

	for (auto object : *container) 
		object.second->init();
	init();
}

void BaseGameStage::drawStage() {
	glClearColor(0, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	auto container = ((Registerer<BaseGameObjectPtr>)*this).getContainer();

	for (auto object : *container)
		object.second->draw(drawingContext);
	draw();
}

void BaseGameStage::drawGUI(UpdateContextPtr context)
{
	auto container = ((Registerer<BaseGUIElementPtr>)*this).getContainer();

	for (auto object : *container)
		object.second->update(context);
	update(context);
}

void BaseGameStage::updateStage(UpdateContextPtr context) {

	auto container = ((Registerer<BaseGameObjectPtr>)*this).getContainer();

	for (auto object : *container)
		object.second->update(context);
	update(context);
}