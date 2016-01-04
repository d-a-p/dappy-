#pragma once

#include"renderable2d.h"

#include"buffers\buffer.h"
#include"buffers\indexbuffer.h"
#include"buffers\vertexarray.h"

namespace dappy {
	namespace graphics {


		class StaticSprite :public Renderable2D
		{
		public:
			VertexArray* m_VertexArray;
			IndexBuffer* m_IndexBuffer;
			Shader& m_Shader;

			StaticSprite(float x, float y, float width, float height, const math::vec4& color, Shader& shader);

			~StaticSprite()
			{
				delete m_VertexArray;
				delete m_IndexBuffer;
			}

			inline const VertexArray* getVAO() const { return m_VertexArray; }
			inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }
			inline Shader& getShader() const { return m_Shader; }





		};


	}
}