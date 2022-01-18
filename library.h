#ifndef SEMINARIO_2_LIBRARY_H
#define SEMINARIO_2_LIBRARY_H

typedef struct arvoreABB *ArvoreABB;

// Altura da arvore

int altura(ArvoreABB a);

// Balanceamento da arvore

int balanceamento(ArvoreABB a);

/*Procurar elemento na arvore*/
int Existe(ArvoreABB a, void *x);


#endif //SEMINARIO_2_LIBRARY_H