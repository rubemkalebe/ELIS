#ifndef ELIS_HPP
#define ELIS_HPP

#include <cstdlib>    //Biblioteca para utilizar comandos system
#include <conio.h>    //Biblioteca para getche()
#include "file.hpp"
#include "interpreter.hpp"

class ELIS {

    File *file;
    Interpreter prompt;

public:

    ELIS();
    ELIS(std::string nomeArq);

};

#endif // ELIS_HPP
