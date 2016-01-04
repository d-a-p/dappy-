#pragma once

#include"../../renderable2d.h"



namespace dappy {
	namespace graphics {
		
		
		class Group:public Renderable2D	{
		private:
			std::vector<Renderable2D*> m_Renderable;
			math::mat4 m_TransformationMat;

		public:
			Group(const math::mat4& transform);
			void add(Renderable2D* renderable);
			void submit(Renderer2D* renderer)const override;


		};


	}
}