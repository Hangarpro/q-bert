#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
    public:
        Enemy();
        void SetColor(int);
        void gotoxy(int,int);
        void leftFall();
        virtual ~Enemy();

    protected:

    private:
};

#endif // ENEMY_H
