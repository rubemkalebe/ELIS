#include "elis.hpp"

ELIS::ELIS() {
    file = new File();
    prompt.comand_H();			            //Ao iniciar mostra o comando ajuda
    prompt.modoComando(texto, linAtual);    //Inicia o modo de comando
}

ELIS::ELIS(std::string nomeArq) {
    file = new File(nomeArq);
    file.insertDepois(texto, linAtual, linAtual);   //Ja inicia o programa no modo de edicao
    prompt.modoComando(texto, nomeArq, linAtual);	//Quando sair vai para o modo de comando
}
