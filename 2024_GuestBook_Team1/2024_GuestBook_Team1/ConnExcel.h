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


using namespace std;

class ConnExcel
{
public:

	void insertExcel(const string, const wstring);

private:

	wstring uniVisit;
	string multiVisit;

	string wcharToChar(const wstring);
	
};

