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
    }

    return 0;
}

int main() {
    if (MainInit() != 0){
        Console::Log("Failed to Init");
    }
    std::cout<<NumCellsTol<<std::endl;
    

    return 0;
}