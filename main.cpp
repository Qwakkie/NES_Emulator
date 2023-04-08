#include <iostream>
#include <Windows.h>

#include "FileSelector.h"

int main()
{
    FileSelector fileSelector{};
    bool result = fileSelector.OpenFile();
    switch (result)
    {
        if (result)
        {
            printf("SELECTED FILE: %s\nFILE PATH: %s\n\n", fileSelector.GetSelectedFile().c_str(), fileSelector.GetFilePath().c_str());
            system("pause");
        }
        else
        {
            printf("ENCOUNTERED AN ERROR: (%d)\n", GetLastError());
            system("pause");
        }
    }
    return 0;
}