#include<stdio.h>
#include<string.h>
int conta_vogais (char*str){     //Funcao que ira contar o numero de vogais na string
  int tam, vogal=0, i;
  tam = strlen(str);             //tam recebe o numero de letras da string
  for(i=0;i<tam;i++){            //Aqui sera varrido toda a string e a cada letra que for igual a uma vogal, a variavel vogal ira receber +1
    if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
      vogal++;
    }
  }
  return vogal;                   //Retorna o numero de vogais obtido
}
int main(){
  char vet[100];                  //Vetor que ira alocar a string
  printf("Insira uma string: ");
  scanf("%s", &vet);              //Recebe a string do usuario
  printf("Numero de vogais: %d", conta_vogais(vet));
  printf("\n");
}
