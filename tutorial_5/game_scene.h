#pragma once

#include "scene.h"
#include "Input.h"

class Game_Scene : public Scene
{
public:
	Game_Scene();
	~Game_Scene();

	virtual void update(const double seconds_to_simulate, Input* input) override;

	bool blockyBoy = false;
	bool pointyHead = false;
	bool testTest = false;

	bool n1 = false;
	bool n2 = false;
	bool n3 = false;
};