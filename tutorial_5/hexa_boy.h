#pragma once

#include "game_object.h"

class Hexa_Boy : public Game_Object
{
public:
	Hexa_Boy(const char* id);
	~Hexa_Boy();

	virtual void simulate_AI(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config, const Input* input) override;
	virtual void render(const double seconds_to_simulate, const Assets* assets, const Scene* scene, const Configuration* config) override;

private:
	double _total_time;
};
