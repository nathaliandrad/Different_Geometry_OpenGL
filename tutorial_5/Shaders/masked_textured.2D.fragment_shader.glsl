#version 330 core

in vec2 interpolated_texture_coordinate;
uniform sampler2D image;
uniform sampler2D mask;

out vec4 fragment_color;

void main()
{
    vec4 image_textel = texture(image, interpolated_texture_coordinate);
    vec4 mask_textel  = texture(mask, interpolated_texture_coordinate);
    fragment_color    = image_textel * mask_textel;

    if(mask_textel.r < 0.5)
    {
        fragment_color.a = 0.0;
    }
}