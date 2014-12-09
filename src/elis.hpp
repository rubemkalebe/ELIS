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

private:



    void pause();   //Funcao criada para pausar o programa. Foi criada para substituir a system("pause"), tendo em vista a eficiencia
};

#endif // ELIS_HPP
