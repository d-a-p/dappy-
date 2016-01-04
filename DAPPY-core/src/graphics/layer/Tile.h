#pragma once
#include"layer.h"


namespace dappy {
	namespace graphics {


		class Tile :public Layer
		{
		protected:
			
			
			Shader* m_Shader;
			 

		public:
			Tile(Shader* shad);
			~Tile();
			

		};


	}
}
