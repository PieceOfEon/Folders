#define _CRT_SECURE_NO_WARNINGS
#define DIRENT_H
#include <direct.h>
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>
#include <windows.h>
#include <tchar.h>
#include<fileapi.h>
#include<TCHAR.H>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include<vector>
#include<conio.h>

using namespace std;

class Papki
{
private:
    string addname;
    string delname;
    string addnametxt;
    
public:
    
    void DelPapka()
    {
        cout << "for example ->>D:\\Test\tor\t->>D:Test\\Test\n";
        cout << "Enter path for folder del: ";
        cin >> delname;
        string path = "" + delname;
        char* p = _strdup(path.c_str());
        if (_rmdir(p) == 0)
        {
            cout << "Directory " << p << " was successfully removed\n";
        }
        else
        {
            cout << "Problem removing directory " << p << ", maybe it's missing\n";
        }
    }

    void Rename()
    {
        cout << "For example D:\\222jjj   to D:\\222\n";
        cout << "Enter path and oldname: ";
        char oldname[50];
        cin >> oldname;
        cout << "Enter path and new name: ";
        char newname[50];
        cin >> newname;
        /*	Deletes the file if exists */
        if (rename(oldname, newname) != 0)
            perror("Error renaming file");
        else
            cout << "File renamed successfully";

    }
    void Disk2()
    {
        DWORD Disks = GetLogicalDrives();
        char temp[2];
        for (int dc = 0; dc < 32; dc++)
        {
            if (Disks & (1 << dc))
            {
                temp[1] = 0;
                temp[0] = 'A' + dc;
                cout << temp << endl;
            }
        }
        
    }

    void CreatePapka()
    {
        cout << "for example ->>D:\\Test\tor\t->>D:Test\\Test\n";
        cout << "Enter path for create: ";
        cin >> addname;
        string path = "" + addname;
        char* p = _strdup(path.c_str());

        if (_mkdir(p) == 0);
        {
            cout << "Directory " << p << " was successfully created\n";
            string dir = "dir ";
            dir += path;
            char* q = _strdup(dir.c_str());
            system(q);
        }
    }

    void Search(string a, string m, unsigned int n) {

        WIN32_FIND_DATAA d;

        if (a.empty() || m.empty()) return;

        string path = a + m;

        if (path.empty()) return;

        HANDLE h = FindFirstFileA(path.c_str(), &d);

        if (!h) return;

        do {

            if (d.cFileName[0] != '.') {

                if (d.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {

                    for (unsigned int j = 0; j < n; j++) cout << "  ";

                    cout << a << d.cFileName << endl;
                    string new_path = a + d.cFileName + "\\";

                    Search(new_path, m, n + 1);

                }
                else {

                    for (unsigned int j = 0; j < n; j++) cout << "  ";

                    cout << "   " << d.cFileName << endl;
                }
            }
        } while (FindNextFileA(h, &d));
    }

    void move()
    {
        cout << "For example ->>\nfor file->> move D:\\rtff* D:\\Dota\nfor folder->>move D:\\Folder D:\\Folder2\n";
        cout << "Enter path and name move to file: ";
        string mo;
        getline(cin, mo);
        char* m= _strdup(mo.c_str());
        system(m);
    }
};

int main(void)
{
    Papki Pa;
    string path;
    char vvod;
    do
    {
        system("cls");
        cout << "1 - Search\n";
        cout << "2 - Add folder\n";
        cout << "3 - Del folder\n";
        cout << "4 - Rename\n";
        cout << "5 - Name disk\n";
        cout << "6 - move file and folder\n";
        cout << "Exit - Esc\n";
        vvod = _getch();
        switch (vvod)
        {
        case'1':
        {
            cout<< "for example ->>D:\\Lineage 2\\\tor\t->>D:\\\n";
            cout << "START: ";
            getline(cin,path);
            Pa.Search(path, "*.*", 0);
            system("pause");
            break;
        }
        case'2':
        {
            Pa.CreatePapka();
            system("pause");
            break;
        }
        case'3':
        {
            Pa.DelPapka();
            system("pause");
            break;
        }
        case'4':
        {
            Pa.Rename(); //tak je mojno menat' format faila
            system("pause");
            break;
        }
        case'5':
        {
            Pa.Disk2();
            system("pause");
            break;
        }
        case'6':
        {
            Pa.move();
            system("pause");
            break;
        }
        }

    } while (vvod != 27);
}