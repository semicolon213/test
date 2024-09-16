/**
@file ConnExcel.cpp
@brief 엑셀관련 클래스 외부 정의 파일
*/

#include "ConnExcel.h"
using namespace std;

/**
@fn  ConnExcel::insertExcel(const wchar_t* excelPath, const wchar_t* visitName)
@brief 전달된 파일 이름 엑셀로 저장하는 함수
@param excelPath 엑셀의 저장경로
@param visitName 저장된파일이름(방문자명)
*/

void ConnExcel::insertExcel(const wstring visitName)
{

    ofstream ofile(,ios::app);
    ifstream ifile(EXCEL);
    bool hasHeader = false;

    int rowCnt = 0;

    string line;
    if (ifile.is_open()) 
    {
        if (getline(ifile, line)) 
        {
            /// 첫 번째 행이 헤더인 경우
            hasHeader = true;
        }

        while (getline(ifile, line)) 
        {
            rowCnt++;
        }
        ifile.close();
    }
    else 
    {
        cerr << "파일 열기 실패!" << endl;
    }


    if (ofile.is_open())
    {
        ofile << wcharToChar(visitName)<< ",";
        ofile.close();
    }
    else
    {
        cerr << "파일 열기 실패!" << endl;
    }

 }

wstring ConnExcel::getVisitList() 
{
    ofstream ofile(EXCEL, ios::app);
    ifstream ifile(EXCEL); 
    bool hasHeader = false;

    string line;
    string getVisit = "방문해 주신 분들 :\t";
    if (ifile.is_open())
    {
        if (getline(ifile, line))
        {
            /// 첫 번째 행이 헤더인 경우
            hasHeader = true;
        }

        while (getline(ifile, line))
        {
            getVisit = getVisit.append(line.append("님\t"));
        }
        ifile.close();
    }
    else
    {
        cerr << "파일 열기 실패!" << endl;
    }

    return charToWchar(getVisit);
}

void ConnExcel::onTimer(HWND hWnd, int clientWidth)
{
    textPosX -= TEXTSPEED;

    if (textPosX < getTextSize(hWnd))
    {
        textPosX = clientWidth;
    }
    InvalidateRect(hWnd, NULL, FALSE);
}



int ConnExcel::getTextSize(HWND hWnd)
{
    HDC hdc = GetDC(hWnd);
    const WCHAR* list = getVisitList().c_str();
    DrawText(hdc, list, -1, &textSize, DT_SINGLELINE | DT_NOCLIP | DT_CALCRECT);

    return textSize.right - textSize.left;
}


void ConnExcel::textMove(HWND hWnd, int clientWidth)
{
        
}

string ConnExcel::wcharToChar(const wstring wcharStr)
{

    int strSize = WideCharToMultiByte(CP_ACP, 0, wcharStr.c_str(), -1, NULL, 0, NULL, NULL);
    if (strSize <= 0) {
        throw runtime_error("필요한 버퍼의 크기를 계산하는데 실패했습니다");
    }
    string charStr(strSize, 0);

    int result = WideCharToMultiByte(CP_ACP, 0, wcharStr.c_str(), -1, &charStr[0], strSize, NULL, NULL);
    if (result == 0) 
    {
        throw runtime_error("wstring to string 변환 실패...");
    }
    size_t lastDot = charStr.find_last_of('.');
    if (lastDot != string::npos) 
    {
         return charStr.substr(0, lastDot);
    }

    return charStr;

}

wstring ConnExcel::charToWchar  (const string charStr)
{
    
    int wStrSize = MultiByteToWideChar(CP_ACP, 0, charStr.c_str(), -1, nullptr, 0);
    if (wStrSize <= 0)
    {
        throw runtime_error("필요한 버퍼의 크기를 계산하는데 실패했습니다.");
    }
    wstring wcharStr(wStrSize, 0);

    int result = MultiByteToWideChar(CP_ACP, 0, charStr.c_str(), -1, &wcharStr[0], wStrSize);
    wcharStr.resize(wStrSize - 1);
    if (result == 0)
    {
        throw runtime_error("string to wstring 변환 실패...");
    }

    return wcharStr;
}