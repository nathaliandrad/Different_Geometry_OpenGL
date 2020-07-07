#include "crazy_cube.h"
#include "colored_3D_shader_program.h"
#include "textured_3D_shader_program.h"
#include "assets.h"
#include "mesh.h"

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtx/transform.hpp>

#define GLEW_STATIC
#include <glew.h>
#include <vector>
#include <math.h>

Crazy_Cube::Crazy_Cube(const char* id)
	: Game_Object(id)
{
}
Crazy_Cube::~Crazy_Cube()
{
}


void Crazy_Cube::simulate_AI(const double, const Assets*, const Scene*, const Configuration*, const Input*)
{

}
void Crazy_Cube::render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config)
{
	static double total_time = 0;
	total_time += seconds_to_simulate;

	_rotation.y = (float)total_time * 2;
	_rotation.z = (float)total_time / 2;
	_rotation.x = (float)total_time / 2;

	const Mesh* mesh = (Mesh*)assets->get_asset("Mesh.Cube");
	glm::mat4 trans = transformation(scene, config);

	const Textured_3D_Shader_Program* program = (Textured_3D_Shader_Program*)assets->get_asset("Shader_Program.3D.Textured");
	const Texture* texture = (Texture*)assets->get_asset("Texture.Crazy.Cube_Texture");
	program->render(config, mesh, texture, &trans);
}