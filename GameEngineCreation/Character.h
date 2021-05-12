#pragma once
#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <SDL.h>
#include <iostream>
#include "Commons.h"
#include "LevelMap.h"
using namespace std;

class Texture2D;

class Character
{
protected:
	SDL_Renderer* mRenderer;
	Vector2D mPosition;
	Texture2D* mTexture;

	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);

	bool mJumping;
	bool mCanJump;

	float mJumpForce;
	float mCollisionRadius;

	

public:

	Character(SDL_Renderer* renderer, string imagePath, Vector2D startPosition, LevelMap* map);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);

	void SetPosition(Vector2D newPosition);
	void AddGravity(float deltaTime);

	Vector2D GetPosition();

	bool mMovingLeft;
	bool mMovingRight;

	void Jump();
	float GetCollisionRadius();
	
	Rect2D GetCollisionBox();

private:
	LevelMap * mCurrentLevelMap;
	FACING mFacingDirection;

};


#endif _CHARACTER_H