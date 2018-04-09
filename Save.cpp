// basic file operations
#include "Save.h"
using namespace std;

int Save(std::string SaveName) {
    std::string SaveFileName = SaveName + ".txt";
    if(Backup(SaveFileName,SaveName + ".bak") != 0){
        Console::Log("Backup Failed");
        return 1;
    }

FILE *file;
    int file_exists;
    const char * filename="my_file.txt";
    
    /*first check if the file exists...*/
    file=fopen(filename,"r");
    if (file==NULL) file_exists=0;
    else {file_exists=1; fclose(file);}
    
    /*...then open it in the appropriate way*/
    if (file_exists==1)
    {
       printf("file exists!\n");
       file=fopen(filename,"r+b");
    }
    else
    {
        printf("file does not exist!\n");
        file=fopen(filename,"w+b");
    }
    
    if (file!=NULL)
    {
       printf ("file opened succesfully!\n");
       fclose(file);
    }



    return 0;
}

int Backup(std::string CopyFile,std::string NewFile ){

    return 0;
}