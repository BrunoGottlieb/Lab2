#include<stdio.h>
#include<stdlib.h>
#include "Grafo.h"

void Inserir_Minhas_Arestas(Grafo* gr) {
	insereAresta(gr, 0, 1, 0, 1);
	insereAresta(gr, 1, 3, 0, 2);
	insereAresta(gr, 3, 7, 0, 3);
	insereAresta(gr, 3, 2, 0, 4);
	insereAresta(gr, 4, 1, 0, 5);
	insereAresta(gr, 4, 5, 0, 4);
	insereAresta(gr, 3, 0, 0, 3);
	insereAresta(gr, 6, 2, 0, 2);
	insereAresta(gr, 1, 7, 0, 1);
	insereAresta(gr, 5, 2, 0, 1);
	insereAresta(gr, 2, 1, 0, 1);
	insereAresta(gr, 1, 5, 0, 2);
	insereAresta(gr, 7, 4, 0, 3);
	insereAresta(gr, 6, 5, 0, 4);
	insereAresta(gr, 7, 2, 0, 5);
	insereAresta(gr, 6, 4, 0, 4);
	insereAresta(gr, 6, 8, 0, 3);
	insereAresta(gr, 2, 8, 0, 2);
	insereAresta(gr, 3, 8, 0, 1);
	insereAresta(gr, 8, 5, 0, 1);
	insereAresta(gr, 9, 4, 0, 2);
	insereAresta(gr, 9, 7, 0, 3);
	insereAresta(gr, 10, 5, 0, 2);
	insereAresta(gr, 10, 9, 0, 2);
}

Grafo *cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado) {
	Grafo *gr = (Grafo*)malloc(sizeof(struct estrutura));
	if (gr != NULL) {
		int i;
		gr->nro_vertices = nro_vertices;
		gr->grau_max = grau_max;
		gr->eh_ponderado = (eh_ponderado != 0) ? 1 : 0;
		gr->grau = (int*)calloc(nro_vertices, sizeof(int));
		gr->arestas = (int**)malloc(nro_vertices * sizeof(int*));
		for (i = 0; i < nro_vertices; i++)
			gr->arestas[i] = (int*)malloc(grau_max * sizeof(int));
		if (gr->eh_ponderado){
			gr->pesos = (float**)malloc(nro_vertices * sizeof(float*));
			for (i = 0; i < nro_vertices; i++)
				gr->pesos[i] = (float*)malloc(grau_max * sizeof(float));
		}
	}
	return gr;
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso) {
	if (gr == NULL)
		return 0;
	if (orig < 0 || orig >= gr->nro_vertices)
		return 0;
	if (dest < 0 || dest >= gr->nro_vertices)
		return 0;
	gr->arestas[orig][gr->grau[orig]] = dest;
	if (gr->eh_ponderado)
		gr->pesos[orig][gr->grau[orig]] = peso;
	gr->grau[orig]++;
	if (eh_digrafo == 0)
		insereAresta(gr, dest, orig, 1, peso);
	return 1;
}

void menorCaminho_Grafo(Grafo*gr, int ini, int *ant, float *dist) {
	int i, cont, NV, ind, *visitado, u;
	cont = NV = gr->nro_vertices;
	visitado = (int*)malloc(NV * sizeof(int));
	for (i = 0; i < NV; i++) {
		ant[i] = -1;
		dist[i] = -1;
		visitado[i] = 0;
	}
	dist[ini] = 0;
	while (cont > 0) {
		u = procuraMenorDistancia(dist, visitado, NV);
		if (u == -1)
			break;
		visitado[u] = 1;
		cont--;
		for (i = 0; i < gr->grau[u]; i++) {
			ind = gr->arestas[u][i];
			if (dist[ind] < 0) {
				//dist[ind] = dist[u] + 1;
				dist[ind] = dist[u] + gr->pesos[u][i];
				ant[ind] = u;
			}
			else {
				//if (dist[ind] > dist[u] + 1) {
					if (dist[ind] > dist[u] + 1) {
						//dist[ind] = dist[u] + 1;
						dist[ind] = dist[u] + gr->pesos[u][i];
						ant[ind] = u;
					}
				//}
			}
		}
	}
	free(visitado);
}

int procuraMenorDistancia(float *dist, int *visitado, int NV) {
	int i, menor = -1, primeiro = 1;
	for (i = 0; i < NV; i++) {
		if (dist[i] >= 0 && visitado[i] == 0) {
			if (primeiro) {
				menor = i;
				primeiro = 0;
			}
			else {
				if (dist[menor] > dist[i])
					menor - i;
			}
		}
	}
	return menor;
}

void libera_Grafo(Grafo* gr) {
	if (gr != NULL) {
		int i;
		for (i = 0; i < gr->nro_vertices; i++)
			free(gr->arestas[i]);
		free(gr->arestas);
		if (gr->eh_ponderado) {
			for (i = 0; i < gr->nro_vertices; i++)
				free(gr->pesos[i]);
			free(gr->pesos);
		}
		free(gr->grau);
		free(gr);
	}
}


