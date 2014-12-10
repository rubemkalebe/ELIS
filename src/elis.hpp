#ifndef ELIS_HPP
#define ELIS_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <string>
#include <list>

//Funcao que insere um texto antes de uma linha
void insertAntes(std::list<std::string> &texto, unsigned int &l, unsigned int &linAtual);

//Funcao para editar uma linha
void editLinha(std::list<std::string> &texto, std::string &linha, unsigned int &l, unsigned int &linAtual);

//Funcao que insere um texto depois de uma linha
void insertDepois(std::list<std::string> &texto, unsigned int &l, unsigned int &linAtual);

//Funcao para copiar uma linha
void funcCopy(std::string &linha);

//Funcao para colar linha/texto (para insertAntes)
void funcPaste_I(std::list<std::string> &texto, std::string &linha, unsigned int &lin,
                 unsigned int &col, unsigned int &linAtual);

//Funcao para colar linha/texto (para insertDepois)
void funcPaste_A(std::list<std::string> &texto, std::string &linha, unsigned int &lin,
                 unsigned int &col, unsigned int &linAtual);

//Funcao que imprime a linha (quando edicao)
void imprimeLinha(std::string linha, unsigned int lin, unsigned int col);

//Define uma linha como atual
void setLinha(std::list<std::string> &texto, unsigned int &linAtual, unsigned int linha);

//Lista todo o texto
void listaLinhas(std::list<std::string> &texto);

//Lista texto do inicio ate a linha n
void listaLinhas(std::list<std::string> &texto, unsigned int n);

//Lista o texto da linha n ate m
void listaLinhas(std::list<std::string> &texto, unsigned int n, unsigned int m);

//Remove uma linha
void removeLinhas(std::list<std::string> &texto, unsigned int n, unsigned int &linAtual);

//Remove da linha n ate m
void removeLinhas(std::list<std::string> &texto, unsigned int n, unsigned int m, unsigned int &linAtual);

//Grava arquivo
void writeArq(std::list<std::string> &texto, std::string nomeArq);

//Abre um arquivo
void openArq(std::list<std::string> &texto, std::string nomeArq, std::string &nomeArq2write,
             unsigned int &linAtual);

//Insere um arquivo no fim do seu texto
void readArq(std::list<std::string> &texto, std::string nomeArq, std::string &nomeArq2write,
             unsigned int &linAtual);

//Funcao criada para pausar o programa. Foi criada para substituir a system("pause"), tendo em vista a eficiencia
void pause();

#endif // ELIS_HPP
