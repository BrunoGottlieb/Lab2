#include<stdio.h>
#include "Grafo.h"

void main(){
	int escolha;
	printf("Cada algoritmo ja possui um grafo de exemplo pre-inserido\n");
	printf("Mas pode ser alterado no codigo pelo usuario.\n");
	printf("[Maiores detalhes no relatorio]\n");
	printf("\nEscolha o algoritmo desejado:\n\n");
	printf("[1] Dijkstra\n[2] Bellman Ford\n[3] Sair\n");
	scanf("%d", &escolha);
	switch (escolha){
		case 1:
			Dijkstra();
		    break;
	    case 2:
	    	Bellman_Ford();
	    	break;
	    case 3:
	    	exit(0);
	    	break;
	    default:
	    	printf("Escolha invalida.");
	    	break;
	}
}

void Dijkstra(){
	int nro_vertices = 11;
	int grau_max = 11;
	int eh_digrafo = 1;
	int ant[11];
	float dist[11];
	int inicio = 0, i;
	puts("");
	Grafo *gr;
	gr = cria_Grafo(nro_vertices, grau_max, 1);
	Inserir_Minhas_Arestas(gr);
	menorCaminho_Grafo(gr, inicio, ant, dist);
	for (i = 0; i < 11; i++){
		printf("Distancia da origem %d ate o vertice %d: %.1f\n", inicio, i, dist[i]);
	}
	puts("");
	libera_Grafo(gr);
	return;
}

void Bellman_Ford(){
    unsigned int tam = 21; // numero de arestas
    unsigned int order = 13; // numero de vertices
    unsigned int i = 0;
    int *dist;
    puts("");
    grafo *aresta = malloc(tam * sizeof(grafo));
	Inserir_Arestas_Grafo(aresta, &i);
    dist = bellman_ford(aresta, tam, order, 0);
    if (dist == NULL) {
        printf("Grafo contem um ciclo negativo ou ficou sem memoria.\n");
        return 1;
    }
    for (i = 0; i < order; i++) {
        printf("Distancia da origem ate o vertice %u: %d\n", i, dist[i]);
    }
    free(aresta);
    free(dist);
    return;
}
