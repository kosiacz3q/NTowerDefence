#pragma once

#include <GL/glew.h>
#include <GLFW\glfw3.h>

#include <assimp\scene.h>
#include <assimp\mesh.h>

#include <Base/GenericAssetsManager.h>
#include <Base/BaseGameObject.h>
#include <Shader\Shader.h>

#include <vector>

class Model : public BaseGameObject
{
public :
	struct MeshEntry {
		static enum BUFFERS {
			VERTEX_BUFFER, TEXCOORD_BUFFER, NORMAL_BUFFER, INDEX_BUFFER
		};
		GLuint vao;
		GLuint vbo[4];

		unsigned int elementCount;

		MeshEntry(aiMesh *mesh);
		~MeshEntry();

		void load(aiMesh *mesh);
		void render();
	};

	std::vector<MeshEntry*> meshEntries;

public:
	Model(const aiScene *scene, const ShaderPtr shader);
	~Model();

	void draw(DrawingContextPtr drawingContext);

	void update(UpdateContextPtr updateContext);

	void init();

private:
	ShaderPtr shader;
};

typedef std::shared_ptr<Model> ModelPtr;
typedef GenericAssetsManager<ModelPtr> ModelManager;
typedef std::shared_ptr<ModelManager> ModelManagerPtr;