#pragma once

#include<GL/glew.h>
#include<string>

namespace dappy {
	namespace graphics {
		
		class Texture {

		private:
			std::string m_Path;
			GLuint m_Tid;
			GLsizei m_Width, m_Height;

			GLuint load();
		public:
			Texture(const std::string& filename);
			~Texture();
			void bind() const;
			void unbine() const;
		
		
			inline const unsigned int getWidth()const { return m_Width; }
			inline const unsigned int getHeight()const { return m_Height; }
			inline const unsigned int getID()const { return m_Tid; }

		};




	}
}