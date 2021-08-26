#include"wall.h"
#include"food.h"
void food::setfood()
{
	while (true)
	{
		x = rand() % 28 + 1;
		y = rand() % 28 + 1;
		if (getfood() == ' ')
		{
			W.setwall(x, y,'#');
			break;
		}
	}

}
char food::getfood()
{
	return W.getwall(x, y);
}

int food::getx()
{
	return x;
}

int food::gety()
{
	return y;
}