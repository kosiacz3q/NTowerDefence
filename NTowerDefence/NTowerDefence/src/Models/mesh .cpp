#pragma once

#include "mesh.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Mesh::Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<ModelTexture > textures)
{
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;

    // Now that we have all the required data, set the vertex buffers and its attribute pointers.
    this->setupMesh();
}

    // Render the mesh
void Mesh::Draw(IShaderPtr shader) 
{
    // Bind appropriate textures
    GLuint diffuseNr = 1;
    GLuint specularNr = 1;
    GLuint normalNr = 1;
    GLuint heightNr = 1;

    for(GLuint i = 0; i < this->textures.size(); i++)
    {
         glActiveTexture(GL_TEXTURE0 + i); // Active proper texture unit before binding
        // Retrieve texture number (the N in diffuse_textureN)
        stringstream ss;
        string number;
        string name = this->textures[i].type;
        if(name == "texture_diffuse")
            ss << diffuseNr++; // Transfer GLuint to stream
        else if(name == "texture_specular")
            ss << specularNr++; // Transfer GLuint to stream
        else if(name == "texture_normal")
            ss << normalNr++; // Transfer GLuint to stream
            else if(name == "texture_height")
            ss << heightNr++; // Transfer GLuint to stream
        number = ss.str(); 
        // Now set the sampler to the correct texture unit
        glUniform1i(glGetUniformLocation(shader->getId() , (name + number).c_str()), i);
        // And finally bind the texture
        glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
    }
        
	
	glBindVertexArray(this->VAO);

	// Set the vertex attribute pointers
	// Vertex Positions
	glEnableVertexAttribArray(0);

	glEnableVertexAttribArray(1);

	glEnableVertexAttribArray(2);


    glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
	
    glBindVertexArray(0);

    // Always good practice to set everything back to defaults once configured.
    for (GLuint i = 0; i < this->textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

void Mesh::setupMesh()
{
    glGenVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);

    glGenBuffers(1, &this->VBO);
    // Load data into vertex buffers
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    // A great thing about structs is that their memory layout is sequential for all its items.
    // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
    // again translates to 3/2 floats which translates to a byte array.
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);  

    // Set the vertex attribute pointers
    // Vertex Positions
    glEnableVertexAttribArray(0);	
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    // Vertex Normals
    glEnableVertexAttribArray(1);	
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));
    // Vertex Texture Coords
    glEnableVertexAttribArray(2);	
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));
    // Vertex Tangent
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Tangent));
    // Vertex Bitangent
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Bitangent));

	glGenBuffers(1, &this->EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);
}



