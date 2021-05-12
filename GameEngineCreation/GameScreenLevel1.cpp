#include "GameScreenLevel1.h"
#include <iostream>
#include "Texture2D.h"
#include "Collisions.h"
#include "Character.h"
#include "LevelMap.h"



GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel();

	mLevelMap = NULL;

	SetLevelMap();
}

GameScreenLevel1::~GameScreenLevel1()
{
	delete mBackgroundTexture;
	mBackgroundTexture = NULL;

	delete myCharacter;
	myCharacter = NULL;

	delete myMario;
	myMario = NULL;

	delete myLuigi;
	myLuigi = NULL;

}

void GameScreenLevel1::Render()
{
	//Draw the background
	mBackgroundTexture->Render(Vector2D(), SDL_FLIP_NONE);
	//myCharacter->Render();
	myMario->Render();
	myLuigi->Render();
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{
	//myCharacter->Update(deltaTime, e);
	myMario->Update(deltaTime, e);
	myLuigi->Update(deltaTime, e);

	if (Collisions::Instance()->Circle(myMario, myLuigi));
	if (Collisions::Instance()->Box(myMario->GetCollisionBox(), myLuigi->GetCollisionBox()));
}

bool GameScreenLevel1::SetUpLevel()
{
	SetLevelMap();
	
	myMario = new CharacterMario(mRenderer, "Images/Mario.png", mLevelMap, Vector2D(130, 0));
	myLuigi = new CharacterLuigi(mRenderer, "Images/Luigi.png", mLevelMap,  Vector2D(352, 0));
	mBackgroundTexture = new Texture2D(mRenderer);

	if (!mBackgroundTexture->LoadFromFile("Images/BackgroundMB.png"))
	{
		cout << "Failed to load the background texture!";
		return false;
	}
	return false;
}

void GameScreenLevel1::SetLevelMap()
{
	int map[MAP_HEIGHT][MAP_WIDTH] = {
		
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	

	//Clear up any old map.
	if (mLevelMap != NULL)
	{
		delete mLevelMap;
	}

	//Set the new one.
	mLevelMap = new LevelMap(map);



}
