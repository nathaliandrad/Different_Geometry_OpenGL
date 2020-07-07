#pragma once

#include <map>
#include <string>
#include <vector>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/transform.hpp>

#include "Input.h"

class Game_Object;
class Input;

class Scene
{
public:
	Scene(const char* id);
	~Scene();

	virtual void update(const double seconds_to_simulate, Input* input) = 0;

	Game_Object* get_game_object(const char* id) const;
	std::vector<Game_Object*> get_game_objects() const;

	const char* id() const;
	// from here
	glm::vec3 camera_position() const;
	glm::vec3 camera_foward() const;
	glm::vec3 camera_up() const;
	//to here
protected:
	std::map<std::string, Game_Object*> _game_objects;
	const char*                         _id;
	//from here
	glm::vec3 _camera_position = glm::vec3(0.f, 0.f, -3.f);
	glm::vec3 _camera_foward   = glm::vec3(0.f, 0.f, 1.f);
	glm::vec3 _camera_up	   = glm::vec3(0.f, 1.f, 0.f);
	//to here
};