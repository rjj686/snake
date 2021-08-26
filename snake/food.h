#pragma once
#include"wall.h"
class food
{
public:
	food(wall& w) :W(w) {}
	void setfood();
	char getfood();
	int getx();
	int gety();
	wall& W;
private:
	int x;
	int y;
};