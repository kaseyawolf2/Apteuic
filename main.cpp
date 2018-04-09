#include "main.h"

int main() {
    if (MainInit() != 0){
        Console::Log("Failed to Init");
    }
    

    return 0;
}




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
    }

    return 0;
}