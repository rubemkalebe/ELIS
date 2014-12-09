#include "line.hpp"

Line::Line() {

}

void Line::editLinha(unsigned int &l) {
    unsigned int col = MIN_COL, lin = MIN_LIN; //Variaveis que representam espacos na tela
    char c;                                    //Entrada do teclado
    std::list<std::string>::iterator it;       //Iterador para referenciar um elemento na lista
    std::cout << "> ";
    imprimeLinha(linha, lin, col);
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
            break;
        }
        else if(c == BACKSPACE) funcBACKSPACE(linha, col, lin);                 //Tecla BACKSPACE
        else if(c == TAB)       funcTAB(linha, lin, col);                       //Tecla TAB
        else if(c == CTRL_C)    funcCopy(linha);								//CTRL+C para copiar linha
        else if(c == CTRL_V)    funcPaste_I(texto, linha, lin, col, linAtual);  //CTRL+V para colar
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

void Line::funcCopy() {
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

void Line::funcPaste_I(unsigned int &lin, unsigned int &col) {
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

void Line::funcPaste_A(unsigned int &lin, unsigned int &col) {
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

void Line::addChar(unsigned int lin, unsigned int &col, char c) {
    if((col == MAX_COL) || (linha.length() + MIN_COL == MAX_COL)) return; //Verifica se ainda pode adicionar
    linha.insert(linha.begin() + (col - MIN_COL), c);                     //Concatena caracteres
    col++;                                                                //Incrementa contador de colunas
    imprimeLinha(linha, lin, col);
}

void Line::imprimeLinha(unsigned int lin, unsigned int col) {
    gotoxy(MIN_COL, lin);
    std::cout << linha;   //Imprime a linha no local adequado
    gotoxy(col, lin);
}

void Line::funcESC(std::list<std::string> &texto, std::string &linha, std::list<std::string>::iterator it, unsigned int &l) {
    if(linha != "") {
        texto.insert(it, linha); //Insere linha
        std::cout << std::endl;
    } else
        l--;                     //Necessario para controlar as linhas
}

void Line::funcENTER(std::list<std::string> &texto, std::string &linha, unsigned int &lin, unsigned int &col, std::list<std::string>::iterator it) {
    std::cout << std::endl;         //Pula linha
    texto.insert(it, linha);        //Insere linha
    linha = "";                     //Zera nova linha que sera usada
    std::cout << "> ";
    lin++;                          //Incrementa numero de linhas
    col = MIN_COL;                  //Nova coluna (iniciando da primeira posicao disponivel)
}

void Line::funcBACKSPACE(std::string &linha, unsigned int &col, unsigned int lin) {
    if((linha != "") && (col > MIN_COL)) {
        linha.erase(linha.begin()+(col - MIN_COL) - 1); //Remove ultimo caracter
        linha.end();                					//Move iterador para o fim da string
        gotoxy(linha.length() + MIN_COL + 1, lin);
        std::cout << "\b \b";
        col--;                      					//Decrementa cursor de colunas
        imprimeLinha(linha, lin, col);
    } else
        return;
}

void Line::funcTAB(std::string &linha, unsigned int &lin, unsigned int &col) {
    if(col > MAX_COL - ESP_TAB) return;                		//Verifica se pode aceitar o TAB para nao atravessar a linha do terminal
    if(linha.length() + ESP_TAB > MAX_COL - 2) return; 		//Verifica se pode aceitar o TAB para nao atravessar a linha do terminal
    for(int i = 1; i <= 5; i++, col++)
        linha.insert(linha.begin()+(col - MIN_COL), ' '); 	//Preenche as lacunas com space
    gotoxy(MIN_COL, lin);                                 	//Move o cursor para a posicao correta
    std::cout << linha;
    gotoxy(col, lin);
}

void Line::funcLEFT(unsigned int lin, unsigned int &col) {
    if((col == MIN_COL)) return; //Verifica se pode aceitar
    col--;
    gotoxy(col, lin);            //Apos decrementar o numerador das colunas movemos o cursor para a posicao correta
}

void Line::funcRIGHT(std::string linha, unsigned int lin, unsigned int &col) {
    if(col >= linha.length() + MIN_COL) return; //Verifica se pode aceitar
    col++;
    gotoxy(col, lin);            				//Apos decrementar o numerador das colunas movemos o cursor para a posicao correta
}

void Line::funcHOME(unsigned int lin, unsigned int &col) {
    col = MIN_COL;
    gotoxy(col, lin);            	//Apos decrementar o numerador das colunas movemos o cursor para a posicao correta
}

void Line::funcEND(std::string linha, unsigned int lin, unsigned int &col) {
    col = linha.length() + MIN_COL; //Desloca o espaco necessario
    gotoxy(col, lin);            	//Apos decrementar o numerador das colunas movemos o cursor para a posicao correta
}

void Line::funcDELETE(std::string &linha, unsigned int lin, unsigned int col) {
    if((linha != "") && (col < linha.length() + MIN_COL)) {
        linha.erase(linha.begin()+(col - MIN_COL)); //Apaga caracter da lista
        gotoxy(linha.length() + MIN_COL+1, lin);    //Posiciona o cursor
        std::cout << "\b \b";                       //Apaga o caracter da tela
        imprimeLinha(linha, lin, col);
    }
}
