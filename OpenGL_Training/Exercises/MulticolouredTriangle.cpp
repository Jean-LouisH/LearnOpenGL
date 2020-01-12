#include "Exercises.hpp"
#include "../Shader.hpp"

void OpenGL_Training::Exercises::multicolouredTriangle()
{
	ApplicationWindow appWindow = ApplicationWindow("Multicoloured Triangle");

	float triangleVertices[] = {
		// positions         // colors
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
	};

	Shader shaders = Shader(
		"PositionAndColour_vertex.glsl", 
		"PositionAndColourWithSineVariableBrightness_fragment.glsl");

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

	shaders.use();
	shaders.getUniforms();

	while (appWindow.handleEvents())
	{
		float timeValue = SDL_GetTicks() / 1000.0;
		float brightness = (sin(timeValue) / 2.0f) + 0.5f;
		shaders.setFloat("brightness", brightness);

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		appWindow.swapBuffers();
		appWindow.sleep();
	}
}