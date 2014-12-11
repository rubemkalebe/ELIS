#include "elis.hpp"
#include "screen.hpp"
#include "keyboard.hpp"
#include "constantes.hpp"

void funcESC(std::list<std::string> &texto, std::string &linha, std::list<std::string>::iterator &it, unsigned int &l) {
    if(linha != "") {
        texto.insert(it, linha); //Insere linha
        std::cout << std::endl;
    } else
        l--;                     //Necessario para controlar as linhas
}

void funcENTER(std::list<std::string> &texto, std::string &linha, unsigned int &lin, unsigned int &col, std::list<std::string>::iterator &it) {
    std::cout << std::endl;         //Pula linha
    texto.insert(it, linha);        //Insere linha
    linha = "";                     //Zera nova linha que sera usada
    std::cout << "> ";
    lin++;                          //Incrementa numero de linhas
    col = MIN_COL;                  //Nova coluna (iniciando da primeira posicao disponivel)
}

void funcBACKSPACE(std::string &linha, unsigned int &col, unsigned int lin) {
    if((linha != "") && (col > MIN_COL)) {
        linha.erase(linha.begin()+(col - MIN_COL) - 1); //Remove ultimo caracter
        linha.end();                					//Move iterador para o fim da string
        gotoxy(linha.length() + MIN_COL + 1, lin);
        std::cout << "\b \b";
        col--;                      					//Decrementa cursor de colunas
        //imprimeLinha(linha, lin, col);
    } else
        return;
}


void funcTAB(std::string &linha, unsigned int &lin, unsigned int &col) {
    if(col > MAX_COL - ESP_TAB) return;                		//Verifica se pode aceitar o TAB para nao atravessar a linha do terminal
    if(linha.length() + ESP_TAB > MAX_COL - 2) return; 		//Verifica se pode aceitar o TAB para nao atravessar a linha do terminal
    for(int i = 1; i <= 5; i++, col++)
        linha.insert(linha.begin()+(col - MIN_COL), ' '); 	//Preenche as lacunas com space
    gotoxy(MIN_COL, lin);                                 	//Move o cursor para a posicao correta
    std::cout << linha;
    gotoxy(col, lin);
}

void funcLEFT(unsigned int lin, unsigned int &col) {
    if((col == MIN_COL)) return; //Verifica se pode aceitar
    col--;
    gotoxy(col, lin);            //Apos decrementar o numerador das colunas movemos o cursor para a posicao correta
}

void funcRIGHT(std::string &linha, unsigned int lin, unsigned int &col) {
    if(col >= linha.length() + MIN_COL) return; //Verifica se pode aceitar
    col++;
    gotoxy(col, lin);            				//Apos decrementar o numerador das colunas movemos o cursor para a posicao correta
}

void funcHOME(unsigned int lin, unsigned int &col) {
    col = MIN_COL;
    gotoxy(col, lin);            	//Apos decrementar o numerador das colunas movemos o cursor para a posicao correta
}

void funcEND(std::string &linha, unsigned int lin, unsigned int &col) {
    col = linha.length() + MIN_COL; //Desloca o espaco necessario
    gotoxy(col, lin);            	//Apos decrementar o numerador das colunas movemos o cursor para a posicao correta
}

void funcDELETE(std::string &linha, unsigned int lin, unsigned int col) {
    if((linha != "") && (col < linha.length() + MIN_COL)) {
        linha.erase(linha.begin()+(col - MIN_COL)); //Apaga caracter da lista
        gotoxy(linha.length() + MIN_COL+1, lin);    //Posiciona o cursor
        std::cout << "\b \b";                       //Apaga o caracter da tela
        imprimeLinha(linha, lin, col);
    }
}

void addChar(std::string &linha, unsigned int lin, unsigned int &col, char c) {
    if((col == MAX_COL) || (linha.length() + MIN_COL == MAX_COL)) return; //Verifica se ainda pode adicionar
    linha.insert(linha.begin() + (col - MIN_COL), c);                     //Concatena caracteres
    col++;                                                                //Incrementa contador de colunas
    //imprimeLinha(linha, lin, col);
}
