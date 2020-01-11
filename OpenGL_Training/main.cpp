#include "Exercises/Exercises.hpp"
#include <vector>
#include <string>

int main(int argc, char* argv[])
{
	enum Exercises
	{
		EXERCISES_EXIT,
		EXERCISES_BLANK,
		EXERCISES_TRIANGLE,
		EXERCISES_RECTANGLE,
	};

	int demoState = EXERCISES_EXIT;

	do
	{
		std::vector<std::string> demos;

		demos.push_back("Exit");
		demos.push_back("Blank");
		demos.push_back("Triangle");
		demos.push_back("Rectangle");

		std::cout << "\n****************************************";
		std::cout << "\n\t\tOpenGL Training\n\n\tSelect demo\n";
		for (int i = 0; i < demos.size(); i++)
			std::cout << "\n" << i << ". " << demos.at(i);
		std::cout << "\n\n\tChoice -> ";
		std::cin >> demoState;

		switch (demoState)
		{
			case EXERCISES_EXIT:; break;
			case EXERCISES_BLANK: OpenGL_Training::Exercises::blank(); break;
			case EXERCISES_TRIANGLE: OpenGL_Training::Exercises::triangle(); break;
			case EXERCISES_RECTANGLE: OpenGL_Training::Exercises::rectangle(); break;

			default: std::cout << "\nNot an option.";
		}

	} while (demoState != EXERCISES_EXIT);

	return 0;
}