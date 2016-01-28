#pragma once

#include "Mesh.h"
#include "Shader.h"
#include <string>
#include <unordered_map>

class Render
{
public:
	Render();
	~Render();

	std::unordered_map<std::string, awcutil::gl::Shader> shaders;
	std::unordered_map<std::string, awcutil::gl::Mesh> meshes;
};

