// basic file operations
#include "File.h"
using namespace std;

void LoadCellFile() {
    ifstream inFile;
    inFile.open("/home/kasey/Documents/Apteuic/Test.txt");

    if (!inFile) {
        cerr << "Unable to open file : Cells.txt";
        return;
    }

    int x;
    while (inFile >> x) {
    }
     
    
    inFile.close();

}