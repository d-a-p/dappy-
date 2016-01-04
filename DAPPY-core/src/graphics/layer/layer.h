#pragma once

#include"../renderable2d.h"
#include"../../shader/shader.h"
#include"../renderer2d.h"
#include"../BatchRenderer2D.h"
#include<vector>

namespace dappy {
	namespace graphics {


		class Layer
		{
		protected:
			Renderer2D* m_Renderer;
			std::vector<Renderable2D*> m_Renderable;
			Shader* m_Shader;
			math::mat4 m_Prmatrix;
			Layer(Renderer2D* rendr, Shader* shad,const math::mat4& proj_mat);

		public:
			Layer() = default;
			virtual ~Layer();
			virtual void add(Renderable2D*);
			virtual void render();


		};


	}
}
