#version 330 core

layout(location=0) out vec4 color;


//uniform vec4 colour;
uniform vec2 light_pos;
in DATA{

	 vec4 position;
	 vec2 tex;
	 float tid;
	 vec4 color;

}fs_in;

uniform sampler2D txture[8];

void main(){
	
	float intensity = 0.9/ length( fs_in.position.xy - light_pos);
	
	vec4 tcolor = fs_in.color;// * intensity;
	if(fs_in.tid > 0.0)
	{
	 int id = int(fs_in.tid-0.5);
	 tcolor = fs_in.color * texture(txture[id],fs_in.tex) ;
		 
	}  
	color = tcolor ; // * intensity ;
	
}