#pragma once

#include "hexagon_mesh.h"

Hexagon_Mesh::Hexagon_Mesh()
	: Mesh("Mesh.Hexagon")
{
	//HEXAGON
	_verticies.insert(_verticies.end(), { -0.4f, -0.5f }); 
	_verticies.insert(_verticies.end(), { -0.8f, 0.f }); 
	_verticies.insert(_verticies.end(), { -0.4f, 0.5f }); 

	_verticies.insert(_verticies.end(), { -0.4f, -0.5f });  
	_verticies.insert(_verticies.end(), { -0.4f, 0.5f }); 
	_verticies.insert(_verticies.end(), { 0.4f, 0.5f });  

	_verticies.insert(_verticies.end(), { 0.4f, 0.5f });  
	_verticies.insert(_verticies.end(), { 0.4f, -0.5f }); 
	_verticies.insert(_verticies.end(), { -0.4f, -0.5f });  

	_verticies.insert(_verticies.end(), { 0.4f, 0.5f });  
	_verticies.insert(_verticies.end(), { 0.8f, 0.f }); 
	_verticies.insert(_verticies.end(), { 0.4f, -0.5f });  

	_verticies.insert(_verticies.end(), { -0.4f, 0.5f });  
	_verticies.insert(_verticies.end(), { -0.4f, -0.5f }); 
	_verticies.insert(_verticies.end(), { 0.4f, -0.5f });  

	_verticies.insert(_verticies.end(), { -0.4f, 0.5f });
	_verticies.insert(_verticies.end(), { -0.8f, 0.f });
	_verticies.insert(_verticies.end(), { -0.4f, 0.5f });

}
Hexagon_Mesh::~Hexagon_Mesh()
{
}