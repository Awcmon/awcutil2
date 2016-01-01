#pragma once

#include <vector>
#include <GL/glew.h>
#include <string>

namespace awcutil
{
	namespace gl
	{

		class Attribute
		{
		public:
			Attribute();
			Attribute(GLuint _program, std::string _name, int _size, GLenum _type, GLboolean _normalized, int _stride, int _offset);
			~Attribute();

			GLuint program;
			GLint location;
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
			Mesh(std::vector<GLfloat> _vertices, std::vector<GLuint> _elements);
			~Mesh();
			void setup();

			std::vector<GLfloat> vertices;
			std::vector<GLuint> elements;
			GLuint vao, vbo, ebo;
			std::vector<Attribute> attributes;

		};

	}
}
