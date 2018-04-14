#include "main.h"

int main(int argc, char* args[]) {

bool NewGame = false;

    if(NewGame){
        if (NewInit() != 0){
            Console::Log("Failed to Init");
        }
    }

    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );
    














    
    //Quit SDL
    SDL_Quit();
    return 0;
}




int NewInit() {
    Console::Log("Starting Init");
    #pragma region AssignXYZ
    int x = 0;
    int y = 0;
    int z = 0;
    for(int i = 0;i < NumCellsTol;i++){
        Cell Temp;
        Temp.X = x;
        Temp.Y = y;
        Temp.Z = z;
        Temp.Humidity = 0;
        Temp.Pressure = 0;
        Temp.Temp = 0;
        Temp.WindDirection = 0;
        Temp.WindSpeed = 0;

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
        



        GameCells.push_back(Temp);
    }
    #pragma endregion
    
    return 0;
}