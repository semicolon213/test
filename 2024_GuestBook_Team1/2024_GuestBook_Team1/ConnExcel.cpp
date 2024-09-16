/**
@file ConnExcel.cpp
@brief �������� Ŭ���� �ܺ� ���� ����
*/

#include "ConnExcel.h"
using namespace std;

/**
@fn  ConnExcel::insertExcel(const wchar_t* excelPath, const wchar_t* visitName)
@brief ���޵� ���� �̸� ������ �����ϴ� �Լ�
@param excelPath ������ ������
@param visitName ����������̸�(�湮�ڸ�)
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
            /// ù ��° ���� ����� ���
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
        cerr << "���� ���� ����!" << endl;
    }


    if (ofile.is_open())
    {
        ofile << wcharToChar(visitName)<< ",";
        ofile.close();
    }
    else
    {
        cerr << "���� ���� ����!" << endl;
    }

 }

wstring ConnExcel::getVisitList() 
{
    ofstream ofile(EXCEL, ios::app);
    ifstream ifile(EXCEL); 
    bool hasHeader = false;

    string line;
    string getVisit = "�湮�� �ֽ� �е� :\t";
    if (ifile.is_open())
    {
        if (getline(ifile, line))
        {
            /// ù ��° ���� ����� ���
            hasHeader = true;
        }

        while (getline(ifile, line))
        {
            getVisit = getVisit.append(line.append("��\t"));
        }
        ifile.close();
    }
    else
    {
        cerr << "���� ���� ����!" << endl;
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
        throw runtime_error("�ʿ��� ������ ũ�⸦ ����ϴµ� �����߽��ϴ�");
    }
    string charStr(strSize, 0);

    int result = WideCharToMultiByte(CP_ACP, 0, wcharStr.c_str(), -1, &charStr[0], strSize, NULL, NULL);
    if (result == 0) 
    {
        throw runtime_error("wstring to string ��ȯ ����...");
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
        throw runtime_error("�ʿ��� ������ ũ�⸦ ����ϴµ� �����߽��ϴ�.");
    }
    wstring wcharStr(wStrSize, 0);

    int result = MultiByteToWideChar(CP_ACP, 0, charStr.c_str(), -1, &wcharStr[0], wStrSize);
    wcharStr.resize(wStrSize - 1);
    if (result == 0)
    {
        throw runtime_error("string to wstring ��ȯ ����...");
    }

    return wcharStr;
}