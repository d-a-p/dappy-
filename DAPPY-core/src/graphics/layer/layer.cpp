#include"layer.h"


namespace dappy {
	namespace graphics {

		Layer::Layer(Renderer2D* rendr, Shader* shad, const math::mat4& proj_mat):
		   m_Renderer(rendr),m_Shader(shad),m_Prmatrix(proj_mat)
		{

			m_Shader->enable();
			m_Shader->setUniformMat4("pr_matrix", m_Prmatrix);
			m_Shader->disable();

		}

		Layer::~Layer() {
			delete m_Renderer;
			delete m_Shader;
			for (auto i : m_Renderable)
				delete i;
		}

		void Layer::add(Renderable2D* rend)
		{
			m_Renderable.push_back(rend);
		}

		void Layer::render()
		{
			m_Shader->enable();
			
			m_Renderer->begin();
			
			
		//	m_Renderer->push(math::mat4::translation(math::vec3(2, 8, 0)));
			for (const Renderable2D* renderable : m_Renderable)
			{
					renderable->submit(m_Renderer);
				
			}
		//			m_Renderer->pop();
				
			m_Renderer->end();

			m_Renderer->flush();


			
		}

	}
}