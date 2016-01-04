#include"BatchRenderer2D.h"


namespace dappy {
	namespace graphics {

		BatchRenderer2D::BatchRenderer2D()
		{
			init();
			flag = 0;
		}

		BatchRenderer2D::~BatchRenderer2D()
		{
			delete m_IBO;
			glDeleteBuffers(1, &m_VBO);

		}

		void BatchRenderer2D::init()
		{
			glGenVertexArrays(1, &m_VAO);
			glGenBuffers(1, &m_VBO);

			glBindVertexArray(m_VAO);
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			glBufferData(GL_ARRAY_BUFFER, R_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

			glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
			glEnableVertexAttribArray(SHADER_TEX_INDEX);
			glEnableVertexAttribArray(SHADER_TID_INDEX);
			glEnableVertexAttribArray(SHADER_COLOR_INDEX);

			glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, R_VERTEX_SIZE, (const void*)0);
			glVertexAttribPointer(SHADER_TEX_INDEX, 2, GL_FLOAT, GL_FALSE, R_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::tex)));
			glVertexAttribPointer(SHADER_TID_INDEX, 1, GL_FLOAT, GL_FALSE, R_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::tid)));
			glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, R_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::color)));
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			GLushort* indices = new GLushort[R_INDICES_SIZE];


			int offset = 0;
			for (int i = 0; i < R_INDICES_SIZE; i += 6)
			{
				indices[i] = offset;
				indices[i + 1] = offset + 1;
				indices[i + 2] = offset + 2;

				indices[i + 3] = offset + 2;
				indices[i + 4] = offset + 3;
				indices[i + 5] = offset;
				offset += 4;
			}

			m_IBO = new IndexBuffer(indices, R_INDICES_SIZE);

			glBindVertexArray(0);

			m_Atlas = ftgl::texture_atlas_new(512, 512, 3);
			m_Font = ftgl::texture_font_new_from_file(m_Atlas, 32, "arial.ttf");

			
		}											 

		void BatchRenderer2D::begin()
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
			
			if (flag == 1)
				printf(" begin() in Betchrenderer2D is called\n");
			flag = 1;

		

		}

		void BatchRenderer2D::end()
		{
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);	
			
			if(flag==0)
				printf(" end() in Betchrenderer2D is called\n");
			flag = 0;
			
			
		}
		
		void BatchRenderer2D::submit(const Renderable2D* renderable)
		{
			if (flag == 0)
			{
				begin();
			}
			
			const math::vec3& position = renderable->getPosition();
			const math::vec2& size = renderable->getSize();
			const math::vec4& color = renderable->getColor();
			const std::vector<math::vec2>& tex = renderable->getTex();
			const GLuint tid = renderable->getTID();

			unsigned int col = 1;
			
			float slot = 0.0f;
			if (tid>0)
			{

				bool found=false;
				for (int i = 0; i < m_TextureSlot.size(); i++)
				{
					if (m_TextureSlot.at(i) == tid)
					{
						slot = (float)(i + 1);
						found = true;
						break;
					}
				}

				if (!found)
				{
					if (m_TextureSlot.size() >= 32)
					{
						end();
						flush();
						begin();
					}

					m_TextureSlot.push_back(tid);
					slot = (float)(m_TextureSlot.size());
				}


				
			}
		//	else
			//{

			int r = color.x*255.0f;
			int g = color.y*255.0f;
			int b = color.z*255.0f;
			int a = color.w*255.0f;
			 col = a << 24 | b << 16 | g << 8 | r;
			//}
			
			m_Buffer->vertex = *Stackback * position;
			m_Buffer->tex = tex[0];
			m_Buffer->tid = slot;
			m_Buffer->color = col;
			m_Buffer++;

			m_Buffer->vertex = *Stackback * math::vec3(position.x,position.y+size.y,position.z);
			m_Buffer->tex = tex[1];
			m_Buffer->tid = slot;
			m_Buffer->color = col;
			m_Buffer++;

			m_Buffer->vertex = *Stackback * math::vec3(position.x + size.x, position.y + size.y, position.z);
			m_Buffer->tex = tex[2];
			m_Buffer->tid = slot;
			m_Buffer->color = col;
			m_Buffer++;

			m_Buffer->vertex = *Stackback * math::vec3(position.x + size.x, position.y, position.z);
			m_Buffer->tex = tex[3];
			m_Buffer->tid = slot;
			m_Buffer->color = col;
			m_Buffer++;
			  
			m_IndexCount += 6;

			
		}

		void BatchRenderer2D::flush(){
		
			if (flag == 1)
			{
				end();
			}
			
			for (int i = 0; i < m_TextureSlot.size(); i++)
			{
				glActiveTexture(GL_TEXTURE0 + i);
				glBindTexture(GL_TEXTURE_2D, m_TextureSlot[i]);
			}

			glBindVertexArray(m_VAO);
			m_IBO->bind();

			glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_SHORT, NULL);

			m_IBO->unbind();
			glBindVertexArray(0);

			m_IndexCount = 0;

			
			
			if (glGetError() != 0)
			{
				std::cout << "    flush()" << std::endl;
			//	system("pause");
			}
		}

		void BatchRenderer2D::renderText(const std::string &text, const math::vec3 &position, const  math::vec4&color)
		{
			using namespace ftgl;

			int r = color.x*255.0f;
			int g = color.y*255.0f;
			int b = color.z*255.0f;
			int a = color.w*255.0f;
			unsigned int col = a << 24 | b << 16 | g << 8 | r;

			
			float slot = 0.0f;
			bool found = false;
				for (int i = 0; i < m_TextureSlot.size(); i++)
				{
					if (m_TextureSlot.at(i) == m_Atlas->id)
					{
						slot = (float)(i + 1);
						found = true;
						break;
					}
				}

				if (!found)
				{
					if (m_TextureSlot.size() >= 32)
					{
						end();
						flush();
						begin();
					}

					m_TextureSlot.push_back(m_Atlas->id);
					slot = (float)(m_TextureSlot.size());
				}

				float x = position.x;
				float scaleX = 960.0 / 32.0;
				float scaleY = 540.0 / 18.0;


				for (int i = 0; i < text.length();i++)
			{
				 
				ftgl::texture_glyph_t* glyph = ftgl::texture_font_get_glyph(m_Font, &text[i]);
			
				
				if (glyph != NULL)
				{

					if (i>0)
					{
						float kerning = texture_glyph_get_kerning(glyph, &text[i-1]);
						x += kerning / scaleX;
						
					}

					float x0 = x + glyph->offset_x / scaleX;
					float y0 = position.y + glyph->offset_y / scaleY;
					float x1 = x0 + glyph->width / scaleX;
					float y1 = y0 - glyph->height / scaleX;

					float u0 = glyph->s0;
					float u1 = glyph->s1;
					float v0 = glyph->t0;
					float v1 = glyph->t1;
						


						m_Buffer->vertex = *Stackback * math::vec3(x0, y0, 0);
						m_Buffer->tex = math::vec2(u0,v0);
						m_Buffer->tid = slot;
						m_Buffer->color = col;
						m_Buffer++;

						m_Buffer->vertex = *Stackback * math::vec3(x0, y1, 0);
						m_Buffer->tex = math::vec2(u0, v1);
						m_Buffer->tid = slot;
						m_Buffer->color = col;
						m_Buffer++;

						m_Buffer->vertex = *Stackback * math::vec3(x1, y1, 0);
						m_Buffer->tex = math::vec2(u1, v1);
						m_Buffer->tid = slot;
						m_Buffer->color = col;
						m_Buffer++;

						m_Buffer->vertex = *Stackback * math::vec3(x1, y0, 0);
						m_Buffer->tex = math::vec2(u1, v0);
						m_Buffer->tid = slot;
						m_Buffer->color = col;
						m_Buffer++;

						m_IndexCount += 6;

						x += glyph->advance_x / scaleX;
				}
				
			}

			
			
		}


	}
}
