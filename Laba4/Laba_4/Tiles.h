#pragma once
#include <iostream>
#include <string>

using namespace std;

class Tiles
{
public:
	string brand;
	float size_h;
	float size_w;
	float price;
	void getData();

	Tiles();

	Tiles(string brandVal, float size_hVal, float size_wVal);

	Tiles(string brandVal, float size_hVal, float size_wVal, float priceVal);

	Tiles(const Tiles &object);
	~Tiles() {} // дуструктор
};
