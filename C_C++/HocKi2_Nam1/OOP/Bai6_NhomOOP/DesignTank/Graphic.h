#ifndef _Graphic_h
#define _Graphic_h

#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

struct Coord
{
public:
	int X;
	int Y;
	Coord() 
	{
		this->X = 0;
		this->Y = 0;
	}
	Coord(int X, int Y)
	{
		this->X = X;
		this->Y = Y;
	}
	friend istream& operator >> (istream& is, Coord& coord)
	{
		cout << "\nInput x: ";
		is >> coord.X;
		cout << "Input y: ";
		is >> coord.Y;
		return is;
	}
	friend ostream& operator >> (ostream& os, Coord& coord)
	{
		os << "\n(x,y) = (" << coord.X << " , " << coord.Y << ")";
		return os;
	}

	Coord operator = (const Coord& coord2)
	{
		this->X = coord2.X;
		this->Y = coord2.Y;
		return*this;
	}

	bool operator == (const Coord& coord2)
	{

		if (this->X == coord2.X && this->Y == coord2.Y)
			return true;
		return false;
	}

	bool operator != (const Coord& coord2)
	{
		
		if (this->X != coord2.X || this->Y != coord2.Y)
			return true;
		return false;
	}
};
typedef struct Coord Coord;

class Graphic
{
public:
	static enum Color
	{
		Black,
		Blue,
		Green,
		Aqua,
		Red,
		Purple,
		Yellow,
		White,
		Gray,
		LightBlue,
		LightGreen,
		LightAqua,
		LightRed,
		LightPurple,
		LightYellow,
		BrightWhite,
	};
	static void DrawRectangleBySize(Coord, int, int);
	static void DrawRectangleBySize(Coord, int, int, char, int textColor = Color::White);
	static void DrawInvisibleRectangleBySize(Coord, int, int, char, int textColor = Color::White);
	static void DrawInvisibleRectangleBySize(Coord, int, int, string, int textColor = Color::White);
	static void DrawRectangleByCoord(Coord, Coord);
	static void DrawSquare(Coord, int);
	static void DrawSquare(Coord, int, char, int textColor = Color::White);
	static void DrawInvisibleSquare(Coord, int, char, int textColor = Color::White);
	static void DrawInvisibleSquare(Coord, int, string, int textColor = Color::White);
	static int DrSquareAndGheightInCoSol(Coord, int, char, int textColor = Color::White);
	static int DrInvisibalSquareAndGheightInCoSol(Coord, int, char, int textColor = Color::White);
	static void GoTo(SHORT, SHORT);
	static void ShowCursor(bool CursorVisibility = false);
	static void SetColor(int, int);
	static void DisableSelection();
	static void SetWindowSize(SHORT, SHORT);
	static void SetScreenBufferSize(SHORT, SHORT);
	static void DisableResizeWindow();
	static void DisableCtrButton(bool Close = false, bool Min = true, bool Max = true);
	static void ShowScrollbar(BOOL Show = true);
	static int wherex();
	static int wherey();
};

#endif // !_Graphic_h

