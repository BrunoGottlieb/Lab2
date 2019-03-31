#include<stdio.h>
 int negativos (int n, float* vet){
     int i, cont=0;    //Variaveis auxiliares
     for(i=0;i<n;i++){ //Verifica cada numero do vetor, se sao menores do que zero
        if(vet[i]<0){
            cont++;    //Cont vai acumulando o total de numeros menores do que zero
        }
     }
     return cont;      //Retorna a quantia de numeros que foram menos do que zero
 }

int main(){
    int n, i;
    printf("Neste programa voce insere uma quantia x de numeros e eu lhe direi quantos desses sao negativos.\n");
    printf("Defina a quantia de numeros a serem testados: ");
    scanf("%d", &n);   //Aqui o usuario define a quantia de numeros que ele deseja inserir
    float vet[n];
    for(i=0;i<n;i++){
        printf("Insira o valor %d: ", i+1);
        scanf("%f", &vet[i]);
    }
    printf("Quantia de numeros negativos: %d\n", negativos(n, vet));
}
