#pragma once

#include<deque>
#include"renderer2d.h"
#include"static_sprite.h"

namespace dappy { namespace graphics {

		class Simple2DRenderer:public Renderer2D 
		{

		private:
			std::deque< const StaticSprite* > m_RendererQueue;

		protected:
		public:
			virtual void submit(const Renderable2D* ) override;
			virtual void flush() override;

		};




} }