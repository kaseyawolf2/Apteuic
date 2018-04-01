#include "Cell.h"
#include "defines.h"

struct Cell;
struct Ter;
void PostLogs(Cell cell){
    std::cout << "X:" << cell.X << std::endl;
    std::cout << "Y:" << cell.Y << std::endl;
    std::cout << "Wind Direction:" << cell.WindDirection << std::endl;
    std::cout << "Wind Speed:" << cell.WindSpeed << std::endl;
    std::cout << "Temp:" << cell.Temp << std::endl;
    std::cout << "Humidity:" << cell.Humidity << std::endl;
    std::cout << "Pressure:" << cell.Pressure << std::endl;
}
void InitCell(Cell &cell) {
    cell.X = 0;
    cell.Y = 0;
    cell.WindSpeed = 0.0f;
    cell.WindDirection = 0.0f;
    cell.Temp = 0.0f;
    cell.Humidity = 0.0f;
    cell.Pressure = 0.0f;
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
int Get_CellPostition(int x,int y){
    int o = y * NumCellsY;
    o = o + x;
    return o;
}