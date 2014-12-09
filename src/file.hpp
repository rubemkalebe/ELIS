#ifndef FILE_HPP
#define FILE_HPP

class File {

private:

    std::list<std::string> texto;   //Cria lista duplamente encadeada que ira armazenar o texto (cada linha sera um no)
    unsigned int linAtual;          //Variavel que define a linha atual. Inicialmente sera zero
    std::string nomeArq;            //Nome do arquivo
    bool alterado;      	        //Identifica se foram feitas alteracoes no texto

public:

    File();
    File(std::string nomeArq);

    //Aqui estao as funcoes de edicao. Tudo que estiver relacionado a edicao de textos esta aqui
    void insertAntes(unsigned int &l);                                                  //Funcao que insere um texto antes de uma linha
	void insertDepois(unsigned int &l);                                                 //Funcao que insere um texto depois de uma linha

    void setLinha(unsigned int linha);   //Define uma linha como atual

    //Funcoes para remover linhas do texto
    void removeLinhas(unsigned int n, unsigned int &linAtual);					//Remove uma linha
	void removeLinhas(unsigned int n, unsigned int m, unsigned int &linAtual);	//Remove da linha n ate m

    //Funcoes para listar as linhas do texto
    void listaLinhas();									//Lista todo o texto
    void listaLinhas(unsigned int n);					//Lista texto do inicio ate a linha n
    void listaLinhas(unsigned int n, unsigned int m);   //Lista o texto da linha n ate m

    //Funcoes para manipulacao de arquivos
	void writeArq();							//Grava arquivo
	void openArq(std::string &nomeArq2write);   //Abre um arquivo
	void readArq(std::string &nomeArq2write);   //Insere um arquivo no fim do seu texto
};

#endif // FILE_HPP
