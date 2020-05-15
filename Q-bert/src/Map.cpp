#include "Map.h"
#include "Cube.h"
#include <stdio.h>
#include <windows.h>

using namespace std;

Map::Map()
{
    Cube(100,1,5);
    Cube(89,11,5);
    Cube(111,11,5);
    Cube(100,21,5);
    Cube(78,21,5);
    Cube(122,21,5);
    Cube(89,31,5);
    Cube(111,31,5);
    Cube(67,31,5);
    Cube(133,31,5);
    Cube(100,41,5);
    Cube(78,41,5);
    Cube(122,41,5);
    Cube(144,41,5);
    Cube(56,41,5);
    Cube(89,51,5);
    Cube(111,51,5);
    Cube(67,51,5);
    Cube(133,51,5);
    Cube(45,51,5);
    Cube(155,51,5);
    Cube(219,1,14);

}

Map::~Map()
{
    //dtor
}
