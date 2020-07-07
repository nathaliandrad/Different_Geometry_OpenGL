#include "hexa_boy.h"
#include "colored_2D_shader_program.h"
#include "assets.h"

#define GLEW_STATIC
#include <glew.h>

#include <vector>
#include <math.h>

Hexa_Boy::Hexa_Boy(const char* id)
	: Game_Object(id)
{
	_total_time = 0;

}
Hexa_Boy::~Hexa_Boy()
{
}


void Hexa_Boy::simulate_AI(const double, const Assets*, const Scene*, const Configuration*, const Input*)
{

}
void Hexa_Boy::render(const double s, const Assets* assets, const Scene* scene, const Configuration* config)
{
	static double time = 0;
	time -= s;

	std::vector<GLfloat> colors =
	{
		//right triangle
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f, 1.0f,
		//top right
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		//bottom left
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		//left
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 1.0f, 1.0f,
	};

	const Colored_2D_Shader_Program* program = (Colored_2D_Shader_Program*)assets->get_asset("Shader_Program.2D.Colored");
	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Hexagon");

	glm::mat4 trans = transformation(scene, config);

	program->render(config, mesh, &colors, &trans);
}