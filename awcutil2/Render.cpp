#include "Render.h"

Render::Render()
{
	
	const GLchar* vertexSource = GLSL (
		in vec2 position;
		void main() 
		{
		   gl_Position = vec4(position, 0.0, 1.0);
		}
	);

	const GLchar* fragmentSource = GLSL(
		uniform vec3 color;
		out vec4 outColor;
		void main()
		{
			outColor = vec4(0.5, 0.5, 1.0, 1.0);
		}
	);
	
	shaders["colorShader"] = awcutil::gl::Shader(vertexSource, fragmentSource);
	
	std::vector<GLfloat> vertices = {
		-1.0f, 1.0f,
		1.0f, 1.0f,
		-1.0f, -1.0f,
		1.0f, -1.0f
	};

	std::vector<GLuint> elements = {
		0, 1, 2,
		1, 2, 3
	};

	meshes["quad"] = awcutil::gl::Mesh(vertices, elements);
	meshes["quad"].attributes.push_back(awcutil::gl::Attribute(shaders["colorShader"].id, "position", 2, GL_FLOAT, GL_FALSE, 0, 0));
	meshes["quad"].setup();
	
}

Render::~Render()
{

}
