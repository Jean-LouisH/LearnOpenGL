#include "ApplicationWindow.hpp"
#include <SDL_events.h>
#include <GL/glew.h>

OpenGL_Training::ApplicationWindow::ApplicationWindow(std::string appName)
{
	std::string displayedAppName = "OpenGL Training Exercise: " + appName;
	this->windowWidth = 800;
	this->windowHeight = 600;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log(
			"SDL could not initialize because: %s",
			SDL_GetError());
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	this->window = SDL_CreateWindow(
		displayedAppName.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		windowWidth,
		windowHeight,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	if (this->window == NULL)
	{
		SDL_Log(
			"SDL could not create the window because: %s",
			SDL_GetError());
	}

	this->context = SDL_GL_CreateContext(window);
	SDL_GL_SetSwapInterval(0);
	glewInit();
	glViewport(0, 0, this->windowWidth, this->windowHeight);
}

OpenGL_Training::ApplicationWindow::~ApplicationWindow()
{
	SDL_GL_DeleteContext(this->context);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

bool OpenGL_Training::ApplicationWindow::handleEvents()
{
	SDL_Event SDLEvents;
	bool isRunning = true;

	while (SDL_PollEvent(&SDLEvents))
	{
		switch (SDLEvents.type)
		{
			/*Close window button*/
		case SDL_QUIT:
			isRunning = false;
			break;

			/*Keyboard inputs*/
		case SDL_KEYDOWN:
			if (SDLEvents.key.keysym.sym == SDLK_ESCAPE)
			{
				isRunning = false;
			}
			else if (SDLEvents.key.keysym.sym < 128) //ASCII values are below 128.
			{
				;
			}
			break;

		case SDL_KEYUP:
			if (SDLEvents.key.keysym.sym < 128)
			{
				;
			}
			else if (SDLEvents.key.keysym.sym == SDLK_F1)
			{
				SDL_SetWindowSize(this->window, 800, 600);
				SDL_SetWindowPosition(this->window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
			}
			break;
		}
	}

	//Register any window dimension changes and resize the glViewport accordingly.
	SDL_GetWindowSize(this->window, &this->windowWidth, &this->windowHeight);
	glViewport(0, 0, this->windowWidth, this->windowHeight);

	return isRunning;
}

void OpenGL_Training::ApplicationWindow::swapBuffers()
{
	time.cycleEnd = SDL_GetTicks();
	time.cycleDelta = time.cycleEnd - time.cycleStart;
	time.frameDelay = FRAME_TIME_ms - time.cycleDelta;
	if (time.frameDelay > 0)
		SDL_Delay(time.frameDelay);
	time.frame = SDL_GetTicks() - time.cycleStart;
	SDL_GL_SwapWindow(this->window);
	time.cycleStart = SDL_GetTicks();
}