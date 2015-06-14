#pragma once

#include "Model.h"
#include <assimp\Importer.hpp>

class ModelLoader
{
public:
	ModelLoader();
	virtual ~ModelLoader();

	ModelPtr LoadModel(const std::string& path, const ShaderPtr shader);

private:

	Assimp::Importer importer;
};

