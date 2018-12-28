#include "stdafx.h"
#include "Food.h"





Food::Food(int x, int y)
{

	foodLocation.x = x;
	foodLocation.y = y;
}


void Food::generateNewLocation(RECT rt)
{
	int x = rand() % (rt.right / 16);
	int y = rand() % (rt.bottom / 16);
	foodLocation.x = x;
	foodLocation.y = y;
}




POINT Food::getFoodLocation()
{
	return foodLocation;
}

Food::~Food()
{
}
