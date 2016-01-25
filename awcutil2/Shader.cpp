#include "Shader.h"

Shader::Shader(const GLchar * vertexSource, const GLchar * fragmentSource, const GLchar * geometrySource)
{
	GLuint vertexShader, fragmentShader, geometryShader;

	// Create and compile the vertex shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	// Create and compile the fragment shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	if (geometrySource != nullptr)
	{
		geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geometryShader, 1, &geometrySource, NULL);
		glCompileShader(geometryShader);
	}

	// Link the vertex and fragment shader into a shader program
	id = glCreateProgram();
	glAttachShader(id, vertexShader);
	glAttachShader(id, fragmentShader);
	if (geometrySource != nullptr)
	{
		glAttachShader(id, geometryShader);
	}
	//glBindFragDataLocation(id, 0, "outColor");
	glLinkProgram(id);

	//Delete the shaders
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	if (geometrySource != nullptr)
	{
		glDeleteShader(geometryShader);
	}
}

Shader::~Shader()
{
	glDeleteProgram(id);
}

Shader & Shader::use()
{
	glUseProgram(id);
	return *this;
}
