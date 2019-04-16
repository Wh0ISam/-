#pragma once
#include "Alive.h"
using namespace std;

class Fish : public Alive
{
public:
	void move();
	void ability();
	void set_fish();
	void get_fish();
};