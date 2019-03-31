struct alunos {
	int matricula;
	char *nome;
	long telefone;
	struct alunos* prox;
};
typedef struct alunos Alunos;

struct turmas {
	int codigo;
	struct disciplinas* disciplinas;
	int qtd_vagas;
	int qtd_vagas_ocupadas;
	char *dia;
	char *horario;
	int sala;
	struct turmas* prox;
};
typedef struct turmas Turmas;

struct disciplinas {
	int codigo;
	char *nomed;
	int creditos;
	struct disciplinas* prox;
};
typedef struct disciplinas Disciplinas;

struct matriculas {
	struct alunos* aluno;
	struct turmas* turma;
	char *data;
	struct matriculas* prox;
};
typedef struct matriculas Matriculas;

//################################################################################

void criar_lista_Matriculas(Matriculas** m);
void inserir_lista_Matriculas(Matriculas** m, int aluno, int turma, char* data, Alunos* enderecoAluno, Turmas* enderecoTurma);
void retirar_lista_Matriculas(Matriculas** m, int v, int v2);
int retirar_lista_matriculas_update(Matriculas**m, int v, int cont, int x);
void imprimir_lista_Matriculas(Matriculas* m);
int busca_turmas_em_matriculas(Matriculas** m, int alvo);
int busca_alunos_em_matriculas(Matriculas** m, int alvo);
Matriculas* busca_lista_Matriculas(Matriculas** m, int alvo, int alvo2);
int Confere_Vagas(Turmas* t);

void criar_lista(Alunos** l);
void inserir_lista(Alunos** l, int matricula, char* nome, long telefone);
void imprimir_lista(Alunos* l);
void retirar_lista(Alunos** l, int v);
int lista_vazia(Alunos** l);
void liberar_lista(Alunos** l);
Alunos* existeAluno(int aluno, Alunos** l);
Alunos* busca_lista(Alunos** l, int v);

void criar_lista_Turmas(Turmas** t);
void inserir_lista_turmas(Turmas** t, int codigo, Disciplinas** endDisciplina, int qtd_vagas, char* dia, char* horario, int sala);
void imprimir_lista_turmas(Turmas* t);
Turmas* busca_lista_turmas(Turmas** t, int v);
void retirar_lista_turmas(Turmas** t, int v);
int retirar_lista_turmas_update(Turmas** t, int v, int cont);
int busca_disciplina_em_turmas(Turmas** t, int alvo);
void lst_insere_ordenado(Turmas** t, int codigo, Disciplinas** endDisciplina, int qtd_vagas, char* dia, char* horario, int sala);
Turmas* existeTurma(int turma, Turmas** t);

void criar_lista_Disciplinas(Disciplinas** d);
void inserir_lista_Disciplinas(Disciplinas** d, int codigo, char* nomed, int creditos);
Disciplinas* existeDisciplina(int disciplina, Disciplinas** d);
void imprimir_lista_Disciplinas(Disciplinas* d);
Disciplinas* busca_lista_Disciplinas(Disciplinas** d, int v);
void retirar_lista_Disciplinas(Disciplinas** d, int v);

void Imprimir_Alunos_de_Turma(Matriculas* m, int v);
void Imprimir_Turmas_Lotadas(Turmas* t);
void Imprimir_alunos_em_cada_turma(Turmas* t);
void Lista_turmas_cada_disciplina(Turmas* t, int v);
void Lista_Disciplinas_Aluno(Matriculas* m, int v);
