// This is Created by DAP...


#include"src/graphics/window.h"

#include<time.h>
#include<vector>
#include"src\math\maths.h"
#include"src\shader\shader.h"
#include"src\graphics\renderable2d.h"
#include"src\graphics\sprite.h"
#include"src\graphics\BatchRenderer2D.h"
#include"src/utils/timer.h"


#include"src/graphics/layer/Tile.h"
#include"src\graphics\layer/layer.h"
#include"src/graphics/layer/groups/group.h"
#include<GL\GL.h>
#include"src\shader\Texture.h"
#include"src/graphics/label/label.h"
int main()
{
	using namespace dappy;
	using namespace graphics;
	using namespace math;


	srand(time(NULL));
	Window window("dappy", 800,600);
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	//Shader* sr = new Shader("src/shader/basic.vert", "src/shader/basic.frag");
	//Shader& shader = *sr;
	
	Shader* sr2 = new Shader("src/shader/basic2.vert", "src/shader/basic2.frag");
	Shader& shader2 = *sr2;
	Shader* sr3 = new Shader("src/shader/basic2.vert", "src/shader/basic2.frag");
	Shader& shader3 = *sr3;

	//shader.enable();
	//shader.setUniformMat4("pr_matrix", ortho);	  

	Timer timer;

	
	glActiveTexture(GL_TEXTURE0);
	
	Texture* txtr =new Texture("C:\\Users\\DAP\\Desktop\\a.png");
	Texture* txtrr = new Texture("C:\\Users\\DAP\\Desktop\\d.png");

	GLint Texid[] = { 0,1,2,3,4,5,6,7 };
	shader2.enable();
	shader2.setUniform1iv("txture", Texid, 8);
	
	shader3.enable();
	shader2.setUniform1iv("txture", Texid, 8);

	

	float time = 0;
	unsigned int fps=0;

	
	
	Tile layer(&shader2),txtlayer(&shader3);
	
	for (int i = -9.0; i < 9.0; i++)
		for (int j = -16.0; j < 16.0; j++)
		{
			if(rand()%4)
				layer.add(new Sprite(j, i, 0.9, 0.9, math::vec4(rand() % 1000 / 1000.0, 1, 0, 1)));
			else if(rand()%2)
					layer.add(new Sprite(j, i, 0.9, 0.9, txtrr));
				else
					layer.add(new Sprite(j, i, 0.9, 0.9, txtr));

		}
	
	Group *text = new Group(math::mat4::translation(math::vec3(11.9, -8.9, 0.0)));
	text->add(new Sprite(0,0, 3.5, 1.3, math::vec4(0.1, 0.1, 0.1, 0.8)));
	Label *dap = new Label("Hi", 0.1, 0.3, math::vec4(0, 1, 0, 1));
	text->add(dap);
	txtlayer.add(text);
	
	while (!window.Closed())
	{
		
		using namespace std;
		double xx, yy;
		window.clear();
		window.getMouseposs(xx, yy);
		xx = (float)xx*32.0 / 860.0 - 15.0;
		yy = 9.0 - yy*17.0 / 540.0;

		mat4 mat = math::mat4::rotation(timer.elapsed()*25.0f, math::vec3(0.0, 0, 0.5));
		mat4 mat2 = math::mat4::rotation(timer.elapsed()*55.0f, math::vec3(0, 0, 1));

		shader2.enable();
		shader2.setUniformMat4("ml_matrix", mat);
		shader2.setUniform2f("light_pos", vec2(xx, yy));
		shader3.enable();
		shader3.setUniform2f("light_pos", vec2(xx, yy));
		
		
	
	


		layer.render();
		txtlayer.render();
		
		
		
		window.update();
		
		fps++;
		if (timer.elapsed() - time > 1)
		{
			time += 1;
			dap->m_String = std::to_string(fps);
			printf("fps :  %d\n", fps);
			fps = 0;
		}
	}
	delete txtr;
	delete txtrr;

	//system("pause");
	
}

