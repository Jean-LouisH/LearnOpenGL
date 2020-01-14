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

	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	SDL_Surface* surface = IMG_Load("../Textures/container.jpg");

	if (surface->pixels != NULL)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	SDL_FreeSurface(surface);

	while (appWindow.handleEvents())
	{
		glClearColor(0.125f, 0.125f, 0.125f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		appWindow.swapBuffers();
		appWindow.sleep();
	}

}