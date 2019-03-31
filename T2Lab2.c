//Aluno: Bruno Gottlieb | CC
#include<stdio.h>  //Biblioteca padrao da linguagem C
#include<stdlib.h> //Biblioteca usada para os comandos maloc e exit
#include<ctype.h>  //Biblioteca usada para converter as letras em maiusculo
#include<string.h> //Biblioteca usada para receber o tamanho da string inserida
#include<time.h>   //Biblioteca usada para inicializar o srand
void converte_maiuscula(char *palavra, int tam){         //Funcao que converte a palavra para maiuscula
  int i;                                                 //Variavel auxiliar
  for(i=0;i<tam;i++){                                    //Laco vai desde a primeira letra ate a ultima(tam)
    palavra[i]=toupper(palavra[i]);                      //Armazena a nova letra ja convertida
  }
}
int solicitar_palavra(char *palavra, int tam){
  printf("\nInsira a palavra a ser buscada: ");
  scanf(" %s", palavra);                                 //Recebe a palavra a ser buscada na matriz e altera direto no endereco da variavel declarada na main
  tam= strlen(palavra);                                  //Tam recebe a quantia de letras da palavra inserida
  converte_maiuscula(palavra,tam);                       //Converte a palavra inserida para maiuscula
  printf("\n");
  return tam;                                            //Retorna o tamanho da palavra
}
void liberar_espaco (int m, char **matriz){              //Funcao que libera o espaco alocado pela matriz
  int  i;                                                //Variavel auxiliar
  for (i=0;i<m;i++){                                     //Libera as linhas da matriz
    free(matriz[i]);                                     //
    }
  free (matriz);                                         //Libera a matriz
  puts("\nEspaco liberado");
  exit (0);                                              //Retorna um ponteiro nulo e finaliza o programa
}
void uma_letra(int m,int n,char *palavra,char **matriz){ //Funcao confere onde esta a letra que o usuario inseriu
  int i, j;                                              //Variaveis auxiliares
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      if(matriz[i][j]==palavra[0]){                      //Apenas confere se a posicao da matriz eh igual a letra do usuario
        printf("Encontrada a letra %c\n", palavra[0]);
        printf("Primeira aparicao da letra %c na posicao [%d][%d]\n",palavra[0],i,j);
        liberar_espaco(m,matriz);                        //Envia para a funcao que libera o espaco alocado pela matriz
      }
    }
  }
}
void diagonal_esquerda(int i, int j, char *palavra, char **matriz, int tam, int m, int n){
  int k=0;                                           //Variavel auxiliar, sera usada para efetuar o incremento
  //Aqui a cada laco sera implementado +1 na linha e +1 coluna, assim a matriz sera conferiada diagonalmente de cima para baixo e da esquerda pra direita
  //A proxima conferencia nao pode ultrapassar o limite inferior e lateral da matriz
  while(((i+k<m))&&((j+k<n))&&(matriz[i+k][j+k]==palavra[k])){
    k++;                                             //Incrementa a variavel k para que a proxima letra possa ser conferida
    if(k==tam){                                      //Se o numero de letras encontradas conferir com o tamanho da palavra eh porque ela foi encontrada
      printf("Encontrou a palavra %s na diagonal esquerda\n", palavra);
      printf("Inicio: [%d][%d]\n", i, j);            //Inicio sera a posicao da primeira letra da palavra
      printf("Final: [%d][%d]\n", i+k-1, j+k-1);     //Final sera a posicao da primeira letra encontrada mais a quantia de incremento efetuada de linhas e mais o incremento de colunas
      liberar_espaco(m,matriz);                      //Envia para a funcao que libera o espaco alocado e finaliza o programa
    }
  }
}
void diagonal_direita(int i, int j, char *palavra, char **matriz, int tam, int m, int n){
  int k=0;                                           //Variavel auxiliar, sera usada para efetuar o incremento
  //Aqui a cada laco sera implementado +1 na linha e -1 coluna, assim a matriz sera conferiada diagonalmente de cima para baixo e da direita pra esquerda
  //A proxima conferencia nao pode ultrapassar o limite inferior e lateral da matriz
  while(((i+k<m))&&((j-k>=0))&&(matriz[i+k][j-k]==palavra[k])){
    k++;                                             //Incrementa a variavel k para que a proxima letra possa ser conferida
    if(k==tam){                                      //Se o numero de letras encontradas conferir com o tamanho da palavra eh porque ela foi encontrada
      printf("Encontrou a palavra %s na diagonal direita\n", palavra);
      printf("Inicio: [%d][%d]\n", i, j);            //Inicio sera a posicao da primeira letra da palavra
      printf("Final: [%d][%d]\n", i+k-1, j-k+1);     //Final sera a posicao da primeira letra encontrada mais a quantia de incremento efetuada de linhas e menos o incremento de colunas
      liberar_espaco(m,matriz);                      //Envia para a funcao que libera o espaco alocado e finaliza o programa
    }
  }
}
void diagonal_esquerda_reversa(int i, int j, char *palavra, char **matriz, int tam, int m, int n){
  int k=0;                                           //Variavel auxiliar, sera usada para efetuar o incremento
  //Aqui a cada laco sera implementado -1 na linha e -1 coluna, assim a matriz sera conferiada diagonalmente de baixo para cima e da direita pra esquerda
  //A proxima conferencia nao pode ultrapassar o limite superior e lateral da matriz
  while(((i-k>=0))&&((j-k>=0))&&(matriz[i-k][j-k]==palavra[k])){
    k++;                                             //Incrementa a variavel k para que a proxima letra possa ser conferida
    if(k==tam){                                      //Se o numero de letras encontradas conferir com o tamanho da palavra eh porque ela foi encontrada
      printf("Encontrou a palavra %s na diagonal esquerda reversa\n", palavra);
      printf("Inicio: [%d][%d]\n", i, j);            //Inicio sera a posicao da primeira letra da palavra
      printf("Final: [%d][%d]\n", i-k+1, j-k+1);     //Final sera a posicao da primeira letra encontrada menos a quantia de incremento efetuada de linhas e menos o incremento de colunas
      liberar_espaco(m,matriz);                      //Envia para a funcao que libera o espaco alocado e finaliza o programa
    }
  }
}
void diagonal_direita_reversa(int i, int j, char *palavra, char **matriz, int tam, int m, int n){
  int k=0;                                           //Variavel auxiliar, sera usada para efetuar o incremento
  //Aqui a cada laco sera implementado -1 na linha e +1 coluna, assim a matriz sera conferiada diagonalmente de baixo para cima e da esquerda para direita
  //A proxima conferencia nao pode ultrapassar o limite superior e lateral da matriz
  while(((i-k>=0))&&((j+k<n))&&(matriz[i-k][j+k]==palavra[k])){
    k++;                                             //Incrementa a variavel k para que a proxima letra possa ser conferida
    if(k==tam){                                      //Se o numero de letras encontradas conferir com o tamanho da palavra eh porque ela foi encontrada
      printf("Encontrou a palavra %s na diagonal direita reversa\n", palavra);
      printf("Inicio: [%d][%d]\n", i, j);            //Inicio sera a posicao da primeira letra da palavra
      printf("Final: [%d][%d]\n", i-k+1, j+k-1);     //Final sera a posicao da primeira letra encontrada menos a quantia de incremento efetuada de linhas e mais o incremento de colunas
      liberar_espaco(m,matriz);                      //Envia para a funcao que libera o espaco alocado e finaliza o programa
    }
  }
}
void vertical_reversa(int i, int j, char *palavra, char **matriz, int tam, int m, int n){
  int k=0;                                           //Variavel auxiliar, sera usada para efetuar o incremento
  //Aqui a cada laco sera implementado -1 na coluna, assim a matriz sera conferiada verticalmente de baixo para cima. A proxima conferencia nao pode ultrapassar o limite superior da matriz
  while((i-k>-1)&&(matriz[i-k][j]==palavra[k])&&(k<=tam)){
    k++;                                             //Incrementa a variavel k para que a proxima letra possa ser conferida
    if(k==tam){                                      //Se o numero de letras encontradas conferir com o tamanho da palavra eh porque ela foi encontrada
      printf("Encontrou a palavra %s na vertical reversa\n", palavra);
      printf("Inicio: [%d][%d]\n", i, j);            //Inicio sera a posicao da primeira letra da palavra
      printf("Final: [%d][%d]\n", i-k+1, j);         //Final sera a posicao da primeira letra encontrada menos a quantia de incremento efetuada de linhas
      liberar_espaco(m,matriz);                      //Envia para a funcao que libera o espaco alocado e finaliza o programa
    }
  }
}
void vertical(int i, int j, char *palavra, char **matriz, int tam, int m, int n){
  int k=0;                                           //Variavel auxiliar, sera usada para efetuar o incremento
  //Aqui a cada laco sera implementado +1 na coluna, assim a matriz sera conferiada verticalmente de cima para baixo. A proxima conferencia nao pode ultrapassar o limite inferior da matriz
  while(((i+k)<m)&&(matriz[i+k][j]==palavra[k])&&(k<=tam)){
    k++;                                             //Incrementa a variavel k para que a proxima letra possa ser conferida
    if(k==tam){                                      //Se o numero de letras encontradas conferir com o tamanho da palavra eh porque ela foi encontrada
      printf("Encontrou a palavra %s na vertical\n", palavra);
      printf("Inicio: [%d][%d]\n", i, j);            //Inicio sera a posicao da primeira letra da palavra
      printf("Final: [%d][%d]\n", i+k-1, j);         //Final sera a posicao da primeira letra encontrada mais a quantia de incremento efetuada de linhas
      printf("\n");
      liberar_espaco(m,matriz);                      //Envia para a funcao que libera o espaco alocado e finaliza o programa
    }
  }
}
void horizontal_reversa(int i, int j, char *palavra, char **matriz, int tam, int m, int n){
  int k=0;                                           //Variavel auxiliar, sera usada para efetuar o incremento
  //Aqui a cada laco sera implementado -1 na linha, assim a matriz sera conferiada horizontalmente da direita para esquerda. A proxima conferencia nao pode ultrapassar o limite lateral da matriz
  while(((j-k)>=0)&&(matriz[i][j-k]==palavra[k])){
    if(k==tam-1){                                    //Se o numero de letras encontradas conferir com o tamanho da palavra eh porque ela foi encontrada
      printf("Encontrou a palavra %s na horizontal reversa\n", palavra);
      printf("Inicio: [%d][%d]\n", i, j);            //Inicio sera a posicao da primeira letra da palavra
      printf("Final: [%d][%d]\n", i, j-k);           //Final sera a posicao da primeira letra encontrada menos a quantia de incremento efetuada de colunas
      liberar_espaco(m,matriz);                      //Envia para a funcao que libera o espaco alocado e finaliza o programa
    }
    k++;                                             //Incrementa a variavel k para que a proxima letra possa ser conferida
  }
}
void horizontal(int i, int j, char *palavra, char **matriz, int tam, int m, int n){
  int k=0;                                           //Variavel auxiliar, sera usada para efetuar o incremento
  //Aqui a cada laco sera implementado +1 na linha, assim a matriz sera conferiada horizontalmente da esquerda para a direita. A proxima conferencia nao pode ultrapassar o limite lateral da matriz
  while(((j+k)<n)&&(matriz[i][j+k]==palavra[k])){
    if(k==tam-1){                                    //Se o numero de letras encontradas conferir com o tamanho da palavra eh porque ela foi encontrada
      printf("Encontrou a palavra %s na horizontal\n", palavra);
      printf("Inicio: [%d][%d]\n", i, j);            //Inicio sera a posicao da primeira letra da palavra
      printf("Final: [%d][%d]\n", i, j+k);           //Final sera a posicao da primeira letra mais a quantia de incremento efetuada de colunas
      liberar_espaco(m,matriz);                      //Envia para a funcao que libera o espaco alocado e finaliza o programa
    }
    k++;                                             //Incrementa a variavel k para que a proxima letra possa ser conferida
  }
}
char **gerar_matriz (int m, int n)                   //Linha= m, Coluna= n
{
  char **matriz;                                     //Ponteiro para a matriz
  int i, j;                                          //Variaveis auxiliares
  matriz= (char**)calloc(m,sizeof(char*));           //Aloca as linhas da matriz
  for (i=0;i<m;i++){                                 //Aloca as colunas da matriz
    matriz[i]= (char*)calloc(n,sizeof(char));        //
  }
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      matriz[i][j]= (65+(rand()%26));                //Matriz recebe letras aleatorias baseando-se na tabela ascii
    }
  }
  return (matriz);                                   //Retorna a matriz para a main
}
void print_matriz(int m, int n, char **matriz){      //Funcao que printa a matriz na tela para o usuario
  int i, j;                                          //Variaveis auxiliares
  printf("\n");
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
    printf ("%c ", matriz[i][j]);                    //Varre a matriz printando posicao por posicao
    }
    printf("\n");                                    //Quebra linha
  }
}
void busca_matriz(int m, int n, char *palavra, char **matriz, int tam){
  int i, j;                                          //Variaveis auxiliares
  for(i=0;i<m;i++){                                  //Laco for para as linhas
    for(j=0;j<n;j++){                                //Laco for para as colunas
      if(matriz[i][j]==palavra[0]){                  //Se a posicao x da matriz for igual a primeira letra da palavra, faz-se as conferencias
          horizontal(i,j,palavra,matriz,tam,m,n);                   //Aqui a posicao da matriz sera enviada para funcoes que irao conferir se a palavra existe
          horizontal_reversa(i,j,palavra,matriz,tam,m,n);           //
          vertical(i,j,palavra,matriz,tam,m,n);                     //
          vertical_reversa(i,j,palavra,matriz,tam,m,n);             //
          diagonal_esquerda(i,j,palavra,matriz,tam,m,n);            //
          diagonal_esquerda_reversa(i,j,palavra,matriz,tam,m,n);    //
          diagonal_direita(i,j,palavra,matriz,tam,m,n);             //
          diagonal_direita_reversa(i,j,palavra,matriz,tam,m,n);     //
      }
    }
  }
}
int confere_maior(int m, int n){             //Funcao que ira conferir qual o maior, colunas ou linhas. (Servira para alocar a palavra do usuario)
  if(m>n){                                   //Se linhas for maior que colunas
    return m;                                //Retorna o valor de linhas
  } else {
    return n;                                //Senao retorne o valor de colunas
  }
}
int main(){
  srand(time(NULL));                         //Usado para auxiliar a funcao rand
  int m, n, tam, maior;
  char **matriz;                             //Declaracao da matriz ponteiro para ponteiro
  printf("Defina o numero de linhas: ");
  scanf("%d", &m);                           //A variavel m sera o numero de linhas da matriz
  printf("Defina o numero de colunas: ");
  scanf("%d", &n);                           //A variavel n sera o numero de colunas da matriz
  maior= confere_maior(m,n);                 //Confere qual das variaveis eh maior entre m ou n, sera usada para alocar o vetor da palavra
  char palavra[maior];                       //Vetor que ira armazenar a palavra inserida
  matriz= gerar_matriz (m,n);                //Envia para a funcao que gera a matriz
  print_matriz(m,n,matriz);                  //Envia para a funcao que printa a matriz na tela
  tam= solicitar_palavra(palavra,tam);       //Manda para a funcao que ira solicitar a palavra do usuario e recebe o tamanho da palavra
  if(tam==1){                                //Se o usuario inseriu apenas uma letra
    uma_letra(m,n,palavra,matriz);           //Vai para a funcao que confere onde esta a letra
  }
  busca_matriz(m,n,palavra,matriz,tam);      //Vai para a funcao que buscara a palavra na matriz
  printf("Palavra nao encontrada.\n");       //Caso o programa ainda nao tenha sido encerrado, a palavra nao foi encontrada
  liberar_espaco(m,matriz);                  //Vai para a funcao que libera o espaco alocado e finaliza o programa
}
