#pragma once
// Std. Includes
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// GL Includes
#include <GL/glew.h> // Contains all the necessery OpenGL includes

#include <assimp/scene.h>

#include <Base/AssetsManager/GenericSharedAssetsManager.h>
#include <Base\IShader.h>

#include "mesh.h"

class ModelContainer
{
public:
    /*  Model Data */
	vector<ModelTexture > textures_loaded;	// Stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    vector<Mesh> meshes;
    
    bool gammaCorrection;

	void draw(IShaderPtr shader);

    /*  Functions   */
    // Constructor, expects a filepath to a 3D model.
	ModelContainer(const aiScene* scene, std::string texturesPath);
    
private:
	string directory;

    /*  Functions   */
    // Loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
	void loadModel(string path);

    // Processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
	void processNode(aiNode* node, const aiScene* scene);

	Mesh processMesh(aiMesh* mesh, const aiScene* scene);

    // Checks all material textures of a given type and loads the textures if they're not loaded yet.
    // The required info is returned as a Texture struct.
	vector<ModelTexture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
};

typedef std::shared_ptr<ModelContainer> ModelContainerPtr;
typedef GenericSharedAssetsManager<ModelContainerPtr> ModelContainersManager;
typedef std::shared_ptr<ModelContainersManager> ModelContainersManagerPtr;