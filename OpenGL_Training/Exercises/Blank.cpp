#include "Exercises.hpp"

void blank()
{
	ApplicationWindow appWindow = ApplicationWindow("Blank");

	while (appWindow.handleEvents())
	{
		glClearColor(0.5f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		appWindow.swapBuffers();
	}
}