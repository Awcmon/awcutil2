#include "Mesh.h"

Attribute::Attribute()
{

}

Attribute::Attribute(GLuint _location, std::string _name, int _size, GLenum _type, GLboolean _normalized, int _stride, int _offset)
{
	location = _location;
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

}


Mesh::~Mesh()
{
}
