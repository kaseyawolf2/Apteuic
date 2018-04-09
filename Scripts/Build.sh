cd ./Build/Objects
echo "Starting Build"
echo "$PWD" 

g++ -c -o Main ./../../main.cpp
g++ -c -o Cell ./../../Cell.cpp
g++ -c -o Console ./../../Console.cpp
g++ -c -o Save ./../../Save.cpp

echo "Objects Built"

cd ./../
g++ -o Build ./Objects/*
echo
'./Build'