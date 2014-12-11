#include "elis.hpp"
#include "screen.hpp"

void gotoxy(int x, int y) {
    COORD p = { x, y }; 												//Recebe coordenadas
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p ); 	//Posiciona cursor
}

void update(std::list<std::string> &texto, std::string &linha, unsigned int col) {
    print(texto);
    std::cout << "\n> ";
    gotoxy(col, linha.size()+1);
}

void update(std::list<std::string> &texto, std::string &linha, unsigned int lin,
            unsigned int col) {
    print(texto);
    std::cout << "\n> ";
    imprimeLinha(linha, lin, col);
    gotoxy(col, linha.size()+1);
}
