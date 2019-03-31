#include<stdio.h>
#include"Restaurant.h"
#include<stdlib.h>
#include<string.h>

int main() {
	int i, l, c, N, VagasEstacionamento, QtdMesas, cont=0, Password=1, escolha, aux, Ticket=1;
	char placa[7];
	Group *G;
	Car *Carro;
	criar_lista_carros(&Carro);
	criar_lista_grupos(&G);
	Solicitar_info(&c, &l, &VagasEstacionamento);
	Table **tables;
	Queue *list = Criar_Fila_Espera();
	ParkingLot *Estacionamento = Criar_Fila_Estacionamento();
	LIMBO *Limbo = pilha_cria();
	tables = (Table**)malloc(sizeof(Table*) * l);
	Alocar_Mesas(tables, l, c);
	for(;;){
		Menuzinho();
		scanf("%d", &escolha);
		switch (escolha) {
		case 1:
			printf("\nInserir novo grupo de pessoas com X integrantes: ");
			scanf("%d", &N);
			inserir_lista_grupos(&G, N);
			cont = 0;
			for (i = 0; N > 4; i++) {
				if (Existe_Mesa_Disponivel(tables, c, l)) {
					N -= 4;
					inserir_grupo_na_mesa(tables, 4, c, l);
					cont++;
				}
				else break;
			} i++;
			if (N > 0 && Existe_Mesa_Disponivel(tables, c, l)) {
				inserir_grupo_na_mesa(tables, N, c, l);
				cont++;
			}
			else Password= Inserir_Fila(list, N, Password);
			printf("\nGrupo foi inserido em %d mesa(s) com sucesso.\n\n", cont);
			break;
		case 2:
			printf("\nInsira o numero da mesa que deseja liberar: ");
			scanf("%d", &escolha);
			if (retirar_lista(tables, escolha, c, l))
				aux= retira_da_fila(list);
			else break;
			if (aux != 0){
				inserir_grupo_na_mesa(tables, aux, c, l);
				printf("%d pessoas sairam da fila de espera e foram para uma mesa vaga.\n\n", aux);
			}
			break;
		case 3:
			if (VagasEstacionamento > 0) {
				aux = 0;
				do{
					printf("\nDigite a placa do carro: ");
					scanf("%s", placa);
					aux= strlen(placa);
					if (aux > 7)
						puts("\nOs algarismos da placa devem ser de no maximo 7 digitos.");
				} while (aux > 7);
				Inserir_Carro(Estacionamento, placa, Ticket, aux);
				VagasEstacionamento--; Ticket++;
			}
			else printf("\nNao ha vagas no estacionamento.\n\n");
			break;
		case 4:
			printf("\nApresente o numero do ticket para retirar o carro: ");
			scanf("%d", &escolha);
			pilha_pop(Estacionamento, escolha, Limbo);
			Reinserir_Carros(Estacionamento, Limbo);
			break;
		case 5:
			SubMenu(tables, l, c, list, Estacionamento);
			break;
		default:
			puts("\nValor inserido eh invalido.\n");
			break;
		}
	}
	system("pause");
}
