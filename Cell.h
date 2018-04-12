#pragma once
#include "defines.h"
#include "Console.h"
#include <iostream>
#include <vector>

struct Room {
    std::vector<int> ListCellsPos;
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
};

int Get_CellPostition(int x,int y,int z);
Cell Get_AdjCell(Cell OrginalCell, std::string Dir);
void PostLogs(Cell cell);
void InitCell(Cell &cell);
bool CheckCell(Cell &cell);
void BalPressure(Room RoomToBal, std::vector<Cell> GameCells);