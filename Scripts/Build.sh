cd ./Build/Objects
echo "Starting Build"
echo "$PWD" 

g++ -c -o Main ./../../main.cpp
g++ -c -o Cell ./../../Cell.cpp

echo "Objects Built"

cd ./../
g++ -o Build ./Objects/*
echo
'./Build'