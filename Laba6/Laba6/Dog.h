#pragma once
#include "Animals.h"

using namespace std;

class Dog : public Animals
{
public:
	void sit();
	void sound();
	void take();
};