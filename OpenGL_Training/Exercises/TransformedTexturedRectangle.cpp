#include "Exercises.hpp"

void OpenGL_Training::Exercises::transformedTexturedRectangle()
{
	ApplicationWindow appWindow = ApplicationWindow("Transformed Textured Rectangle");

	Shader shaders = Shader("TransformedTexture_vertex.glsl", "Texture_fragment.glsl");

	while (appWindow.handleEvents())
	{

		appWindow.swapBuffers();
		appWindow.sleep();
	}
}