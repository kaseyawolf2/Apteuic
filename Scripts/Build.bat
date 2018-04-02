cd ./Build/Objects

g++ -c -o Main ./../../main.cpp
g++ -c -o Cell ./../../Cell.cpp
g++ -c -o Console ./../../Console.cpp

cd ./../
g++ -o Build ./Objects/*
Build.exe