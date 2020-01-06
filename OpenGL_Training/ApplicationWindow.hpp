#pragma once

#include <SDL.h>
#include "Timing.hpp"
#include <string>

#define FRAME_TIME_ms 17

namespace OpenGL_Training
{
	class ApplicationWindow
	{
	private:
		SDL_Window* window;
		SDL_GLContext context;
		Timing time;
		int windowWidth;
		int windowHeight;
	public:
		ApplicationWindow(std::string appName);
		~ApplicationWindow();
		bool handleEvents();
		void swapBuffers();
		void sleep();
	};
}
