#pragma once

#include <memory>
#include <vector>

#include <Base\AssimpUtils.h>
#include <Base/GenericAssetsManager.h>
#include <Base/BaseGameObject.h>
#include <Shader\Shader.h>

#include <GL\glew.h>
#include <assimp/scene.h>



class Model : BaseGameObject
{
public:
	Model(const aiScene* scene, const ShaderPtr shader);
	virtual ~Model();

	void draw(DrawingContextPtr drawingContext);

	void update(UpdateContextPtr updateContext);

	void init();

private:

	void genVAOsAndUniformBuffer();
	void recursive_render(const aiScene *sc, const aiNode* nd);

	const aiScene* scene;
	ShaderPtr shader;
	GLuint matrixID;

	GLuint vertexLoc;
	GLuint normalLoc;
	GLuint texCoordLoc;

	GLuint vertexArrayId;

	std::map<std::string, GLuint> textureIdMap;
	std::vector<AssimpUtils::MyMesh> myMeshes;
};

typedef std::shared_ptr<Model> ModelPtr;
typedef GenericAssetsManager<ModelPtr> ModelManager;
typedef std::shared_ptr<ModelManager> ModelManagerPtr;