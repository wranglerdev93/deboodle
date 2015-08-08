#pragma once

#include <string>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

namespace Wrangler {

	class GLSLProgram
	{
		public:
			GLSLProgram();
			~GLSLProgram();

			void compileShaders(const std::string& vertexShaderFilepath, const std::string& fragmentShaderFilepath);
			void compileShadersFromSource(const char* vertexSource, const char* fragmentSource);
			void linkShaders();
			void addAttribute(const std::string& attributeName);

			GLint getUniformLocation(const std::string& uniformName);

			void use();
			void unuse();

			void dispose();

		private:
			GLuint _programID;
			int _numAttributes;
			void compileShader(const char* source, const std::string& name, GLuint id);
			GLuint _vertexShaderID;
			GLuint _fragmentShaderID;
	};

}
