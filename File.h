#include <iostream>
#include <fstream>
#include <vector>
#include "Console.h"
#include "Cell.h"

std::vector<Cell> LoadCellFile(std::string SaveName);
void SaveCellFile(std::vector<Cell> GameCells, std::string SaveName);