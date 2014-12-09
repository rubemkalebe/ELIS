#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <Windows.h>  //Biblioteca para mover cursor

class Screen {

public:

    Screen();

    static void gotoxy(int x, int y); //Funcao para mover o cursor
};

#endif // SCREEN_HPP
