#pragma once

#include "square_mesh.h"

Square_Mesh::Square_Mesh()
	: Mesh("Mesh.Square")
{
	//SQUARE
	_verticies.insert(_verticies.end(), {-0.5f, -0.5f});  
	_verticies.insert(_verticies.end(), {-0.5f, 0.5f}); 
	_verticies.insert(_verticies.end(), {0.5f, -0.5f});  
	_verticies.insert(_verticies.end(), { 0.5f, -0.5f });  
	_verticies.insert(_verticies.end(), { -0.5f, 0.5f }); 
	_verticies.insert(_verticies.end(), { 0.5f, 0.5f });  
	
}
Square_Mesh::~Square_Mesh()
{
}