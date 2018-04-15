#pragma once
#include "defines.h"
#include "Cell.h"
#include "Console.h"
#include "Window.h"
#include "File.h"
#include <iostream>
#include <vector>



int NewInit();
void PressureBal();
void Tick();

//Globals
std::vector<Cell> GameCells;