// DEFINICOES
typedef struct aluno Aluno;
typedef struct no No;
typedef struct arvore Arvore;

// CRIAR
void criaLista(Aluno **aluno);
void criaAluno(int cod, char *nome, float media, Aluno **alunoInicio, Arvore *arvoreCodigo, Arvore *arvoreMedia, Arvore *arvoreNome);
No *criaNo(Aluno *aluno, int cod);
Arvore *criaArvore();

// IMPRESSAO
void imprime(Aluno *aluno);
void imprimeArvore(Arvore *arvoreGeral);
void imprimeArvoreRecursiva(No *atual);

// AUXILIARES
Aluno *buscaAluno(Aluno *aluno, int cod);

//REMOVER
int removerArvoreRecursiva(No *noAtual, Aluno *alunoRemover);
void removerRaiz(Arvore *arvore);
void remover(Aluno **alunoInicio, int cod, Arvore *arvoreCodigo, Arvore *arvoreMedia, Arvore *arvoreNome);

// INSERIR
void insereArvoreCodigoRecursiva(No *noPai, No *no);
void insereArvoreCodigo(Arvore *arvoreCodigo, Aluno *aluno, int codAluno);
void insereArvoreMediaRecursiva(No *noPai, No *no);
void insereArvoreMedia(Arvore *arvoreMedia, Aluno *aluno, int codAluno);
void insereArvoreNomeRecursiva(No *noPai, No *no);
void insereArvoreNome(Arvore *arvoreNome, Aluno *aluno, int codAluno);

// MENU
void menuPrincipal(Aluno **aluno, Arvore *arvoreCodigo, Arvore *arvoreMedia, Arvore *arvoreNome);
