#version 330 core

in vec2 vertex_position;
in vec2 vertex_texture_coordinate;

uniform mat4 transformation;

out vec2 interpolated_texture_coordinate;

void main()
{
    gl_Position                     = transformation * vec4(vertex_position.x, vertex_position.y, 0.0, 1.0);
    interpolated_texture_coordinate = vertex_texture_coordinate;
}