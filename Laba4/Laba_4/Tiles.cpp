#include "pch.h"
#include <iostream>
#include <string>
#include "Tiles.h"

using namespace std;

Tiles::Tiles() // по умолчанию
{
	brand = "NoBrend";
	size_h = 0;
	size_w = 0;
	price = 0;
}

Tiles::Tiles(string brandVal, float size_hVal, float size_wVal) // с параметрами
{
	brand = brandVal;
	size_h = size_hVal;
	size_w = size_wVal;
	price = 0;
}

Tiles::Tiles(string brandVal, float size_hVal, float size_wVal, float priceVal) : brand(brandVal), size_h(size_hVal), size_w(size_wVal), price(priceVal) // инициализирующий конструктор
{

}

Tiles::Tiles(const Tiles &object) // копирования
{
	brand = object.brand;
	size_h = object.size_h;
	size_w = object.size_w;
	price = object.price;
}

void Tiles::getData()
{
	cout << "Бренд кафеля" << brand << endl;
	cout << "Высота кафеля" << size_h << endl;
	cout << "Ширина кафеля" << size_w << endl;
	cout << "Цена кафеля" << price << endl;
}
