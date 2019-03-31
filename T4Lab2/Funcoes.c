#include<stdio.h>
#include<stdlib.h>
#include"Restaurant.h"

void Solicitar_info(int *c, int *l, int *VagasEstacionamento) {
	puts("INFORMACOES INICIAIS:\n");
	printf("Informe quantas colunas de mesas: ");
	scanf("%d", c);
	printf("Informe quantas linhas de mesas: ");
	scanf("%d", l);
	printf("Informe quantas vagas tem o estacionamento: ");
	scanf("%d", VagasEstacionamento);
	puts("\nRESTAURANTE INAUGURADO!\n");
}

void Menuzinho() {
	puts("Escolha uma acao:\n");
	printf("[1] Inserir novo grupo de clientes\n");
	printf("[2] Liberar uma mesa\n");
	printf("[3] Inserir carro no estacionamento\n");
	printf("[4] Retirar carro do estacionamento\n");
	printf("[5] Exigir relatorio\n");
	return;
}

void SubMenu(Table **tables, int l, int c, Queue *list, ParkingLot *Estacionamento) {
	int escolha;
	puts("Sub-Menu Relatorios:\n");
	puts("[1] Ocupacao de mesa (buscar por numero)");
	puts("[2] Ocupacao das mesas (todas)");
	puts("[3] Fila de espera");
	puts("[4] Exibir estacionamento");
	scanf("%d", &escolha);
	switch (escolha)
	{
	case 1:
		printf("\nDigite o numero da mesa desejada: ");
		scanf("%d", &escolha);
		busca_lista(tables, escolha, l, c);
		break;
	case 2:
		listar_mesas(tables, l, c);
		break;
	case 3:
		Listar_Fila(list);
		break;
	case 4:
		Exibir_Estacionamento(Estacionamento);
		break;
	default:
		puts("Valor inserido eh invalido");
		break;
	}
}

bool retirar_lista(Table** t, int v, int c, int l) {
	int i, j;
	for (i = 0; i < l; i++) {
		for (j = 0; j < c; j++) {
			if (t[i][j].TableNumber == v) {
				t[i][j].People = 0;
				t[i][j].freeTable = true;
				t[i][j].CardIndex = 0;
				printf("\nMesa %d liberada com sucesso!\n\n", v);
				return true;
			}
		}
	}
	printf("\nMesa %d nao foi encontrada.\n\n", v);
	return false;
}

void Listar_Fila(Queue* f) {
	int aux = 0, cont=0;
	Group* tmp = f->first;
	if (f->first == NULL) {
		printf("\nNao ha pessoas na fila de espera\n\n");
		return;
	}
	while (tmp != NULL) {
		aux += tmp->integrants;
		cont++;
		tmp = tmp->next;
	}
	printf("\nTotal de grupos na fila: %d\nTotal de pessoas esperando: %d\n\n", cont, aux);
	return;
}

void listar_mesas(Table** tables, int l, int c) {
	puts("");
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++)
			printf("Mesa %d: %d pessoas\n", tables[i][j].TableNumber, tables[i][j].People);
	}
	puts("");
}

void busca_lista(Table** list, int v, int l, int c) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++){
			if(list[i][j].TableNumber == v){
				printf("\nQuantia de pessoas na mesa %d: %d pessoas.\n\n", v, list[i][j].People);
				return;
			}
		}
	}
	printf("\nMesa %d nao foi encontrada.\n\n", v);
	return;
}

void Alocar_Mesas(Table **tables, int l, int c) {
	for (int i = 0; i < l; i++)
		tables[i] = (Table*)malloc(sizeof(Table) * c);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < c; j++)
			CreateTable(i*c + j+1,&tables[i][j]);
	}
	return;
}

void CreateTable(int index, Table *t) {
	t->freeTable = true;
	t->CardIndex = t->TableNumber = index;
	t->People = 0;
}

void criar_lista_grupos(Group **G) {
	*G = NULL;
}

void criar_lista_mesas(Table **T) {
	*T = NULL;
}

void criar_lista_carros(Car **C) {
	*C = NULL;
}

void inserir_lista_grupos(Group **G, int N) {
	Group* novo = (Group*)malloc(sizeof(Group));
	novo->integrants = N;
	novo->Password = NULL;
	novo->next = *G;
	*G = novo;
}

Queue *Criar_Fila_Espera(void) {
	Queue* list = (Queue*)malloc(sizeof(Queue));
	list->first = list->last= NULL;
	return list;
}

ParkingLot *Criar_Fila_Estacionamento(void) {
	ParkingLot* list = (ParkingLot*)malloc(sizeof(ParkingLot));
	list->first = list->last = NULL;
	return list;
}

int Inserir_Fila(Queue* f, int v, int Password){
	Group* n = (Group*)malloc(sizeof(Group));
	n->integrants = v;
	n->Password = Password + 1;
	n->next = NULL;
	Password++;
	if (f->last != NULL)
		f->last->next = n;
	else
		f->first = n;
	f->last = n;
	printf("\nGrupo com %d integrantes foi inserido na fila com senha de espera %d\n", v, Password-1);
	return Password;
}

int retira_da_fila(Queue* f){
	if (f->first == NULL)
		return 0;
	int aux = f->first->integrants;
	f->first->integrants -= 4;
	if (f->first->integrants <= 0) {
		f->first = f->first->next;
		if (f->first == NULL)
			f->last = NULL;
		return aux;
	} else return 4;
}

void inserir_grupo_na_mesa(Table **tables, int n, int columns, int rows) {
	if (Existe_Mesa_Disponivel(tables, columns, rows)) {
		for (int i = 0; i < rows;i++) {
			for (int j = 0; j < columns; j++) {
				if (tables[i][j].freeTable) {
					tables[i][j].People = n;
					tables[i][j].freeTable = false;
					return;
				}
			}
		}
	}
}

bool Existe_Mesa_Disponivel(Table **tables, int c, int l) {
	for (int i = 0; i < l;i++) {
		for (int j = 0; j < c; j++) {
			if (tables[i][j].freeTable)
				return true;
		}
	}
	return false;
}

void Exibir_Estacionamento(ParkingLot* f) {
	int cont = 0;
	Car* tmp = f->first;
	if (f->first == NULL || f->last == NULL) {
		printf("\nNao ha carros no estacionamento\n\n");
		return;
	}
	while (tmp != NULL) {
		cont++;
		printf("\ncarro %d:\n", cont);
		printf("Placa: %s\n", tmp->Plate);
		printf("Ticket: %d\n", tmp->Ticket);
		tmp = tmp->Next;
	}
	printf("\nTotal de %d carros na fila.\n\n", cont);
	return;
}

void Inserir_Carro(ParkingLot* f, char *placa, int Ticket, int tam) {
	int i;
	Car* n = (Car*)malloc(sizeof(Car));
	for(i=0; i<tam; i++)
		n->Plate[i] = placa[i];
	n->Plate[i] = '\0';
	n->Ticket = Ticket;
	n->Next = NULL;
	if (f->last != NULL) {
		n->Previous = f->last;
		f->last->Next = n;
		f->last = n;
	}
	else {
		f->first = n;
		f->first->Previous = NULL;
		f->last = n;
		f->last->Previous = NULL;
	}
	printf("\nCarro de placa %s foi inserido no estacionamento com Ticket: %d\n\n", placa, Ticket);
	return;
}

void Reinserir_Carros(ParkingLot* p, LIMBO* Limbo) {
	Car* tmp; int cont=0;
	if (Limbo->First == NULL) {
		printf("Nao ha carros para serem reinseridos\n\n");
		return;
	}
	while(Limbo->First !=NULL){
		tmp = Limbo->First;
		Limbo->First = tmp->Next;
		int i;
		Car* n = (Car*)malloc(sizeof(Car));
		for (i = 0; i < 7; i++)
			n->Plate[i] = tmp->Plate[i];
		n->Plate[i] = '\0';
		n->Ticket = tmp->Ticket;
		n->Next = NULL;
		if (p->last != NULL) {
			n->Previous = p->last;
			p->last->Next = n;
		}
		else
			p->first = n;
		p->last = n;
		free(tmp);
		cont++;
	}
	printf("%d carros foram retirados e reinseridos propriamente.\n\n", cont);
	return;
}

int Confere_Ticket(ParkingLot* p, int target) {
	Car* tmp = p->first;
	while (tmp != NULL) {
		if (tmp->Ticket == target)
			return 1;
		tmp = tmp->Next;
	}
	return 0;
}

void pilha_pop(ParkingLot* p, int target, LIMBO *Limbo) {
	Car* tmp;
	if (p->first == NULL) {
		printf("\nNao ha carros no estacionamento\n\n");
		return;
	}
	if(Confere_Ticket(p, target) == 1){
		while (p->last->Ticket != target){
			tmp = p->last;
			pilha_push(Limbo, tmp);
			p->last = tmp->Previous;
			p->last->Next = NULL;
			free(tmp);
		}
		tmp = p->last;
		if (p->last == p->first) {
			p->last->Next = NULL;
			p->last = NULL;
		}
		else {
			p->last = tmp->Previous;
			p->last->Next = NULL;
		}
		free(tmp);
		printf("\nCarro %d retirado com sucesso!\n\n", target);
	}
	else {
		printf("\nCarro de ticket %d nao consta no estacionamento.\n\n", target);
		return;
	}
}

void pilha_push(LIMBO* p, Car* t){
	Car* n = (Car*)malloc(sizeof(Car));
	for (int i = 0; i < 7; i++)
		n->Plate[i] = t->Plate[i];
	n->Ticket = t->Ticket;
	n->Next = p->First;
	p->First = n;
}

LIMBO* pilha_cria(void){
	LIMBO* p = (LIMBO*)malloc(sizeof(LIMBO));
	p->First = NULL;
	return p;
}
