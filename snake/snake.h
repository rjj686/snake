#pragma once
#include"food.h"
#include"wall.h"


class snake
{
public:
    int x;
    int y;
    snake* next;
    snake* head(wall &w);//��������
    void addpoint(snake* head,food &f,wall &w);
};