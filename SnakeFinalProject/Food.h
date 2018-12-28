#pragma once
class Food
{
public:
	
	Food(int x, int y);
	~Food();
	void generateNewLocation(RECT rt);
	POINT getFoodLocation();
	
	POINT foodLocation;
};

