#pragma once

struct Configuration
{
	bool render_wireframe = false;

	int screen_width      = 2500;
	int screen_height     = 1500;
	int y_units           = 4;
	int z_units           = -20;
	float fov = 45.f;

	enum class Projection
	{
		Orthographic,
		Perspective
	};
	Projection projection = Projection::Orthographic;
};