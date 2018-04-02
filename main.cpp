#include "defines.h"
#include "Cell.h"
#include "Console.h"
#include <iostream>
//Globals
Cell GameCells[NumCellsTol];

int MainInit(){
    Console::Log("Starting Init");
    for(int i = 0;i < NumCellsTol;i++){
        if(!CheckCell(GameCells[i])){
            std::cout << "Problem with Cell: " << i << std::endl;
            PostLogs(GameCells[i]);
            return 1;
        }
        GameCells[i].X = i % NumCellsX;
        GameCells[i].Y = i % (NumCellsY;
        GameCells[i].Z = i % NumCellsZ;
    }

    return 0;
}
void PressureBal();

int main() {
    if (MainInit() != 0){
        Console::Log("Failed to Init");
    }
    GameCells[0].Pressure = 5;
    PressureBal();
    PostLogs(GameCells[0]);
    PostLogs(GameCells[1]);
    PostLogs(GameCells[2]);
    PostLogs(GameCells[3]);
    


    return 0;
}

void PressureBal() {
    for(int cx = 0;cx < NumCellsX;cx++){
        for (int cy = 0; cy < NumCellsY; cy++){
            for (int cz = 0; cz < NumCellsZ; cz++){
                
                float add = 0.0f;
                float numadd = 0.0f;

                if (Get_CellPostition(cx-1,cy,cz) != -1){            
                    add += GameCells[Get_CellPostition(cx-1,cy,cz)].Pressure;
                    numadd += 1;
                }
                if (Get_CellPostition(cx,cy-1,cz) != -1){            
                    add += GameCells[Get_CellPostition(cx,cy-1,cz)].Pressure;
                    numadd += 1;
                }
                if (Get_CellPostition(cx+1,cy,cz) != -1){            
                    add += GameCells[Get_CellPostition(cx+1,cy,cz)].Pressure;
                    numadd += 1;
                }
                if (Get_CellPostition(cx,cy+1,cz) != -1){            
                    add += GameCells[Get_CellPostition(cx,cy+1,cz)].Pressure;
                    numadd += 1;
                }
                add += GameCells[Get_CellPostition(cx,cy,cz)].Pressure;
                numadd += 1;
                
                float ave = add/numadd;                
            }
        }
    }
}