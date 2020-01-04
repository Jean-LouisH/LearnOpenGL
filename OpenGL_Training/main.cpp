#include "Exercises/Exercises.hpp"

int main(int argc, char* argv[])
{
	enum Exercises
	{
		EXERCISES_EXIT,
		EXERCISES_BLANK
	};

	int demoState = EXERCISES_EXIT;

	do
	{
		std::cout << "\n****************************************";
		std::cout << "\n\t\tOpenGL Training\n\n\tSelect demo";
		std::cout << "\n\n0. Exit";
		std::cout << "\n1. Blank";
		std::cout << "\n\n\tChoice -> ";
		std::cin >> demoState;

		switch (demoState)
		{
			case EXERCISES_EXIT:; break;
			case EXERCISES_BLANK: OpenGL_Training::Exercises::blank(); break;

			default: std::cout << "\nNot an option.";
		}

	} while (demoState != EXERCISES_EXIT);

	return 0;
}