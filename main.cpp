#include "main.h"

int main(int argc, char* args[]) {

bool NewGame = false;
bool QuitProgram = false;

    if(NewGame){
        if (NewInit() != 0){
            Console::Log("Failed to Init");
        }
    }

    Window window(500, 500);


    SDL_Event E;
    while(!QuitProgram){
        while( SDL_PollEvent( &E )) {
            if(E.type == SDL_QUIT ){
                QuitProgram = true;
            }
        }


    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( window.renderer, 255, 0, 0, 255 );

    // Clear winow
    SDL_RenderClear( window.renderer );

    // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
   

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( window.renderer, 0, 0, 255, 255 );

    // Render rect
    SDL_RenderFillRect( window.renderer, &r );

    SDL_RenderPresent(window.renderer);



    

    //SDL_GL_SwapWindow(window.window);
    }

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