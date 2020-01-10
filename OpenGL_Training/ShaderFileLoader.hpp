#pragma once

#include <gl/glew.h>
#include <string>

namespace ShaderFileLoader
{
	/**File name only, without the file path.*/
	GLchar* load(std::string fileName);
}