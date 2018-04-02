#include "Cell.h"
#include "defines.h"
#include "Console.h"

struct Cell;
struct Ter;
void PostLogs(Cell cell){
    std::cout << "X:" << cell.X << std::endl;
    std::cout << "Y:" << cell.Y << std::endl;
    std::cout << "Z:" << cell.Z << std::endl;
    std::cout << "Wind Direction:" << cell.WindDirection << std::endl;
    std::cout << "Wind Speed:" << cell.WindSpeed << std::endl;
    std::cout << "Temp:" << cell.Temp << std::endl;
    std::cout << "Humidity:" << cell.Humidity << std::endl;
    std::cout << "Pressure:" << cell.Pressure << std::endl;
    Console::Log("");
}
bool CheckCell(Cell &cell) {
    if(cell.X != 0){return false;}
    if(cell.Y != 0){return false;}
    if(cell.WindSpeed != 0.0f){return false;}
    if(cell.WindDirection != 0.0f){return false;}
    if(cell.Temp != 0.0f){return false;}
    if(cell.Humidity != 0.0f){return false;}
    if(cell.Pressure != 0.0f){return false;}
    return true;
}
int Get_CellPostition(int x,int y,int z){
    //invaild checking
    if(x > NumCellsX || x < 0 || y > NumCellsY || y < 0 || z > NumCellsZ || z < 0 ){
        Console::Log("Invaild Cell");
        return -1;
    }
    

    int o = y * NumCellsY;
    o = o + x;
    o = o + (z*(NumCellsX*NumCellsY));
    return o;
}