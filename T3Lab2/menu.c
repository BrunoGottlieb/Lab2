#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"funcoes.h"

void ExcluirMatriculas(Matriculas** m){
  int alvo, alvo2;
  puts("------------------------------------");
  puts("    Menu Matriculas --> Excluir Matriculas:\n");
  printf("    Informe o codigo de cadastro do aluno: ");
  scanf("%d", &alvo);
  printf("    Informe o codigo da turma: ");
  scanf("%d", &alvo2);
  Matriculas* lism= busca_lista_Matriculas (m, alvo, alvo2);  //busca_lista um elemento na lista
  if(lism==NULL){
	printf ("\nA matricula nao foi encontrada\n");
  }else{
	printf ("\nA matricula foi encontrada e excluida com sucesso.\n");
  }
  retirar_lista_Matriculas (m, alvo, alvo2);
  return;
}
void ListarMatriculas(Matriculas* m) {
	puts("------------------------------------");
	puts("    Menu Matriculas --> Listar Matriculas:\n");
	imprimir_lista_Matriculas(m);
	return;
}
void IncluirMatriculas(Matriculas** m, Alunos** l, Turmas** t) {
	int aluno, turma, vagas=0;
	char *data = (char*)malloc(10);
	bool alunoo = false, turmaa = false;
	Alunos* enderecoAluno;
	Turmas* enderecoTurma;
	puts("------------------------------------");
	puts("    Menu  Matriculas --> Incluir Matriculas:\n");
	printf("    Codigo do aluno: ");
	scanf("%d", &aluno);
	printf("    Turma: ");
	scanf("%d", &turma);
	printf("    Data: ");
	scanf("%s", data);

	if (existeAluno(aluno, l) != NULL) {
		enderecoAluno = existeAluno(aluno, l);
		alunoo = true;
	}
	else {
		printf("\nNao existe este aluno.\n");
		alunoo = false;
		return;
	}

	if (existeTurma(turma, t) != NULL) {
		enderecoTurma = existeTurma(turma, t);
		turmaa = true;
	}
	else {
		printf("\nNao existe esta turma.\n");
		turmaa = false;
		return;
	}

	vagas = Confere_Vagas(enderecoTurma);

	if (turmaa == true && alunoo == true && vagas > 0) {
		inserir_lista_Matriculas(m, aluno, turma, data, enderecoAluno, enderecoTurma);
		puts("\nMatricula criada com sucesso!\n");
		printf("Vagas na turma %d antes: %d\n", turma, vagas);
		printf("Vagas na turma %d agora: %d\n\n", turma, vagas - 1);
		return;
	}
	if (vagas == 0) {
		puts("\nNao ha vagas suficientes nesta turma.");
		return;
	}
}

void ListarDisciplinas(Disciplinas* d) {
	puts("------------------------------------");
	puts("    Menu Disciplinas --> Listar Disciplinas:\n");
	imprimir_lista_Disciplinas(d);
	return;
}
void IncluirDisciplinas(Disciplinas** d) {
	int codigo, creditos;
	char *nomed = (char*)malloc(30);
	puts("------------------------------------");
	puts("    Menu Disciplinas --> Incluir Disciplinas:\n");
	printf("    Codigo da disciplina: ");
	scanf("%d", &codigo);
	printf("    Nome da disciplina: ");
	scanf("%s", nomed);
	printf("    Creditos: ");
	scanf("%d", &creditos);
	inserir_lista_Disciplinas(d, codigo, nomed, creditos);
	return;
}
void ExcluirDisciplinas(Disciplinas** d, Turmas** t) {
	int alvo, aux;
	int cont=0;
	puts("------------------------------------");
	puts("    Menu Disciplinas --> Excluir Disciplinas:\n");
	printf("    Informe o codigo da disciplina a ser excluida: ");
	scanf("%d", &alvo);
	Disciplinas* lisd = busca_lista_Disciplinas(d, alvo);  //busca_lista um elemento na lista
	if (lisd == NULL) {
		printf("\nA disciplina %d nao foi encontrada\n", alvo);
		return;
	}
	else {
		printf("\nA disciplina %d foi encontrada e excluida com sucesso.\n", lisd->codigo);	
	}
	aux = busca_disciplina_em_turmas(t, alvo);
	while (aux != NULL) {
		cont= retirar_lista_turmas_update(t, aux, cont);
		aux = busca_disciplina_em_turmas(t, alvo);
	}
	if (cont != 0) {
		printf("\n%d turmas referentes a essa disciplina foram tambem excluidas.\n", cont);
	}
	else {
		puts("\nNao haviam turmas relacionadas a essa disciplina.\n");
	}
	retirar_lista_Disciplinas(d, alvo);
	return;
}

void IncluirTurmas(Turmas** t, Disciplinas** d) {
	int codigo;
	int disciplina;
	Disciplinas* enderecoDisciplina;
	int qtd_vagas;
	char *dia = (char*)malloc(20);
	char *horario = (char*)malloc(10);
	int sala;
	puts("------------------------------------");
	puts("    Menu Turmas --> Incluir turmas:\n");
	printf("    Codigo: ");
	scanf(" %d", &codigo);
	printf("    Disciplina: ");
	scanf("%d", &disciplina);
	printf("    Quantidade de vagas ofertadas: ");
	scanf("%d", &qtd_vagas);
	printf("    Dia da semana: ");
	scanf("%s", dia);
	printf("    Horario: ");
	scanf("%s", horario);
	printf("    Sala: ");
	scanf("%d", &sala);
	if (existeDisciplina(disciplina, d) != NULL) {
		enderecoDisciplina = existeDisciplina(disciplina, d);
		inserir_lista_turmas(t, codigo, &enderecoDisciplina, qtd_vagas, dia, horario, sala);
		puts("\nTurma inserida com sucesso!");
		return;
	}
	else {
		printf("\nNao existe esta disciplina.\n");
		return;
	}
}
void ExcluirTurmas(Turmas** t, Matriculas** m) {
	puts("------------------------------------");
	puts("    Menu Turmas --> Excluir Turmas:\n");
	printf("    Informe o codigo da turma a ser excluida: ");
	int alvo, aux, cont=0, seletor=1;
	scanf("%d", &alvo);
	Turmas* tis = busca_lista_turmas(t, alvo);  //busca_lista um elemento na lista
	if (tis == NULL) {
		printf("\nA turma %d nao foi encontrada\n", alvo);
		return;
	}
	else {
		printf("\nA turma %d foi encontrada e excluida com sucesso.\n", tis->codigo);
	}
	aux = busca_turmas_em_matriculas(m, alvo);
	while (aux != NULL) {
		cont = retirar_lista_matriculas_update(m, aux, cont, seletor);
		aux = busca_turmas_em_matriculas(m, alvo);
	}
	if (cont != 0) {
		printf("\n%d matriculas referentes a essa turma foram tambem excluidas.\n", cont);
	}
	else {
		puts("\nNao haviam matriculas relacionadas a essa turma.\n");
	}
	retirar_lista_turmas(t, alvo);
	return;
}
void ListarTurmas(Turmas** t) {
	puts("------------------------------------");
	puts("    Menu Turmas --> Listar Turmas:\n");
	imprimir_lista_turmas(*t);
	return;
}

void ListarAlunos(Alunos* l) {
	puts("------------------------------------");
	puts("    Menu Alunos --> Listar Alunos:\n");
	imprimir_lista(l);
	return;
}
void IncluirAlunos(Alunos** l) {
	int matricula;
	long telefone;
	char *nome = (char*)malloc(30);
	puts("------------------------------------");
	puts("    Menu Alunos --> Incluir Alunos:\n");
	printf("    Nome: ");
	scanf(" %s", nome);
	printf("    Numero de matricula: ");
	scanf("%d", &matricula);
	printf("    Telefone: ");
	scanf("%li", &telefone);
	inserir_lista(l, matricula, nome, telefone);
	return;
}
void ExcluirAlunos(Alunos** l, Matriculas** m) {
	int alvo, aux, cont=0, seletor=2;
	puts("------------------------------------");
	puts("    Menu Alunos --> excluir Alunos:\n");
	printf("Informe o numero de cadastro: ");
	scanf("%d", &alvo);
	Alunos* lis = busca_lista(l, alvo);  //busca_lista um elemento na lista
	if (lis == NULL) {
		printf("\nO aluno de cadastro %d nao foi encontrado\n", alvo);
		return;
	}
	else {
		printf("\nO cadastro %d foi encontrado. Aluno %s foi excluido.\n", lis->matricula, lis->nome);
	}
	aux = busca_alunos_em_matriculas(m, alvo);

	while (aux != NULL) {
		cont = retirar_lista_matriculas_update(m, aux, cont, seletor);
		aux = busca_alunos_em_matriculas(m, alvo);
	}
	if (cont != 0) {
		printf("\n%d matriculas referentes a esse aluno foram tambem excluidas.\n", cont);
	}
	else {
		puts("\nNao haviam matriculas relacionadas a esse aluno.\n");
	}

	retirar_lista(l, alvo);
	return;
}

void Lista_Alunos_em_Turma(Matriculas** m) {
	puts("------------------------------------");
	puts("    Menu Relatorios --> Listar Alunos em turma:\n");
	printf("Insira o codigo da turma desejada: ");
	int alvo;
	scanf("%d", &alvo);
	Imprimir_Alunos_de_Turma(*m, alvo);
	return;
}
void Turmas_Lotadas(Turmas** t) {
	puts("------------------------------------");
	puts("    Menu Relatorios --> Listar turmas lotadas:\n");
	Imprimir_Turmas_Lotadas(*t);
	return;
}
void Disciplina_Turmas_Existentes(Turmas** t) {
	int alvo;
	puts("------------------------------------");
	puts("    Menu Relatorios --> Quantia de turmas de certa disciplina:\n");
	printf("Insira o codigo da disciplina desejada: ");
	scanf("%d", &alvo);
	Lista_turmas_cada_disciplina(*t, alvo);
	return;
}
void Alunos_em_cada_turma(Turmas** t) {
	puts("------------------------------------");
	puts("    Menu Relatorios --> Quantia de alunos em cada turma:\n");
	Imprimir_alunos_em_cada_turma(*t);
	return;
}
void Disiplinas_de_Aluno(Matriculas** m) {
	int alvo;
	puts("------------------------------------");
	puts("    Menu Relatorios --> Disciplinas de certo aluno:\n");
	printf("Insira a matricula do aluno desejado: ");
	scanf("%d", &alvo);
	Lista_Disciplinas_Aluno(*m, alvo);
	return;
}

void MenuAlunos(Alunos** l, Matriculas** m) {
	int opcao;
	bool loop = true;
	while (loop == true) {
		puts("------------------------------------");
		puts("   Menu alunos:");
		puts("\n  [1] Incluir alunos");
		puts("  [2] Excluir alunos");
		puts("  [3] Listar alunos");
		puts("  [4] Voltar ao menu principal");
		printf("\nSelecione uma opcao: ");
		scanf("%d", &opcao);
		switch (opcao) {
		case 1:
			IncluirAlunos(l);
			break;
		case 2:
			ExcluirAlunos(l, m);
			break;
		case 3:
			ListarAlunos(*l);
			break;
		case 4:
			return; //Retorna ao menu principal
			break;
		}
	}
}
void MenuTurmas(Turmas** t, Disciplinas** d, Matriculas** m) {
	int opcao;
	bool loop = true;
	while (loop == true) {
		puts("------------------------------------");
		puts(" Menu turmas:");
		puts("\n  [1] Incluir turmas");
		puts("  [2] Excluir turmas");
		puts("  [3] Listar turmas");
		puts("  [4] Voltar ao menu principal");
		printf("\nSelecione uma opcao: ");
		scanf("%d", &opcao);
		switch (opcao) {
		case 1:
			IncluirTurmas(t, d);
			break;
		case 2:
			ExcluirTurmas(t, m);
			break;
		case 3:
			ListarTurmas(t);
			break;
		case 4:
			return; //Retorna ao menu principal
			break;
		}
	}
}
void MenuDisciplinas(Disciplinas** d, Turmas** t) {
	int opcao;
	bool loop = true;
	while (loop == true) {
		puts("------------------------------------");
		puts(" Menu disciplinas:");
		puts("\n  [1] Incluir disciplinas");
		puts("  [2] Excluir disciplinas");
		puts("  [3] Listar disciplinas");
		puts("  [4] Voltar ao menu principal");
		printf("\nSelecione uma opcao: ");
		scanf("%d", &opcao);
		switch (opcao) {
		case 1:
			IncluirDisciplinas(d);
			break;
		case 2:
			ExcluirDisciplinas(d, t);
			//t = retirar_lista_turmas_upgrade(t);
			break;
		case 3:
			ListarDisciplinas(*d);
			break;
		case 4:
			return; //Retorna ao menu principal
			break;
		}
	}
}
void MenuMatriculas(Matriculas** m, Alunos** l, Turmas** t) {
	int opcao;
	bool loop = true;
	while (loop == true) {
		puts("------------------------------------");
		puts(" Menu matriculas:");
		puts("\n  [1] Incluir matriculas");
		puts("  [2] Excluir matriculas");
		puts("  [3] Listar matriculas");
		puts("  [4] Voltar ao menu principal");
		printf("\nSelecione uma opcao: ");
		scanf("%d", &opcao);
		switch (opcao) {
		case 1:
			IncluirMatriculas(m, l, t);
			break;
		case 2:
			ExcluirMatriculas(m);
			break;
		case 3:
			ListarMatriculas(*m);
			break;
		case 4:
			return; //Retorna ao menu principal
			break;
		}
	}
}
void MenuRelatorios(Matriculas** m, Turmas** t) {
	int opcao;
	bool loop = true;
	while (loop == true) {
		puts("------------------------------------");
		puts(" Menu Relatorios:");
		puts("\n  [1] Lista de alunos em certa turma");
		puts("  [2] Quantia de turmas de certa disciplina");
		puts("  [3] Disciplinas de certo aluno");
		puts("  [4] Quantia de alunos em cada turma");
		puts("  [5] Turmas que estao lotadas");
		puts("  [6] Voltar ao menu principal");
		printf("\nSelecione uma opcao: ");
		scanf("%d", &opcao);
		switch (opcao) {
		case 1:
			Lista_Alunos_em_Turma(m);
			break;
		case 2:
			Disciplina_Turmas_Existentes(t);
			break;
		case 3:
			Disiplinas_de_Aluno(m);
			break;
		case 4:
			Alunos_em_cada_turma(t);
			break;
		case 5:
			Turmas_Lotadas(t);
			break;
		case 6:
			return;
			break;
		}
	}
}

int MenuPrincipal(Alunos** l, Turmas** t, Disciplinas** d, Matriculas** m) {
	int opcao;
	bool repetir = true;
	while (repetir == true) {
		puts("------------------------------------");
		puts(" Menu principal:\n");
		puts("[1] Menu alunos");
		puts("[2] Menu Turmas");
		puts("[3] Menu disciplinas");
		puts("[4] Menu matriculas");
		puts("[5] Menu relatorios");
		puts("[6] Sair do programa");
		printf("\nSelecione uma opcao: ");
		scanf("%d", &opcao);
		switch (opcao) {
		case 1:
			MenuAlunos(l, m);
			break;
		case 2:
			MenuTurmas(t, d, m);
			break;
		case 3:
			MenuDisciplinas(d, t);
			break;
		case 4:
			MenuMatriculas(m, l, t);
			break;
		case 5:
			MenuRelatorios(m, t);
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("\nOpcao invalida.\n");
			break;
		}
	}
}

int main() {
	Alunos* l;
	Turmas* t;
	Disciplinas* d;
	Matriculas* m;
	criar_lista(&l); // cria e inicializa lista como vazia para os alunos
	criar_lista_Turmas(&t); //Cria e inicializa lista vazia para as turmas
	criar_lista_Disciplinas(&d);
	criar_lista_Matriculas(&m);
	MenuPrincipal(&l, &t, &d, &m);
	return 0;
}
