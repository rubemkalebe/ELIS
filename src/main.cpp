#include <iostream>
#include <cstdlib>
#include <list>
#include "elis.hpp"
#include "interpreter.hpp"

int main(int argc, char **argv) {

    //Cria lista duplamente encadeada que ira armazenar o texto (cada linha sera um no)
    std::list<std::string> texto;

    //Variavel que define a linha atual. Inicialmente sera zero
    unsigned int linAtual = texto.size();

    //Muda o titulo da janela
    system("title ELIS - Editor de Linhas Simples");

    if(argc == 2) {									 //Verifica quantidade de parametros (esse indica que o usuario entrou com um arquivo)
        std::string nomeArq = argv[1];				 //Pega o nome do arquivo
        openArq(texto, nomeArq, nomeArq, linAtual);	 //Abre ele
        insertDepois(texto, linAtual, linAtual);	 //Ja inicia o programa no modo de edicao
        modoComando(texto, nomeArq, linAtual);		 //Quando sair vai para o modo de comando
    } else {
        comand_H();									 //Ao iniciar mostra o comando ajuda
        modoComando(texto, linAtual);                //Inicia o modo de comando
    }

    pause(); //Pausa o programa

    return 0;
}
