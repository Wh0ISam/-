#pragma once
#include "Alive.h"

using namespace std;

class Bird : public Alive
{
public:
	void move();
	void sound();
	void set_bird();
	void get_bird();
};