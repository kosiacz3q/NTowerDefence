#include "ModelObject.h"



ModelObject::ModelObject(ModelContainerPtr modelContainer, IShaderPtr shader)
	: modelContainer(modelContainer)
	, shader(shader)
{

}


ModelObject::~ModelObject()
{

}

void ModelObject::draw(DrawingContextPtr drawingContext)
{
	shader->activate();

	shader->setMVP(modelMatrix, drawingContext->view, drawingContext->projection);

	modelContainer->draw(shader);
}

void ModelObject::update(UpdateContextPtr updateContext)
{

}

void ModelObject::init()
{

}
