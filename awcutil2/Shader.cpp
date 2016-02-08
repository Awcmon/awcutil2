#include "Shader.h"

namespace awcutil
{
	namespace gl
	{
		Shader::Shader()
		{

		}

		Shader::Shader(const GLchar * vertexSource, const GLchar * fragmentSource, const GLchar * geometrySource)
		{
			compile(vertexSource, fragmentSource, geometrySource);
		}

		Shader::~Shader()
		{
			glDeleteProgram(id);
		}

		void Shader::compile(const GLchar * vertexSource, const GLchar * fragmentSource, const GLchar * geometrySource)
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

		Shader & Shader::use()
		{
			glUseProgram(id);
			return *this;
		}

		void Shader::setFloat(const GLchar *name, GLfloat value, GLboolean useShader)
		{
			if (useShader)
				use();
			glUniform1f(glGetUniformLocation(id, name), value);
		}
		void Shader::setInteger(const GLchar *name, GLint value, GLboolean useShader)
		{
			if (useShader)
				use();
			glUniform1i(glGetUniformLocation(id, name), value);
		}
		void Shader::setVector2f(const GLchar *name, GLfloat x, GLfloat y, GLboolean useShader)
		{
			if (useShader)
				use();
			glUniform2f(glGetUniformLocation(id, name), x, y);
		}
		void Shader::setVector2f(const GLchar *name, const glm::vec2 &value, GLboolean useShader)
		{
			if (useShader)
				use();
			glUniform2f(glGetUniformLocation(id, name), value.x, value.y);
		}
		void Shader::setVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader)
		{
			if (useShader)
				use();
			glUniform3f(glGetUniformLocation(id, name), x, y, z);
		}
		void Shader::setVector3f(const GLchar *name, const glm::vec3 &value, GLboolean useShader)
		{
			if (useShader)
				use();
			glUniform3f(glGetUniformLocation(id, name), value.x, value.y, value.z);
		}
		void Shader::setVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader)
		{
			if (useShader)
				use();
			glUniform4f(glGetUniformLocation(id, name), x, y, z, w);
		}
		void Shader::setVector4f(const GLchar *name, const glm::vec4 &value, GLboolean useShader)
		{
			if (useShader)
				use();
			glUniform4f(glGetUniformLocation(id, name), value.x, value.y, value.z, value.w);
		}
		void Shader::setMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader)
		{
			if (useShader)
				use();
			glUniformMatrix4fv(glGetUniformLocation(id, name), 1, GL_FALSE, glm::value_ptr(matrix));
		}

	}
}
