#pragma once
#ifndef _CHARACTERLUIGI_H_
#define _CHARACTERLUIGI_H_
#include <SDL.h>
#include "Commons.h"
#include "GameScreen.h"
#include "Character.h"

using namespace std;
class CharacterLuigi : public Character
{


public:

	CharacterLuigi(SDL_Renderer* renderer, string imagePath, Vector2D startPosition);
	CharacterLuigi(SDL_Renderer * renderer, string imagePath, LevelMap * map, Vector2D startPosition);
	void Update(float deltatime, SDL_Event e);

};
#endif _CHARACTERLUIGI_H