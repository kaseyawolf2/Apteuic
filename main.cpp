#include "defines.h"
#include "Cell.h"
#include "Console.h"
#include <iostream>
//Globals
Cell GameCells[NumCellsTol];

int MainInit(){
    Console::Log("Starting Init");
    int x = 0;
    int y = 0;
    int z = 0;
    for(int i = 0;i < NumCellsTol;i++){
        if(!CheckCell(GameCells[i])){
            std::cout << "Problem with Cell: " << i << std::endl;
            PostLogs(GameCells[i]);
            return 1;
        }

        GameCells[i].X = x;
        GameCells[i].Y = y;
        GameCells[i].Z = z;
        if (x < (NumCellsX - 1))
        {
            x++;
        }
        else if (x == (NumCellsX - 1) && y < (NumCellsY - 1))
        {
            x = 0;
            y++;
        }
        else if (x == (NumCellsX - 1) && y == (NumCellsY - 1))
        {
            x = 0;
            y = 0;
            z++;
        }
        if (x > NumCellsX || y > NumCellsY || z > NumCellsZ)
        {
            Console::Log("Position out of bound");
        }
        PostLogs(GameCells[i]);
    }

    return 0;
}
void PressureBal();

int main() {
    if (MainInit() != 0){
        Console::Log("Failed to Init");
    }
    GameCells[0].Pressure = 5;
    //PressureBal();
    


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