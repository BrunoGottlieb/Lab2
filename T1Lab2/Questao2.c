#include<stdio.h>
int primo(int n){
  int i, cont=0, aux=0;                    //Variaveis auxiliares
    for(i=1;i<=n;i++){
        cont= n % i;                       //Cont recebe o resto da divisao de n por todos os numeros anteriores a ele
        if (cont==0){                      //Caso cont tenha sido 0, ele soma 1 ao aux
            aux+=1;
        }
    }
      if (aux==2){                         //Caso aux seja 2, significa que cont recebeu resto 0 apenas para 1 e para o proprio n
        return 1;                          //Assim retornando valor 1 pois o numero eh primo
      } else {
        return 0;                          //Caso contrario, o numero nao eh primo
      }
}
int main(){
  int n, resp;
  printf("Insira o valor de n: ");
  scanf("%d", &n);                          //Recebe o numero do usuario
  printf("\n");
  resp= primo(n);                           //Resp recebe 1 ou 0
  if(resp==1){                              //Opcionalmente, o programa pode imprimir a resposta na tela, baseando-se no valor recebido do return
    printf("O numero %d eh primo", n);
  } else {
    printf("O numero %d nao eh primo", n);
  }
  printf("\n");
}
