#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Grafo.h"

void Inserir_Arestas_Grafo(grafo *aresta, int *i){
	Inserir_Aresta(aresta, 0, 1, 3, i);
	Inserir_Aresta(aresta, 0, 2, 2, i);
	Inserir_Aresta(aresta, 0, 3, 3, i);
	Inserir_Aresta(aresta, 1, 2, 1, i);
	Inserir_Aresta(aresta, 2, 3, -1, i);
	Inserir_Aresta(aresta, 1, 6, -2, i);
    Inserir_Aresta(aresta, 2, 5, 4, i);
    Inserir_Aresta(aresta, 3, 4, 2, i);
    Inserir_Aresta(aresta, 4, 5, 2, i);
	Inserir_Aresta(aresta, 5, 6, -1, i);
	Inserir_Aresta(aresta, 6, 7, 2, i);
	Inserir_Aresta(aresta, 6, 8, 4, i);
	Inserir_Aresta(aresta, 7, 8, -3, i);
	Inserir_Aresta(aresta, 8, 9, 2, i);
	Inserir_Aresta(aresta, 9, 10, -2, i);
	Inserir_Aresta(aresta, 9, 12, 4, i);
	Inserir_Aresta(aresta, 10, 11, 1, i);
	Inserir_Aresta(aresta, 4, 11, -4, i);
	Inserir_Aresta(aresta, 4, 10, 1, i);
	Inserir_Aresta(aresta, 8, 12, -1, i);
	Inserir_Aresta(aresta, 10, 12, 2, i);
}

int *bellman_ford(const grafo *aresta, unsigned int tam, unsigned int order, unsigned int vertice)
{
    unsigned int i;
    int *dist = malloc(order * sizeof(unsigned int));
    unsigned int a, v, ciclo_negativo = 0;
    if (dist == NULL) {
        return NULL;
    }
    // Todas as distancias iniciam infinitas
    for (i = 0; i < order; i++) {
        dist[i] = INT_MAX;
    }
    // Distancia para iniciar um vertice eh zero
    dist[vertice] = 0;
    // Relaxamento
    for (v = 0; v < order; v++) {
        for (a = 0; a < tam; a++) {
            const unsigned int primeiro = aresta[a].primeiro;
            const unsigned int ultimo = aresta[a].ultimo;
            const int peso = aresta[a].peso;
            if (dist[primeiro] != INT_MAX && dist[primeiro] + peso < dist[ultimo])
                dist[ultimo] = dist[primeiro] + peso;
        }
    }
    // Checa por pesos negativos
    for (a = 0; a < tam && !ciclo_negativo; a++) {
        const unsigned int primeiro = aresta[a].primeiro;
        const unsigned int ultimo = aresta[a].ultimo;
        const int peso = aresta[a].peso;
        ciclo_negativo = dist[primeiro] + peso < dist[ultimo];
    }
    if (ciclo_negativo) {
        free(dist);
        dist = NULL;
    }

    return dist;
}

//Conecta duas arestas
void Inserir_Aresta(grafo *aresta, unsigned int primeiro, unsigned int ultimo, int peso, unsigned int *pos)
{
    aresta[*pos].primeiro = primeiro;
    aresta[*pos].ultimo = ultimo;
    aresta[*pos].peso = peso;
    (*pos)++;
}

