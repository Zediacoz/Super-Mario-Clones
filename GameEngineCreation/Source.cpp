#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include "Constants.h"
#include "Texture2D.h"
#include "GameScreenManager.h"
#include <SDL_mixer.h>


//Globals
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
Mix_Music* gMusic = NULL;
//Texture2D* gTexture = NULL;
GameScreenManager* gameScreenManager;
Uint32 g0ldTime;
using namespace::std;

bool InitSDL();
void CloseSDL();
bool Update();
void Render();
void LoadMusic(string path);

int main(int argc, char* args[])
{
	if (InitSDL())
	{
		gameScreenManager = new GameScreenManager(gRenderer, SCREEN_LEVEL1);
		g0ldTime = SDL_GetTicks();
		//Flag to check if we wish to quit.
		bool quit = false;
		//Game Loop.
		while (!quit)
		{
			Render();
			quit = Update();
		}
	}
	//Close Window and free resources.
	CloseSDL();

	return 0;
}
bool Update()
{
	//Get the new time.
	Uint32 newTime = SDL_GetTicks();
	//Event Handler.
	SDL_Event e;
	//Get the events.
	SDL_PollEvent(&e);


	//Handle any events.
	switch (e.type)
	{
		//Click the 'X' to quit.
	case SDL_QUIT:
		return true;
		break;
	}
	gameScreenManager->Update((float)(newTime-g0ldTime)/1000.0f, e);
	//Set the current time to be the old time.
	g0ldTime = newTime;
	return false;
}
void CloseSDL()
{
	//Release the window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	//Quit SDL subsystems.
	IMG_Quit();
	SDL_Quit();

	//Release the renderer.
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	//Release the texture. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//delete gTexture;
	//gTexture = NULL;
	//Destroy the game screen manager.

	delete gameScreenManager;
	gameScreenManager = NULL;

	//Music
	Mix_FreeMusic(gMusic);
	gMusic = NULL;


}
void Render()
{
	//Clear the screen.
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	gameScreenManager->Render();

	//Update the screen.
	SDL_RenderPresent(gRenderer);
}

void LoadMusic(string path)
{

	gMusic = Mix_LoadMUS(path.c_str());


	if (gMusic == NULL)
	{
		cout << "Failed to load background music! Error: " << Mix_GetError() << endl;
	}


	return void();
}

bool InitSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SLD did not initialise. Error: " << SDL_GetError();
		return false;
	}
	else
	{
		// All good, so attempt to create the window.
			gWindow = SDL_CreateWindow("Games Engine Creation",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				SCREEN_WIDTH,
				SCREEN_HEIGHT,
				SDL_WINDOW_SHOWN);

			//Did the window get created?
			if (gWindow == NULL)
			{
				//Nope
				cout << "Window was not created. Error: " << SDL_GetError();
				return false;
			}

			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer != NULL)
			{
				//Initialise PNG loading.
				int imageFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imageFlags) & imageFlags))
				{
					cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
					return false;
				}
				
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					cout << "Mixer could not initialise. Error: " << Mix_GetError();
					return false;
				}
				LoadMusic("Music/Mario.mp3");

				if (Mix_PlayingMusic() == 0)
				{
					Mix_PlayMusic(gMusic, -1);
				}

				//gTexture = new Texture2D(gRenderer);
				//if (!gTexture->LoadFromFile("Images/test.bmp"))
				//{
				//	return false;
				//}
			}
			else
			{
				cout << "Renderer could not initialise. Error: " << SDL_GetError();
				//return false;
			}
	}
	return true;
}

