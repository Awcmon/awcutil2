#pragma once

#include <vector>
#include <GL/glew.h>
#include <string>

class Attribute
{
public:
	Attribute();
	Attribute(GLuint _location, std::string _name, int _size, GLenum _type, GLboolean _normalized, int _stride, int _offset);
	~Attribute();

	GLuint location;
	std::string name;
	GLint size;
	GLenum type;
	GLboolean normalized;
	GLsizei stride;
	void* offset;
};

class Mesh
{
public:
	Mesh();
	~Mesh();

	GLuint vao, vbo, ebo;
	std::vector<Attribute> attributes;

};

