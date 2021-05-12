#pragma once
#ifndef _LEVELMAP_H
#define _LEVELMAP_H

#include "Constants.h"

class LevelMap
{
public:
	LevelMap(int map[MAP_HEIGHT][MAP_WIDTH]);
	~LevelMap(); 
	int GetTileAt(unsigned int h, unsigned int w);

private: 
	int** mMap;

};


#endif