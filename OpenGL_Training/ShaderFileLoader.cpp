#include "ShaderFileLoader.hpp"
#include <fstream>
#include <iostream>

#ifdef _DEBUG
	#define SHADER_PATH "../Shaders/"
#else
	#define SHADER_PATH "Shaders/"
#endif

GLchar* OpenGL_Training::ShaderFileLoader::load(std::string fileName)
{
	FILE* readFile = fopen((SHADER_PATH + fileName).c_str(), "rb");

	char* text = NULL;
	int fileSize = 0;

	if (readFile != NULL)
	{
		fseek(readFile, 0, SEEK_END);
		fileSize = ftell(readFile);
		rewind(readFile);
		text = (char*) malloc(sizeof(char) * (fileSize + 1));
		if (text != NULL)
		{
			fread(text, sizeof(char), fileSize, readFile);
			text[fileSize] = NULL;
		}
		fclose(readFile);
	}
	return text;
}