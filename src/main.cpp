#include <iostream>
#include <cstdlib>
#include "elis.hpp"

void pause() {
    std::cout << "\nPressione qualquer tecla para continuar...\n";
    char tmp = getch();
}

int main(int argc, char **argv) {

    system("title ELIS - Editor de Linhas Simples"); //Muda o titulo da janela

    if(argc == 2) {									 //Verifica quantidade de parametros (esse indica que o usuario entrou com um arquivo)
        std::string nomeArq = argv[1];				 //Pega o nome do arquivo
        ELIS *elis = new ELIS(nomeArq);
    } else {
        ELIS *elis = new ELIS();
    }

    pause();

    return 0;
}
