#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "funcoes.h"


//##############################ALUNOS#########################################

void criar_lista(Alunos** l) {
	*l= NULL;
}

void inserir_lista(Alunos** l, int matricula, char* nome, long telefone) {
	Alunos* novo = (Alunos*)malloc(sizeof(Alunos));
	novo->matricula = matricula;
	novo->nome = nome;
	novo->telefone = telefone;
	novo->prox = *l;
	*l= novo;
}

Alunos* existeAluno(int aluno, Alunos** l) {
	Alunos* Inicio = *l;
	while (Inicio != NULL) {
		if (Inicio->matricula == aluno) {
			return Inicio;
		}
		Inicio = Inicio->prox;
	}
	return NULL;
}

void imprimir_lista(Alunos* l) {
	Alunos* p;
	int aux = 0;
	for (p = l; p != NULL; p = p->prox) {
		aux++;
		printf("Nome = %s\n", p->nome);
		printf("Matricula = %d\n", p->matricula);
		printf("Telefone = %li\n\n", p->telefone);
	}
	if (aux == 0)
		puts("Nao existem alunos\n");
}

Alunos* busca_lista(Alunos** l, int v) {
	Alunos* p;
	for (p = *l; p != NULL; p = p->prox) {
		if (p->matricula == v) {
			return p;
		}
	}return NULL; /* não achou o elemento */
}

/* função retira: retira elemento da lista */
void retirar_lista(Alunos** l, int v) {
	Alunos* ant = NULL; /* ponteiro para elemento anterior */
	Alunos* p = *l; /* ponteiro para percorrer a lista */
	/* procura elemento na lista, guardando anterior */
	while (p != NULL && p->matricula != v) {
		ant = p;
		p = p->prox;
	}
	/* verifica se achou elemento */
	if (p == NULL)
		return; /* não achou: retorna lista original */
		/* retira elemento */
	if (ant == NULL) { /* retira elemento do inicio */
		*l = p->prox;
	}
	else { /* retira elemento do meio da lista */
		ant->prox = p->prox;
	}
	free(p);
	return;
}

int lista_vazia(Alunos** l) {
	return (l == NULL);
}

void liberar_lista(Alunos** l) {
	Alunos* p = *l;
	while (p != NULL) {
		Alunos* t = p->prox; /* guarda referência p/ próx. elemento */
		free(p); /* libera a memória apontada por p */
		p = t; /* faz p apontar para o próximo */
	}
	puts("\nLista completamente liberada");
}

//##############################TURMAS##########################################

void criar_lista_Turmas(Turmas** t) {
	*t= NULL;
}

void inserir_lista_turmas(Turmas** t, int codigo, Disciplinas** endDisciplina, int qtd_vagas, char* dia, char* horario, int sala) {
	Turmas* novo = (Turmas*)malloc(sizeof(Turmas));

	novo->codigo = codigo;
	novo->disciplinas = *endDisciplina;
	novo->qtd_vagas = qtd_vagas;
	novo->qtd_vagas_ocupadas = 0;
	novo->dia = dia;
	novo->horario = horario;
	novo->sala = sala;
	novo->prox = *t;
	*t= novo;
}

void lst_insere_ordenado(Turmas** t, int codigo, Disciplinas** endDisciplina, int qtd_vagas, char* dia, char* horario, int sala) {
	Turmas* novo;
	Turmas* ant = NULL; /* ponteiro para elemento anterior */
	Turmas* p = *t; /* ponteiro para percorrer a lista */
	/* procura posição de inserção */
	while (p != NULL && p->codigo < codigo)
	{
		ant = p; p = p->prox;
	}
	/* cria novo elemento */
	novo = (Turmas*)malloc(sizeof(Turmas));
	novo->codigo = codigo;
	novo->disciplinas = *endDisciplina;
	novo->qtd_vagas = qtd_vagas;
	novo->qtd_vagas_ocupadas = 0;
	novo->dia = dia;
	novo->horario = horario;
	novo->sala = sala;
	/* encadeia elemento */
	if (ant == NULL)
	{ /* insere elemento no início */
		novo->prox = *t; 
		*t = novo;
		return;
	}
	else { /* insere elemento no meio da lista */
		novo->prox = ant->prox;
		ant->prox = novo;
		*t = novo;
	}
}

Turmas* existeTurma(int turma, Turmas** t) {
	Turmas* Iniciot = *t;
	while (Iniciot != NULL) {
		if (Iniciot->codigo == turma) {
			return Iniciot;
		}
		Iniciot = Iniciot->prox;
	}
	return NULL;
}

void imprimir_lista_turmas(Turmas* t) {
	Turmas* p;
	int aux = 0;
	for (p = t; p != NULL; p = p->prox) {
		aux++;
		printf("Codigo = %d\n", p->codigo);
		printf("Disciplina = %d\n", p->disciplinas->codigo);
		printf("Quantidade de vagas ofertadas = %d\n", p->qtd_vagas);
		printf("Quantidade de vagas ocupadas = %d\n", p->qtd_vagas_ocupadas);
		printf("Dia = %s\n", p->dia);
		printf("Horario = %s\n", p->horario);
		printf("Sala = %d\n\n", p->sala);
	}
	if (aux == 0)
		puts("Nao existem turmas\n");
}

Turmas* busca_lista_turmas(Turmas** t, int v) {
	Turmas* p;
	for (p = *t; p != NULL; p = p->prox) {
		if (p->codigo == v) {
			return p;
		}
	}return NULL; /* não achou o elemento */
}

int busca_disciplina_em_turmas(Turmas** t, int alvo) {
	Turmas* p;
	for (p = *t; p != NULL; p = p->prox) {
		if (p->disciplinas->codigo == alvo) {
			return p->codigo;
		}
	}return NULL; /* não achou o elemento */
}

void retirar_lista_turmas(Turmas** t, int v) {
	Turmas* ant = NULL; /* ponteiro para elemento anterior */
	Turmas* p = *t; /* ponteiro para percorrer a lista */
	/* procura elemento na lista, guardando anterior */
	while (p != NULL && p->codigo != v) {
		ant = p;
		p = p->prox;
	}
	/* verifica se achou elemento */
	if (p == NULL)
		return; /* não achou: retorna lista original */
		/* retira elemento */
	if (ant == NULL) { /* retira elemento do inicio */
		*t = p->prox;
	}
	else { /* retira elemento do meio da lista */
		ant->prox = p->prox;
	}
	free(p);
	return;
}

int retirar_lista_turmas_update(Turmas** t, int v, int cont) {
	Turmas* ant = NULL; /* ponteiro para elemento anterior */
	Turmas* p = *t; /* ponteiro para percorrer a lista */
	/* procura elemento na lista, guardando anterior */
	while (p != NULL && p->codigo != v) {
		ant = p;
		p = p->prox;
	}
	/* verifica se achou elemento */
	if (p == NULL)
		return NULL; /* não achou: retorna lista original */
		/* retira elemento */
	if (ant == NULL) { /* retira elemento do inicio */
		*t = p->prox;
		cont++;
	}
	else { /* retira elemento do meio da lista */
		ant->prox = p->prox;
		cont++;
	}
	free(p);
	return (cont);
}

//################################DISCPLINAS##################################

void criar_lista_Disciplinas(Disciplinas** d) {
	*d= NULL;
}

void inserir_lista_Disciplinas(Disciplinas** d, int codigo, char* nomed, int creditos) {
	Disciplinas* novo = (Disciplinas*)malloc(sizeof(Disciplinas));
	novo->codigo = codigo;
	novo->nomed = nomed;
	novo->creditos = creditos;
	novo->prox = *d;
	*d= novo;;
}

Disciplinas* existeDisciplina(int disciplina, Disciplinas** d) {
	Disciplinas* dInicio = *d;
	while (dInicio != NULL) {
		if (dInicio->codigo == disciplina) {
			return dInicio;
		}
		dInicio = dInicio->prox;
	}
	return NULL;
}

void imprimir_lista_Disciplinas(Disciplinas* d) {
	Disciplinas* p;
	int aux = 0;
	for (p = d; p != NULL; p = p->prox) {
		aux++;
		printf("Codigo = %d\n", p->codigo);
		printf("Nome = %s\n", p->nomed);
		printf("creditos = %d\n\n", p->creditos);
	}
	if (aux == 0)
		puts("Nao existem disciplinas\n");
}

Disciplinas* busca_lista_Disciplinas(Disciplinas** d, int v) {
	Disciplinas* p;
	for (p = *d; p != NULL; p = p->prox) {
		if (p->codigo == v) {
			return p;
		}
	}return NULL; /* não achou o elemento */
}

void retirar_lista_Disciplinas(Disciplinas** d, int v) {
	Disciplinas* ant = NULL; /* ponteiro para elemento anterior */
	Disciplinas* p = *d; /* ponteiro para percorrer a lista */
	/* procura elemento na lista, guardando anterior */
	while (p != NULL && p->codigo != v) {
		ant = p;
		p = p->prox;
	}
	/* verifica se achou elemento */
	if (p == NULL)
		return; /* não achou: retorna lista original */
		/* retira elemento */
	if (ant == NULL) { /* retira elemento do inicio */
		*d = p->prox;
	}
	else { /* retira elemento do meio da lista */
		ant->prox = p->prox;
	}
	free(p);
	return;
}

//################################MATRICULAS##################################

void criar_lista_Matriculas(Matriculas** m) {
	*m=  NULL;
}

void inserir_lista_Matriculas(Matriculas** m, int aluno, int turma, char* data, Alunos* enderecoAluno, Turmas* enderecoTurma) {
	Matriculas* novo = (Matriculas*)malloc(sizeof(Matriculas));
	novo->aluno = enderecoAluno;
	novo->turma = enderecoTurma;
	novo->data = data;
	novo->turma->qtd_vagas_ocupadas += 1;
	novo->prox = *m;
	*m= novo;
}

Matriculas* busca_lista_Matriculas(Matriculas** m, int v, int v2) {
	Matriculas* p;
	for (p = *m; p != NULL; p = p->prox) {
		if (p->aluno->matricula == v && p->turma->codigo == v2) {
			return p;
		}
	}return NULL; /* não achou o elemento */
}

void retirar_lista_Matriculas(Matriculas** m, int v, int v2) {
	Matriculas* ant = NULL; /* ponteiro para elemento anterior */
	Matriculas* p = *m; /* ponteiro para percorrer a lista */
	/* procura elemento na lista, guardando anterior */
	while (p != NULL && p->aluno->matricula != v && p->turma->codigo != v2) {
		ant = p;
		p = p->prox;
	}
	/* verifica se achou elemento */
	if (p == NULL)
		return; /* não achou: retorna lista original */
		/* retira elemento */
	if (ant == NULL) { /* retira elemento do inicio */
		*m = p->prox;
	}
	else { /* retira elemento do meio da lista */
		ant->prox = p->prox;
	}
	free(p);
	return;
}

int retirar_lista_matriculas_update(Matriculas** m, int v, int cont, int x) {
	Matriculas* ant = NULL; /* ponteiro para elemento anterior */
	Matriculas* p = *m; /* ponteiro para percorrer a lista */
	/* procura elemento na lista, guardando anterior */
	if (x == 1) {
		while (p != NULL && p->turma->codigo != v) {
			ant = p;
			p = p->prox;
		}
	}
	if (x == 2) {
		while (p != NULL && p->aluno->matricula != v) {
			ant = p;
			p = p->prox;
		}
	}
	/* verifica se achou elemento */
	if (p == NULL)
		return NULL; /* não achou: retorna lista original */
		/* retira elemento */
	if (ant == NULL) { /* retira elemento do inicio */
		*m = p->prox;
		cont++;
	}
	else { /* retira elemento do meio da lista */
		ant->prox = p->prox;
		cont++;
	}
	free(p);
	return (cont);
}

void imprimir_lista_Matriculas(Matriculas* m) {
	Matriculas* p;
	int aux = 0;
	for (p = m; p != NULL; p = p->prox) {
		aux++;
		printf("Aluno = %d | %s\n", p->aluno->matricula, p->aluno->nome);
		printf("Turma = %d\n", p->turma->codigo);
		printf("Data = %s\n\n", p->data);
	}
	if (aux == 0)
		puts("Nao existem matriculas\n");
}

int Confere_Vagas(Turmas* t) {
	if (t->qtd_vagas > t->qtd_vagas_ocupadas) {
		return ((t->qtd_vagas) - (t->qtd_vagas_ocupadas));
	}
	else {
		return 0;
	}
}

int busca_turmas_em_matriculas(Matriculas** m, int alvo) {
	Matriculas* p;
	for (p = *m; p != NULL; p = p->prox) {
		if (p->turma->codigo == alvo) {
			return p->turma->codigo;
		}
	}return NULL; /* não achou o elemento */
}

int busca_alunos_em_matriculas(Matriculas** m, int alvo) {
	Matriculas* p;
	for (p = *m; p != NULL; p = p->prox) {
		if (p->aluno->matricula == alvo) {
			return p->aluno->matricula;
		}
	}return NULL; /* não achou o elemento */
}

//########################################RELATORIOS#######################################################

void Imprimir_Alunos_de_Turma(Matriculas* m, int v) {
	Matriculas* p;
	int cont=0;
	puts("");
	for (p = m; p != NULL; p = p->prox) {
		if (p->turma->codigo == v) {
			printf("Matricula: %d | Nome: %s\n", p->aluno->matricula, p->aluno->nome);
			cont++;
		}
	}
	if (cont == 0)
		puts("Nao ha alunos nesta turma");
	puts("");
}

void Imprimir_Turmas_Lotadas(Turmas* t) {
	Turmas* p;
	int cont = 0;
	for (p = t; p != NULL; p = p->prox) {
		if (p->qtd_vagas_ocupadas == p->qtd_vagas) {
			printf("\nTurma: %d\n", p->codigo);
			cont++;
		}
	}
	if (cont == 0)
		puts("Nao ha turmas lotadas.");
	puts("");
}

void Imprimir_alunos_em_cada_turma(Turmas* t) {
	Turmas* p;
	int cont = 0;
	for (p = t; p != NULL; p = p->prox) {
		printf("Turma %d: %d alunos\n", p->codigo ,p->qtd_vagas_ocupadas);
		cont++;
	}
	if (cont == 0)
		printf("Nao ha turmas cadastradas\n");
	puts("");
}

void Lista_turmas_cada_disciplina(Turmas* t, int v) {
	Turmas* p;
	int cont = 0;
	puts("");
	for (p = t; p != NULL; p = p->prox) {
		if (p->disciplinas->codigo == v) {
			printf("Turma: %d\n", p->codigo);
			cont++;
		}
	}
	printf("\nTotal de turmas: %d\n\n", cont);
	return;
}

void Lista_Disciplinas_Aluno(Matriculas* m, int v) {
	Matriculas* p;
	int cont = 0;
	puts("");
	for (p = m; p != NULL; p = p->prox) {
		if (p->aluno->matricula == v) {
			printf("Disciplina: %d | %s\n", p->turma->disciplinas->codigo, p->turma->disciplinas->nomed);
			cont++;
		}
	}
	if (cont == 0)
		puts("Este aluno nao cursa nenhuma disciplina");
	puts("");
}
