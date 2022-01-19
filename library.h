#ifndef SEMINARIO_2_LIBRARY_H
#define SEMINARIO_2_LIBRARY_H
typedef struct arvoreBin *ArvoreBin;
typedef struct alunos *Alunos;
typedef struct professores *Professores;
// Altura da arvore

int altura(ArvoreBin a);

// Balanceamento da arvore

int balanceamento(ArvoreBin a);

//Procurar elemento na arvore

int existe(ArvoreBin a, int x);

//Imprimir Largura e função auxiliar

void ImprimirNivel(ArvoreBin a,int cont,int nivel);
void imprimirLargura(ArvoreBin a,int nivel);

//Inserir elementos

ArvoreBin inserir(ArvoreBin a, char lado, int chave, void* objeto);

//Buscar elemento

void* Buscar(ArvoreBin a, int chave);

#endif //SEMINARIO_2_LIBRARY_H