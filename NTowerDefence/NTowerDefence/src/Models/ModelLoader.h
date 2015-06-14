#pragma once

#include <assimp\Importer.hpp>

#include "Model.h"

class ModelLoader
{
public:
	ModelLoader();
	virtual ~ModelLoader();

	ModelPtr LoadModel(const std::string& path, const ShaderPtr shader);

private:

	Assimp::Importer importer;
};

