#include "Exercises.hpp"

void OpenGL_Training::Exercises::triangle()
{
	ApplicationWindow appWindow = ApplicationWindow("Triangle");

	while (appWindow.handleEvents())
	{
		appWindow.swapBuffers();
	}
}