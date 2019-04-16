#pragma once
#include "Alive.h"

using namespace std;

class Animal : public Alive
{
public:
	void move();
	void set_animal();
	void get_animal();
};