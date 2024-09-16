#pragma once

#include <Windows.h>
#include <mutex>
#include <memory>
#include <thread>

#include "framework.h"

#include "BlueWindow.h"
#include "DrowWindow.h"
#include "FileManager.h"
#include "Function.h"
#include "ColorPalette.h"
#include "ConnExcel.h"
#include "Struct.h"

#define MAX_LOADSTRING 100



static RECT DesktopRT;      //사용자 화면 크기 받기용
static RECT MainRT;         //메인 윈도우 크기 받기용

using namespace std;

class Window
{
private :
	HINSTANCE hInst;
	HWND hWnd;
	
	static LRESULT CALLBACK StaticWndProc(HWND, UINT, WPARAM, LPARAM);
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	static INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

	int getClientWidth();

	RECT clientWidth;

	static unique_ptr<Window> sinTonIns;
	static once_flag flag;

	unique_ptr<Function> function;
	unique_ptr<FileManager> fileManager;
	unique_ptr<ColorPalette> colorPalette;
	unique_ptr<DrowWindow> dWindow;
	unique_ptr<BlueWindow> pBW;
	unique_ptr<ConnExcel> excel;


	HWND SideMenu = NULL;
	HWND d_hWnd = nullptr;
	HWND b_hWnd = nullptr;

	PINFO drawPInfo;

	int penNum = 0;

	int px, py;

	bool LBState = false;

public :
	Window() = default;
	~Window() = default;

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	WCHAR szTitle[MAX_LOADSTRING];
	WCHAR szWindowClass[MAX_LOADSTRING];

	ATOM MyRegisterClass(HINSTANCE);
	BOOL InitInstance(HINSTANCE, int);

	static Window* GetInstance();

};

