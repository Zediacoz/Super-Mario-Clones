#include "Character.h"
#include "Texture2D.h"
#include "Constants.h"
#include <iostream>


Character::Character(SDL_Renderer * renderer, string imagePath, Vector2D startPosition, LevelMap* map)
{
	mRenderer = renderer;
	mTexture = new Texture2D(renderer);
	mTexture->LoadFromFile(imagePath);
	mPosition = startPosition;
	mFacingDirection = FACING_RIGHT;

	mMovingLeft = false;
	mMovingRight = false;

	mCollisionRadius = 15.0f;

	mCurrentLevelMap = map;



}

Character::~Character()
{
	mRenderer = NULL;
	delete mTexture;
}

void Character::Render()
{

	if (mFacingDirection == FACING_RIGHT)
	{
		mTexture->Render(mPosition, SDL_FLIP_NONE);
	}
	else
	{
		mTexture->Render(mPosition, SDL_FLIP_HORIZONTAL);
	}
}

void Character::Update(float deltaTime, SDL_Event e)
{
	int centralXPosition = (int)(mPosition.x + (mTexture->GetWidth()*0.5f)) / TILE_WIDTH;
	int footPosition = (int)(mPosition.y + mTexture->GetHeight()) / TILE_HEIGHT;
	int headPosition = (int)mPosition.y / TILE_HEIGHT;
	//AddGravity(deltaTime); - POSSIBLE FEATURE !!!!!
	//Deal with jumping first.
	if (mJumping)
	{
		
		//adjust position
		mPosition.y -= mJumpForce*deltaTime;

		//reduce jump force
		mJumpForce -= JUMP_FORCE_DECREMENT*deltaTime;

		//has the jump force reduce to zero?
		if (mCurrentLevelMap->GetTileAt(headPosition, centralXPosition) != 0 || (mCurrentLevelMap->GetTileAt(footPosition, centralXPosition) != 0 && mJumpForce <= 0.00f) )
			mJumping = false;
	}

	
	if (mCurrentLevelMap->GetTileAt(footPosition, centralXPosition) == 0)
	{
		AddGravity(deltaTime);
	}
	else
	{
		//Collided with ground so we can jump again
		mCanJump = true;
	}
	/*switch (e.type)
	{
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			mMovingLeft = true;
			mMovingRight = false;
			break;
		case SDLK_RIGHT:
			mMovingRight = true;
			mMovingLeft = false;
			break;
		case SDLK_SPACE:
			Jump();
			break;
		}
		break;
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			mMovingLeft = false;

			break;
		case SDLK_RIGHT:
			mMovingRight = false;

			break;
		}
	}*/
	if (mMovingLeft)
	{
		
		MoveLeft(deltaTime);
	}
	else if (mMovingRight)
	{
		
		MoveRight(deltaTime);
	}

}

void Character::SetPosition(Vector2D newPosition)
{
	mPosition = newPosition;
}

void Character::AddGravity(float deltaTime)
{
	mPosition.y += GRAVITY * deltaTime;
	//Collided with ground so we can jump again.
	mCanJump = false;

}

Vector2D Character::GetPosition()
{
	return mPosition;
}

void Character::Jump()
{
	if (!mJumping && mCanJump)
	{
		mJumpForce = INITIAL_JUMP_FORCE;
		mJumping = true;
		mCanJump = false;
	}
}

float Character::GetCollisionRadius()
{
	return mCollisionRadius;
}

void Character::MoveLeft(float deltaTime)
{
	int centralYPosition = (int)(mPosition.y + (mTexture->GetHeight()*0.5f)) / TILE_HEIGHT;
	int leftSide = (int) mPosition.x / TILE_WIDTH;
	
	mFacingDirection = FACING_LEFT;
		if (mCurrentLevelMap->GetTileAt(centralYPosition, leftSide) == 0) {
		mPosition.x -= 100 * deltaTime;
	}
}

void Character::MoveRight(float deltaTime)
{
	int centralYPosition = (int)(mPosition.y + (mTexture->GetHeight()*0.5f)) / TILE_HEIGHT;
	int rightSide = (int) (mPosition.x + mTexture->GetWidth() ) / TILE_WIDTH;
	
	mFacingDirection = FACING_RIGHT;
		if (mCurrentLevelMap->GetTileAt(centralYPosition, rightSide) == 0) {
		mPosition.x += 100 * deltaTime;
	}
}


Rect2D Character::GetCollisionBox()
{
	return Rect2D(mPosition.x, mPosition.y, mTexture->GetWidth(), mTexture->GetHeight());
}