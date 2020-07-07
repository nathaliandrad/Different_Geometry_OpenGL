#include "game_scene.h"
#include "pointy_head.h"
#include "blocky_boy.h"
#include "hexa_boy.h"
#include "crazy_crate.h"
#include "crazy_cube.h"
#include "crazy_pyramid.h"

#include <glew.h>

#include <glfw3.h>
Game_Scene::Game_Scene()
	: Scene("Game")
{

}

Game_Scene::~Game_Scene()
{

}

void Game_Scene::update(const double , Input* input)
{

	
	if (input->is_button_state(Input::Button::num1, Input::Button_State::DOWN)) {
		Blocky_Boy* blocky_boy2 = new Blocky_Boy("Game_Object.Blocky_Boy");
		_game_objects[blocky_boy2->id()] = blocky_boy2;
		blocky_boy2->translate(glm::vec3(0.0f, 0, 0));
		_camera_position = glm::vec3(0.0f, 0.f, -3.f);
	}
	if (input->is_button_state(Input::Button::num2, Input::Button_State::PRESSED)) {
		Pointy_Head* pointy_head = new Pointy_Head("Game_Object.Pointy_Head");
		_game_objects[pointy_head->id()] = pointy_head;
		pointy_head->translate(glm::vec3(10, 0, 0));
		_camera_position = glm::vec3(10.f, 0.f, -3.f);
	}
	if (input->is_button_state(Input::Button::num3, Input::Button_State::DOWN)) {
		Hexa_Boy* hexa_boy = new Hexa_Boy("Game_Object.Hexa_Boy");
		_game_objects[hexa_boy->id()] = hexa_boy;
		hexa_boy->translate(glm::vec3(-5.0f, 0, 0));
		_camera_position = glm::vec3(-5.0f, 0.f, -3.f);
	}
	//left
	if (input->is_button_state(Input::Button::num4, Input::Button_State::PRESSED)) {
		Crazy_Crate* crazy_crate = new Crazy_Crate("Game_Object.Crate");
		_game_objects[crazy_crate->id()] = crazy_crate;
		crazy_crate->translate(glm::vec3(5, 0, 0));
		_camera_position = glm::vec3(5.f, 0.f, -3.f);
	}

	if (input->is_button_state(Input::Button::num5, Input::Button_State::PRESSED)) {
		pointyHead = true;
		Crazy_Cube* crazy_cube = new Crazy_Cube("Game_Object.Cube");
		_game_objects[crazy_cube->id()] = crazy_cube;
		crazy_cube->translate(glm::vec3(-10.0f, 0, 0));
		_camera_position = glm::vec3(-10.0f, 0.f, -3.f);
	}

	if (input->is_button_state(Input::Button::num6, Input::Button_State::PRESSED)) {
		Crazy_Pyramid* crazy_pyramid = new Crazy_Pyramid("Game_Object.Pyramid");
		_game_objects[crazy_pyramid->id()] = crazy_pyramid;
		crazy_pyramid->translate(glm::vec3(-15.0f, 0, 0));
		_camera_position = glm::vec3(-15.0f, 0.f, -3.f);

	}

	if (input->is_button_state(Input::Button::QUIT, Input::Button_State::PRESSED)) {
		exit(0);
	}
}