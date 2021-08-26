#include<iostream>
#include<windows.h>
#include<time.h>
#include"wall.h"
#include"food.h"
#include"snake.h"
using namespace std;
void move(wall& w, snake*head);
bool DOWN = false, UP = false, RIGHT = false, LEFT = false;

int main()
{
	srand((unsigned int)time(NULL));
	wall w;
	snake s;
	food f(w);
	w.wall1();
	snake*head=s.head(w);
	f.setfood();
	while (true)
	{
		w.printwall();
		move(w, head);
		Sleep(800);
		if (head->x == 0 || head->x == 29 || head->y == 0 || head->y == 29)
		{
			cout << "游戏结束" << endl;
			break;
		}
		if (f.getfood() !='#')
		{
			f.setfood();
		}
		system("cls");
	}
	system("pause");
	return 0;	
}

void move(wall& w, snake*head)
{
	int down = 1, up = 1, right = 1, left = 1;
	down = GetKeyState(VK_DOWN);
	up = GetKeyState(VK_UP);
	right = GetKeyState(VK_RIGHT);
	left = GetKeyState(VK_LEFT);//获取下箭头键状态   如果down>0 表示被松开  down<0 表示被按下
	if (down < 0)      //如果下箭头键被按下   
	{
		head->y = head->y +1;
		w.setwall(head->x, head->y, '@');
		w.setwall(head->x, head->y-1, ' ');
		DOWN = true, UP = false, RIGHT = false, LEFT = false;
	}
	if (up < 0)      //如果上箭头键被按下   
	{
		head->y = head->y -1;
		w.setwall(head->x, head->y, '@');
		w.setwall(head->x, head->y+1, ' ');
		DOWN = false, UP = true, RIGHT = false, LEFT = false;
	}
	if (right < 0)      //如果右箭头键被按下   
	{
		head->x = head->x + 1;
		w.setwall(head->x, head->y, '@');
		w.setwall(head->x-1, head->y, ' ');
		DOWN = false, UP = false, RIGHT = true, LEFT = false;
	};
	if (left < 0)      //如果左箭头键被按下   
	{
		head->x = head->x - 1;
		w.setwall(head->x, head->y, '@');
		w.setwall(head->x+1, head->y, ' ');
		DOWN = false, UP = false, RIGHT = false, LEFT = true;
	}
	if (DOWN)
	{
		head->y = head->y + 1;
		w.setwall(head->x, head->y, '@');
		w.setwall(head->x, head->y - 1, ' ');
	}
	if(UP)
	{
		head->y = head->y - 1;
		w.setwall(head->x, head->y, '@');
		w.setwall(head->x, head->y + 1, ' ');
	}
	if (LEFT)
	{
		head->x = head->x - 1;
		w.setwall(head->x, head->y, '@');
		w.setwall(head->x + 1, head->y, ' ');
	}
	if (RIGHT)
	{
		head->x = head->x + 1;
		w.setwall(head->x, head->y, '@');
		w.setwall(head->x - 1, head->y, ' ');
	}
}

