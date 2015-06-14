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

#include <Base/GenericAssetsManager.h>
#include <Base/BaseGameObject.h>
#include <Shader\Shader.h>

#include <Models\mesh.h>

class Model : public BaseGameObject
{
public:
    /*  Model Data */
	vector<ModelTexture > textures_loaded;	// Stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    vector<Mesh> meshes;
    
    bool gammaCorrection;

    /*  Functions   */
    // Constructor, expects a filepath to a 3D model.
	Model(const aiScene* scene, ShaderPtr shader, std::string texturesPath);

	void draw(DrawingContextPtr drawingContext);

	void update(UpdateContextPtr updateContext);

	void init();
    
private:
	ShaderPtr shader;
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

typedef std::shared_ptr<Model> ModelPtr;
typedef GenericAssetsManager<ModelPtr> ModelManager;
typedef std::shared_ptr<ModelManager> ModelManagerPtr;