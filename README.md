## Apresentação ##

Este programa foi desenvolvido com os objetivos de colocar em prática os conteúdos aprendidos nas disciplinas de Estruturas de Dados Básicas I e Laboratório de Programação I e embora desenvolvido em C++, ele usa amplamente o paradigma imperativo.

Trata-se de um editor de textos orientado a linhas, ou seja, edita-se uma linha por vez. Por mais estranho que possa parecer, esse tipo de editor de texto era bastante comum no século XX.

Quem já usou - ou ainda usa - editores como o VI ou VIM, vai encontrar uma certa semelhança.

## Discussão sobre estrutura de dados ##

Pode haver uma discussão sobre qual estrutura de dados é mais adequada para armazenar o texto. Nesse caso, foi utilizada uma lista encadeada, na qual cada nó é uma linha.

Essa estrutura utilizada é bem próxima da que também é muito utilizada para processamento de texto: *gap buffer*. Logo, utilizar lista encadeada é uma decisão de projeto sensata.

Uma outra estrutura de dados, conhecida como *Rope*, também é muito utilizada no desenvolvimento de projetos da área. No entanto, ela é ideal para armazenar/processar as *strings*, i.e., ela surge como uma alternativa para o armazenamento dos caracteres, sendo que para um simples projeto como esse (processar textos) não precisamos de tal complexidade.

## Breve descrição dos comandos ##

Primeiramente, o ELIS tem dois modos: o de comandos e o de edição. Os ':' indicam que você está no modo de comando. Já o '>' indica que você está no modo de edição.

Saiba também que o ELIS pode ser executado passando-se um arquivo (que exista ou não) como parâmetro ou sem nenhum parâmetro.

A seguir acompanhe uma breve descrição dos comandos. Essa lista pode ser acessada no programa a partir do comando **H**.

* **I [n]**:      Modo de edição que permite a inserção de texto antes da linha *n* ou da linha atual.

* **A [n]**:      Modo de edição que permite a inserção de texto depois da linha *n* ou da linha atual.

* **G n**:        Permite editar a linha *n*.

* **M [n]**:      Torna *n* a linha atual ou a última linha do texto passará a ser a linha atual.

* **D [n [m]]**:  Remove as linhas de *n* até *m*. Se apenas *n* é fornecido, remove-se a linha *n*. Se nenhum número é fornecido, remove-se a linha atual.

* **L [n [m]]**:  Lista as linhas de *n* até *m*. Se apenas *n* é fornecido, lista-se todo o texto até a linha *n*. Se não, lista-se todo o texto.

* **W name**: Salva o arquivo. O comando sem o fornecimento do parâmetro grava o texto no arquivo atual.

* **E name**:  Abre o arquivo passado por parâmetro.

* **O name**:  Lê e adiciona arquivo passado por parâmetro ao seu texto.

* **H**:         Exibe um texto de ajuda.

* **Q**:         Encerra o programa.

**Obs.:** Os [] indicam argumentos opcionais; As letras *n* e *m* representam linhas; A palavra *name* representa o nome do arquivo que deve incluir extensão.

## Como executar? ##

Infelizmente, por conta do uso da API do Windows, essa versão só executa em ambientes Windows.

1. [Baixe aqui](https://github.com/rubemkalebe/ELIS/archive/master.zip) este repositório.
2. Extraia o arquivo .zip que foi baixado anteriormente.
3. Abra a pasta extraída.
4. Execute o programa *main.exe*.

Caso faça alguma alteração ou necessite compilar os códigos, basta entrar na pasta 'src' e digitar o seguinte comando para o compilador G++: g++ *.cpp -o ../main. Ou então, use uma IDE.

## Equipe de desenvolvimento ##

* Rubem Kalebe (rubemkalebe@gmail.com).

## Observações ##

Este projeto foi encerrado em Dezembro de 2014. Ele foi desenvolvido inicialmente no segundo semestre de 2013 como projeto das disciplinas citadas e essa versão apresentada é um *remake* desenvolvido para corrigir alguns erros encontrados.

A equipe inicial era composta por:

* Jefferson Galvão Araujo
* Jordan Alexander Belo Alves
* Rubem Kalebe Santos

Existe um último *bug* no projeto envolvendo o comando *M* (comando para linha atual). Esse *bug* não foi resolvido por mera preguiça, mas não é difícil resolvê-lo. De qualquer forma, não use esse comando que nada acontecerá :)
