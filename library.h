#ifndef SEMINARIO_2_LIBRARY_H
#define SEMINARIO_2_LIBRARY_H

typedef struct arvoreBin *ArvoreBin;

// Altura da arvore

int altura(ArvoreBin a);

// Balanceamento da arvore

int balanceamento(ArvoreBin a);

//Procurar elemento na arvore

int existe(ArvoreBin a, int x);

//Imprimir Largura

void imprimirLargura(ArvoreBin a,int nivel);

//Inserir elementos

ArvoreBin inserir(ArvoreBin a, char lado, int chave, void* objeto, int noPai);

//Buscar elemento

void* Buscar(ArvoreBin a, int chave);

//Destruir a arvore

ArvoreBin Destruir(ArvoreBin a);


#endif //SEMINARIO_2_LIBRARY_H