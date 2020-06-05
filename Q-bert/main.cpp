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
    int exit = 0;
    char opcion, salir = 0, letra;

    PlaySound(TEXT("Theme.wav"), NULL, SND_FILENAME | SND_ASYNC);
    while (exit != 4){
        salir = '0';
        system("cls");
        SetColor(15);
        menu.Principal();
        opcion = getch();
        switch (opcion){
            case '1':
                PlaySound(NULL, NULL, SND_ASYNC);
                system("cls");
                Map();
                Jugador.Pintar(99,3);
                Cubo.nivel();
                Cubo.objetivo();
                Cubo.vidas();
                PlaySound(TEXT("Stage Start.wav"), NULL, SND_FILENAME | SND_ASYNC);
                Sleep(4000);
                Jugador.txtnivel();
                Cubo.txtvidas();
                while (salir != 3){
                    letra = getch();
                    Jugador.Movimiento(letra);
                    salir = Jugador.salida();
                    if (salir == 4){
                        return 0;
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
