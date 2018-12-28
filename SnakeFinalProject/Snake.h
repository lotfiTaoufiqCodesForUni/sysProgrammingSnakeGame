#pragma once
#include "Food.h"


class Snake
{
public:
	Snake(int x, int y, int a, int b);
	~Snake();
	void move(int xSpeed, int ySpeed);
	POINT part[100];
	int lnSnake = 2;
	int dx = 1;
	int dy = 0;
	POINT foodLocation;
	void generateNewLocation(RECT rt);

	void update(RECT rt, HWND hWnd);
	void show(HDC hdc );
};

