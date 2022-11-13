#include<iostream>
#include<string>
using namespace std;

extern void menu();
extern void show_menu();
extern wstring** enter_name_computer();
extern wstring** enter_name_cpu();
extern wstring** enter_name_vid_graphic();
extern char** enter_osu();
extern char** enter_ssd();
int startupAuthoriz(int argsC,
    char* argsV[])

{
    int passwordLength = 0;
    for (int argumentIndex = 1;
        argumentIndex < argsC;
        argumentIndex++)
    {
        const char* argK = argsV[argumentIndex];
        const char* argV = argsV[argumentIndex + 1];
        if (strcmp(argK, "-login") == 0)
        {
            std::cout << "�� �������������� ��\t" << argV << endl;
        }
        else
        {
            if (strcmp(argK, "-password") == 0)
            {
                passwordLength = strlen(argV);
                break;
            }
        }
    }



    return passwordLength;
}
int main(int argsC,
    char* argsV[],
    char* environmentParameters[]
)
{

    setlocale(LC_ALL, "");

    if (argsC > 1)
    {
        return startupAuthoriz(argsC, argsV);
    }
    else
    {
        menu();
    }

    cin.get();
    return 0;
}

#ifndef INPUT_MAIN_SAMPLE_H
#define INPUT_MAIN_SAMPLE_H

void show_menu()
{

    wcout << L"����i�� ����� ����:" << endl;
    wcout << L"1.) ������ ����� ��������" << endl;
    wcout << L"2.) ������ ������" << endl;
    wcout << L"3.) ����� ��������������" << endl;
    wcout << L"4.) ��������� ������" << endl;

}
wstring** enter_name_cpu()
{
    wstring* cpu = new wstring();
    wcout << L"����i�� ����� ���������:" << endl;
    wcin.ignore();
    getline(wcin, *cpu);

    return &cpu;
}
wstring** enter_name_vid_graphic()
{
    wstring* vid_graphic = new wstring();
    wcout << L"����i�� ����� �i��������:" << endl;
    wcin.ignore();
    getline(wcin, *vid_graphic);

    return &vid_graphic;
}
wstring** enter_name_computer()
{
    wstring* comp = new wstring();
    wcout << L"����i�� ����� ��������:" << endl;
    wcin.ignore();
    getline(wcin, *comp);

    return &comp;
}
char** enter_osu()
{
    const short int MAX_PASSWORD_LENGTH = 16;
    char* osu = new char[MAX_PASSWORD_LENGTH];

    wcout << L"����i�� ��� ���:" << endl;
    cin >> osu;
    return &osu;
}
char** enter_ssd()
{
    const short int MAX_PASSWORD_LENGTH = 16;
    char* ssd = new char[MAX_PASSWORD_LENGTH];

    wcout << L"����i�� ��� �����i :" << endl;
    cin >> ssd;
    return &ssd;
}
void menu()
{
    short int selectedMenuItem = 1;
    wstring comp = L"";
    wstring cpu = L"";
    wstring vid_graphic = L"";

    char* osu = nullptr;
    char* ssd = nullptr;
    show_menu();
    cin >> selectedMenuItem;
    switch (selectedMenuItem)
    {
    case 1:
        comp = **enter_name_computer();
        break;
    case 2:
        osu = *enter_osu();

        ssd = *enter_ssd();
        break;
    case 3:
        comp = **enter_name_computer();
        osu = *enter_osu();
        ssd = *enter_ssd();
        cpu = **enter_name_cpu();
        vid_graphic = **enter_name_vid_graphic(); 
        break;
    case 4:
    default:

        exit(0);
    }

    if (!comp.empty())
    {
        wcout << L"����� ��������:\t" << comp << endl;
    }
    if (!cpu.empty())
    {
        wcout << L"����� ��������� :\t" << cpu << endl;
    }
    if (!vid_graphic.empty())
    {
        wcout << L"����� �i��������:\t" << vid_graphic << endl;
    }
    
   
        if (osu != nullptr)
        {


            wcout << L"��� �����i ���:"
                << osu << endl;
            delete[] osu;
        }

        if (ssd != nullptr)
        {


            wcout << L"��� �����i SSD:"
                << ssd << endl;
            delete[] ssd;
        }
    
}
#endif