// basic file operations
#include "File.h"
using namespace std;

vector<Cell> LoadCellFile(std::string SaveName) {

    
    ifstream inFile;
    std::string Open = "./Saves/";
    Open += SaveName;
    Open += "/Cells.txt";

    inFile.open(Open.c_str());

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
    for (int i = 0; i < Cellnum; i++)
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
void SaveCellFile(vector<Cell> GameCells, std::string SaveName) {
    ofstream OutFile;
    std::string Open = "./Saves/";
    Open += SaveName;
    Open += "/Cells.txt";
    
    OutFile.open(Open.c_str());

    if (!OutFile) {
        cerr << "Unable to Save to file : Cells.txt";
        return;
    }

    OutFile << GameCells.size() << " ";

    for (unsigned int i = 0; i < GameCells.size(); i++)
    {
        OutFile << GameCells[i].X << " " << GameCells[i].Y << " " << GameCells[i].Z << " " << GameCells[i].Humidity << " " << GameCells[i].Pressure << " " << GameCells[i].Temp << " " << GameCells[i].WindDirection<< " " << GameCells[i].WindSpeed << " ";
    }
     
    
    OutFile.close();

}