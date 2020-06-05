#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
        Player();
        void SetColor(int);
        void gotoxy(int,int);
        void Movimiento(char);
        int getcaida();
        void setCaida(int);
        void deletePlayer(int,int);
        void Pintar(int,int);
        void limites(int,int);
        void colorCubo(int,int);
        void cubos();
        void borrar(int,int);
        void setColores(int);
        int getColores(int);
        void setLevel(int,int);
        void txtnivel();
        void txtvidas();
        int salida();
        virtual ~Player();

    protected:

    private:
        int x = 99;
        int y = 3;
        int life = 4;
        int level = 1;
        int cubo = 1;
        int s_color[21] = {0};
        int caida = 0;
};

#endif // PLAYER_H
