#include "CharacterMario.h"
#include "Texture2D.h"
#include "Constants.h"
#include "Commons.h"
#include "Character.h"

CharacterMario::CharacterMario(SDL_Renderer * renderer, string imagePath, LevelMap* map, Vector2D startPosition) : Character(renderer,imagePath,startPosition, map)
{
}

void CharacterMario::Update(float deltatime, SDL_Event e)
{
	switch (e.type)
	{
	case SDL_KEYUP:
		switch (e.key.keysym.sym)
		{
		case SDLK_a:
			mMovingLeft = false;
			break;

		case SDLK_d:
			mMovingRight = false;
			break;

		default:
			break;
		}
		break;
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym)
		{
		case SDLK_w:
			Character::Jump();
			break;

		case SDLK_DOWN:
			break;

		case SDLK_a:
			mMovingRight = false;
			mMovingLeft = true;
			break;

		case SDLK_d:
			mMovingLeft = false;
			mMovingRight = true;
			break;

		default: break;
		}
		break;
	}
	Character::Update(deltatime, e);
}


	



