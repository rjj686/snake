#include"snake.h"
#include"wall.h"

snake * snake::head(wall &w)
{
	snake* head = new snake;//Í·Ö¸Õë
	snake* p1 = NULL;
	head->x = rand() % 28+1;
	head->y = rand() % 28+1;
	head->next = NULL;
	w.setwall(head->x, head->y, '@');
	return head;
}
void snake::addpoint(snake* head,food &f,wall &w)
{
	
}

