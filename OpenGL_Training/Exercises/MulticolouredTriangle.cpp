#include "Exercises.hpp"

void OpenGL_Training::Exercises::multicolouredTriangle()
{
	ApplicationWindow appWindow = ApplicationWindow("Multicoloured Triangle");

	float triangleVertices[] = {
		// positions         // colors
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
	};

	const char* vertexShaderSource = ShaderFileLoader::load("PositionAndColour_vertex.glsl");
	const char* fragmentShaderSource = ShaderFileLoader::load("PositionAndColour_fragment.glsl");

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

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	unsigned int vertexArrayObject;
	unsigned int vertexBufferObject;
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);
	glGenBuffers(1, &vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glUseProgram(shaderProgram);

	while (appWindow.handleEvents())
	{
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		appWindow.swapBuffers();
		appWindow.sleep();
	}
}