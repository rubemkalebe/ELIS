#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <iostream>
#include <string>
#include <list>

//Encerra o modo de edicao
void funcESC(std::list<std::string> &texto, std::string &linha, std::list<std::string>::iterator it, unsigned int &l);

//Finaliza linha
void funcENTER(std::list<std::string> &texto, std::string &linha, unsigned int &lin,
               unsigned int &col, std::list<std::string>::iterator it);

//Funciona como Backspace no modo de edicao
void funcBACKSPACE(std::string &linha, unsigned int &col, unsigned int lin);

//Funciona como Tab
void funcTAB(std::string &linha, unsigned int &lin, unsigned int &col);

//Desloca o cursor para esquerda
void funcLEFT(unsigned int lin, unsigned int &col);

//Desloca o cursor para a direita
void funcRIGHT(std::string linha, unsigned int lin, unsigned int &col);

//Desloca o cursor para o inicio da linha
void funcHOME(unsigned int lin, unsigned int &col);

//Desloca o cursor para o fim da linha
void funcEND(std::string linha, unsigned int lin, unsigned int &col);

//Deleta um caracter
void funcDELETE(std::string &linha, unsigned int lin, unsigned int col);

//Adiciona um caracter a linha
void addChar(std::string &linha, unsigned int lin, unsigned int &col, char c);

#endif // KEYBOARD_HPP
