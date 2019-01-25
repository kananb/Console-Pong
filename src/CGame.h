#ifndef GUARD_CGAME_H
#define GUARD_CGAME_H
#pragma once


#include <windows.h>
#include <vector>
#include <string>


const COLORREF pDefaultColorTable[16] = {
		RGB(0, 0, 0), RGB(0, 0, 128), RGB(0, 128, 0), RGB(0, 128, 128),
		RGB(128, 0, 0), RGB(128, 0, 128), RGB(128, 128, 0), RGB(192, 192, 192),
		RGB(128, 128, 128), RGB(0, 0, 255), RGB(0, 255, 0), RGB(0, 255, 255),
		RGB(255, 0, 0), RGB(255, 0, 255), RGB(255, 255, 0), RGB(255, 255, 255) };


class CGame {

public:


	CGame(SHORT nScreenWidth, SHORT nScreenHeight);
	CGame(SHORT nScreenWidth, SHORT nScreenHeight, COLORREF pColorTable[16]);
	~CGame();



	void ClearScreen();
	void DrawRect(INT X, INT Y, INT nRectWidth, INT nRectHeight, CHAR chFillCharacter, INT nColor);
	void FillRect(INT X, INT Y, INT nRectWidth, INT nRectHeight, CHAR chFillCharacter, INT nColor);
	void DrawLine(INT X1, INT Y1, INT X2, INT Y2, CHAR chFillCharacter, INT nColor);
	void DrawPixel(INT X, INT Y, CHAR chFillCharacter, INT nColor);
	void DrawString(INT X, INT Y, const CHAR * szFillString, SIZE_T nStringLen, INT nColor);

	BOOL FlushBuffer();



	SHORT GetWidth() const { return nScreenWidth; }
	SHORT GetHeight() const { return nScreenHeight; }
	INT GetResolution() const { return nScreenResolution; }

	const std::string & GetTitle() { return szTitle; }
	void SetTitle(const std::string& szTitle);


private:


	BOOL GetConsoleHandle(const COLORREF pColorTable[16] = pDefaultColorTable);

	
	std::string szTitle;
	SHORT nScreenWidth, nScreenHeight;
	INT nScreenResolution;

	HANDLE hConsole;
	SMALL_RECT srBufferRect;
	CONSOLE_SCREEN_BUFFER_INFOEX csbi;

	std::vector<CHAR_INFO> rgScreenBuffer;


};

#endif // GUARD_CGAME_H