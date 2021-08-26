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
			cout << "��Ϸ����" << endl;
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
	left = GetKeyState(VK_LEFT);//��ȡ�¼�ͷ��״̬   ���down>0 ��ʾ���ɿ�  down<0 ��ʾ������
	if (down < 0)      //����¼�ͷ��������   
	{
		head->y = head->y +1;
		w.setwall(head->x, head->y, '@');
		w.setwall(head->x, head->y-1, ' ');
		DOWN = true, UP = false, RIGHT = false, LEFT = false;
	}
	if (up < 0)      //����ϼ�ͷ��������   
	{
		head->y = head->y -1;
		w.setwall(head->x, head->y, '@');
		w.setwall(head->x, head->y+1, ' ');
		DOWN = false, UP = true, RIGHT = false, LEFT = false;
	}
	if (right < 0)      //����Ҽ�ͷ��������   
	{
		head->x = head->x + 1;
		w.setwall(head->x, head->y, '@');
		w.setwall(head->x-1, head->y, ' ');
		DOWN = false, UP = false, RIGHT = true, LEFT = false;
	};
	if (left < 0)      //������ͷ��������   
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

