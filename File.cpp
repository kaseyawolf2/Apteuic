// basic file operations
#include "File.h"
#include <vector>
using namespace std;

vector<Cell> LoadCellFile() {

    
    ifstream inFile;
    inFile.open("/home/kasey/Documents/Apteuic/Cells.txt");

    if (!inFile) {
        cerr << "Unable to open file : Cells.txt";
        vector<Cell> TempVec;    
        Cell Empty;
        Empty.X = -1;
        Empty.Y = -1;
        Empty.Z = -1;
        TempVec.push_back(Empty);
        return TempVec;
    }
    vector<Cell> TempVec;
    Cell TempCel;
    int Cellnum;
    inFile >> Cellnum;
    for (size_t i = 0; i < Cellnum; i++)
    {    
    inFile >> TempCel.X;
    inFile >> TempCel.Y;
    inFile >> TempCel.Z;
    inFile >> TempCel.Humidity;
    inFile >> TempCel.Pressure;
    inFile >> TempCel.Temp;
    inFile >> TempCel.WindDirection;
    inFile >> TempCel.WindSpeed;
    TempVec.push_back(TempCel);
    }
    
    inFile.close();
    if(!TempVec.empty()){
        return TempVec;
    }
}
void SaveCellFile(vector<Cell> GameCells) {
    ofstream OutFile;
    OutFile.open("/home/kasey/Documents/Apteuic/Cells.txt");

    if (!OutFile) {
        cerr << "Unable to open file : Cells.txt";
        return;
    }

    OutFile << GameCells.size() << " ";

    for (unsigned int i = 0; i < GameCells.size(); i++)
    {
        OutFile << GameCells[i].X << " " << GameCells[i].Y << " " << GameCells[i].Z << " " << GameCells[i].Humidity << " " << GameCells[i].Pressure << " " << GameCells[i].Temp << " " << GameCells[i].WindDirection<< " " << GameCells[i].WindSpeed << " ";
        
    }
     
    
    OutFile.close();

}