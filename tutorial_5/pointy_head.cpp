#include "pointy_head.h"
#include "colored_2D_shader_program.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>

#include <vector>
#include <math.h>

Pointy_Head::Pointy_Head(const char* id)
	: Game_Object(id)
{
	_total_time = 0;
}
Pointy_Head::~Pointy_Head()
{
}


void Pointy_Head::simulate_AI(const double, const Assets*, const Scene*, const Configuration*,const Input*)
{

}
void Pointy_Head::render(const double s, const Assets* assets, const Scene* scene, const Configuration* config)
{
	static double time = 0;
	time += s;

	std::vector<GLfloat> colors =
	{
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
	
	};

	const Colored_2D_Shader_Program* program = (Colored_2D_Shader_Program*)assets->get_asset("Shader_Program.2D.Colored");
	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Triangle");

	glm::mat4 trans = transformation(scene, config);

	program->render(config, mesh, &colors, &trans);
}