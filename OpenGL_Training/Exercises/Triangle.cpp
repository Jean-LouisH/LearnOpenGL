#include "Exercises.hpp"

void OpenGL_Training::Exercises::triangle()
{
	ApplicationWindow appWindow = ApplicationWindow("Triangle");

	//Although a 2D shape, the triangle's z-axis is 
	// still accounted for in GL functions
	float triangleVertices[] = 
	{
	//   x      y     z
		-0.5f, -0.5f, 0.0f, //lower left point
		 0.5f, -0.5f, 0.0f, //lower right point
		 0.0f,  0.5f, 0.0f  //top middle point
	};

	while (appWindow.handleEvents())
	{
		appWindow.swapBuffers();
	}
}