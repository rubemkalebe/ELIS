#include "screen.hpp"

void gotoxy(int x, int y) {
    COORD p = { x, y }; 												//Recebe coordenadas
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p ); 	//Posiciona cursor
}
