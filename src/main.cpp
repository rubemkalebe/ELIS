#include <iostream>
#include <cstdlib>
#include "elis.hpp"

int main(int argc, char **argv) {

    system("title ELIS - Editor de Linhas Simples"); //Muda o titulo da janela

    if(argc == 2) {									 //Verifica quantidade de parametros (esse indica que o usuario entrou com um arquivo)
        std::string nomeArq = argv[1];				 //Pega o nome do arquivo
        ELIS *elis = new ELIS(nomeArq);

        openArq(texto, nomeArq, nomeArq, linAtual);	 //Abre ele
        insertDepois(texto, linAtual, linAtual);	 //Ja inicia o programa no modo de edicao
        modoComando(texto, nomeArq, linAtual);		 //Quando sair vai para o modo de comando
    } else {
        ELIS *elis = new ELIS();
    }

    pause(); //Pausa

    return 0;

}
