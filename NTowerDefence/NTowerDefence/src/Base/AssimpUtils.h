#pragma once

#include <assimp\color4.h>
#include <gl\glew.h>

namespace AssimpUtils
{
	void set_float4(float f[4], float a, float b, float c, float d);

	void color4_to_float4(const aiColor4D *c, float f[4]);

	struct MyMesh
	{
		GLuint vao;
		GLuint texIndex;
		GLuint uniformBlockIndex;
		int numFaces;
	};

	struct MyMaterial
	{
		float diffuse[4];
		float ambient[4];
		float specular[4];
		float emissive[4];
		float shininess;
		int texCount;
	};
}