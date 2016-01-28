#pragma once

#define GLSL(src) "#version 150 core\n" #src

#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace awcutil
{
	namespace gl
	{

		class Shader
		{
		public:
			Shader(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource = nullptr);
			~Shader();
			Shader &use();

			void    setFloat(const GLchar *name, GLfloat value, GLboolean useShader = false);
			void    setInteger(const GLchar *name, GLint value, GLboolean useShader = false);
			void    setVector2f(const GLchar *name, GLfloat x, GLfloat y, GLboolean useShader = false);
			void    setVector2f(const GLchar *name, const glm::vec2 &value, GLboolean useShader = false);
			void    setVector3f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader = false);
			void    setVector3f(const GLchar *name, const glm::vec3 &value, GLboolean useShader = false);
			void    setVector4f(const GLchar *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader = false);
			void    setVector4f(const GLchar *name, const glm::vec4 &value, GLboolean useShader = false);
			void    setMatrix4(const GLchar *name, const glm::mat4 &matrix, GLboolean useShader = false);

			GLuint id;

		};

	}
}
