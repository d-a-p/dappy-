#pragma once

#include"renderable2d.h"

namespace dappy {
	namespace graphics {


		class Sprite :public Renderable2D
		{
		public:

			Sprite(float x, float y, float width, float height, const math::vec4& color);
			Sprite(float x, float y, float width, float height, Texture*);


		};


	}
}