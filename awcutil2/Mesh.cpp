#include "Mesh.h"

#include <iostream>

namespace awcutil
{
	namespace gl
	{

		Attribute::Attribute()
		{

		}

		Attribute::Attribute(GLuint _program, std::string _name, int _size, GLenum _type, GLboolean _normalized, int _stride, int _offset)
		{
			program = _program;
			//location = _location;
			name = _name;
			size = _size;
			type = _type;
			normalized = _normalized;
			stride = _stride * sizeof(float);
			offset = (void*)(_offset * sizeof(float));
		}

		Attribute::~Attribute()
		{
			offset = NULL;
		}

		Mesh::Mesh()
		{
			/*
			glGenVertexArrays(1, &vao);
			glGenBuffers(1, &vbo);
			glGenBuffers(1, &ebo);
			glBindVertexArray(vao);

			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			*/
		}

		Mesh::Mesh(std::vector<GLfloat> _vertices, std::vector<GLuint> _elements)
		{
			vertices = _vertices;
			elements = _elements;
		}

		Mesh::~Mesh()
		{
			glDeleteBuffers(1, &vbo);
			glDeleteBuffers(1, &ebo);
			glDeleteVertexArrays(1, &vao);
		}

		void Mesh::setup()
		{

			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);

			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

			glGenBuffers(1, &ebo);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size() * sizeof(GLuint), &elements[0], GL_STATIC_DRAW);

			for (int i = 0; i < (int)attributes.size(); i++)
			{
				Attribute cur = attributes[i];
				cur.location = glGetAttribLocation(cur.program, cur.name.c_str());
				glEnableVertexAttribArray(cur.location);
				glVertexAttribPointer(cur.location, cur.size, cur.type, cur.normalized, cur.stride, cur.offset);
			}
		}

	}
}
