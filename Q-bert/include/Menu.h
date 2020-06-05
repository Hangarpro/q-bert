#ifndef MENU_H
#define MENU_H


class Menu
{
    public:
        Menu();
        void SetColor(int);
        void gotoxy(int,int);
        void Principal();
        void Creditos();
        void Instrucciones();
        void Loser();
        void Winner();
        virtual ~Menu();

    protected:

    private:
};

#endif // MENU_H
