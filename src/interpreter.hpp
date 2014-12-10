#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <list>

//Executa o modo de comando
void modoComando(std::list<std::string> &texto, unsigned int &linAtual);

//Executa o modo de comando quando houver parametro
void modoComando(std::list<std::string> &texto, std::string nomeArq, unsigned int &linAtual);

//Executa as instrucoes do comando I (Inserir texto antes)
void comand_I(std::list<std::string> &texto, unsigned int &linAtual);

//Executa as instrucoes do comando A (Inserir texto depois)
void comand_A(std::list<std::string> &texto, unsigned int &linAtual);

//Executa as instrucoes do comando G (Editar linha)
void comand_G(std::list<std::string> &texto, unsigned int &linAtual);

//Executa as instrucoes do comando M (Torna uma linha atual)
void comand_M(std::list<std::string> &texto, unsigned int &linAtual);

//Executa as instrucoes do comando D ou L (Remover/Listar)
void comand_DL(std::list<std::string> &texto, unsigned int &linAtual, char op);

//Executa o comando de Ajuda (descreve comandos do programa)
void comand_H();

//Funciona como Backspace no modo de comando
void funcBACKSPACE(std::string &op);

#endif // INTERPRETER_HPP
