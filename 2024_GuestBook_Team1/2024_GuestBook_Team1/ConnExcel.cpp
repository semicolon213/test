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

void ConnExcel::insertExcel(const string excelPath, const wstring visitName)
{

    ofstream ofile(excelPath,ios::app);
    ifstream ifile(excelPath);
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


string ConnExcel::wcharToChar(const wstring wcharStr)
{

    int strSize = WideCharToMultiByte(CP_ACP, 0, wcharStr.c_str(), -1, NULL, 0, NULL, NULL);
    if (strSize <= 0) {
        throw runtime_error("�ʿ��� ������ ũ�⸦ ����ϴµ� �����߽��ϴ�");
    }
    string charStr(strSize, 0);

    int result = WideCharToMultiByte(CP_ACP, 0, wcharStr.c_str(), -1, &charStr[0], strSize, NULL, NULL);
    if (result == 0) {
        throw std::runtime_error("��ȯ ����...");
    }
    size_t lastDot = charStr.find_last_of('.');
    if (lastDot != string::npos) {
         return charStr.substr(0, lastDot);
    }

    return charStr;

}