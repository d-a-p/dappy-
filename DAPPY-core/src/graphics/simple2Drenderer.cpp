#include"simple2Drenderer.h"
#include"renderable2d.h"

namespace dappy {
	namespace graphics {


		void Simple2DRenderer::submit(const Renderable2D* renderable)
		{
			m_RendererQueue.push_back((StaticSprite*)renderable);
		}
		void Simple2DRenderer::flush()
		{
			while (!m_RendererQueue.empty()) {

				const StaticSprite* renderable = m_RendererQueue.front();
				renderable->getVAO()->bind();
				renderable->getIBO()->bind();

				renderable->getShader().setUniformMat4("ml_matrix", math::mat4::translation(renderable->getPosition()));
				glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);
																											  
				renderable->getIBO()->unbind();
				renderable->getVAO()->unbind();

				m_RendererQueue.pop_front();
			}
		}




	}
}