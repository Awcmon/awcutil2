#pragma once

#define GLSL(src) "#version 150 core\n" #src

#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource = nullptr);
	~Shader();
	Shader &use();

	GLuint id;

};
