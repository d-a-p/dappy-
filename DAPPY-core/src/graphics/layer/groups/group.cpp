#include"group.h"

namespace dappy {
	namespace graphics {


		Group::Group(const math::mat4& transform)
			: m_TransformationMat(transform)
		{

		}

		void Group::submit(Renderer2D* renderer) const
		{
			renderer->push(m_TransformationMat);

			for (const Renderable2D* renderable : m_Renderable)
				renderable->submit(renderer);
		
			renderer->pop();
		}

		void Group::add(Renderable2D* renderable)
		{
			m_Renderable.push_back(renderable);
		}

	}
}