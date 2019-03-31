#include<stdio.h>
#include<math.h>
double avalia (double* poli, int grau, double x){
    int i;
    double aux[grau+1], resultado=0;
    aux[0]=1;
    for(i=1;i<grau+1;i++){
      aux[i]=pow(x,i);               //aux recebe a potencia de x elevado no valor atual i
    }
    for(i=0;i<grau+1;i++){
      resultado+= (poli[i]*aux[i]);  //Resultado soma-se com o valor do polinomio multiplicado pelo aux obtido
    }
    return resultado;
}

int main(){
    int grau, i, tam;
    printf("Defina o maior grau do vetor: ");
    scanf("%d", &grau);
    tam= grau+1;                     //tam eh grau+1 pois um dos valores do polinomio nao possui x
    double vet[tam], x;
    for(i=0;i<tam;i++){
        if(i==0){
        printf("\nInsira o %do valor (aquele que nao tem x): ", i+1);
      } else {
        printf("\nInsira o %do valor (aquele cujo x eh elevado na %d): ", i+1, i);
      }
        scanf("%lf", &vet[i]);
    }
    printf("\nInsira o valor de X: ");
    scanf("%lf", &x);
    printf("\nResultado: %lf", avalia(vet,grau,x));
    printf("\n");
    return 0;
}
