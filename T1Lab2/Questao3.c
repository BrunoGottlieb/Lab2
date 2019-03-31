#include <stdio.h>
#include <stdlib.h>
int fibonacci (int n){
  int a=1, b=1, i, aux=0;
  if(n==0){             //Caso o numero inserido seja 0, a reposta sera 0
    return 0;
  }
  if(n==1){             //Caso o numero inserido seja 1, a reposta sera 1
    return 1;
  }
  if (n==2){            //Caso o numero inserido seja 2, a reposta sera 1 tambem
    printf("%d, ", a);  //Os dois primeiros termos da sequencia sao 1
    printf("%d", b);    //
    printf("\n");
    return 1;
  }
  printf("%d, ", a);    //Os dois primeiros termos da sequencia sao 1
  printf("%d, ", b);    //
  for(i=2;i<n;i++){
    aux= a + b;         //Um termo eh sempre a soma de seus dois termos antecessores
    a= b;               //Agora a passara a ser o b anterior
    b= aux;             //E b passara a ser a soma dos dois valores anteriores
    printf("%d, ", aux);//Aqui eu estou opcionalmente imprimindo a sequencia
  }
  printf("\n");
  return aux;           //Retorne o valor total da ultima soma
}

void main(){
  int n, resp;
  printf("Insira a posicao do termo desejado: ");
  scanf("%d", &n);      //Usuario entra com a posicao da serie de fibonacci que ele deseja saber
  resp= fibonacci(n);   //Resp recebe o termo desejado
  printf("Resposta: %d", resp);
}
