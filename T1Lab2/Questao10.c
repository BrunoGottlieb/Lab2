#include<stdio.h>
#include<string.h>
void roda_string (char* str){
  int tam, i;
  char aux;
  tam= strlen(str);        //tam recebe o tamanho da string
  aux= str[tam-1];         //aux recebe a ultima letra da string
  for(i=tam-1;i>0;i--){
    str[i]= str[i-1];      //Cada letra da string eh passada para uma posicao a esquerda
  }
  str[0]=aux;              //A primeira letra da string torna-se a ultima da palavra original
  printf("\n\nString deslocada: ");
  printf("%s", str);       //Printa a nova string
  puts("\n");
}
void main(){
  char string[100];        //Vetor no qual ira alocar a string
  printf("Insira uma string: ");
  scanf("%s", &string);    //Recebe a string do usuario
  roda_string(string);     //Envia para a  funcao que realizara o deslocamento
}
