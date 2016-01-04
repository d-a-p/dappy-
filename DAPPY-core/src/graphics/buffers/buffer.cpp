#include"buffer.h"

namespace dappy {

	namespace graphics {




		Buffer::Buffer(GLfloat * data, GLsizei count, GLuint componentcount)
			: m_Componentcount(componentcount)
		{
			glGenBuffers(1, &m_BufferId);
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
			glBufferData(GL_ARRAY_BUFFER, count*sizeof(GLfloat), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER,0);

		}

		Buffer::~Buffer()
		{
			glDeleteBuffers(1, &m_BufferId);
		}


		void Buffer::bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
		}

		void Buffer::unbind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

	}
}