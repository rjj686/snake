#pragma once
#include<iostream>
using namespace std;

class wall
{
public:
	void wall1();//≥ı ºªØ«Ω
	void printwall();//¥Ú”°«Ω
	char getwall(int x,int y);
	void setwall(int x,int y,char c);
private:
		char wall[30][30];
};