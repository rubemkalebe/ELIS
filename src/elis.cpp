#include "elis.hpp"

ELIS::ELIS() {
    file = new File();
    prompt.comand_H();			            //Ao iniciar mostra o comando ajuda
    prompt.modoComando(texto, linAtual);    //Inicia o modo de comando
}

ELIS::ELIS(std::string nomeArq) {
    file = new File(nomeArq);
}



void ELIS::pause() {
    std::cout << "\nPressione qualquer tecla para continuar...\n";
    char tmp = getch();
}
