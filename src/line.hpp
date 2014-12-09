#ifndef LINE_HPP
#define LINE_HPP

class Line {

    std::string linha;

public:

    Line();

private:

    void editLinha(unsigned int &l);                                //Funcao para editar uma linha
    void funcCopy();                                                  //Funcao para copiar uma linha
	void funcPaste_I(unsigned int &lin, unsigned int &col);         //Funcao para colar linha/texto (para insertAntes)
	void funcPaste_A(unsigned int &lin, unsigned int &col);         //Funcao para colar linha/texto (para insertDepois)
	void addChar(unsigned int lin, unsigned int &col, char c);      //Adiciona um caracter a linha
	void imprimeLinha(unsigned int lin, unsigned int col);           //Funcao que imprime a linha (quando edicao)

    // Métodos para tratamento de caracteres de comando
    void funcESC(std::list<std::string>::iterator it, unsigned int &l); //Encerra o modo de edicao
	void funcENTER(unsigned int &lin, unsigned int &col, std::list<std::string>::iterator it); //Finaliza linha
	void funcBACKSPACE(unsigned int &col, unsigned int lin);                //Funciona como Backspace no modo de edicao
	void funcTAB(unsigned int &lin, unsigned int &col);                     //Funciona como Tab
	void funcLEFT(unsigned int lin, unsigned int &col);                                         //Desloca o cursor para esquerda
	void funcRIGHT(unsigned int lin, unsigned int &col);                     //Desloca o cursor para a direita
	void funcHOME(unsigned int lin, unsigned int &col);                                         //Desloca o cursor para o inicio da linha
	void funcEND(unsigned int lin, unsigned int &col);                       //Desloca o cursor para o fim da linha
	void funcDELETE(unsigned int lin, unsigned int col);                    //Deleta um caracter

};

#endif // LINE_HPP
