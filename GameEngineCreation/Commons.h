#pragma once
struct Vector2D {
	float x;
	float y;

	Vector2D()
	{
		x = 0.0f;
		y = 0.0f;
	}
	Vector2D(float initialX, float initialY)
	{
		x = initialX;
		y = initialY;
	}
};

enum SCREENS
{
	SCREEN_INTRO =0,
	SCREEN_MENU,
	SCREEN_LEVEL1,
	SCREEN_LEVEL2,
	SCREEN_GAMEOVER,
	SCREEN_HIGHSCORES
};

enum FACING
{
	FACING_LEFT = 0,
	FACING_RIGHT
};

struct Rect2D
{
	float x;
	float y;
	float width, height;


	Rect2D()
	{
		x = 0.0f;
		y = 0.0f;
		width = 0;
		height = 0;

	}

	Rect2D(float X, float Y, float Width, float Height)
	{
		x = X;
		y = Y;
		width = Width;
		height = Height;
	}
};