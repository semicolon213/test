/**
@file RegisterList.h
@brief 방문자 명단 전광판 클래스 멤버 정의 파일
*/

#pragma once
#include <Windows.h>


class RegisterList
{
private :
	int listPos = 0;
	int sWidth = 0;
	int listWidth = 0;

	SIZE size;
	LPCWSTR list = L"방문해 주신 분들 : Test1, Test2, Test3, Test4";

public :
	void timer(HWND);
	void paint(HDC);
	void getsWidth(LPARAM);

};

