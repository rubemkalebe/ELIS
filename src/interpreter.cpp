#include "interpreter.hpp"

Interpreter::Interpreter() {

}

void modoComando() {
    char op, tmp;       	//op -> armazena comando ; tmp -> armazena a entrada do teclado apos o comando
                            //(identifica o pressionamento do ENTER, por exemplo)
    std::string nomeArq2write, nomeArq2read; //Variaveis para salvar ou ler arquivo
    //O laco do modo de comando executara indefinidamente enquanto o usuario nao quiser sair
    do {
        system("cls");
        std::cout << ": ";
        op = getche();
        if((op >= 'A' && op <= 'Z') || (op >= 'a' && op <= 'z')) { //Descarta outras teclas
            switch(op) {
                case 'i' :
                case 'I' :
                    comand_I(texto, linAtual);                     //Comando de insercao de texto antes de uma linha
                    alterado = true;
                    break;
                case 'a' :
                case 'A' :
                    comand_A(texto, linAtual);                     //Comando de insercao de texto depois de uma linha
                    alterado = true;
                    break;
                case 'g' :
                case 'G' :
                    comand_G(texto, linAtual);
                    alterado = true;
                    break;
                case 'm' :
                case 'M' :
                    comand_M(texto, linAtual);                     //Comando que define uma linha como atual
                    break;
                case 'l' :
                case 'L' :
                    comand_DL(texto, linAtual, op);                //Comando de listagem de linhas
                    break;
                case 'd' :
                case 'D' :
                    comand_DL(texto, linAtual, op);                //Comando de remocao de linhas
                    alterado = true;
                    break;
                case 'w' :
                case 'W' :                                         //Comando para gravacao de arquivo
                    tmp = getche();
                    if(tmp == ' ') { 								//O space identifica que o usuario digitara um nome para o arquivo
                        system("cls");
                        std::cout << "Digite o nome do arquivo para grava\207\306o: ";
                        std::cin >> nomeArq2write;
                        writeArq(texto, nomeArq2write);
                        alterado = false;
                    } else if(tmp == ENTER && nomeArq2write == "") { //Se o usuario tentar salvar sem ter um nome para o arquivo
                        system("cls");
                        std::cout << "Erro! Digite o nome do arquivo!\n";
                        pause();
                    } else {    									//Salva com o nome ja fornecido
                        writeArq(texto, nomeArq2write);
                        alterado = false;
                    }
                    break;
                case 'e' :
                case 'E' :                                         //Comando para leitura de arquivo
                    tmp = getche();
                    if(tmp == ' ') { 							   //O space identifica que o usuario digitara um nome para o arquivo
                        system("cls");
                        std::cout << "Digite o nome do arquivo para leitura: ";
                        std::cin >> nomeArq2read;
                        openArq(texto, nomeArq2read, nomeArq2write, linAtual);
                        alterado = true;
                    } else
                        continue; //Ignora entrada
                    break;
                case 'o' :
                case 'O' :
                    tmp = getche();
                    if(tmp == ' ') { 							  //O space identifica que o usuario digitara um nome para o arquivo
                        system("cls");
                        std::cout << "Digite o nome do arquivo para leitura: ";
                        std::cin >> nomeArq2read;
                        readArq(texto, nomeArq2read, nomeArq2write, linAtual);
                        alterado = true;
                    } else
                        continue; //Ignora entrada
                    break;
                case 'h' :
                case 'H' :
                    tmp = getche();
                    if(tmp == ENTER)
                        comand_H();
                    else
                        continue;
                    break;
                case 'q' :
                case 'Q' :                                         //Comando para terminar a execucao do programa
                    tmp = getche();
                    if(tmp == ENTER && alterado == false)
                        return;
                    else if(tmp == ENTER && alterado == true) { //Para nao perder o trabalho feito ele pergunta se quer sair sem salvar
                            system("cls");
                            std::cout << "Tem certeza que deseja sair sem salvar? [S/N] ";
                            tmp = getche();
                            if(tmp == 's' || tmp == 'S')
                                return;
                    }
                    else
                        continue; //Ignora entrada
                    break;
                default  :
                    tmp = getche();
                    if(tmp == ENTER) { //Advertencia quanto a qualquer comando que nao esteja listado
                        std::cout << "\nComando inv\240lido!!\n";
                        pause();
                    } else
                        continue;
            }
        }
    } while(op != 'q' || op != 'Q');
}

void modoComando(std::string nomeArq) {
    char op, tmp;       	//op -> armazena comando ; tmp -> armazena a entrada do teclado apos o comando
                            //(identifica o pressionamento do ENTER, por exemplo)
    std::string nomeArq2write = nomeArq, nomeArq2read; //Variaveis para salvar ou ler arquivo
    //O laco do modo de comando executara indefinidamente enquanto o usuario nao quiser sair
    do {
        system("cls");
        std::cout << ": ";
        op = getche();
        if((op >= 'A' && op <= 'Z') || (op >= 'a' && op <= 'z')) { //Descarta outras teclas
            switch(op) {
                case 'i' :
                case 'I' :
                    comand_I(texto, linAtual);                     //Comando de insercao de texto antes de uma linha
                    alterado = true;
                    break;
                case 'a' :
                case 'A' :
                    comand_A(texto, linAtual);                     //Comando de insercao de texto depois de uma linha
                    alterado = true;
                    break;
                case 'g' :
                case 'G' :
                    comand_G(texto, linAtual);
                    alterado = true;
                    break;
                case 'm' :
                case 'M' :
                    comand_M(texto, linAtual);                     //Comando que define uma linha como atual
                    break;
                case 'l' :
                case 'L' :
                    comand_DL(texto, linAtual, op);                //Comando de listagem de linhas
                    break;
                case 'd' :
                case 'D' :
                    comand_DL(texto, linAtual, op);                //Comando de remocao de linhas
                    alterado = true;
                    break;
                case 'w' :
                case 'W' :                                         //Comando para gravacao de arquivo
                    tmp = getche();
                    if(tmp == ' ') {							  //O space identifica que o usuario digitara um nome para o arquivo
                        system("cls");
                        std::cout << "Digite o nome do arquivo para grava\207\306o: ";
                        std::cin >> nomeArq2write;
                        writeArq(texto, nomeArq2write);
                        alterado = false;
                    } else {   //Salva com o nome ja fornecido
                        writeArq(texto, nomeArq2write);
                        alterado = false;
                    }
                    break;
                case 'e' :
                case 'E' :                                         //Comando para leitura de arquivo
                    tmp = getche();
                    if(tmp == ' ') { 							  //O space identifica que o usuario digitara um nome para o arquivo
                        system("cls");
                        std::cout << "Digite o nome do arquivo para leitura: ";
                        std::cin >> nomeArq2read;
                        openArq(texto, nomeArq2read, nomeArq2write, linAtual);
                        alterado = true;
                    } else
                        continue; //Ignora entrada
                    break;
                case 'o' :
                case 'O' :
                    tmp = getche();
                    if(tmp == ' ') { 				 	 	      //O space identifica que o usuario digitara um nome para o arquivo
                        system("cls");
                        std::cout << "Digite o nome do arquivo para leitura: ";
                        std::cin >> nomeArq2read;
                        readArq(texto, nomeArq2read, nomeArq2write, linAtual);
                        alterado = true;
                    } else
                        continue; //Ignora entrada
                    break;
                case 'h' :
                case 'H' :
                    tmp = getche();
                    if(tmp == ENTER)
                        comand_H();
                    else
                        continue;
                    break;
                case 'q' :
                case 'Q' :                                         //Comando para terminar a execucao do programa
                    tmp = getche();
                    if(tmp == ENTER && alterado == false)
                        return;
                    else if(tmp == ENTER && alterado == true) { //Para nao perder o trabalho feito ele pergunta se quer sair sem salvar
                            system("cls");
                            std::cout << "Tem certeza que deseja sair sem salvar? [S/N] ";
                            tmp = getche();
                            if(tmp == 's' || tmp == 'S')
                                return;
                    }
                    else
                        continue; //Ignora entrada
                    break;
                default  :
                    tmp = getche();
                    if(tmp == ENTER) { 								//Advertencia quanto a qualquer comando que nao esteja listado
                        std::cout << "\nComando inv\240lido!!\n";
                        pause();
                    } else
                        continue;
            }
        }
    } while(op != 'q' || op != 'Q');
}

void comand_I(std::list<std::string> &texto, unsigned int &linAtual) {
    unsigned int n;     //Armazena o numero de uma linha
    char tmp, tmp2;     //Variveis para controlar as entradas do teclado
    std::string op_lin; //String para armazenar a linha temporariamente
    tmp = getche();
    if(tmp == ENTER) {
        system("cls");
        insertAntes(texto, linAtual, linAtual); //Insere a partir da linha atual
    } else if(tmp == ' ') {
        while(true) {
            tmp2 = getche();
            if(tmp2 >= '0' && tmp2 <= '9')
                op_lin.push_back(tmp2);         //Recebe numeros para formar linha
            else if(tmp2 == ENTER) {
                const char *c = op_lin.c_str(); //Transforma a string em um vetor de char
                n = atoi(c);                    //Usa atoi para converter o vetor de char com a linha para int
                if((n > linAtual || n == 0) && n != 1) {
                    std::cout << "\nLinha Inv\240lida!!\n";
                    pause();
                    return;
                } else {
                    system("cls");
                    insertAntes(texto, n, linAtual); //Insere a partir da linha passada como parametro
                    return;
                }
            } else if(tmp == BACKSPACE) funcBACKSPACE(op_lin);
        else
            return;
        }
    }
}

void comand_A(std::list<std::string> &texto, unsigned int &linAtual) {
    unsigned int n;     //Armazena o numero de uma linha
    char tmp, tmp2;     //Variveis para controlar as entradas do teclado
    std::string op_lin; //String para armazenar a linha temporariamente
    tmp = getche();
    if(tmp == ENTER) {
        system("cls");
        insertDepois(texto, linAtual, linAtual); //Insere a partir da linha atual
    } else if(tmp == ' ') {
        while(true) {
            tmp2 = getche();
            if(tmp2 >= '0' && tmp2 <= '9')
                op_lin.push_back(tmp2);         //Recebe numeros para formar linha
            else if(tmp2 == ENTER) {
                const char *c = op_lin.c_str(); //Transforma a string em um vetor de char
                n = atoi(c);                    //Usa atoi para converter o vetor de char com a linha para int
                if(n > linAtual || n == 0 || n == 0) {
                    std::cout << "\nLinha Inv\240lida!!\n";
                    pause();
                    return;
                } else {
                    system("cls");
                    insertDepois(texto, n, linAtual); //Insere a partir da linha passada como parametro
                    return;
                }
            } else if(tmp == BACKSPACE) funcBACKSPACE(op_lin);
        else
            return;
        }
    }
}

void comand_M(std::list<std::string> &texto, unsigned int &linAtual) {
    unsigned int n;     //Armazena o numero de uma linha
    char tmp, tmp2;     //Variveis para controlar as entradas do teclado
    std::string op_lin; //String para armazenar a linha temporariamente
    tmp = getche();
    if(tmp == ENTER) {
        system("cls");
        setLinha(texto, linAtual, linAtual); //Define ultima linha como atual
    } else if(tmp == ' ') {
        while(true) {
            tmp2 = getche();
            if(tmp2 >= '0' && tmp2 <= '9')
                op_lin.push_back(tmp2);         //Recebe numeros para formar linha
            else if(tmp2 == ENTER) {
                const char *c = op_lin.c_str(); //Transforma a string em um vetor de char
                n = atoi(c);                    //Usa atoi para converter o vetor de char com a linha para int
                if(n > linAtual) {
                    std::cout << "\nLinha Inv\240lida!!\n";
                    pause();
                    return;
                } else {
                    system("cls");
                    setLinha(texto, linAtual, n); //Define linha passada como parametro como atual
                    return;
                }
            } else if(tmp == BACKSPACE) funcBACKSPACE(op_lin);
        else
            return;
        }
    }
}

void comand_DL(std::list<std::string> &texto, unsigned int &linAtual, char op) {
    unsigned int n, m;     //Variaveis para armazenar numeros de linhas
    char tmp, tmp2, tmp3;  //Variveis para controlar as entradas do teclado
    std::string op_lin;    //String para armazenar a linha temporariamente
    tmp = getche();
    if(tmp == ENTER) {
        system("cls");
        if(op == 'd' || op == 'D')      removeLinhas(texto, linAtual, linAtual); //Remove linha atual
        else if(op == 'l' || op == 'L') listaLinhas(texto);                      //Lista todo o texto
        return;
    } else if (tmp == ' ') {
        op_lin = "";
        while(true) {
            tmp2 = getche();
            if(tmp2 >= '0' && tmp2 <= '9')
                op_lin.push_back(tmp2);         //Recebe numeros para formar linha
            else if(tmp2 == ENTER) {
                const char *c = op_lin.c_str(); //Transforma a string em um vetor de char
                n = atoi(c);                    //Usa atoi para converter o vetor de char com a linha para int
                if(n > linAtual) {
                    std::cout << "\nLinha Inv\240lida!!\n";
                    pause();
                    return;
                }
                system("cls");
                if(op == 'd' || op == 'D')      removeLinhas(texto, n, linAtual); //Remove linha passada por parametro
                else if(op == 'l' || op == 'L') listaLinhas(texto, n);            //Lista texto ate a linha n
                break;
            } else if(tmp2 == ' ') {
                const char *c = op_lin.c_str();
                n = atoi(c);
                op_lin = "";
                while(true) {
                    tmp3 = getche();
                    if(tmp3 >= '0' && tmp3 <= '9')
                        op_lin.push_back(tmp3);
                    else if(tmp3 == ENTER) {
                        const char *c = op_lin.c_str();
                        m = atoi(c);
                        if(m > linAtual || n > m) {
                            std::cout << "\nLinha Inv\240lida!!\n";
                            pause();
                            return;
                        }
                        system("cls");
                        if(op == 'd' || op == 'D')      removeLinhas(texto, n, m, linAtual); //Remove da linha n ate m
                        else if(op == 'l' || op == 'L') listaLinhas(texto, n, m);            //Lista da linha n ate m
                        break;
                    }
                }
                if(tmp3 == ENTER )
                    return;
            } else if(tmp2 == BACKSPACE) funcBACKSPACE(op_lin);
              else
                return;
        }
    } else if(tmp == BACKSPACE) funcBACKSPACE(op_lin);
      else
        return;
}

void comand_G(std::list<std::string> &texto, unsigned int &linAtual) {
    unsigned int i = 1, n;						//Contador de linhas e variavel para receber linha
    char tmp, tmp2;     						//Variveis para controlar as entradas do teclado
    std::string op_lin; 						//String para armazenar a linha temporariamente
    std::string linha = "";                     //Variavel onde armazenaremos temporariamente a linha
    std::list<std::string>::iterator it;        //Iterador para referenciar um elemento na lista
    tmp = getche();
    if(tmp == ENTER) {
        std::cout << "\nComando inv\240lido!!\n";
        pause();
    } else if(tmp == ' ') {
        while(true) {
            tmp2 = getche();
            if(tmp2 >= '0' && tmp2 <= '9')
                op_lin.push_back(tmp2);         //Recebe numeros para formar linha
            else if(tmp2 == ENTER) {
                const char *c = op_lin.c_str(); //Transforma a string em um vetor de char
                n = atoi(c);                    //Usa atoi para converter o vetor de char com a linha para int
                if(n > linAtual || n == 0) {
                    std::cout << "\nLinha Inv\240lida!!\n";
                    pause();
                    return;
                } else {
                    system("cls");
                    for(it = texto.begin(); it != texto.end() || i <= n; it++, i++) {
                        if(i == n) {
                            linha = *it;		//Guarda a linha
                            texto.erase(it);	//Deleta do texto
                            break;
                        }
                    }
                    editLinha(texto, linha, n, linAtual);	//Abre para edicao
                    return;
                }
            } else if(tmp == BACKSPACE) funcBACKSPACE(op_lin);
        else
            return;
        }
    }
}

void comand_H() {
    system ("cls");
    std::cout << "\t\t\tBem-vindo ao ELIS" << std::endl << std::endl;
    std::cout << "   Comandos:" << std::endl << std::endl;
    std::cout << "-> I [n]:      Modo de edi\207\306o que permite a inser\207\306o de texto antes da linha n" << std::endl;
    std::cout << "               ou da linha atual." << std::endl << std::endl;
    std::cout << "-> A [n]:      Modo de edi\207\306o que permite a inser\207\306o de texto depois da linha n" << std::endl;
    std::cout << "               ou da linha atual." << std::endl << std::endl;
    std::cout << "-> G n:        Permite editar a linha n." << std::endl << std::endl;
    std::cout << "-> M [n]:      Torna n a linha atual ou a \243ltima linha do texto passa a ser a" << std::endl;
    std::cout << "               atual." << std::endl << std::endl;
    std::cout << "-> D [n [m]]:  Remove as linhas n at\202 m. Se apenas n \202 fornecido, remove-se a" << std::endl;
    std::cout << "               linha n. Se nenhum n\243mero \202 fornecido, remove-se a linha atual." << std::endl << std::endl;
    std::cout << "-> L [n [m]]:  Lista as linhas n at\202 m. Se apenas n \202 fornecido, lista-se todo" << std::endl;
    std::cout << "               o texto at\202 a linha n. Se n\306o, lista-se todo o texto." << std::endl << std::endl;
    std::cout << "-> W [<name>]: Salva o arquivo. O comando sem o fornecimento do nome grava o" << std::endl;
    std::cout << "               texto no arquivo atual." << std::endl << std::endl;
    std::cout << "-> E <name> :  Abre arquivo passado por par\203metro." << std::endl << std::endl;
    std::cout << "-> O <name> :  L\210 e adiciona arquivo passado por par\203metro ao seu texto." << std::endl << std::endl;
    std::cout << "-> H :         Exibe um texto de ajuda." << std::endl << std::endl;
    std::cout << "-> Q :         Encerra o programa." << std::endl << std::endl;
    std::cout << "\n* Os [] indicam argumentos opcionais." << std::endl;
    std::cout << "\n* As letras n e m representam linhas." << std::endl;
    std::cout << "\n* A palavra name representa o nome do arquivo que deve incluir extens\306o." << std::endl;
    std::cout << "\n* Os ':' indicam que voc\210 est\240 no modo de comando." << std::endl;
    std::cout << "\n* O '>' indica que voc\210 est\240 no modo de edi\207\306o." << std::endl;
    pause();
}

void Interpreter::funcBACKSPACE(std::string &op) {
    if(op != "") {
        op.erase(op.end() - 1);  //Remove ultimo caracter
        op.end();                //Move iterador para o fim da string
        std::cout << "\b \b";    //Volta o cursor e apaga caracter
        gotoxy(MIN_COL+2, 0);    //Move o cursor para a posicao correta
        std::cout << op;
        gotoxy(op.length()+1, 0);
    }
}
