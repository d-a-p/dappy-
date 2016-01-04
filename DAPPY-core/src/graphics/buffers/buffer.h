#pragma once
#include<GL\glew.h>




namespace dappy {
	namespace graphics {

		class Buffer {
		private:
			GLuint m_BufferId;
			GLuint m_Componentcount;
		public:

			Buffer(GLfloat *data, GLsizei count, GLuint componentcount);
			~Buffer();
			void bind()  const;
			void unbind() const;
			GLuint getComponentCount() const { return m_Componentcount; }
		};


	}
}