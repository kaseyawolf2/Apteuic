#pragma once
#include<iostream>

struct Ter {
    int Ter_ID;
    float Fertility;
};

struct Cell {
    int X;
    int Y;
    float WindSpeed;
    float WindDirection;
    float Temp;
    float Humidity;
    float Pressure;
    Ter Terrain;    
};
int Get_CellPostition(int x,int y);
Cell Get_AdjCell(Cell OrginalCell, std::string Dir);
void PostLogs(Cell cell);
void InitCell(Cell &cell);
bool CheckCell(Cell &cell);