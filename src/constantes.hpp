#ifndef CONSTANTES_HPP_INCLUDED
#define CONSTANTES_HPP_INCLUDED

////////////////Constantes que representam teclas ou posicoes na tela/////////////////////////////////

enum {
    ESC = 27, ENTER = 13, BACKSPACE = 8, TAB = 9,
    UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, DEL = 83,
    CAR_ESP = -32, HOME = 71, END = 79, CTRL_V = 22, CTRL_C = 3,

    //Constantes que identificam espacos na tela (lembrar que o terminal eh uma matriz onde acessaremos cada celula)
    MIN_COL = 2, MAX_COL = 79, MIN_LIN = 0, ESP_TAB = 5
};

#endif // CONSTANTES_HPP_INCLUDED
