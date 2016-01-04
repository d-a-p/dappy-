#pragma once
#include"../renderable2d.h"

namespace dappy {
	namespace graphics {


		class Label:public Renderable2D
		{
		public:
			std::string m_String;
			float x, y;
		public:
			math::vec3&  position;
			
			Label(std::string txt, float x , float y , math::vec4 color)
				: Renderable2D() , m_String(txt) , position(m_Position)
			{
				m_Position = math::vec3(x, y, 0.0);
				m_Color = color;
			}

			void submit(Renderer2D* renderer) const
			{
				renderer->renderText(m_String, math::vec3(position.x, position.y, 0.0), m_Color);
			}

		};


	}
}