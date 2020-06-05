#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <fstream>
#include <Cube.h>
using namespace std;
Player Jugador;

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
        //PlaySound(TEXT("Jump.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Jugador.Pintar(x,y);
        Jugador.colorCubo(x,y);
    }
    if (letra == 'a'){
        Jugador.deletePlayer(x,y);
        gotoxy(x-11,y+10);
        x = x-11;
        y = y+10;
        //PlaySound(TEXT("Jump.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Jugador.Pintar(x,y);
        Jugador.colorCubo(x,y);
    }
    if(letra == 'd'){
        Jugador.deletePlayer(x,y);
        x = x+11;
        y = y-10;
       // PlaySound(TEXT("Jump.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Jugador.Pintar(x,y);
        Jugador.colorCubo(x,y);
    }
    if (letra == 'w'){
        Jugador.deletePlayer(x,y);
        gotoxy(x-11,y-10);
        x = x-11;
        y = y-10;
       // PlaySound(TEXT("Jump.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Jugador.Pintar(x,y);
        Jugador.colorCubo(x,y);
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
            Jugador.setColores(0);
            SetColor(14);
        }
    }
    else if (x == 88 and y == 13){
        if (level == 1){
            Cube(89,11,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(1);
            SetColor(14);
        }
    }
    else if (x == 77 and y == 23){
        if (level == 1){
            Cube(78,21,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(2);
            SetColor(14);
        }
    }
    else if (x == 66 and y == 33){
        if (level == 1){
            Cube(67,31,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(3);
            SetColor(14);
        }
    }
    else if (x == 55 and y == 43){
        if (level == 1){
            Cube(56,41,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(4);
            SetColor(14);
        }
    }
    else if (x == 44 and y == 53){
        if (level == 1){
            Cube(45,51,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(5);
            SetColor(14);
        }
    }
    else if (x == 110 and y == 13){
        if (level == 1){
            Cube(111,11,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(6);
            SetColor(14);
        }
    }
    else if (x == 121 and y == 23){
        if (level == 1){
            Cube(122,21,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(7);
            SetColor(14);
        }
    }
    else if (x == 132 and y == 33){
        if (level == 1){
            Cube(133,31,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(8);
            SetColor(14);
        }
    }
    else if (x == 143 and y == 43){
        if (level == 1){
            Cube(144,41,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(9);
            SetColor(14);
        }
    }
    else if (x == 154 and y == 53){
        if (level == 1){
            Cube(155,51,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(10);
            SetColor(14);
        }
    }
    else if (x == 66 and y == 53){
        if (level == 1){
            Cube(67,51,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(11);
            SetColor(14);
        }
    }
    else if (x == 88 and y == 53){
        if (level == 1){
            Cube(89,51,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(12);
            SetColor(14);
        }
    }
    else if (x == 110 and y == 53){
        if (level == 1){
            Cube(111,51,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(13);
            SetColor(14);
        }
    }
    else if (x == 132 and y == 53){
        if (level == 1){
            Cube(133,51,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(14);
            SetColor(14);
        }
    }
    else if (x == 99 and y == 23){
        if (level == 1){
            Cube(100,21,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(15);
            SetColor(14);
        }
    }
    else if (x == 88 and y == 33){
        if (level == 1){
            Cube(89,31,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(16);
            SetColor(14);
        }
    }
    else if (x == 110 and y == 33){
        if (level == 1){
            Cube(111,31,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(17);
            SetColor(14);
        }
    }
    else if (x == 99 and y == 43){
        if (level == 1){
            Cube(100,41,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(18);
            SetColor(14);
        }
    }
    else if (x == 77 and y == 43){
        if (level == 1){
            Cube(78,41,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(19);
            SetColor(14);
        }
    }
    else if (x == 121 and y == 43){
        if (level == 1){
            Cube(122,41,14);
            Jugador.Pintar(x,y);
            Jugador.setColores(20);
            SetColor(14);
        }
    }
    else{
       //PlaySound(TEXT("Fall.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(1000);
        Jugador.borrar(x,y);
        x = 99;
        y = 3;
        Jugador.Pintar(x,y);
        Jugador.setCaida(1);
        int pintoresco;
        pintoresco = Jugador.getColores(0);
        if (pintoresco == 1){
           SetColor(14);
        }
        else{
            SetColor(5);
        }
    }
}

void Player::setColores(int i){
    s_color[i] = 1;
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
