#include<stdio.h>
void inverte (int n, int* vet){
    int i, meio,aux;
    meio= n/2;
    printf("\n");
    for(i=0;i<meio;i++){    //Laco eh executado ate a metade do vetor, para nao ordenar novamente
        aux= vet[i];        //aux recebe o numero em questao temporariamente
        vet[i]= vet[n-i-1]; //Comeca recebendo desde o ultimo valor
        vet[n-i-1]= aux;    //Os ultimos valores vao recebendo os primeiros
    }
    for(i=0;i<n;i++){       //Printa o vetor agora invertido
        printf("%d\n", vet[i]);
        }
}
int main(){
int n, i;
    puts("Esse programa inverte a ordem dos valores inseridos");
    printf("Defina o tamanho do vetor: ");
    scanf("%d", &n);
    int vet[n];
    for(i=0;i<n;i++){
        printf("Insira o valor %d: ", i+1);
        scanf("%d", &vet[i]);
    }
    inverte(n,vet);
}
