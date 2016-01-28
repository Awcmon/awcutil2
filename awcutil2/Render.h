#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <GL/glew.h>

#include "Mesh.h"
#include "Shader.h"

class Render
{
public:
	Render();
	~Render();

	std::unordered_map<std::string, awcutil::gl::Shader> shaders;
	std::unordered_map<std::string, awcutil::gl::Mesh> meshes;
	//std::unordered_map<std::string, awcutil::gl::Texture> textures;
};

