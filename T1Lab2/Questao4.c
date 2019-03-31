#include<stdio.h>
int soma_impares(int n){
    int i, soma=0;
    for(i=1;i<=n;i++){ //Comeca em 1 e vai somando todos os numeros impares ate o numero n
        soma+= i;      //Soma vai acumulando todos os numeros impares somados entre si
        i++;           //Incrementa i novamente para ser apenas os i impares
    }
    return soma;       //Retorna o resultado da soma
}
int main(){
    int n;
    printf("Defina o valor de n: ");
    scanf("%d", &n);   //Usuario entra com o valor desejado
    printf("Resultado da soma: %d", soma_impares (n));
}
