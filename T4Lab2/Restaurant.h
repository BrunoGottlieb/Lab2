#include<stdbool.h>

typedef struct Group {
	int integrants;
	int Password;
	struct Group *next;
}Group;
typedef struct Table {
	bool freeTable;
	int TableNumber;
	int CardIndex;
	int People;
	struct Table* Next;
}Table;
typedef struct Queue {
	Group *first;
	Group *last;
}Queue;

struct Car{
	char Plate[7];
	int Ticket;
struct Car* Next;
struct Car* Previous;
};
typedef struct Car Car;

typedef struct ParkingLot {
	Car* first;
	Car* last;
} ParkingLot;

typedef struct LIMBO{ //Os carros retirados do estacionamento vem temporariamente para ca
	Car* First;
} LIMBO;

void Solicitar_info(int *c, int *l, int *VagasEstacionamento);
void Menuzinho();
void SubMenu(Table **tables, int l, int c, Queue *list, ParkingLot *Estacionamento);
void Alocar_Mesas(Table **tables, int l, int c);
void criar_lista_grupos(Group** G);
void criar_lista_mesas(Table **T);
void inserir_lista_grupos(Group **G, int N);
void inserir_grupo_na_mesa(Table **tables, int n, int columns, int rows);
bool Existe_Mesa_Disponivel(Table **tables, int c, int l);
void CreateTable(int index, Table *t);
Queue *Criar_Fila_Espera();
int Inserir_Fila(Queue* f, int v, int Password);
void busca_lista(Table** list, int v, int l, int c);
void listar_mesas(Table** tables, int l, int c);
void Listar_Fila(Queue* f);
bool retirar_lista(Table** t, int v, int c, int l);
int retira_da_fila(Queue* f);
ParkingLot *Criar_Fila_Estacionamento();
void criar_lista_carros(Car **C);
void Inserir_Carro(ParkingLot* f, char *placa, int Ticket, int aux);
void Exibir_Estacionamento(ParkingLot* f);
void pilha_pop(ParkingLot* p, int target, LIMBO *Limbo);
LIMBO* pilha_cria(void);
void pilha_push(LIMBO* p, Car* t);
void Reinserir_Carros(ParkingLot* p, LIMBO* Limbo);
int Confere_Ticket(ParkingLot* p, int target);
