#include<stdio.h>
void retangulo(int *x0, int *x1, int *y0, int *y1){ //Essa funcao fara o retangulo | recebe as variaveis em ponteiro
  printf("Defina x0: ");
  scanf("%d", x0);                                  //Altera diretamente na variavel, sem necessidade de return
  printf("Defina x1: ");
  scanf("%d", x1);
  printf("Defina y0: ");
  scanf("%d", y0);
  printf("Defina y1: ");
  scanf("%d", y1);
  printf("\n");
}
int dentro_ret(int x0, int y0, int x1, int y1, int x, int y){
  printf("\n");
  if(x>=x0 && x<=x1 && y>=y0 && y<=y1){             //Confere se x e y estao dentro dos limites do retangulo
      printf("Esta dentro do retangulo.");
  } else {
      printf("Nao esta dentro do retangulo.");
    }
  printf("\n");
}

int main(){
    int x0, x1, y0, y1, x, y;
    retangulo(&x0,&x1,&y0,&y1);                     //Envia os enderecos das variaveis para a funcao
    printf("Insira o valor de x: ");
    scanf("%d", &x);
    printf("Insira o valor de y: ");
    scanf("%d", &y);
    dentro_ret(x0,y0,x1,y1,x,y);                   //Manda para a funcao que confere se esta dentro dos limites
}
