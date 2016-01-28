
#include <iostream>

#include <SDL.h>
#undef main
#undef M_PI
#include <GL/glew.h>
#include <SDL_opengl.h>

#define _AWCUTIL_SDL
#define _AWCUTIL_OPENGL
#include <awcutil.h>

#define _USE_MATH_DEFINES
#include <math.h>

using std::cout;

using awcutil::Vector2f;

using awcutil::clamp;
using awcutil::approach;
using awcutil::deg2rad;
using awcutil::rad2deg;
using awcutil::dsin;
using awcutil::dcos;
using awcutil::angd_normalize;
using awcutil::angd_difference;
using awcutil::angd_approach;
using awcutil::angd_forward;
using awcutil::angr_normalize;
using awcutil::angr_difference;
using awcutil::angr_approach;
using awcutil::angr_forward;

using awcutil::sdl::Window;
using awcutil::sdl::EventContainer;

using awcutil::gl::Attribute;
using awcutil::gl::Mesh;
using awcutil::gl::Shader;

const GLchar* vertexSource =
"#version 150 core\n"
"in vec2 position;"
"void main() {"
"   gl_Position = vec4(position, 0.0, 1.0);"
"}";
//const GLchar* fragmentSource = "#version 150\n uniform vec3 triangleColor; out vec4 outColor; void main() { outColor = vec4(0.5, 0.5, 1.0, 1.0); } ";
const GLchar* fragmentSource = GLSL(
	uniform vec3 color;
	out vec4 outColor;
	void main() 
	{
		outColor = vec4(0.5, 0.5, 1.0, 1.0);
	}
);

void generateCircle(vector<GLfloat> &vbo, vector<GLuint> &ebo, GLfloat radius, GLint points)
{
	//Generate vertices
	vbo.push_back(0.0f);
	vbo.push_back(0.0f);
	for (int i = 0; i < points; i++)
	{
		float ang = (float)(((2.0*((double)M_PI)) / ((double)points))*((double)i));
		vbo.push_back((GLfloat)cos(ang)*radius);
		vbo.push_back((GLfloat)sin(ang)*radius);
	}

	//Generate elements
	for (int i = 1; i < points; i++)
	{
		ebo.push_back(0);
		ebo.push_back(i);
		ebo.push_back(i + 1);
	}
	ebo.push_back(0);
	ebo.push_back(points);
	ebo.push_back(1);
}

int main(int argc, char* args[])
{
	//cout << angr_normalize((float)M_PI);
	Window window("Hi", 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);
	bool run = true;
	EventContainer events;

	Render render;

	
	vector<GLfloat> vertices = {
		-0.5f, 0.5f,
		0.5f, 0.5f,
		-0.5f, -0.5f,
		0.5f, -0.5f
	};

	vector<GLuint> elements = {
		0, 1, 2,
		1, 2, 3
	};

	vector<GLfloat> vertices2;
	vector<GLuint> elements2;
	generateCircle(vertices2, elements2, 1.0f, 200);

	Shader shaderProgram(vertexSource, fragmentSource);
	shaderProgram.use();

	// Get the location of the color uniform
	GLint uniColor = glGetUniformLocation(shaderProgram.id, "triangleColor");

	//Meshes
	Mesh testmesh(vertices, elements);
	testmesh.attributes.push_back(Attribute(shaderProgram.id, "position", 2, GL_FLOAT, GL_FALSE, 0, 0));
	testmesh.setup();

	Mesh testmesh2(vertices2, elements2);
	testmesh2.attributes.push_back(Attribute(shaderProgram.id, "position", 2, GL_FLOAT, GL_FALSE, 0, 0));
	testmesh2.setup();

	while (run)
	{
		events.think();
		if (events.has_event_type(SDL_QUIT))
		{
			run = false;
		}
		
		// Clear the screen to black
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//glBindVertexArray(testmesh.vao);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glBindVertexArray(testmesh2.vao);
		//glDrawElements(GL_TRIANGLES, elements2.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(render.meshes["quad"].vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		SDL_GL_SwapWindow(window.window);
	}

	return 0;
}
