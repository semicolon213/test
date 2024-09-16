#pragma once


#include <Windows.h>
#include <commdlg.h>
#include <vector>
#include <string>
#include <fstream>
#include <shlwapi.h>

#include "Resource.h"

#pragma comment(lib, "Shlwapi.lib")
#pragma comment(lib, "Comdlg32.lib")

#define ID_FILE_LIST 101


class FileManager
{
private:

	std::vector<std::wstring> fileList;
	 HWND hRightPanel;
	 HWND hFileListBox;
	 HINSTANCE hInst;
	 HWND hWnd;


	 OPENFILENAME OFN;

public:
	static FileManager& getInstance() {
		static FileManager instance;
		return instance;
	}
	
	FileManager();
	FileManager(HWND hWnd);
	~FileManager() = default;
	/*패널 함수*/
	void InitializePanels(HWND hWnd);
	void ResizePanels(HWND hWnd, LPARAM lParam);

	/*버튼 함수*/
	void AddFileToList(const std::wstring& fileName);
	void UpdateFileListUI();
	std::wstring SaveFile();



};