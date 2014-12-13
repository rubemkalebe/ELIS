#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <Windows.h>  //Biblioteca para mover cursor

//Funcao para mover o cursor
void gotoxy(int x, int y);

//Atualiza tela
void update(std::list<std::string> &texto, std::string &linha, unsigned int col);
void update(std::list<std::string> &texto, std::string &linha, unsigned int lin,
            unsigned int col);

//Identifica a posicao do cursor
void position(int &x, int &y);

#endif // SCREEN_HPP
