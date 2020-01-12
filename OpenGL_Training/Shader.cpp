#include "Shader.hpp"
#include <GL/glew.h>
#include <iostream>
#include "ShaderFileLoader.hpp"

OpenGL_Training::Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
{
	const char* vertexShaderSource = ShaderFileLoader::load(vertexShaderPath);
	const char* fragmentShaderSource = ShaderFileLoader::load(fragmentShaderPath);

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	int vertexShaderCompilationSuccess;
	char vertexShaderInfoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexShaderCompilationSuccess);
	if (!vertexShaderCompilationSuccess)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, vertexShaderInfoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED " << vertexShaderInfoLog << std::endl;
	}

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	int fragmentShaderCompilationSuccess;
	char fragmentShaderInfoLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentShaderCompilationSuccess);
	if (!fragmentShaderCompilationSuccess)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, fragmentShaderInfoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED " << fragmentShaderInfoLog << std::endl;
	}

	this->programID = glCreateProgram();

	glAttachShader(this->programID, vertexShader);
	glAttachShader(this->programID, fragmentShader);
	glLinkProgram(this->programID);

	int programLinkSuccess;
	char programInfoLog[512];
	glGetProgramiv(this->programID, GL_LINK_STATUS, &programLinkSuccess);
	if (!programLinkSuccess)
	{
		glGetProgramInfoLog(this->programID, 512, NULL, programInfoLog);
		std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED " << programInfoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

OpenGL_Training::Shader::~Shader()
{
	glDeleteProgram(this->programID);
}

/**Disclaimer, Author: Jtaim. A Disquis user in the LearnOpenGL Shader tutorial comment section
Reference: https://learnopengl.com/Getting-started/Shaders#comment-4468935635 */
void OpenGL_Training::Shader::getUniforms() 
{
	int how_many{};
	int bufsize{}; // max name size
	glGetProgramiv(programID, GL_ACTIVE_UNIFORMS, &how_many);
	glGetProgramiv(programID, GL_ACTIVE_UNIFORM_MAX_LENGTH, &bufsize);

	for (int i{}; i < how_many; ++i) 
	{
		GLenum type{};
		int size{};
		std::unique_ptr<char> name(new char[bufsize]);

		glGetActiveUniform(programID, i, bufsize, nullptr, &size, &type, name.get());
		std::cout << "Active uniform: \"" << name << "\"\n"
			<< "Location: " << glGetUniformLocation(programID, name.get()) << "\n"
			<< "Type: " << type << "\n\n";
	}
}

void OpenGL_Training::Shader::use()
{
	glUseProgram(this->programID);
}

void OpenGL_Training::Shader::setBool(const char* name, bool value)
{
	glUniform1i(glGetUniformLocation(this->programID, name), (int)value);
}

void OpenGL_Training::Shader::setInt(const char* name, int value)
{
	glUniform1i(glGetUniformLocation(this->programID, name), value);
}

void OpenGL_Training::Shader::setFloat(const char* name, float value)
{
	glUniform1f(glGetUniformLocation(this->programID, name), value);
}