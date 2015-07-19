#pragma once

#include <assimp\Importer.hpp>

#include "ModelContainer.h"

class ModelLoader
{
public:
	ModelLoader();
	virtual ~ModelLoader();

	ModelContainerPtr LoadModel(const std::string& path);

private:

	Assimp::Importer importer;
};

