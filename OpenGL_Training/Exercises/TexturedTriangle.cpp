#include "Exercises.hpp"

void OpenGL_Training::Exercises::texturedTriangle()
{
	ApplicationWindow appWindow = ApplicationWindow("Textured Triangle");

	float triangleVertices[] = {
		//x      y     z
		-0.5f, -0.5f, 0.0f, //lower left point
		 0.5f, -0.5f, 0.0f, //lower right point
		 0.0f,  0.5f, 0.0f  //top middle point
	};

	float texCoords[] = {
		0.0f, 0.0f,  // lower-left corner  
		1.0f, 0.0f,  // lower-right corner
		0.5f, 1.0f   // top-center corner
	};

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	//float borderColor[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	//glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

	while (appWindow.handleEvents())
	{
		glClearColor(0.125f, 0.125f, 0.125f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		appWindow.swapBuffers();
		appWindow.sleep();
	}

}