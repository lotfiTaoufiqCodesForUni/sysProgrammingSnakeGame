#include "stdafx.h"
#include "Snake.h"
#include "Food.h"

Snake::Snake(int x,int y,int a,int b)
{
	 
	foodLocation.x = 200;
	foodLocation.y = 200;
	part[0].x = x;
	part[0].y = y;
	part[1].x = a;
	part[1].y = b;
	part[2].x = a+1;
	part[2].y = y;
}


void Snake::generateNewLocation(RECT rt)
{
	int x = rand() % (rt.right / 16);
	int y = rand() % (rt.bottom / 16);
	foodLocation.x = x;
	foodLocation.y = y;
}


void Snake::update(RECT rt,HWND hWnd) {
	for (int i = lnSnake - 1; i > 0; i--)
	{
		part[i] = part[i - 1];
	}
	part[0].x = part[0].x + dx;
	part[0].y = part[0].y + dy;

	if (part[0].x * 16 >= rt.right)part[0].x = 0;
	if (part[0].x < 0)part[0].x = rt.right / 16;
	if (part[0].y * 16 >= rt.bottom)part[0].y = 0;
	if (part[0].y < 0)part[0].y = rt.bottom / 16;

	if ((part[0].x == foodLocation.x) && (part[0].y == foodLocation.y))
	{
		lnSnake++;
		generateNewLocation(rt);
	}
	for (int i = lnSnake - 1; i > 0; i--)

		if ((part[0].x == part[i].x) && (part[0].y == part[i].y))
		{
			KillTimer(hWnd, 1);
			MessageBox(hWnd, L"Game over", L"Info", MB_OK);
			PostQuitMessage(0);

		}
}


void Snake::show(HDC hdc) {
	  
	

	
	Ellipse(hdc, foodLocation.x * 16, foodLocation.y * 16, foodLocation.x * 16  +16, foodLocation.y * 16 + 16);
	for (int i = 0; i < lnSnake; i++)
		Rectangle(hdc, part[i].x * 16, part[i].y * 16, part[i].x * 16 + 16, part[i].y * 16 + 16);
}

void Snake::move(int xSpeed, int ySpeed) {
	dx = xSpeed;
	dy = ySpeed;
}


Snake::~Snake()
{
}
