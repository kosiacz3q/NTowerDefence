#pragma once

#include <Base\BaseGameObject.h>
#include <Base\IShader.h>

#include <Models\ModelContainer.h>

class ModelObject
	: public BaseGameObject
{
public:
	ModelObject(ModelContainerPtr modelContainer, IShaderPtr shader);
	~ModelObject();

	void draw(DrawingContextPtr drawingContext);

	void update(UpdateContextPtr updateContext);

	void init();

private:
	IShaderPtr shader;

	ModelContainerPtr modelContainer;
};
