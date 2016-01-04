#pragma once
#include"renderer2d.h"
#include"../graphics/buffers/indexbuffer.h"
#include"renderable2d.h"

#include"../../ext/Freetype-gl/freetype-gl.h"

namespace dappy {
	namespace graphics {

#define R_MAX_SPRITE	60000
#define R_VERTEX_SIZE	 sizeof(VertexData)
#define R_SPRITE_SIZE	R_VERTEX_SIZE * 4
#define R_BUFFER_SIZE	R_MAX_SPRITE * R_SPRITE_SIZE
#define R_INDICES_SIZE	R_MAX_SPRITE * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_TEX_INDEX 1
#define SHADER_TID_INDEX 2
#define SHADER_COLOR_INDEX 3



		class BatchRenderer2D :public Renderer2D 
		{
			
		private:
			unsigned char flag; // to handle begin() and end() inclusive in submit() and flush()

			GLuint m_VAO;
			GLuint m_VBO;
			VertexData* m_Buffer;
			GLsizei m_IndexCount;
			void init();
			ftgl::texture_atlas_t* m_Atlas;
			ftgl::texture_font_t	* m_Font;

			std::vector<GLuint> m_TextureSlot;
		public:
			IndexBuffer* m_IBO;
			BatchRenderer2D();
			~BatchRenderer2D();
			void begin()override;
			void end()override;
			void flush()override;
			void submit(const Renderable2D* renderable)override;
			void renderText(const std::string &, const math::vec3 &, const  math::vec4&) override;


		};


	}
}
