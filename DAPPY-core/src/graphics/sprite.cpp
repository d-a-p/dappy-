#include"sprite.h"

using namespace dappy;
using namespace graphics;

Sprite::Sprite(float x, float y, float width, float height, const math::vec4& color)
	: Renderable2D(math::vec3(x, y, 0), math::vec2(width, height), color)
{}

Sprite::Sprite(float x, float y, float width, float height, Texture* tex)
	: Renderable2D(math::vec3(x, y, 0), math::vec2(width, height), math::vec4(1,1,1,1))
{
	m_Texture = tex;
}