#include<iostream>
#include"wall.h"
using namespace std;

void wall::wall1()
{
	for (int i = 0;i < 30;i++)
	{
		for (int j = 0;j < 30;j++)
		{
			if (i == 0 || j == 0 || i == 29 || j == 29)
			{
				wall[i][j] = '*';
			}
			else
			{
				wall[i][j] = ' ';
			}
		}
	}
}

void wall::printwall()
{
	for (int i = 0;i < 30;i++)
	{
		for (int j = 0;j < 30;j++)
		{
			cout << wall[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

char wall::getwall(int x,int y)
{
	return wall[y][x];
}
void wall::setwall(int x, int y,char c)
{
	wall[y][x] = c;
}
