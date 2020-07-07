#include "blocky_boy.h"
#include "colored_2D_shader_program.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>

#include <vector>
#include <math.h>

Blocky_Boy::Blocky_Boy(const char* id)
	: Game_Object(id)
{
	_total_time = 0;
}
Blocky_Boy::~Blocky_Boy()
{
}
void Blocky_Boy::simulate_AI(const double, const Assets*, const Scene*, const Configuration*, const Input*)
{

}
void Blocky_Boy::render(const double s, const Assets* assets, const Scene* scene, const Configuration* config)
{
	static double time = 0;
	time -= s;
	std::vector<GLfloat> colors =
	{
		1.f,0.f,1.f,0.6f,
		1.f,0.f,1.f,0.5f,
		0.f,0.f,1.f,0.5f,

		0.f,0.f,1.f,0.5f,
		1.f,0.f,1.f,0.5f,
		1.f,0.f,1.f,0.6f,
		
	};

	const Colored_2D_Shader_Program* program = (Colored_2D_Shader_Program*)assets->get_asset("Shader_Program.2D.Colored");
	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Square");

	glm::mat4 trans = transformation(scene, config);

	program->render(config, mesh, &colors, &trans);
}