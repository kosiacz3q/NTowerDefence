#pragma once

#include <assimp\color4.h>
#include <gl\glew.h>

namespace AssimpUtils
{
	void set_float4(float f[4], float a, float b, float c, float d);

	void color4_to_float4(const aiColor4D *c, float f[4]);

	struct MyMesh;

	struct MyMaterial;
}