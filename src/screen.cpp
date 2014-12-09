#include "screen.hpp"

Screen::Screen() {

}

void Screen::gotoxy(int x, int y) {
    COORD p = { x, y }; 												//Recebe coordenadas
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p ); 	//Posiciona cursor
}
