#include"Tile.h"

namespace dappy {
	namespace graphics {

		Tile::Tile(Shader* shad):
		Layer(new BatchRenderer2D(), shad, math::mat4::orthographic(-16.0f,16.0f,-9.0f,9.0f,-3.0f,3.0f)), m_Shader(shad)
		{
			
		}
		Tile::~Tile()
		{

		}

	}
}