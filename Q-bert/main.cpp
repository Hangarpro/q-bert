#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <dos.h>
#include <dir.h>
#include <stdio.h>
#include <fstream>
#include "Cube.h"
#include "Map.h"
#include "Player.h"
#include "Menu.h"

using namespace std;
void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
void SetColor(int ForgC){
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

int main(){
    Player Jugador;
    Menu menu;
    Cube Cubo;
    int exit = 0, movimientos = 0;
    char opcion, salir = 0, letra;
    time_t inicio = 0,fin,delta;
    int b_time = 200, b_moves = 180;

    PlaySound(TEXT("Theme.wav"), NULL, SND_FILENAME | SND_ASYNC);
    while (exit != 4){
        salir = '0';
        Jugador.setSalir(0);
        Jugador.setContador(1);
        system("cls");
        SetColor(15);
        menu.Principal();
        opcion = getch();
        switch (opcion){
            case '1':
                PlaySound(NULL, NULL, SND_ASYNC);
                system("cls");
                Map();
                gotoxy(160, 38);
                cout << "Highscore   -   Time: " << b_time << "s  Moves: " << b_moves;
                Jugador.Pintar(99,3);
                Cubo.nivel();
                Cubo.objetivo();
                Cubo.vidas();
                PlaySound(TEXT("Stage Start.wav"), NULL, SND_FILENAME | SND_ASYNC);
                Sleep(4000);
                Jugador.txtnivel();
                Cubo.txtvidas();
                inicio = time(NULL);
                while (salir != 3){
                    letra = getch();
                    movimientos = Jugador.getContador();
                    Jugador.Movimiento(letra);
                    salir = Jugador.salida();
                    fin = time(NULL);
                    delta = fin-inicio;
                    gotoxy(160,42);
                    cout << "                                                        ";
                    gotoxy(160,42);
                    cout << "Score   -   Time: " << delta << "s Moves: " << movimientos;
                    if (salir == 4){
                        return 0;
                    }
                }
                if (movimientos < b_moves){
                    b_moves = movimientos;
                    b_time = delta;
                }
                if (movimientos == b_moves){
                    if(delta < b_time){
                        b_time = delta;
                    }
                }
            break;
            case '2':
                system("cls");
                while (salir != '3'){
                    menu.Instrucciones();
                    salir = getche();
                }
            break;
            case '3':
                system("cls");
                while (salir != '3'){
                    menu.Creditos();
                    salir = getche();
                }
            break;
            case '4':
                system("cls");
                return 0;
            break;
        }
    }
    return 0;
}
