#ifndef _Map_h
#define _Map_h

#include <iostream>
#include "Graphic.h"
#include <vector>
#include <time.h>


#define DEFAULT_HEIGHT_MAP 5
#define DEFAULT_WIDTH_MAP 5
#define SMALL_VEHICLE 's'
#define TANK 't'
#define INFANTRY 'i'
#define EMPTY_POSITION ' '
#define DEAD 'X'



static enum Target
{
	Tank = 1,
	Infantry,
	SmallVehicle,
};

class Map
{
private:
	int row;
	int col;
	char **map;
	bool** exist;

public:

#pragma region Constructor
	Map();
	Map(int, int);
#pragma endregion

#pragma region Destructor
	~Map();
#pragma endregion

#pragma region Method
	char GetValueAt(Coord);
	void SetValueAt(Coord,char value);
	void SetExistedAt(Coord, bool existed = true);
	int GetHeight();
	int GetWidth();
	void SetWidth(int);
	void SetHeight(int);
	void Init();
	void Init(int, int);
	void ResetMapSize();
	void Close();
	bool IsEmptyPosition(Coord pos);
	int RandomAmountOfTarget();
	Coord RandomTargetCoordinate();
	void RandomTargetPosition(char);
	void ShowMap(Coord);
	char RandomTypeOfTarget();
	bool IsFull();
#pragma endregion


};

#endif // !_Map_h



