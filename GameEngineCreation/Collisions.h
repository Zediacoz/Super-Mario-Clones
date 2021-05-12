#pragma once
#ifndef _COLLISIONS_H_
#define _COLLISIONS_H_
#include <SDL.h>
#include "Commons.h"
#include <string>

class Character;

class Collisions
{
public:

	~Collisions();

	static Collisions* Instance();

	bool Circle(Character* character1, Character* character2);
	bool Box(Rect2D rect1, Rect2D rect2);

private:
	
	Collisions();

	static Collisions* mInstance;
};




#endif _COLLISIONS_H