#include "AssimpUtils.h"

namespace AssimpUtils
{
	void set_float4(float f[4], float a, float b, float c, float d)
	{
		f[0] = a;
		f[1] = b;
		f[2] = c;
		f[3] = d;
	}

	void color4_to_float4(const aiColor4D *c, float f[4])
	{
		f[0] = c->r;
		f[1] = c->g;
		f[2] = c->b;
		f[3] = c->a;
	}

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