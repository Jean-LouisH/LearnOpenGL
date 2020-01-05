#include "Exercises.hpp"

void OpenGL_Training::Exercises::triangle()
{
	ApplicationWindow appWindow = ApplicationWindow("Triangle");

	//Although a 2D shape, the triangle's z-axis is 
	// still accounted for in GL functions
	float triangleVertices[] = 
	{
		//x      y     z
		-0.5f, -0.5f, 0.0f, //lower left point
		 0.5f, -0.5f, 0.0f, //lower right point
		 0.0f,  0.5f, 0.0f  //top middle point
	};

	unsigned int vertexBufferObject;
	unsigned int vertexArrayObject;
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);
	glGenBuffers(1, &vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

	const char* vertexShaderSource = R"(
		#version 330 core
		layout (location = 0) in vec3 aPos;

		void main()
		{
			gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
		}
	)";

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

	const char* fragmentShaderSource = R"(
		#version 330 core
		out vec4 FragColor;
	
		void main()
		{
			FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
		}
	)";

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

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int programLinkSuccess;
	char programInfoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &programLinkSuccess);
	if (!programLinkSuccess)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, programInfoLog);
		std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED " << programInfoLog << std::endl;
	}

	glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glClearColor(0.0f, 0.0f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	while (appWindow.handleEvents())
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
		appWindow.swapBuffers();
	}
}