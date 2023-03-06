#include "Map.h"

#pragma region Constructor
Map::Map()
{
	this->row = DEFAULT_HEIGHT_MAP;
	this->col = DEFAULT_WIDTH_MAP;
	map = new char* [row];
	for (int i = 0; i < row; i++)
		map[i] = new char[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			map[i][j] = EMPTY_POSITION;
	exist = new bool* [row];
	for (int i = 0; i < row; i++)
		exist[i] = new bool[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			exist[i][j] = false;
}

Map::Map(int width, int height)
{
	this->row = height;
	this->col = width;
	map = new char* [row];
	for (int i = 0; i < row; i++)
		map[i] = new char[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			map[i][j] = EMPTY_POSITION;
	exist = new bool* [row];
	for (int i = 0; i < row; i++)
		exist[i] = new bool[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			exist[i][j] = false;
}
#pragma endregion

#pragma region Destructor
Map::~Map()
{
	if (map != nullptr)
	{
		for (int i = 0; i < row; i++)
		{
			delete[]map[i];
			map[i] = nullptr;
		}
		delete[]map;
		map = nullptr;
	}
	if (exist != nullptr)
	{
		for (int i = 0; i < row; i++)
		{
			delete[]exist[i];
			exist[i] = nullptr;
		}
		delete[]exist;
		exist = nullptr;
	}
}
#pragma endregion

#pragma region Method
int Map::GetHeight()
{
	return row;
}
int Map::GetWidth()
{
	return col;
}
void Map::SetWidth(int value)
{
	col = value;
}
void Map::SetHeight(int value)
{
	row = value;
}
char Map::GetValueAt(Coord coord)
{
	return map[coord.Y][coord.X];
}
void Map::SetValueAt(Coord coord,char value)
{
	map[coord.Y][coord.X] = value;
}

void Map::SetExistedAt(Coord coord, bool existed)
{
	exist[coord.Y][coord.X] = existed;
}

void Map::Init()
{
	if (map != nullptr)
	{
		for (int i = 0; i < row; i++)
		{
			delete[]map[i];
			map[i] = nullptr;
		}
		delete[]map;
		map = nullptr;
	}
	map = new char* [row];
	for (int i = 0; i < row; i++)
		map[i] = new char[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			map[i][j] = EMPTY_POSITION;
	exist = new bool* [row];
	for (int i = 0; i < row; i++)
		exist[i] = new bool[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			exist[i][j] = false;
}
void Map::Init(int width, int height)
{
	if (map != nullptr)
	{
		for (int i = 0; i < row; i++)
		{
			delete[]map[i];
			map[i] = nullptr;
		}
		delete[]map;
		map = nullptr;
	}
	this->row = height;
	this->col = width;
	map = new char* [row];
	for (int i = 0; i < row; i++)
		map[i] = new char[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			map[i][j] = EMPTY_POSITION;
	exist = new bool* [row];
	for (int i = 0; i < row; i++)
		exist[i] = new bool[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			exist[i][j] = false;
}
void Map::ResetMapSize()
{
	if (map != nullptr)
	{
		for (int i = 0; i < row; i++)
		{
			delete[]map[i];
			map[i] = nullptr;
		}
		delete[]map;
		map = nullptr;
	}
	this->row = DEFAULT_HEIGHT_MAP;
	this->col = DEFAULT_WIDTH_MAP;
	map = new char* [row];
	for (int i = 0; i < row; i++)
		map[i] = new char[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			map[i][j] = EMPTY_POSITION;
	exist = new bool* [row];
	for (int i = 0; i < row; i++)
		exist[i] = new bool[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			exist[i][j] = false;
}
void Map::Close()
{
	if (map != nullptr)
	{
		for (int i = 0; i < row; i++)
		{
			delete[]map[i];
			map[i] = nullptr;
		}
		delete[]map;
		map = nullptr;
	}
}

bool Map::IsEmptyPosition(Coord pos)
{
	if (map[pos.X][pos.Y] == EMPTY_POSITION)
		return 1;
	return 0;
}

int Map::RandomAmountOfTarget()
{
	return (rand() % (row * col - 1 + 1) + 1);
}

Coord Map::RandomTargetCoordinate()
{
	Coord pos;
	pos.X = rand() % (col-1 - 0 + 1) + 0;
	pos.Y = rand() % (row-1 - 0 + 1) + 0;
	return pos;
}

void Map::ShowMap(Coord original)
{
	int frameSize = 5;
	int colHeightConsole;
	Coord temp = original;
	Graphic::DrawInvisibleSquare(temp, frameSize, "y\\x");
	temp.X = original.X + frameSize;
	for (int i = 0; i < col; i++)
	{
		colHeightConsole = Graphic::DrInvisibalSquareAndGheightInCoSol(temp, frameSize, (char)(i+48));
		temp.X += frameSize;
	}
	temp.X = original.X;
	temp.Y = original.Y+colHeightConsole;

	for (int i = 0; i < row; i++)
	{
		Graphic::DrawInvisibleSquare(temp, frameSize, (char)(i + 48));
		temp.Y += colHeightConsole + 1;
	}
	temp.X = original.X + frameSize;
	temp.Y = original.Y + colHeightConsole;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if(exist[i][j] == true && map[i][j] == EMPTY_POSITION)
				Graphic::DrawSquare(temp, frameSize, DEAD, Graphic::Color::Red);
			else
				Graphic::DrawSquare(temp, frameSize, map[i][j], Graphic::Color::Aqua);
			temp.X += frameSize;
		}
		temp.X = original.X + frameSize;
		temp.Y += colHeightConsole +1;
	}
}

void Map::RandomTargetPosition(char target)
{
	bool success;
	Coord position; 
	srand(time(NULL));
	do
	{
		position = RandomTargetCoordinate();
		success = IsEmptyPosition(position);
	} while (success == false && !IsFull());
	if(success == true)
		map[position.X][position.Y] = target;
}

bool Map::IsFull()
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (map[i][j] == EMPTY_POSITION)
				return false;
	return true;
}

char  Map::RandomTypeOfTarget()
{
	int type = rand() % (Target::SmallVehicle - Target::Tank + 1) + Target::Tank;
	if (type == Target::SmallVehicle)
		return SMALL_VEHICLE;
	else if (type == Target::Infantry)
		return INFANTRY;
	else
		return TANK;
}

#pragma endregion