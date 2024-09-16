/**
@file ConnExcel.h
@brief ¿¢¼¿°ü·Ã Å¬·¡½º ¸â¹ö Á¤ÀÇ ÆÄÀÏ
*/

#pragma once


#include <Windows.h>
#include <iostream>
#include <codecvt>
#include <locale>
#include <string>
#include <fstream>

#include <comdef.h>
#include <tchar.h>

#include "Resource.h"


using namespace std;

class ConnExcel
{
public:

	void insertExcel(const wstring);
	wstring getVisitList();
	void textMove(HWND, int);

private:

	wstring uniVisit;
	string multiVisit;

	string wcharToChar(const wstring);
	wstring charToWchar(const string);

	void onTimer(HWND, int);
	int getTextSize(HWND);

	int textPosX;
	int textWidth = 0;
	RECT clientWidth;
	RECT textSize;
};