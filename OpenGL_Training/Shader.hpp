#pragma once

#include <glm/glm.hpp>

namespace OpenGL_Training
{
	class Shader
	{
	private:
		unsigned int programID;
	public:
		Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
		~Shader();
		void getUniforms();
		unsigned int getID();
		void use();
		void setBool(const char* name, bool value);
		void setInt(const char* name, int value);
		void setFloat(const char* name, float value);
		void setMat4(const char* name, glm::mat4 transform);
	};
}