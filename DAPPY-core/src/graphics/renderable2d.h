#pragma once

#include"../math/maths.h"
#include"../shader/shader.h"
#include"../graphics/renderer2d.h"
#include"../shader/Texture.h"

namespace dappy {
	namespace graphics {


		struct VertexData
		{
			math::vec3 vertex;
			math::vec2 tex;
			float tid;
			unsigned int color;
		};

		class Renderable2D {

		protected:
			
			math::vec2 m_Size;
			math::vec3 m_Position;
			math::vec4 m_Color;
			std::vector<math::vec2> m_Tex;
			Texture* m_Texture;
			
			void setTexture()
			{
				m_Tex.push_back(math::vec2(0,0));
				m_Tex.push_back(math::vec2(0, 1));
				m_Tex.push_back(math::vec2(1, 1));
				m_Tex.push_back(math::vec2(1, 0));

			}

			Renderable2D(): m_Texture(nullptr) { setTexture(); }
			
		public:

			Renderable2D(math::vec3 position, math::vec2 size, math::vec4 color)
				:m_Position(position), m_Size(size), m_Color(color), m_Texture(nullptr)
			{
				setTexture();
			}

			~Renderable2D() {}	

			virtual void submit(Renderer2D* renderer) const
			{
				renderer->submit(this);
			}
		
			inline const math::vec3& getPosition() const { return m_Position; }
			inline const math::vec2& getSize() const { return m_Size; }
			inline const math::vec4&	 getColor() const { return m_Color; }
			inline const std::vector<math::vec2>& getTex() const { return m_Tex; }
			inline const GLuint getTID() const { return m_Texture ? m_Texture->getID() : 0; }

			

		};
	}
}