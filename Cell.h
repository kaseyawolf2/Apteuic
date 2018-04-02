#pragma once
#include<iostream>


struct Mat { 

};

struct Ter {
    int Ter_ID;
    float Fertility;
    Mat Material;

};


struct Cell {
    int X;
    int Y;
    int Z;
    float WindSpeed;
    float WindDirection;
    float Temp;
    float Humidity;
    float Pressure;
    Ter Terrain;    
};
int Get_CellPostition(int x,int y,int z);
Cell Get_AdjCell(Cell OrginalCell, std::string Dir);
void PostLogs(Cell cell);
void InitCell(Cell &cell);
bool CheckCell(Cell &cell);