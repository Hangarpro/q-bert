#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <fstream>
#include <Cube.h>
#include <Map.h>
#include <Menu.h>
using namespace std;
Player Jugador;
Cube Cubo;
Menu menu;
int salir = 1, contador = 1;

void Player::SetColor(int ForgC){
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

void Player::gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

Player::Player(){

}

void Player::Movimiento(char letra){
    if (Jugador.getcaida() == 1){
        x = 99;
        y = 3;
        Jugador.setCaida(0);
    }
    if(letra == 's'){
        Jugador.deletePlayer(x,y);
        x = x+11;
        y = y+10;
        PlaySound(TEXT("Jump.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Jugador.Pintar(x,y);
        Jugador.colorCubo(x,y);
        Jugador.setLevel(x,y);
        contador++;
    }
    if (letra == 'a'){
        Jugador.deletePlayer(x,y);
        gotoxy(x-11,y+10);
        x = x-11;
        y = y+10;
        PlaySound(TEXT("Jump.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Jugador.Pintar(x,y);
        Jugador.colorCubo(x,y);
        Jugador.setLevel(x,y);
        contador++;
    }
    if(letra == 'd'){
        Jugador.deletePlayer(x,y);
        x = x+11;
        y = y-10;
        PlaySound(TEXT("Jump.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Jugador.Pintar(x,y);
        Jugador.colorCubo(x,y);
        Jugador.setLevel(x,y);
        contador++;
    }
    if (letra == 'w'){
        Jugador.deletePlayer(x,y);
        gotoxy(x-11,y-10);
        x = x-11;
        y = y-10;
        PlaySound(TEXT("Jump.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Jugador.Pintar(x,y);
        Jugador.colorCubo(x,y);
        Jugador.setLevel(x,y);
        contador++;
    }
}

void Player::deletePlayer(int x, int y){
    gotoxy(x,y);
    cout << "..." <<endl;
    gotoxy(x-1,y+1);
    cout << "....." <<endl;
    gotoxy(x-2,y+2);
    cout << "......." <<endl;
    gotoxy(x-3,y+3);
    cout << "........." <<endl;
}

void Player::borrar(int x, int y){
    gotoxy(x,y);
    cout << "   " <<endl;
    gotoxy(x-1,y+1);
    cout << "     " <<endl;
    gotoxy(x-2,y+2);
    cout << "       " <<endl;
    gotoxy(x-3,y+3);
    cout << "         " <<endl;
}

void Player::Pintar(int x,int y){
    SetColor(12);
    gotoxy(x,y);
    cout << (char)178<< (char)178<<(char)178<<endl;
    gotoxy(x-1,y+1);
    cout << (char)178<<(char)178<<(char)178<<(char)178<<(char)178<<endl;
    gotoxy(x-2,y+2);
    cout << (char)178<< (char)178<<(char)178<< (char)178<< (char)178<<(char)178<<(char)178<<endl;
    gotoxy(x-3,y+3);
    cout << (char)178<< (char)178<<(char)178<< (char)178<< (char)178<<(char)178<<(char)178<<(char)178<<(char)178<<endl;
    SetColor(5);
}



Player::~Player()
{
    //dtor
}

void Player::colorCubo(int x, int y){
    if (x == 99 and y == 3){
        if (level == 1){
            Cube(100,1,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(0) < 1){
                Jugador.setColores(0);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(0) == 1){
                Cube(100,1,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(0);
                SetColor(14);
            }
            if(Jugador.getColores(0) < 1){
                Cube(100,1,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(0);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(0) == 2){
                Cube(100,1,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(0);
                SetColor(14);
            }
            if(Jugador.getColores(0) == 1){
                Cube(100,1,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(0);
                SetColor(3);
            }
            if(Jugador.getColores(0) < 1){
                Cube(100,1,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(0);
                SetColor(2);
            }
            if(Jugador.getColores(0) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 88 and y == 13){
        if (level == 1){
            Cube(89,11,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(1) < 1){
                Jugador.setColores(1);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(1) == 1){
                Cube(89,11,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(1);
                SetColor(14);
            }
            if(Jugador.getColores(1) < 1){
                Cube(89,11,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(1);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(1) == 2){
                Cube(89,11,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(1);
                SetColor(14);
            }
            if(Jugador.getColores(1) == 1){
                Cube(89,11,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(1);
                SetColor(3);
            }
            if(Jugador.getColores(1) < 1){
                Cube(89,11,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(1);
                SetColor(2);
            }
            if(Jugador.getColores(1) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 77 and y == 23){
        if (level == 1){
            Cube(78,21,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(2) < 1){
                Jugador.setColores(2);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(2) == 1){
                Cube(78,21,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(2);
                SetColor(14);
            }
            if(Jugador.getColores(2) < 1){
                Cube(78,21,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(2);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(2) == 2){
                Cube(78,21,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(2);
                SetColor(14);
            }
            if(Jugador.getColores(2) == 1){
                Cube(78,21,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(2);
                SetColor(3);
            }
            if(Jugador.getColores(2) < 1){
                Cube(78,21,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(2);
                SetColor(2);
            }
            if(Jugador.getColores(2) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 66 and y == 33){
        if (level == 1){
            Cube(67,31,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(3) < 1){
                Jugador.setColores(3);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(3) == 1){
                Cube(67,31,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(3);
                SetColor(14);
            }
            if(Jugador.getColores(3) < 1){
                Cube(67,31,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(3);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(3) == 2){
                Cube(67,31,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(3);
                SetColor(14);
            }
            if(Jugador.getColores(3) == 1){
                Cube(67,31,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(3);
                SetColor(3);
            }
            if(Jugador.getColores(3) < 1){
                Cube(67,31,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(3);
                SetColor(2);
            }
            if(Jugador.getColores(3) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 55 and y == 43){
        if (level == 1){
            Cube(56,41,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(4) < 1){
                Jugador.setColores(4);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(4) == 1){
                Cube(56,41,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(4);
                SetColor(14);
            }
            if(Jugador.getColores(4) < 1){
                Cube(56,41,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(4);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(4) == 2){
                Cube(56,41,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(4);
                SetColor(14);
            }
            if(Jugador.getColores(4) == 1){
                Cube(56,41,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(4);
                SetColor(3);
            }
            if(Jugador.getColores(4) < 1){
                Cube(56,41,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(4);
                SetColor(2);
            }
            if(Jugador.getColores(4) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 44 and y == 53){
        if (level == 1){
            Cube(45,51,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(5) < 1){
                Jugador.setColores(5);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(5) == 1){
                Cube(45,51,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(5);
                SetColor(14);
            }
            if(Jugador.getColores(5) < 1){
                Cube(45,51,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(5);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(5) == 2){
                Cube(45,51,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(5);
                SetColor(14);
            }
            if(Jugador.getColores(5) == 1){
                Cube(45,51,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(5);
                SetColor(3);
            }
            if(Jugador.getColores(5) < 1){
                Cube(45,51,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(5);
                SetColor(2);
            }
            if(Jugador.getColores(5) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 110 and y == 13){
        if (level == 1){
            Cube(111,11,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(6) < 1){
                Jugador.setColores(6);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(6) == 1){
                Cube(111,11,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(6);
                SetColor(14);
            }
            if(Jugador.getColores(6) < 1){
                Cube(111,11,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(6);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(6) == 2){
                Cube(111,11,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(6);
                SetColor(14);
            }
            if(Jugador.getColores(6) == 1){
                Cube(111,11,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(6);
                SetColor(3);
            }
            if(Jugador.getColores(6) < 1){
                Cube(111,11,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(6);
                SetColor(2);
            }
            if(Jugador.getColores(6) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 121 and y == 23){
        if (level == 1){
            Cube(122,21,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(7) < 1){
                Jugador.setColores(7);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(7) == 1){
                Cube(122,21,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(7);
                SetColor(14);
            }
            if(Jugador.getColores(7) < 1){
                Cube(122,21,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(7);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(7) == 2){
                Cube(122,21,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(7);
                SetColor(14);
            }
            if(Jugador.getColores(7) == 1){
                Cube(122,21,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(7);
                SetColor(3);
            }
            if(Jugador.getColores(7) < 1){
                Cube(122,21,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(7);
                SetColor(2);
            }
            if(Jugador.getColores(7) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 132 and y == 33){
        if (level == 1){
            Cube(133,31,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(8) < 1){
                Jugador.setColores(8);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(8) == 1){
                Cube(133,31,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(8);
                SetColor(14);
            }
            if(Jugador.getColores(8) < 1){
                Cube(133,31,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(8);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(8) == 2){
                Cube(133,31,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(8);
                SetColor(14);
            }
            if(Jugador.getColores(8) == 1){
                Cube(133,31,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(8);
                SetColor(3);
            }
            if(Jugador.getColores(8) < 1){
                Cube(133,31,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(8);
                SetColor(2);
            }
            if(Jugador.getColores(8) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 143 and y == 43){
        if (level == 1){
            Cube(144,41,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(9) < 1){
                Jugador.setColores(9);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(9) == 1){
                Cube(144,41,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(9);
                SetColor(14);
            }
            if(Jugador.getColores(9) < 1){
                Cube(144,41,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(9);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(9) == 2){
                Cube(144,41,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(9);
                SetColor(14);
            }
            if(Jugador.getColores(9) == 1){
                Cube(144,41,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(9);
                SetColor(3);
            }
            if(Jugador.getColores(9) < 1){
                Cube(144,41,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(9);
                SetColor(2);
            }
            if(Jugador.getColores(9) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 154 and y == 53){
        if (level == 1){
            Cube(155,51,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(10) < 1){
                Jugador.setColores(10);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(10) == 1){
                Cube(155,51,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(10);
                SetColor(14);
            }
            if(Jugador.getColores(10) < 1){
                Cube(155,51,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(10);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(10) == 2){
                Cube(155,51,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(10);
                SetColor(14);
            }
            if(Jugador.getColores(10) == 1){
                Cube(155,51,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(10);
                SetColor(3);
            }
            if(Jugador.getColores(10) < 1){
                Cube(155,51,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(10);
                SetColor(2);
            }
            if(Jugador.getColores(10) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 66 and y == 53){
        if (level == 1){
            Cube(67,51,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(11) < 1){
                Jugador.setColores(11);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(11) == 1){
                Cube(67,51,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(11);
                SetColor(14);
            }
            if(Jugador.getColores(11) < 1){
                Cube(67,51,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(11);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(11) == 2){
                Cube(67,51,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(11);
                SetColor(14);
            }
            if(Jugador.getColores(11) == 1){
                Cube(67,51,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(11);
                SetColor(3);
            }
            if(Jugador.getColores(11) < 1){
                Cube(67,51,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(11);
                SetColor(2);
            }
            if(Jugador.getColores(11) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 88 and y == 53){
        if (level == 1){
            Cube(89,51,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(12) < 1){
                Jugador.setColores(12);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(12) == 1){
                Cube(89,51,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(12);
                SetColor(14);
            }
            if(Jugador.getColores(12) < 1){
                Cube(89,51,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(12);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(12) == 2){
                Cube(89,51,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(12);
                SetColor(14);
            }
            if(Jugador.getColores(12) == 1){
                Cube(89,51,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(12);
                SetColor(3);
            }
            if(Jugador.getColores(12) < 1){
                Cube(89,51,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(12);
                SetColor(2);
            }
            if(Jugador.getColores(12) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 110 and y == 53){
        if (level == 1){
            Cube(111,51,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(13) < 1){
                Jugador.setColores(13);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(13) == 1){
                Cube(111,51,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(13);
                SetColor(14);
            }
            if(Jugador.getColores(13) < 1){
                Cube(111,51,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(13);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(13) == 2){
                Cube(111,51,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(13);
                SetColor(14);
            }
            if(Jugador.getColores(13) == 1){
                Cube(111,51,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(13);
                SetColor(3);
            }
            if(Jugador.getColores(13) < 1){
                Cube(111,51,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(13);
                SetColor(2);
            }
            if(Jugador.getColores(13) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 132 and y == 53){
        if (level == 1){
            Cube(133,51,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(14) < 1){
                Jugador.setColores(14);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(14) == 1){
                Cube(133,51,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(14);
                SetColor(14);
            }
            if(Jugador.getColores(14) < 1){
                Cube(133,51,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(14);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(14) == 2){
                Cube(133,51,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(14);
                SetColor(14);
            }
            if(Jugador.getColores(14) == 1){
                Cube(133,51,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(14);
                SetColor(3);
            }
            if(Jugador.getColores(14) < 1){
                Cube(133,51,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(14);
                SetColor(2);
            }
            if(Jugador.getColores(14) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 99 and y == 23){
        if (level == 1){
            Cube(100,21,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(15) < 1){
                Jugador.setColores(15);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(15) == 1){
                Cube(100,21,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(15);
                SetColor(14);
            }
            if(Jugador.getColores(15) < 1){
                Cube(100,21,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(15);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(15) == 2){
                Cube(100,21,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(15);
                SetColor(14);
            }
            if(Jugador.getColores(15) == 1){
                Cube(100,21,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(15);
                SetColor(3);
            }
            if(Jugador.getColores(15) < 1){
                Cube(100,21,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(15);
                SetColor(2);
            }
            if(Jugador.getColores(15) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 88 and y == 33){
        if (level == 1){
            Cube(89,31,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(16) < 1){
                Jugador.setColores(16);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(16) == 1){
                Cube(89,31,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(16);
                SetColor(14);
            }
            if(Jugador.getColores(16) < 1){
                Cube(89,31,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(16);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(16) == 2){
                Cube(89,31,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(16);
                SetColor(14);
            }
            if(Jugador.getColores(16) == 1){
                Cube(89,31,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(16);
                SetColor(3);
            }
            if(Jugador.getColores(16) < 1){
                Cube(89,31,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(16);
                SetColor(2);
            }
            if(Jugador.getColores(16) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 110 and y == 33){
        if (level == 1){
            Cube(111,31,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(17) < 1){
                Jugador.setColores(17);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(17) == 1){
                Cube(111,31,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(17);
                SetColor(14);
            }
            if(Jugador.getColores(17) < 1){
                Cube(111,31,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(17);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(17) == 2){
                Cube(111,31,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(17);
                SetColor(14);
            }
            if(Jugador.getColores(17) == 1){
                Cube(111,31,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(17);
                SetColor(3);
            }
            if(Jugador.getColores(17) < 1){
                Cube(111,31,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(17);
                SetColor(2);
            }
            if(Jugador.getColores(17) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 99 and y == 43){
        if (level == 1){
            Cube(100,41,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(18) < 1){
                Jugador.setColores(18);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(18) == 1){
                Cube(100,41,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(18);
                SetColor(14);
            }
            if(Jugador.getColores(18) < 1){
                Cube(100,41,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(18);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(18) == 2){
                Cube(100,41,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(18);
                SetColor(14);
            }
            if(Jugador.getColores(18) == 1){
                Cube(100,41,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(18);
                SetColor(3);
            }
            if(Jugador.getColores(18) < 1){
                Cube(100,41,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(18);
                SetColor(2);
            }
            if(Jugador.getColores(18) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 77 and y == 43){
        if (level == 1){
            Cube(78,41,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(19) < 1){
                Jugador.setColores(19);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(19) == 1){
                Cube(78,41,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(19);
                SetColor(14);
            }
            if(Jugador.getColores(19) < 1){
                Cube(78,41,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(19);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(19) == 2){
                Cube(78,41,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(19);
                SetColor(14);
            }
            if(Jugador.getColores(19) == 1){
                Cube(78,41,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(19);
                SetColor(3);
            }
            if(Jugador.getColores(19) < 1){
                Cube(78,41,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(19);
                SetColor(2);
            }
            if(Jugador.getColores(19) > 2){
                SetColor(14);
            }
        }
    }
    else if (x == 121 and y == 43){
        if (level == 1){
            Cube(122,41,14);
            Jugador.Pintar(x,y);
            if(Jugador.getColores(20) < 1){
                Jugador.setColores(20);
            }
            SetColor(14);
        }
        if (level == 2){
            if(Jugador.getColores(20) == 1){
                Cube(122,41,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(20);
                SetColor(14);
            }
            if(Jugador.getColores(20) < 1){
                Cube(122,41,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(20);
                SetColor(2);
            }
            else{
                SetColor(14);
            }
        }
        if(level == 3){
            if(Jugador.getColores(20) == 2){
                Cube(122,41,14);
                Jugador.Pintar(x,y);
                Jugador.setColores(20);
                SetColor(14);
            }
            if(Jugador.getColores(20) == 1){
                Cube(122,41,3);
                Jugador.Pintar(x,y);
                Jugador.setColores(20);
                SetColor(3);
            }
            if(Jugador.getColores(20) < 1){
                Cube(122,41,2);
                Jugador.Pintar(x,y);
                Jugador.setColores(20);
                SetColor(2);
            }
            if(Jugador.getColores(20) > 2){
                SetColor(14);
            }
        }
    }
    else{
        PlaySound(TEXT("Fall.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(1000);
        Jugador.borrar(x,y);
        Cubo.objetivo();
        x = 99;
        y = 3;
        life--;
        Jugador.txtvidas();
        Jugador.Pintar(x,y);
        Jugador.setCaida(1);
        int pintoresco;
        pintoresco = Jugador.getColores(0);
        if (level == 1){
            if (pintoresco == 1){
                SetColor(14);
            }
            else{
                SetColor(5);
            }
        }
        if (level == 2){
            if (pintoresco > 1){
                SetColor(14);
            }
            if (pintoresco == 1){
                SetColor(2);
            }
            if (pintoresco < 1){
                SetColor(5);
            }
        }
        if (level == 3){
            if (pintoresco > 2){
                SetColor(14);
            }
            if (pintoresco == 2){
                SetColor(3  );
            }
            if (pintoresco == 1){
                SetColor(2);
            }
            if (pintoresco < 1){
                SetColor(5);
            }
        }
    }
}

void Player::setColores(int i){
    s_color[i]++;
}

void Player::setCaida(int i){
    caida = i;
}

int Player::getcaida(){
    return caida;
}

int Player::getColores(int i){
    return s_color[i];
}

void Player::setLevel(int x, int y){
    int contador = 0;
    if (level == 1){
        for (int i = 0;i < 21; i++){
            contador = contador + s_color[i];
        }
        if (contador >= 21){
            level = 2;
            PlaySound(TEXT("Stage Clear.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(4000);
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
            SetColor(5);
            Jugador.deletePlayer(x,y);
            x = 99;
            y = 3;
            Jugador.Pintar(x,y);
            Jugador.txtnivel();
            PlaySound(TEXT("Stage Start.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(4000);
            Jugador.setCaida(1);
            SetColor(5);
            for (int i = 0;i < 21; i++){
                s_color[i] = 0;
            }
        }
    }
    if (level == 2){
        for (int i = 0;i < 21; i++){
            contador = contador + s_color[i];
        }
        if (contador >= 42){
            level = 3;
            PlaySound(TEXT("Stage Clear.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(4000);
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
            SetColor(5);
            Jugador.deletePlayer(x,y);
            x = 99;
            y = 3;
            Jugador.Pintar(x,y);
            Jugador.txtnivel();
            PlaySound(TEXT("Stage Start.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(4000);
            Jugador.setCaida(1);
            SetColor(5);
            for (int i = 0;i < 21; i++){
                s_color[i] = 0;
            }
        }
    }
    if (level == 3){
        for (int i = 0;i < 21; i++){
            contador = contador + s_color[i];
        }
        if (contador >= 63){
            system("cls");
            menu.Winner();
            PlaySound(TEXT("Stage Clear.wav"), NULL, SND_FILENAME | SND_ASYNC);
            Sleep(4000);
            salir = 3;
            Jugador.setCaida(1);
            level = 1;
            life = 4;
            for (int i = 0;i < 21; i++){
                s_color[i] = 0;
            }
        }
    }
}

void Player::txtnivel(){
    if (level == 1){
        gotoxy(58,4);
        cout << " ,--.";
        gotoxy(58,5);
        cout << "/   |";
        gotoxy(58,6);
        cout << "`|  |";
        gotoxy(58,7);
        cout << " |  |";
        gotoxy(58,8);
        cout << " `--'";
    }
    if (level == 2){
        gotoxy(58,4);
        cout << "     ";
        gotoxy(58,5);
        cout << "     ";
        gotoxy(58,6);
        cout << "     ";
        gotoxy(58,7);
        cout << "     ";
        gotoxy(58,8);
        cout << "     ";
        gotoxy(58,4);
        cout << ",---.";
        gotoxy(58,5);
        cout << "'.-.  "<<(char)92;
        gotoxy(58,6);
        cout << " .-' .'";
        gotoxy(58,7);
        cout << "/   '-.";
        gotoxy(58,8);
        cout << "'-----'";
    }
    if (level == 3){
        gotoxy(58,4);
        cout << "     ";
        gotoxy(58,5);
        cout << "       ";
        gotoxy(58,6);
        cout << "       ";
        gotoxy(58,7);
        cout << "       ";
        gotoxy(58,8);
        cout << "       ";
        gotoxy(58,4);
        cout << ",----.";
        gotoxy(58,5);
        cout << "'.-.  |";
        gotoxy(58,6);
        cout << "  .' <";
        gotoxy(58,7);
        cout << "/'-'  |";
        gotoxy(58,8);
        cout << "`----'";
    }
}

void Player::txtvidas(){
    if (life == 3){
        gotoxy(38,20);
        cout << "               ";
        gotoxy(38,21);
        cout << "                ";
        gotoxy(38,22);
        cout << "                ";
        gotoxy(38,23);
        cout << "                ";
        gotoxy(38,24);
        cout << "               ";
        gotoxy(38,25);
        cout << "             ";
        gotoxy(38,26);
        cout << "           ";
        gotoxy(38,27);
        cout << "         ";
    }
    if (life == 2){
        gotoxy(20,20);
        cout << "               ";
        gotoxy(20,21);
        cout << "                ";
        gotoxy(20,22);
        cout << "                ";
        gotoxy(20,23);
        cout << "                ";
        gotoxy(20,24);
        cout << "               ";
        gotoxy(20,25);
        cout << "             ";
        gotoxy(20,26);
        cout << "           ";
        gotoxy(20,27);
        cout << "         ";
    }
    if (life == 1){
        gotoxy(2,20);
        cout << "               ";
        gotoxy(2,21);
        cout << "                ";
        gotoxy(2,22);
        cout << "                ";
        gotoxy(2,23);
        cout << "                ";
        gotoxy(2,24);
        cout << "               ";
        gotoxy(2,25);
        cout << "             ";
        gotoxy(2,26);
        cout << "           ";
        gotoxy(2,27);
        cout << "         ";
    }
    if (life == 0){
        system("cls");
        menu.Loser();
        PlaySound(TEXT("Game Over.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(4000);
        salir = 3;
        life = 4;
        level = 1;
        for (int i = 0;i < 21; i++){
                s_color[i] = 0;
        }
    }
}

int Player::salida(){
    return salir;
}

void Player::setSalir(int salida){
    salir = salida;
}

int Player::getContador(){
    return contador;
}

void Player::setContador(int _contador){
    contador = _contador;
}
