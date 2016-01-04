//
// this file is created by DAP...
//


#include"shader.h"
#include"../utils/utils_file.h"
#include<vector>

using namespace dappy;
using namespace graphics;


Shader::Shader(const char * vertPath, const char * fragPath)
	: m_vertPath(vertPath),m_fragPath(fragPath)
{
	m_shadarID = load();
}

dappy::graphics::Shader::~Shader()
{
	glDeleteProgram(m_shadarID);
}

void dappy::graphics::Shader::enable() const
{
	glUseProgram(m_shadarID);
}

void dappy::graphics::Shader::disable() const
{
	glUseProgram(0);
}

GLint dappy::graphics::Shader::load()
{
	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	
	std::string vertsource = dappy::read_file(m_vertPath);
	std::string fragsource = dappy::read_file(m_fragPath);

	const char* vert = vertsource.c_str();
	const char* frag = fragsource.c_str();
																					  // for vertex shader
	glShaderSource(vertex, 1, &vert, NULL);
	glCompileShader(vertex);

	GLint result;
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
	
	if (result == GL_FALSE)
	{
		GLint length;
		glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> error(length);
		glGetShaderInfoLog(vertex,length,&length,&error[0]);
		std::cout << "FAILED TO COMPILE 'VERTEX' SHADER!!!..." << std::endl;
		for (char i : error)
			std::cout << i;

		glDeleteShader(vertex);
		return 0;
	}


																						// for fragment shader
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragment, 1, &frag, NULL);
	glCompileShader(fragment);

	
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

	if (result == 0)
	{
		GLint length;
		glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> error(length);
		glGetShaderInfoLog(fragment, length, &length, &error[0]);
		std::cout << "FAILED TO COMPILE 'FRAGMENT' SHADER!!!..."  << std::endl;
		for (char i : error)
			std::cout << i;

		glDeleteShader(fragment);
		return 0;
	}
	
	GLuint program = glCreateProgram();

	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vertex);
	glDeleteShader(fragment);	
	
	return program;
}

void dappy::graphics::Shader::setUniform1i(const GLchar * name, int value)
{
	glUniform1i(getUniformLocation(name), value);
}

void dappy::graphics::Shader::setUniform1iv(const GLchar * name, int * value, int count)
{
	glUniform1iv(getUniformLocation(name), count, value);
}

void dappy::graphics::Shader::setUniform1f(const GLchar * name, float value)
{
	glUniform1f(getUniformLocation(name), value);

}

void dappy::graphics::Shader::setUniform1fv(const GLchar * name, float * value, int count)
{
	glUniform1fv(getUniformLocation(name), count, value);

}

void dappy::graphics::Shader::setUniform2f(const GLchar * name, const math::vec2 & vector)
{
	glUniform2f(getUniformLocation(name), vector.x, vector.y);

}

void dappy::graphics::Shader::setUniform3f(const GLchar * name, const math::vec3 & vector)
{
	glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);

}

void dappy::graphics::Shader::setUniform4f(const GLchar * name, const math::vec4 & vector)
{
	glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);

}

void dappy::graphics::Shader::setUniformMat4(const GLchar * name, const math::mat4 & matrix)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);

}



