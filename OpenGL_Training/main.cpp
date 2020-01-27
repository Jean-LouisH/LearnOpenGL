#include "Exercises/Exercises.hpp"
#include <vector>
#include <string>

using namespace OpenGL_Training::Exercises;

int main(int argc, char* argv[])
{
	enum Exercises
	{
		EXERCISES_EXIT,
		EXERCISES_BLANK,
		EXERCISES_TRIANGLE,
		EXERCISES_RECTANGLE,
		EXERCISES_SHADE_CHANGING_TRIANGLE,
		EXERCISES_MULTICOLOURED_TRIANGLE,
		EXERCISES_TEXTURED_RECTANGLE,
		EXERCISES_TRANSFORMED_TEXTURED_RECTANGLE,
	};

	int demoState = EXERCISES_EXIT;

	do
	{
		std::vector<std::string> demos;

		demos.push_back("Exit");
		demos.push_back("Blank");
		demos.push_back("Triangle");
		demos.push_back("Rectangle");
		demos.push_back("Shade Changing Triangle");
		demos.push_back("Multi-coloured Triangle");
		demos.push_back("Textured Rectangle");
		demos.push_back("Transformed Textured Rectangle");

		std::cout << "\n****************************************";
		std::cout << "\n\t\tOpenGL Training\n\n\tSelect demo\n";
		for (int i = 0; i < demos.size(); i++)
			std::cout << "\n" << i << ". " << demos.at(i);
		std::cout << "\n\n\tChoice -> ";
		std::cin >> demoState;

		switch (demoState)
		{
			case EXERCISES_EXIT:; break;
			case EXERCISES_BLANK: blank(); break;
			case EXERCISES_TRIANGLE: triangle(); break;
			case EXERCISES_RECTANGLE: rectangle(); break;
			case EXERCISES_SHADE_CHANGING_TRIANGLE: shadeChangingTriangle(); break;
			case EXERCISES_MULTICOLOURED_TRIANGLE: multicolouredTriangle(); break;
			case EXERCISES_TEXTURED_RECTANGLE: texturedRectangle(); break;
			case EXERCISES_TRANSFORMED_TEXTURED_RECTANGLE: transformedTexturedRectangle(); break;

			default: std::cout << "\nNot an option.";
		}

	} while (demoState != EXERCISES_EXIT);

	return 0;
}