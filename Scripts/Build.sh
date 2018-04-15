cd ./Build/Objects
echo "Starting Build"
echo "$PWD" 

g++ -c -o Main      ./../../main.cpp
g++ -c -o Cell      ./../../Cell.cpp
g++ -c -o Console   ./../../Console.cpp
g++ -c -o File      ./../../File.cpp
g++ -c -o Window    ./../../Window.cpp

echo "Objects Built"

libs= -lSDL2main -lSDL2

cd ./../

g++ -g -o Build ./Objects/* $libs

echo
'./Build'