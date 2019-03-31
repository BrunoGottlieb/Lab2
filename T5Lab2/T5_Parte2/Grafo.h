struct estrutura{
	int eh_ponderado;
	int nro_vertices;
	int grau_max;
	int** arestas;
	float** pesos;
	int* grau;
}; typedef struct estrutura Grafo;

typedef struct {
    unsigned int primeiro;
    unsigned int ultimo;
    int peso;
} grafo;

Grafo *cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado);
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);
void libera_Grafo(Grafo* gr);
void menorCaminho_Grafo(Grafo*gr, int ini, int *ant, float *dist);
int procuraMenorDistancia(float *dist, int *visitado, int NV);
void Inserir_Minhas_Arestas(Grafo* gr);


int *bellman_ford(const grafo *aresta, unsigned int tam, unsigned int order, unsigned int vertice);
void Inserir_Aresta(grafo *aresta, unsigned int primeiro, unsigned int ultimo, int peso, unsigned int *pos);

