#include "ModelLoader.h"

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

ModelLoader::ModelLoader()
{
}


ModelLoader::~ModelLoader()
{
}


ModelPtr ModelLoader::LoadModel(const std::string& path)
{
	return ModelPtr(new Model(importer.ReadFile(path, aiProcessPreset_TargetRealtime_Quality)));
}