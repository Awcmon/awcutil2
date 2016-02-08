#include "Render.h"

Render::Render()
{
	
	const GLchar* vertsrc = GLSL (
		in vec2 position;
		void main() 
		{
		   gl_Position = vec4(position, 0.0, 1.0);
		}
	);

	const GLchar* fragsrc = GLSL(
		uniform vec3 color;
		out vec4 outColor;
		void main()
		{
			outColor = vec4(0.5, 0.5, 1.0, 1.0);
		}
	);
	
	shaders["colorShader"] = awcutil::gl::Shader(vertsrc, fragsrc);
	
	std::vector<GLfloat> verts = {
		-1.0f, 1.0f,
		1.0f, 1.0f,
		-1.0f, -1.0f,
		1.0f, -1.0f
	};

	std::vector<GLuint> elems = {
		0, 1, 2,
		1, 2, 3
	};

	/*
	awcutil::gl::Mesh testmesh(verts, elems);
	testmesh.attributes.push_back(awcutil::gl::Attribute(shaders["colorShader"].id, "position", 2, GL_FLOAT, GL_FALSE, 0, 0));
	testmesh.setup();
	*/
	/*
	meshes["quad"] = awcutil::gl::Mesh(vertices, elements);
	meshes["quad"].attributes.push_back(awcutil::gl::Attribute(shaders["colorShader"].id, "position", 2, GL_FLOAT, GL_FALSE, 0, 0));
	meshes["quad"].setup();
	*/
	
}

Render::~Render()
{

}
