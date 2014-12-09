#include "file.hpp"

File::File() {
    linAtual = texto.size();    //Variavel que define a linha atual. Inicialmente sera zero
    nomeArq = "";
    alterado = false;
}

File::File(std::string nomeArq) {
    linAtual = texto.size();    //Variavel que define a linha atual. Inicialmente sera zero
    this->nomeArq = nomeArq;
    alterado = false;
    openArq(nomeArq);	 //Abre ele
}

void insertAntes(unsigned int &l) {
    if(l == 0) l++; 						   //Obviamente nao podemos inserir antes da posicao 0
    unsigned int col = MIN_COL, lin = MIN_LIN; //Variaveis que representam espacos na tela
    char c;                                    //Entrada do teclado
    std::string linha = "";                    //Variavel onde armazenaremos temporariamente a linha
    std::list<std::string>::iterator it;       //Iterador para referenciar um elemento na lista
    std::cout << "> ";
    while(true) {
        c = (char) getch();
        if(c == ESC) {                     //Tecla ESC
            it = texto.begin();
            std::advance (it, l-1);        //Insere antes de uma determinada linha
            funcESC(texto, linha, it, l);
            break;
        } else if(c == ENTER) {            //Tecla ENTER
            it = texto.begin();
            std::advance (it, l-1);        //Insere antes de uma determinada linha
            funcENTER(texto, linha, lin, col, it);
            l++;                           //Incrementa controle de linhas
        }
        else if(c == BACKSPACE) funcBACKSPACE(linha, col, lin);                 //Tecla BACKSPACE
        else if(c == TAB)       funcTAB(linha, lin, col);                       //Tecla TAB
        else if(c == CTRL_C)    funcCopy(linha);								//CTRL+C para copiar linha
        else if(c == CTRL_V)    funcPaste_I(texto, linha, lin, col, l);  		//CTRL+V para colar
        //Tratamento para alguns caracteres diferentes/especiais (Setas direcionais, delete, home, ...)
        else if(c == CAR_ESP) {
            c = getche();
            if(c == LEFT)       funcLEFT(lin, col);             //Tecla pra esquerda
            else if(c == RIGHT) funcRIGHT(linha, lin, col);     //Tecla pra direita
            else if(c == UP)    continue;                       //Tecla para cima
            else if(c == DOWN)  continue;                       //Tecla para baixo
            else if(c == DEL)   funcDELETE(linha, lin, col);    //Tecla Delete
            else if(c == HOME)  funcHOME(lin, col);             //Tecla Home
            else if(c == END)   funcEND(linha, lin, col);       //Tecla END
            else                continue;                       //Nao serao aceitas outras teclas
        } else                  addChar(linha, lin, col, c);    //Recebe caracter
    }
    linAtual = texto.size(); //Por padrao, sempre ao final de uma insercao definimos a ultima linha como atual
}

void insertDepois(unsigned int &l) {
    linAtual = l; 							   //Necessario para inserir o texto na posicao correta
    unsigned int col = MIN_COL, lin = MIN_LIN; //Variaveis que representam espacos na tela
    char c;                                    //Entrada do teclado
    std::string linha = "";                    //Variavel onde armazenaremos temporariamente a linha
    std::list<std::string>::iterator it;       //Iterador para referenciar um elemento na lista
    std::cout << "> ";
    while(true) {
        c = (char) getch();
        if(c == ESC) {                     //Tecla ESC
            it = texto.begin();
            std::advance (it, linAtual);   //Insere depois de uma determinada linha
            funcESC(texto, linha, it, linAtual);
            break;
        } else if(c == ENTER) {            //Tecla ENTER
            it = texto.begin();
            std::advance (it, linAtual);   //Insere depois de uma determinada linha
            funcENTER(texto, linha, lin, col, it);
            linAtual++;                    //Incrementa controle de linhas
        }
        else if(c == BACKSPACE) funcBACKSPACE(linha, col, lin);                 //Tecla BACKSPACE
        else if(c == TAB)       funcTAB(linha, lin, col);                       //Tecla TAB
        else if(c == CTRL_C)    funcCopy(linha);								//CTRL+C para copiar linha
        else if(c == CTRL_V)    funcPaste_A(texto, linha, lin, col, linAtual);  //CTRL+V para colar
        //Alguns caracteres diferentes/especiais (Setas direcionais, delete, home, ...)
        else if(c == CAR_ESP) {
            c = getche();
            if(c == LEFT)       funcLEFT(lin, col);             //Tecla pra esquerda
            else if(c == RIGHT) funcRIGHT(linha, lin, col);     //Tecla pra direita
            else if(c == UP)    continue;                       //Tecla para cima
            else if(c == DOWN)  continue;                       //Tecla para baixo
            else if(c == DEL)   funcDELETE(linha, lin, col);    //Tecla Delete
            else if(c == HOME)  funcHOME(lin, col);             //Tecla Home
            else if(c == END)   funcEND(linha, lin, col);       //Tecla END
            else                continue;                       //Nao serao aceitas outras
        } else                  addChar(linha, lin, col, c);    //Recebe caracter
    }
    linAtual = texto.size(); //Por padrao, sempre ao final de uma insercao definimos a ultima linha como atual
}

void setLinha(unsigned int linha) {
    if(linha <= texto.size()) {			//Se a linha esta dentro do limite (de 0 ate a ultima linha)
        linAtual = linha;
        std::cout << "A linha " << linAtual << " foi definidada como atual!\n";
        pause();
    }
    else
        std::cout << "Comando inv\240lido! Essa linha n\306o existe!" << std::endl;
}

void removeLinhas(unsigned int n) {
    if(n == 0) n++;                            //Nao podemos remover a linha 0-1
    if(texto.size() == 0) {
        std::cout << "Opera\207\306o Inv\240lida!! Nada foi escrito!!\n";
        pause();
        return;
    }
    std::list<std::string>::iterator it;       //Iterador para referenciar um elemento na lista
    it = texto.begin();
    std::advance(it, n-1);
    texto.erase(it);
    std::cout << "Opera\207\306o realizada com sucesso!!\n";
    pause();
    linAtual = texto.size(); //Por padrao, sempre ao final de uma alteracao definimos a ultima linha como atual
}

void removeLinhas(unsigned int n, unsigned int m) {
    if(n == 0) n++;                            //Nao podemos remover a linha 0-1
    std::list<std::string>::iterator it;       //Iterador para referenciar um elemento na lista
    it = texto.begin();
    std::advance(it, n-1);
    for(unsigned int tmp = n; (it != texto.end()) && (tmp <= m); tmp++) { //Remove a partir de uma linha ate outra
        texto.erase(it);
        it = texto.begin();
        std::advance(it, n-1);                 //Aponta sempre para a posicao na qual deve remover
    }
    std::cout << "Opera\207\306o realizada com sucesso!!\n";
    pause();
    linAtual = texto.size(); //Por padrao, sempre ao final de uma alteracao definimos a ultima linha como atual
}

void listaLinhas() {
    if(texto.size() == 0) {
        std::cout << "Opera\207\306o Inv\240lida!! Nada foi escrito!!\n";
        pause();
        return;
    }
    std::list<std::string>::iterator it;       //Iterador para referenciar um elemento na lista
    for(it = texto.begin(); it != texto.end(); it++) {
       std::cout << "> ";
       std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    pause();
}

void listaLinhas(unsigned int n) {
    unsigned int tmp = 1;                      								   //Variavel para controlar listagem de linhas
    std::list<std::string>::iterator it;       								   //Iterador para referenciar um elemento na lista
    for(it = texto.begin(); (it != texto.end()) && (tmp <= n); it++, tmp++) {  //Lista a partir da linha 1 ate n
       std::cout << "> ";
       std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    pause();
}

void listaLinhas(unsigned int n, unsigned int m) {
    std::list<std::string>::iterator it;      	 								//Iterador para referenciar um elemento na lista
    it = texto.begin();
    std::advance(it, n-1);                     									//Lembre-se que na lista a linha inicial é n-1
    for(unsigned int tmp = n; (it != texto.end()) && (tmp <= m); it++, tmp++) { //Lista a partir de uma linha ate outra
       std::cout << "> ";
       std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    pause();
}

void writeArq() {
    std::list<std::string>::iterator it; //Iterador para referenciar um elemento na lista
    std::ofstream fout(nomeArq.c_str()); //Abre arquivo para gravacao
    if(fout.is_open()) {
        for(it = texto.begin(); it != texto.end(); it++)
           fout << *it << std::endl;
        fout.close();                   //Fecha arquivo
    } else {
        std::cout << "Erro na leitura do arquivo!\n";
        return;
    }
}

void openArq(std::string &nomeArq2write, unsigned int &linAtual) {
    char tmp;
    std::string linha = "";                    //Variavel onde armazenaremos temporariamente a linha
    std::list<std::string>::iterator it;       //Iterador para referenciar um elemento na lista
    std::ifstream fin(nomeArq.c_str());        //Abre arquivo para leitura
    if(fin.is_open()) {
        if(!texto.empty()) {
            std::cout << "Tem certeza que deseja apagar seu texto e abrir esse arquivo? ";
            tmp = getche();
            if(tmp == 's' || tmp == 'S') {
                for(it = texto.begin(); it != texto.end(); it = texto.begin())
                    texto.erase(it);               //Apaga linhas remanescentes
            }
        }
        while(getline(fin, linha))
            texto.push_back(linha);            //Insere linhas presentes no arquivo
        linAtual = texto.size();               //Por padrao, sempre ao final de uma alteracao definimos a ultima linha como atual
        fin.close();                           //Fecha arquivo
    } else {
            nomeArq2write = nomeArq;
            system("cls");
            writeArq(texto, nomeArq);
    }
}

void File::readArq(std::string &nomeArq2write) {
    char tmp;
    std::string linha = "";                    //Variavel onde armazenaremos temporariamente a linha
    std::ifstream fin(nomeArq.c_str());        //Abre arquivo para leitura
    if(fin.is_open()) {
        while(getline(fin, linha))
            texto.push_back(linha);            //Insere linhas presentes no arquivo
        linAtual = texto.size();               //Por padrao, sempre ao final de uma alteracao definimos a ultima linha como atual
        std::cout << "Leitura realizada com sucesso!\n";
        pause();
        fin.close();                           //Fecha arquivo
    } else {
        std::cout << "Arquivo n\306o encontrado!\n" << "Voce deseja criar um arquivo com esse nome? [S/N] ";
        tmp = getche();
        if(tmp == 's' || tmp == 'S') {
            std::cout << "\nDigite o nome do arquivo que deseja criar: ";
            std::cin >> nomeArq;
            nomeArq2write = nomeArq;
            system("cls");
            writeArq(texto, nomeArq);
        }
        else
            return;
    }
}
