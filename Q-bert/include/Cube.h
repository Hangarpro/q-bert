#ifndef CUBE_H
#define CUBE_H


class Cube
{
    public:
        Cube(int,int,int);
        Cube();
        void SetColor(int);
        void gotoxy(int,int);
        void objetivo();
        void nivel();
        void vidas();
        void txtvidas();
        virtual ~Cube();

    protected:

    private:
};

#endif // CUBE_H
