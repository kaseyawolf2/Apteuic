#pragma once
#include "defines.h"
#include "Cell.h"
#include "Console.h"
#include "File.h"
#include <iostream>
#include <vector>



int MainInit();
void PressureBal();
void Tick();


//Globals
std::vector<Cell> GameCells;