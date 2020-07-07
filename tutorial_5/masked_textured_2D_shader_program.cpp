#include "masked_textured_2D_shader_program.h"
#include "mesh.h"
#include "expectations.h"
#include "configuration.h"

Masked_Textured_2D_Shader_Program::Masked_Textured_2D_Shader_Program(const Shader* vertex_shader, const Shader* fragment_shader)
	: Shader_Program("Shader_Program.2D.Masked_Textured", vertex_shader, fragment_shader)
{
}
Masked_Textured_2D_Shader_Program::~Masked_Textured_2D_Shader_Program()
{
}

void Masked_Textured_2D_Shader_Program::render(const Configuration* config, const Mesh* mesh, const Texture* texture, const Texture* mask, const glm::mat4* transformation) const
{
	glUseProgram(program());
	glBindVertexArray(vao());

	GLuint vbo_index;
	glGenBuffers(1, &vbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh->verticies().size(), mesh->verticies().data(), GL_STATIC_DRAW);

	GLint vertex_location = glGetAttribLocation(program(), "vertex_position");
	expect(vertex_location != -1, "Failed to get vertex_location");
	glEnableVertexAttribArray(vertex_location);
	glVertexAttribPointer(vertex_location, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	GLint transformation_location = glGetUniformLocation(program(), "transformation");
	expect(transformation_location != -1, "Failed to find mask uniform location.");
	glUniformMatrix4fv(transformation_location, 1, GL_FALSE, &(*transformation)[0][0]);

	GLuint tbo_index;
	glGenBuffers(1, &tbo_index);
	glBindBuffer(GL_ARRAY_BUFFER, tbo_index);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * mesh->texture_coordinates().size(), mesh->texture_coordinates().data(), GL_STATIC_DRAW);

	GLint texture_coordinate_location = glGetAttribLocation(program(), "vertex_texture_coordinate");
	expect(texture_coordinate_location != -1, "Failed to get texture_coordinate_location");
	glEnableVertexAttribArray(texture_coordinate_location);
	glVertexAttribPointer(texture_coordinate_location, 2, GL_FLOAT, GL_FALSE, 0, NULL);

	GLuint texture_locations[2];
	glGenTextures(2, texture_locations);

	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_2D, texture_locations[0]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->width(), texture->height(),
		0, GL_RGB, GL_UNSIGNED_BYTE, texture->data());

	GLint image_location = glGetUniformLocation(program(), "image");
	expect(image_location != -1, "Failed to find image uniform location.");
	glUniform1i(image_location, 0);

	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, texture_locations[1]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mask->width(), mask->height(),
		0, GL_RGB, GL_UNSIGNED_BYTE, mask->data());

	GLint mask_location = glGetUniformLocation(program(), "mask");
	expect(mask_location != -1, "Failed to find mask uniform location.");
	glUniform1i(mask_location, 1);

	if(config->render_wireframe)
	{
		glDrawArrays(GL_LINE_LOOP, 0, GLsizei(mesh->verticies().size() / 2));
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, GLsizei(mesh->verticies().size() / 2));
	}


	glDeleteBuffers(1, &vbo_index);
	glDeleteTextures(2, texture_locations);
}