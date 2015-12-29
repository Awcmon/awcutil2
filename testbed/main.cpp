
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

const GLchar* vertexSource =
"#version 150 core\n"
"in vec2 position;"
"void main() {"
"   gl_Position = vec4(position, 0.0, 1.0);"
"}";
const GLchar* fragmentSource = "#version 150\n uniform vec3 triangleColor; out vec4 outColor; void main() { outColor = vec4(0.5, 0.5, 0.5, 1.0); } ";

int main(int argc, char* args[])
{
	//cout << angr_normalize((float)M_PI);
	Window window("Hi", 800, 600, SDL_WINDOW_OPENGL);
	bool run = true;
	EventContainer events;

	
	vector<GLfloat> vertices = {
		-0.5f, 0.5f,
		0.5f, 0.5f,
		-0.5f, -0.5f,
		0.5f, -0.5f
	};

	vector<GLfloat> vertices2 = {
		0.9f, 0.9f,
		0.9f, 0.95f,
		0.95f, 0.9f,
		0.95f, 0.95f
	};

	vector<GLuint> elements = {
		0, 1, 2,
		1, 2, 3
	};
	
	//Shader testshader(vertexSource, fragmentSource);

	// Create and compile the vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	// Create and compile the fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	// Link the vertex and fragment shader into a shader program
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	// Get the location of the color uniform
	GLint uniColor = glGetUniformLocation(shaderProgram, "triangleColor");

	//Meshes
	Mesh testmesh(vertices, elements);
	testmesh.attributes.push_back(Attribute(shaderProgram, "position", 2, GL_FLOAT, GL_FALSE, 0, 0));
	testmesh.setup();

	Mesh testmesh2(vertices2, elements);
	testmesh2.attributes.push_back(Attribute(shaderProgram, "position", 2, GL_FLOAT, GL_FALSE, 0, 0));
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

		glBindVertexArray(testmesh.vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(testmesh2.vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		SDL_GL_SwapWindow(window.window);
	}

	return 0;
}
