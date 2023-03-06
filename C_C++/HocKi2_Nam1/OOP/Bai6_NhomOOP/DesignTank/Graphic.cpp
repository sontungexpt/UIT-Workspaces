#include "Graphic.h"


void Graphic::GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}

void Graphic::ShowCursor(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}

void Graphic::SetColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}

void Graphic::DisableSelection()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

void Graphic::SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}


void Graphic::SetScreenBufferSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;

	SetConsoleScreenBufferSize(hStdout, NewSize);
}

void Graphic::DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void Graphic::DisableCtrButton(bool Close, bool Min, bool Max)
{
	HWND hWnd = GetConsoleWindow();
	HMENU hMenu = GetSystemMenu(hWnd, false);

	if (Close == 1)
	{
		DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
	}
	if (Min == 1)
	{
		DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
	}
	if (Max == 1)
	{
		DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	}
}

void Graphic::ShowScrollbar(BOOL Show)
{
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

void Graphic::DrawRectangleBySize(Coord original, int width, int height)
{
	GoTo(original.X, original.Y);
	cout << char(218);
	GoTo(original.X + width, original.Y);
	cout << char(191);
	GoTo(original.X, original.Y + height);
	cout << char(192);
	GoTo(original.X + width, original.Y + height);
	cout << char(217);
	for (int i = 1; i < width; i++)
	{
		GoTo(original.X + i, original.Y);
		cout << char(196);
	}
	for (int i = 1; i < width; i++)
	{
		GoTo(original.X + i, original.Y + height);
		cout << char(196);
	}
	for (int i = 1; i < height; i++)
	{
		GoTo(original.X, original.Y + i);
		cout << char(179);
	}
	for (int i = 1; i < height; i++)
	{
		GoTo(original.X + width, original.Y + i);
		cout << char(179);
	}
}
void Graphic::DrawRectangleBySize(Coord original, int width, int height, char centerChar, int textColor)
{
	GoTo(original.X, original.Y);
	cout << char(218);
	GoTo(original.X + width, original.Y);
	cout << char(191);
	GoTo(original.X, original.Y + height);
	cout << char(192);
	GoTo(original.X + width, original.Y + height);
	cout << char(217);
	for (int i = 1; i < width; i++)
	{
		GoTo(original.X + i, original.Y);
		cout << char(196);
	}
	for (int i = 1; i < width; i++)
	{
		GoTo(original.X + i, original.Y + height);
		cout << char(196);
	}
	for (int i = 1; i < height; i++)
	{
		GoTo(original.X, original.Y + i);
		cout << char(179);
	}
	for (int i = 1; i < height; i++)
	{
		GoTo(original.X + width, original.Y + i);
		cout << char(179);
	}
	GoTo(original.X + width / 2, original.Y + height / 2);
	SetColor(Color::Black, textColor);
	cout << centerChar;
	SetColor(Color::Black, Color::White);
}

void Graphic::DrawInvisibleRectangleBySize(Coord original, int width, int height, char centerChar, int textColor)
{
	GoTo(original.X + width / 2, original.Y + height / 2);
	SetColor(Color::Black, textColor);
	cout << centerChar;
	SetColor(Color::Black, Color::White);
}

void Graphic::DrawInvisibleRectangleBySize(Coord original, int width, int height, string centerChar, int textColor)
{
	GoTo(original.X + width / 2 - centerChar.length()/2, original.Y + height / 2);
	SetColor(Color::Black, textColor);
	cout << centerChar;
	SetColor(Color::Black, Color::White);
}
void Graphic::DrawRectangleByCoord(Coord topRight, Coord leftBottom)
{
	GoTo(topRight.X, topRight.Y);
	cout << char(218);
	GoTo(leftBottom.X , topRight.Y);
	cout << char(191);
	GoTo(topRight.X, leftBottom.Y);
	cout << char(192);
	GoTo(leftBottom.X , leftBottom.Y );
	cout << char(217);
	for (int i = 1; topRight.X + i < leftBottom.X; i++)
	{
		GoTo(topRight.X + i, topRight.Y);
		cout << char(196);
	}
	for (int i = 1; topRight.X + i < leftBottom.X; i++)
	{
		GoTo(topRight.X + i, leftBottom.Y );
		cout << char(196);
	}
	for (int i = 1;  topRight.Y + i < leftBottom.Y; i++)
	{
		GoTo(topRight.X, topRight.Y + i);
		cout << char(179);
	}
	for (int i = 1;  topRight.Y + i < leftBottom.Y; i++)
	{
		GoTo(leftBottom.X , topRight.Y + i);
		cout << char(179);
	}
}
void Graphic::DrawSquare(Coord original, int edgeLength)
{
	if(edgeLength%2 != 0)
		DrawRectangleBySize(original, edgeLength-1, edgeLength / 2);
	else
		DrawRectangleBySize(original, edgeLength, edgeLength / 2);

}

void Graphic::DrawSquare(Coord original, int edgeLength, char charCenter, int textColor)
{
	if (edgeLength % 2 != 0)
		DrawRectangleBySize(original, edgeLength - 1, edgeLength / 2,charCenter,textColor);
	else
		DrawRectangleBySize(original, edgeLength, edgeLength / 2, charCenter, textColor);
}

void Graphic::DrawInvisibleSquare(Coord original, int edgeLength, string charCenter, int textColor)
{
	if (edgeLength % 2 != 0)
		DrawInvisibleRectangleBySize(original, edgeLength - 1, edgeLength / 2, charCenter, textColor);
	else
		DrawInvisibleRectangleBySize(original, edgeLength, edgeLength / 2, charCenter, textColor);
}

void Graphic::DrawInvisibleSquare(Coord original, int edgeLength, char charCenter, int textColor)
{
	if (edgeLength % 2 != 0)
		DrawInvisibleRectangleBySize(original, edgeLength - 1, edgeLength / 2, charCenter, textColor);
	else
		DrawInvisibleRectangleBySize(original, edgeLength, edgeLength / 2, charCenter, textColor);
}

int Graphic::DrSquareAndGheightInCoSol(Coord original, int edgeLength, char charCenter, int textColor)
{
	if (edgeLength % 2 != 0)
		DrawRectangleBySize(original, edgeLength - 1, edgeLength / 2, charCenter, textColor);
	else
		DrawRectangleBySize(original, edgeLength, edgeLength / 2, charCenter, textColor);
	return edgeLength / 2;
}

int Graphic::DrInvisibalSquareAndGheightInCoSol(Coord original, int edgeLength, char charCenter, int textColor)
{
	if (edgeLength % 2 != 0)
		DrawInvisibleRectangleBySize(original, edgeLength - 1, edgeLength / 2, charCenter, textColor);
	else
		DrawInvisibleRectangleBySize(original, edgeLength, edgeLength / 2, charCenter, textColor);
	return edgeLength / 2;
}

int Graphic::wherex() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}

int Graphic::wherey() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}

