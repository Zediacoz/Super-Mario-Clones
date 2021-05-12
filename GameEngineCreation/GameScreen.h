#pragma once
#ifndef _GAMESCREEN_H
#define _GAMESCREEN_H
#include <SDL.h>
#include "Commons.h"
#include <string>
using namespace::std;
class GameScreen
{
protected:
	SDL_Renderer * mRenderer;

public:
	GameScreen(SDL_Renderer* renderer);
	~GameScreen();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

};

#endif _GAMESCREEN_H