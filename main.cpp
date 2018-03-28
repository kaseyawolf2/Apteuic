#include "defines.h"
#include "Cell.h"
#include <iostream>
namespace Console {
    void Log(const char* Text){
        std::cout << Text << std::endl;
        return;
    }
}
//Globals
Cell GameCells[TolCells];

int MainInit(){
    Console::Log("Starting Init");
    GameCells[3].X=6;
    for(int i = 0;i < TolCells;i++){
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
    

    return 0;
}