#include "Cube.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>

using namespace std;

void Cube::SetColor(int ForgC){
WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
}

Cube::Cube(){

}

void Cube::gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

Cube::Cube(int x, int y, int color){
    SetColor(15);
    gotoxy(x,y);
    cout << "$" << endl;
    gotoxy(x-3,y+1);
    cout << "$";
    SetColor(color);
    cout << ".....";
    SetColor(15);
    cout << "$" << endl;
    gotoxy(x-6,y+2);
    cout << "$";
    SetColor(color);
    cout << "...........";
    SetColor(15);
    cout << "$" << endl;
    gotoxy(x-9,y+3);
    cout << "$";
    SetColor(color);
    cout << ".................";
    SetColor(15);
    cout << "$" << endl;
    gotoxy(x-11,y+4);
    cout << "$";
    SetColor(3);
    cout << "7";
    SetColor(color);
    cout << "...................";
    SetColor(1);
    cout << "Z";
    SetColor(15);
    cout << "$" << endl;
    gotoxy(x-11,y+5);
    cout << "$";
    SetColor(3);
    cout << "7777";
    SetColor(color);
    cout << ".............";
    SetColor(1);
    cout << "ZZZZ";
    SetColor(15);
    cout << "$" << endl;
    gotoxy(x-11,y+6);
    cout << "$";
    SetColor(3);
    cout << "7777777";
    SetColor(color);
    cout << ".......";
    SetColor(1);
    cout << "ZZZZZZZ";
    SetColor(15);
    cout << "$" << endl;
    gotoxy(x-11,y+7);
    cout << "$";
    SetColor(3);
    cout << "7777777777";
    SetColor(15);
    cout << "Y";
    SetColor(1);
    cout << "ZZZZZZZZZZ";
    SetColor(15);
    cout << "$" << endl;
    gotoxy(x-11,y+8);
    cout << "$";
    SetColor(3);
    cout << "7777777777";
    SetColor(15);
    cout << "Y";
    SetColor(1);
    cout << "ZZZZZZZZZZ";
    SetColor(15);
    cout << "$" << endl;
    gotoxy(x-11,y+9);
    cout << "$";
    SetColor(3);
    cout << "7777777777";
    SetColor(15);
    cout << "Y";
    SetColor(1);
    cout << "ZZZZZZZZZZ";
    SetColor(15);
    cout << "$" << endl;
    gotoxy(x-9,y+10);
    cout << "$";
    SetColor(3);
    cout << "77777777";
    SetColor(15);
    cout << "Y";
    SetColor(1);
    cout << "ZZZZZZZZ";
    SetColor(15);
    cout << "$" << endl;
    gotoxy(x-6,y+11);
    cout << "$";
    SetColor(3);
    cout << "77777";
    SetColor(15);
    cout << "Y";
    SetColor(1);
    cout << "ZZZZZ";
    SetColor(15);
    cout << "$" << endl;
    gotoxy(x-3,y+12);
    cout << "$";
    SetColor(3);
    cout << "77";
    SetColor(15);
    cout << "Y";
    SetColor(1);
    cout << "ZZ";
    SetColor(15);
    cout << "$" << endl;
    gotoxy(x,y+13);
    cout << "$"<< endl;
}

void Cube::objetivo(){
    gotoxy(120,4);
    cout <<" ,-----.  ,-----.        ,--. ,------. ,--------. ,--. ,--.   ,--.  ,-----." << endl;
    gotoxy(120,5);
    cout <<"'  .-.  ' |  |) /_       |  | |  .---' '--.  .--' |  |  "<<(char)92<<"  `.'  /  '  .-.  '     .--." << endl;
    gotoxy(120,6);
    cout <<"|  | |  | |  .-.  "<<(char)92<<" ,--. |  | |  `--,     |  |    |  |   "<<(char)92<<"     /   |  | |  |     '--'" << endl;
    gotoxy(120,7);
    cout <<"'  '-'  ' |  '--' / |  '-'  / |  `---.    |  |    |  |    "<<(char)92<<"   /    '  '-'  '     .--." << endl;
    gotoxy(120,8);
    cout <<" `-----'  `------'   `-----'  `------'    `--'    `--'     `-'      `-----'      '--'" << endl;
}

Cube::~Cube()
{
    //dtor
}
