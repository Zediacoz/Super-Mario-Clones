#pragma once
#ifndef _CHARACTERMARIO_H_
#define _CHARACTERMARIO_H_
#include <SDL.h>
#include "Commons.h"
#include "GameScreen.h"
#include "Character.h"

using namespace std;
class CharacterMario : public Character
{


public:

	CharacterMario(SDL_Renderer* renderer, string imagePath, Vector2D startPosition);
	CharacterMario(SDL_Renderer * renderer, string imagePath, LevelMap * map, Vector2D startPosition);
	void Update(float deltatime, SDL_Event e);

};
#endif _CHARACTERMARIO_H