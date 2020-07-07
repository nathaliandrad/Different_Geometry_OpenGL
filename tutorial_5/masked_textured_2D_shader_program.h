#pragma once

#include "shader_program.h"
#include "texture.h"

#include <glm/mat4x4.hpp>

#include <vector>

class Mesh;
struct Configuration;

class Masked_Textured_2D_Shader_Program : public Shader_Program
{
public:
	Masked_Textured_2D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader);
	~Masked_Textured_2D_Shader_Program();

	void render(const Configuration* config, const Mesh* mesh, const Texture* texture, const Texture* mask, const glm::mat4* transformation) const;
};
