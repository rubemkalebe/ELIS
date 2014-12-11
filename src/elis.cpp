#include "elis.hpp"
#include "screen.hpp"
#include "keyboard.hpp"
#include "constantes.hpp"

void insertAntes(std::list<std::string> &texto, unsigned int &l, unsigned int &linAtual) {
    if(l == 0) l++;                             //Obviamente nao podemos inserir antes da posicao 0
    unsigned int col = MIN_COL, lin = MIN_LIN;  //Variaveis que representam espacos na tela
    char c;                                     //Entrada do teclado
    std::string linha = "";                     //Variavel onde armazenaremos temporariamente a linha
    std::list<std::string>::iterator it;        //Iterador para referenciar um elemento na lista
    update(texto, linha, col);                  // Atualiza tela

    while(true) {
        gotoxy(col, texto.size()+1);
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
            update(texto, linha, col); // Atualiza tela
        } else if(c == BACKSPACE) {         //Tecla BACKSPACE
            funcBACKSPACE(linha, col, lin);
            update(texto, linha, texto.size(), col); // Atualiza tela
        } else if(c == TAB) {   //Tecla TAB
            funcTAB(linha, lin, col);
            update(texto, linha, texto.size(), col); // Atualiza tela
        } else if(c == CTRL_C) { //CTRL+C para copiar linha
            funcCopy(linha);
        } else if(c == CTRL_V) { //CTRL+V para colar
            funcPaste_I(texto, linha, lin, col, l);
        }
        //Tratamento para alguns caracteres diferentes/especiais (Setas direcionais, delete, home, ...)
        else if(c == CAR_ESP) {
            c = getche();
            if(c == LEFT) {             //Tecla pra esquerda
                funcLEFT(lin, col);
            } else if(c == RIGHT) {     //Tecla pra direita
                funcRIGHT(linha, lin, col);
            } else if(c == UP) {        //Tecla para cima
                continue;
            } else if(c == DOWN) {      //Tecla para baixo
                continue;
            } else if(c == DEL) {       //Tecla Delete
                funcDELETE(linha, lin, col);
                update(texto, linha, texto.size(), col); // Atualiza tela
            } else if(c == HOME) {      //Tecla Home
                funcHOME(lin, col);
            } else if(c == END) {       //Tecla END
                funcEND(linha, lin, col);
            } else {                    //Nao serao aceitas outras teclas
                continue;
            }
        } else {
            addChar(linha, lin, col, c);    //Recebe caracter
            imprimeLinha(linha, texto.size(), col);
        }
    }
    linAtual = texto.size(); //Por padrao, sempre ao final de uma insercao definimos a ultima linha como atual
}

void editLinha(std::list<std::string> &texto, std::string &linha, unsigned int &l, unsigned int &linAtual) {
    unsigned int col = MIN_COL, lin = MIN_LIN; //Variaveis que representam espacos na tela
    char c;                                    //Entrada do teclado
    std::list<std::string>::iterator it;       //Iterador para referenciar um elemento na lista
    update(texto, linha, col);                  // Atualiza tela
    imprimeLinha(linha, texto.size(), col);
    while(true) {
        gotoxy(col, texto.size()+1);
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
            update(texto, linha, col); // Atualiza tela
            break;
        } else if(c == BACKSPACE) {         //Tecla BACKSPACE
            funcBACKSPACE(linha, col, lin);
            update(texto, linha, texto.size(), col); // Atualiza tela
        } else if(c == TAB) {   //Tecla TAB
            funcTAB(linha, lin, col);
            update(texto, linha, texto.size(), col); // Atualiza tela
        } else if(c == CTRL_C) { //CTRL+C para copiar linha
            funcCopy(linha);
        } else if(c == CTRL_V) { //CTRL+V para colar
            funcPaste_A(texto, linha, lin, col, linAtual);
        }
        //Tratamento para alguns caracteres diferentes/especiais (Setas direcionais, delete, home, ...)
        else if(c == CAR_ESP) {
            c = getche();
            if(c == LEFT) {             //Tecla pra esquerda
                funcLEFT(lin, col);
            } else if(c == RIGHT) {     //Tecla pra direita
                funcRIGHT(linha, lin, col);
            } else if(c == UP) {        //Tecla para cima
                continue;
            } else if(c == DOWN) {      //Tecla para baixo
                continue;
            } else if(c == DEL) {       //Tecla Delete
                funcDELETE(linha, lin, col);
                update(texto, linha, texto.size(), col); // Atualiza tela
            } else if(c == HOME) {      //Tecla Home
                funcHOME(lin, col);
            } else if(c == END) {       //Tecla END
                funcEND(linha, lin, col);
            } else {                    //Nao serao aceitas outras teclas
                continue;
            }
        } else {
            addChar(linha, lin, col, c);    //Recebe caracter
            imprimeLinha(linha, texto.size(), col);
        }
    }
    linAtual = texto.size(); //Por padrao, sempre ao final de uma insercao definimos a ultima linha como atual
}

void insertDepois(std::list<std::string> &texto, unsigned int &l, unsigned int &linAtual) {
    linAtual = l; 							   //Necessario para inserir o texto na posicao correta
    unsigned int col = MIN_COL, lin = MIN_LIN; //Variaveis que representam espacos na tela
    char c;                                    //Entrada do teclado
    std::string linha = "";                    //Variavel onde armazenaremos temporariamente a linha
    std::list<std::string>::iterator it;       //Iterador para referenciar um elemento na lista
    update(texto, linha, col);                  // Atualiza tela

    while(true) {
        gotoxy(col, texto.size()+1);
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
            update(texto, linha, col); // Atualiza tela
        } else if(c == BACKSPACE) {         //Tecla BACKSPACE
            funcBACKSPACE(linha, col, lin);
            update(texto, linha, texto.size(), col); // Atualiza tela
        } else if(c == TAB) {   //Tecla TAB
            funcTAB(linha, lin, col);
            update(texto, linha, texto.size(), col); // Atualiza tela
        } else if(c == CTRL_C) { //CTRL+C para copiar linha
            funcCopy(linha);
        } else if(c == CTRL_V) { //CTRL+V para colar
            funcPaste_A(texto, linha, lin, col, linAtual);
        }
        //Tratamento para alguns caracteres diferentes/especiais (Setas direcionais, delete, home, ...)
        else if(c == CAR_ESP) {
            c = getche();
            if(c == LEFT) {             //Tecla pra esquerda
                funcLEFT(lin, col);
            } else if(c == RIGHT) {     //Tecla pra direita
                funcRIGHT(linha, lin, col);
            } else if(c == UP) {        //Tecla para cima
                continue;
            } else if(c == DOWN) {      //Tecla para baixo
                continue;
            } else if(c == DEL) {       //Tecla Delete
                funcDELETE(linha, lin, col);
                update(texto, linha, texto.size(), col); // Atualiza tela
            } else if(c == HOME) {      //Tecla Home
                funcHOME(lin, col);
            } else if(c == END) {       //Tecla END
                funcEND(linha, lin, col);
            } else {                    //Nao serao aceitas outras teclas
                continue;
            }
        } else {
            addChar(linha, lin, col, c);    //Recebe caracter
            imprimeLinha(linha, texto.size(), col);
        }
    }
    linAtual = texto.size(); //Por padrao, sempre ao final de uma insercao definimos a ultima linha como atual
}

void funcCopy(std::string &linha) {
    HGLOBAL hText;
    char *pText;
    hText = GlobalAlloc(GMEM_DDESHARE|GMEM_MOVEABLE, linha.size()+1); 	//Aloca espaco para armazenar a linha
    pText = (char*)GlobalLock(hText);
    const char *c = linha.c_str(); 										//Transforma a string em um vetor de char
    strcpy(pText, c);
    GlobalUnlock(hText);

    OpenClipboard(NULL);												//Abre Clipboard
    EmptyClipboard();													//Limpa o Clipboard
    SetClipboardData(CF_OEMTEXT, hText);								//Insere a linha no Clipboard (O "CF_OEMTXT" garante que os acentos funcionem)
    CloseClipboard();													//Fecha Clipboard
    GlobalFree(hText);
}

void funcPaste_I(std::list<std::string> &texto, std::string &linha, unsigned int &lin, unsigned int &col, unsigned int &linAtual) {
    std::list<std::string>::iterator it;									//Iterador para referenciar um elemento na lista
    OpenClipboard(NULL);													//Abre Clipboard
    HANDLE hData = GetClipboardData(CF_OEMTEXT);							//Le os dados (O "CF_OEMTXT" garante que os acentos venham)
    if(hData == NULL)   return;												//Se nao for um texto, ou for outro tipo de cola, ele nao aceita
    char *pszText = static_cast<char*>( GlobalLock(hData) );				//Converte os dados para um vetor de char
    CloseClipboard();														//Fecha Clipboard
    for(int i = 0; pszText[i] != '\0'; i++) {
        if(pszText[i] == '\n') {											//Caracter '\n' corresponde ao ENTER
            it = texto.begin();
            std::advance(it, linAtual-1);									//Estamos no insertAntes
            funcENTER(texto, linha, lin, col, it);
            linAtual++;
        } else if(col >= MAX_COL)   continue;								//Nao deixa ultrapassar a linha do terminal
        else {
            linha.insert(linha.begin() + (col - MIN_COL), pszText[i]);      //Concatena caracteres
            col++;
        }
        imprimeLinha(linha, lin, col);
    }
    col = linha.size() + MIN_COL; 	//Por padrao, sempre ao final de uma insercao definimos a ultima linha como atual
}

void funcPaste_A(std::list<std::string> &texto, std::string &linha, unsigned int &lin, unsigned int &col, unsigned int &linAtual) {
    std::list<std::string>::iterator it;									//Iterador para referenciar um elemento na lista
    OpenClipboard(NULL);													//Abre Clipboard
    HANDLE hData = GetClipboardData(CF_OEMTEXT);							//Le os dados (O "CF_OEMTXT" garante que os acentos venham)
    if(hData == NULL)   return;												//Se nao for um texto, ou for outro tipo de cola, ele nao aceita
    char *pszText = static_cast<char*>( GlobalLock(hData) );				//Converte os dados para um vetor de char
    CloseClipboard();														//Fecha Clipboard
    for(int i = 0; pszText[i] != '\0'; i++) {
        if(pszText[i] == '\n') {											//Caracter '\n' corresponde ao ENTER
            it = texto.begin();
            std::advance(it, linAtual);										//Estamos no insertDepois
            funcENTER(texto, linha, lin, col, it);
            linAtual++;
        } else if(col >= MAX_COL)   continue;								//Nao deixa ultrapassar a linha do terminal
        else {
            linha.insert(linha.begin() + (col - MIN_COL), pszText[i]);      //Concatena caracteres
            col++;
        }
        imprimeLinha(linha, lin, col);
    }
    col = linha.size() + MIN_COL; 	//Por padrao, sempre ao final de uma insercao definimos a ultima linha como atual
}

void imprimeLinha(std::string &linha, unsigned int lin, unsigned int col) {
    gotoxy(MIN_COL, lin+1);
    std::cout << linha;   //Imprime a linha no local adequado
    gotoxy(col, lin+1);
}

void setLinha(std::list<std::string> &texto, unsigned int &linAtual, unsigned int linha) {
    if(linha <= texto.size()) {			//Se a linha esta dentro do limite (de 0 ate a ultima linha)
        linAtual = linha;
        std::cout << "A linha " << linAtual << " foi definidada como atual!\n";
        pause();
    }
    else
        std::cout << "Comando inv\240lido! Essa linha n\306o existe!" << std::endl;
}

void listaLinhas(std::list<std::string> &texto) {
    if(texto.size() == 0) {
        std::cout << "Opera\207\306o Inv\240lida!! Nada foi escrito!!\n";
        pause();
        return;
    }
    std::list<std::string>::iterator it;       //Iterador para referenciar um elemento na lista
    int i = 1;
    for(it = texto.begin(); it != texto.end(); it++, i++) {
       std::cout << i << " ";
       std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    pause();
}

void listaLinhas(std::list<std::string> &texto, unsigned int n) {
    unsigned int tmp = 1;                      								   //Variavel para controlar listagem de linhas
    std::list<std::string>::iterator it;       								   //Iterador para referenciar um elemento na lista
    int i = 1;
    for(it = texto.begin(); (it != texto.end()) && (tmp <= n); it++, tmp++) {  //Lista a partir da linha 1 ate n
       std::cout << tmp << " ";
       std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    pause();
}

void listaLinhas(std::list<std::string> &texto, unsigned int n, unsigned int m) {
    std::list<std::string>::iterator it;      	 								//Iterador para referenciar um elemento na lista
    it = texto.begin();
    std::advance(it, n-1);                     									//Lembre-se que na lista a linha inicial é n-1
    for(unsigned int tmp = n; (it != texto.end()) && (tmp <= m); it++, tmp++) { //Lista a partir de uma linha ate outra
       std::cout << tmp << " ";
       std::cout << *it << std::endl;
    }
    std::cout << std::endl;
    pause();
}

void print(std::list<std::string> &texto) {
    std::list<std::string>::iterator it;       								   //Iterador para referenciar um elemento na lista
    int i = 1;
    system("cls");
    for(it = texto.begin(); it != texto.end(); it++, i++) {
       std::cout << i << " ";
       std::cout << *it << std::endl;
    }
}

void removeLinhas(std::list<std::string> &texto, unsigned int n, unsigned int &linAtual) {
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

void removeLinhas(std::list<std::string> &texto, unsigned int n, unsigned int m, unsigned int &linAtual) {
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

void writeArq(std::list<std::string> &texto, std::string &nomeArq) {
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

void openArq(std::list<std::string> &texto, std::string &nomeArq, std::string &nomeArq2write, unsigned int &linAtual) {
    char tmp;
    std::string linha = "";                    //Variavel onde armazenaremos temporariamente a linha
    std::list<std::string>::iterator it;       //Iterador para referenciar um elemento na lista
    std::ifstream fin(nomeArq.c_str());        //Abre arquivo para leitura
    if(fin.is_open()) {
        if(!texto.empty()) {
            std::cout << "Tem certeza que deseja apagar seu texto e abrir esse arquivo? ";
            tmp = getche();
            if(tmp == 's' || tmp == 'S') {
                for(it = texto.begin(); it != texto.end(); it = texto.begin()) {
                    texto.erase(it);               //Apaga linhas remanescentes
                }
                std::string titulo = "title " + nomeArq + " - ELIS";
                system(titulo.c_str());
            } else {
                return;
            }
        }
        while(getline(fin, linha))
            texto.push_back(linha);            //Insere linhas presentes no arquivo
        linAtual = texto.size();               //Por padrao, sempre ao final de uma alteracao definimos a ultima linha como atual
        fin.close();                           //Fecha arquivo
    } else {
            nomeArq2write = nomeArq;
            writeArq(texto, nomeArq);
    }
    system("cls");
}

void readArq(std::list<std::string> &texto, std::string &nomeArq, std::string &nomeArq2write, unsigned int &linAtual) {
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

void pause() {
    std::cout << "\nPressione qualquer tecla para continuar...\n";
    char tmp = getch();
}
