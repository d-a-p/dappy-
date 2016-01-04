#pragma once
#include<GL\glew.h>
#include"../math/maths.h"
#include<iostream>

namespace dappy {
	namespace graphics {

		class Shader
		{
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void enable()const;
			void disable() const;


		private:
			GLuint m_shadarID;
			const char *m_vertPath, *m_fragPath;

			GLint load();
			GLint getUniformLocation(const GLchar* name) {
				return glGetUniformLocation(m_shadarID,name);
			}

		public:
			void setUniform1i(const GLchar* name, int value);
			void setUniform1iv(const GLchar* name,int* value , int count);
			void setUniform1f(const GLchar* name, float value);
			void setUniform1fv(const GLchar* name,float* value , int count);
			void setUniform2f(const GLchar* name, const math::vec2& vector);
			void setUniform3f(const GLchar* name, const math::vec3& vector);
			void setUniform4f(const GLchar* name, const math::vec4& vector);
			void setUniformMat4(const GLchar* name, const math::mat4& matrix);








		};


	}
}