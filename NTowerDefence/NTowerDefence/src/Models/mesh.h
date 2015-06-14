#pragma once
// Std. Includes
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
// GL Includes
#include <GL/glew.h> // Contains all the necessery OpenGL includes
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <assimp\types.h>

#include <Shader\Shader.h>

struct Vertex {
    // Position
    glm::vec3 Position;
    // Normal
    glm::vec3 Normal;
    // TexCoords
    glm::vec2 TexCoords;
    // Tangent
    glm::vec3 Tangent;
    // Bitangent
    glm::vec3 Bitangent;
};

struct ModelTexture {
    GLuint id;
    string type;
    aiString path;
};

class Mesh {
public:
    vector<Vertex> vertices;
    vector<GLuint> indices;
	vector<ModelTexture> textures;
    GLuint VAO;

	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<ModelTexture> textures);

    // Render the mesh
	void Draw(ShaderPtr shader);

private:
    GLuint VBO, EBO;
	void setupMesh();
};



