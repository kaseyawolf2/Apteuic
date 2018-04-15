@echo off
cd ./Build/Objects

g++ -c -o Main      ./../../main.cpp
g++ -c -o Cell      ./../../Cell.cpp
g++ -c -o Console   ./../../Console.cpp
g++ -c -o File      ./../../File.cpp
g++ -c -o Window      ./../../Window.cpp

set libs= -lmingw32 -lSDL2main -lSDL2

cd ./../

g++ -g -o Build ./Objects/* %libs%

.\Build.exe