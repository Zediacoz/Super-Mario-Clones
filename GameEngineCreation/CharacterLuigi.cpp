#include "CharacterLuigi.h"
#include "Texture2D.h"
#include "Constants.h"
#include "Commons.h"
#include "Character.h"

CharacterLuigi::CharacterLuigi(SDL_Renderer * renderer, string imagePath, LevelMap* map, Vector2D startPosition) : Character(renderer, imagePath, startPosition, map)
{
}

void CharacterLuigi::Update(float deltatime, SDL_Event e)
{
	switch (e.type)
	{
		//Deal with keyboard input.
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			mMovingLeft = false;
			break;

		case SDLK_RIGHT:
			mMovingRight = false;
			break;

		default:
			break;
		}
		break;
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			Character::Jump();
			break;

		case SDLK_DOWN:
			break;

		case SDLK_LEFT:
			mMovingRight = false;
			mMovingLeft = true;
			break;

		case SDLK_RIGHT:
			mMovingLeft = false;
			mMovingRight = true;
			break;

		default: break;
		}
		break;
	}
	Character::Update(deltatime, e);
}
