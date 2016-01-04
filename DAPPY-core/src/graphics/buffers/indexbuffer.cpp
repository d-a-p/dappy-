#include"indexbuffer.h"

namespace dappy {

	namespace graphics {




		IndexBuffer::IndexBuffer(GLushort * data, GLsizei count)
			: m_Count(count)
		{
			glGenBuffers(1, &m_BufferId);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferId);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(GLushort), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		}

		IndexBuffer::~IndexBuffer()
		{
			glDeleteBuffers(1, &m_BufferId);
		}

		void IndexBuffer::bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferId);
		}

		void IndexBuffer::unbind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

	}
}