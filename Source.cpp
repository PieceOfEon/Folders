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


using namespace std;

class Papki
{
private:
    string addname;
    string delname;
    string addnametxt;
    
    
 /*   struct _finddata_t {
        unsigned    attrib;
        time_t      time_create;
        time_t      time_access;
        time_t      time_write;
        _fsize_t    size;
        char        name[260];
    };*/
public:
    

    void searchpath(const char* file)
    {
        
       /* char* res;*/

       /* res = searchpath(file);*/

        if (strlen(file) == 0)
            cout << file << " not found\n";
        else
            cout << file << " found in %s\n"; /*printf("DMC.EXE found in %s\n", file);*/
       /* return res;*/
        /*return;*/
    }

    void CreateTxt()
    {
        cout << "Enter folder name: ";
        cin >> addnametxt;
        string path = "\\" + addname+".txt";
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

   void Inform()
    {
       /*setlocale(LC_ALL, "");
       HANDLE search_file;
       WIN32_FIND_DATA aa;
       search_file = FindFirstFile("C:\\*", &aa);
       while (FindNextFile(search_file, &aa) != NULL)
       {
           cout << aa.cFileName << "\n";
       }*/
        /*std::string path = "путь к папке";
        GetFileAttributes
        for (const auto& entry : FileIdInfo()::directory_iterator(path))
            std::cout << entry.path() << std::endl;*/
       /* string infpapka;
        cout << "Enter folder name getInf: ";
        cin >> infpapka;
        string path = "\\" + infpapka;
       
        char* q = _strdup(infpapka.c_str());
        system(q);*/
        /*if (_mkdir(p) == 0);
        {
            cout << "Directory " << p << " was successfully created\n";
            string dir = "dir ";
            dir += path;
            char* q = _strdup(dir.c_str());
            system(q);

        }*/

    }

    void DelPapka()
    {
        cout << "Enter folder name: ";
        cin >> delname;
        string path = "\\" + delname;
        char* p = _strdup(path.c_str());
        if (_rmdir(p) == 0)
        {
            cout << "Directory " << p << " was successfully removed\n";
        }
        else
        {
            cout << "Problem removing directory " << p << ", maybe she's missing\n";
        }

    }

    void RenameFolder()
    {
        char old_name[] = "D:\\jjj";

        char new_name[] = "D:\\222jjj";
        int value;

        // File name is changed here
        value = rename(old_name, new_name);

        // Print the result
        if (!value)
        {
            printf("%s", "File name changed successfully");
        }
        else
        {
            perror("Error");
        }
    }

    void Search2(int argc, TCHAR* argv[])
    {
        WIN32_FIND_DATA FindFileData;
        HANDLE hFind;

        if (argc != 2)
        {
            _tprintf(TEXT("Usage: %s [target_file]\n"), argv[0]);
            return;
        }

        _tprintf(TEXT("Target file is %s\n"), argv[1]);
        hFind = FindFirstFile(argv[1], &FindFileData);
        if (hFind == INVALID_HANDLE_VALUE)
        {
            printf("FindFirstFile failed (%d)\n", GetLastError());
            return;
        }
        else
        {
            _tprintf(TEXT("The first file found is %s\n"),
                FindFileData.cFileName);
            FindClose(hFind);
        }
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
        cout << "Enter folder name: ";
        cin >> addname;
        string path = "\\" + addname;
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

    void my_search_tree(string dir, string mask, unsigned int depth) {

        WIN32_FIND_DATAA d;

        if (dir.empty() || mask.empty()) return;

        string path = dir + mask;

        if (path.empty()) return;

        HANDLE h = FindFirstFileA(path.c_str(), &d);

        if (!h) return;

        do {

            if (d.cFileName[0] != '.') {

                if (d.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {

                    for (unsigned int j = 0; j < depth; j++) cout << "  ";

                    cout << dir << d.cFileName << endl;
                    string new_path = dir + d.cFileName + "\\";

                    my_search_tree(new_path, mask, depth + 1);

                }
                else {

                    for (unsigned int j = 0; j < depth; j++) cout << "  ";

                    cout << "   " << d.cFileName << endl;
                }
            }
        } while (FindNextFileA(h, &d));
    }
 
};

int main(void)
{
    Papki Pa;
   /* Pa.CreatePapka();
    Pa.DelPapka();*/
    /*Pa.CreatePapka();*/
    /*Pa.Search();*/
    /*Pa.Disk2();*/
   /* Pa.Inf();*/
    /*Pa.CreatePapka();*/
    string path = "D:\\Lineage 2\\";
    cout << "START: " << path << endl;

    Pa.my_search_tree(path, "*.*", 0);
   /* Pa.Inform();*/
    //char curdir[MAXPATH]; //объявляем строку

    //Pa.GetCurrentDir(curdir); //записываем в строку текущий путь

    //printf("\nТекущая папка %s", curdir);

    ////переходим на диск С, в корневой каталог.
    //chdir("c:\\");

    ////создаём папку c названием: "freedom"
    //mkdir("freedom");

    ////возвращаемся назад
    //chdir(curdir);

    /*vector<string>file;
    file.push_back("1.bmp");
    Pa.dfsFolder("D:", file);*/
    
   
  /*  WIN32_FIND_DATA FindFileData = FILE_ATTRIBUTE_DIRECTORY;
    HANDLE hFind;

    hFind = FindFirstFile("*", &FindFileData);
    if (hFind == INVALID_HANDLE_VALUE)
        return 1;
    else
    {
        cout << FindFileData.cFileName << endl;
        FindClose(hFind);
        return 0;
    }*/
   /* Pa.TEST2();*/

  

    /*if (_mkdir("\\testtmp") == 0)
    {
        printf("Directory '\\testtmp' was successfully created\n");
        system("dir \\testtmp");
        if (_rmdir("\\testtmp") == 0)
            printf("Directory '\\testtmp' was successfully removed\n");
        else
            printf("Problem removing directory '\\testtmp'\n");
    }
    else
        printf("Problem creating directory '\\testtmp'\n");*/
}