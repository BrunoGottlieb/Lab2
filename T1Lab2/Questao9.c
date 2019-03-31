#include<stdio.h>
//#include<ctype.h>        //Poderia ser usada esta biblioteca
#include<string.h>         //Biblioteca usada para receber o tamanho da string
void minusculo(char* str){
  //str=strlwr(str);       //Poderia ser convertido com essa funcao
  int tam, i;
  tam= strlen(str);        //tam recebe o numero de letras da string
  for(i=0;i<tam;i++){
    str[i]+= 32;           //Recebe o valor de sua propria letra somado com 32
  }                        //Essa soma resultara na mesma letra, mas minuscula, de acordo com a tabela asccii
  printf("\n");
}
int main(){
  char letra, str[100];
  printf("Insira uma string em letras MAIUSCULAS: ");
  scanf("%s", &str);
  minusculo(str);          //Funcao que ira transformar para minusculo
  printf("String agora em minusculo: ");
  printf("%s", str);
  printf("\n");
  return 0;
}
