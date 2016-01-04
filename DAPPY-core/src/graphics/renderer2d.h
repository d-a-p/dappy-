#pragma once

#include<GL\glew.h>
#include"../math/maths.h"
#include<vector>


namespace dappy {
	namespace graphics {

		
		class Renderable2D;

		class Renderer2D {
		
		protected:
			std::vector <math::mat4> m_TransformationStack;
			math::mat4* Stackback;
			Renderer2D()
			{
				m_TransformationStack.push_back(math::mat4::identity());
				Stackback = &m_TransformationStack.back();
			}

		public:

			void push(const math::mat4& mat, bool override = false)
			{
				if(override)
					m_TransformationStack.push_back(mat);
				else
					m_TransformationStack.push_back((*Stackback) * mat);
				Stackback = &m_TransformationStack.back();;
			}
			void pop()
			{
				if (m_TransformationStack.size() > 1)
					m_TransformationStack.pop_back();
				Stackback = &m_TransformationStack.back();;

				//TODO:to log
			}

			virtual void end() = 0;
			virtual void begin() = 0;
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0; 
			virtual void renderText(const std::string &, const math::vec3 &, const  math::vec4&) {}
			
		};



	}
}