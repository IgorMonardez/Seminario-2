#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct arvoreBin {
    int chave;
    int tipo;
    void *obj;
    struct arvoreBin *dir,*esq;
};

int altura(ArvoreBin a) {
    if(a == NULL)
        return 0;
    else {
        int he,hd;
        he = altura(a->esq);
        hd = altura(a->dir);
        if(he > hd)
            return he+1;
        else
            return hd + 1;
    }
}

int balanceamento(ArvoreBin a) {
    if(a == NULL)
        return 1;
    else {
        int he = altura(a->esq);
        int hd = altura(a->dir);
        if(abs(he-hd) > 1)
            return 0;
        else {
            int ret = balanceamento(a->esq);
            if(ret == 1)
                return 1;
            return balanceamento(a->dir);
        }
    }
}

/*Verificar se um elemento existe*/

int existe(ArvoreBin a, int x) {
    if(a == NULL) {
        return 0;
    }else if(a->chave == x) {
        return 1;
    }else {
        int ret = existe(a->esq,x);
        if(ret == 1) {
            return 1;
        }
        return existe(a->dir,x);
    }
}

ArvoreBin inserir(ArvoreBin a, char lado,int tipo, int chave, void* objeto) {
    if(a == NULL) {
        a = (ArvoreBin) malloc(sizeof(ArvoreBin));
        a->chave = chave;
        a->tipo = tipo;
        a->obj = objeto;
        a->esq = NULL;
        a->dir = NULL;
        printf("%d", a->chave);
        return a;
    }
    else {
        if(a->dir==NULL && a->esq==NULL && lado=='e')
            a->esq = inserir(a->esq, lado, chave,tipo, objeto);
        else {
            if (a->dir == NULL && a->esq == NULL && lado == 'd')
                a->dir = inserir(a->dir, lado, chave, tipo, objeto);
            else {
                a->esq = inserir(a->esq, lado, chave, tipo, objeto);
                a->dir = inserir(a->dir, lado, chave, tipo, objeto);

            }
        }
    }
    return a;
}

void imprimirNivel(ArvoreBin a,int cont, int nivel){
    if(a!=NULL) {
        if(cont == nivel)
            printf("%d ",a->chave);
        else {
            imprimirNivel(a->esq,cont+1,nivel);
            imprimirNivel(a->dir,cont+1,nivel);
        }
    }
}

void imprimirLargura(ArvoreBin a,int nivel) {
    if(a != NULL) {
        int h =  altura(a);
        if(nivel<h) {
            imprimirNivel(a,0,nivel);
            printf("\n");
            imprimirLargura(a,nivel+1);
        }
    }
}

int BuscarTipo(ArvoreBin a, int chave) {
    int result = existe(a, chave);
    if(result == 0)
        printf("Elemento não existe\n");
    else
    if(a->chave == chave)
        return a->tipo;
    else {
        int aux = 0;
        aux = BuscarTipo(a->esq,chave);
        if(aux!=0)
            return aux;
        else
            return BuscarTipo(a->dir,chave);
    }
}

void* Buscar(ArvoreBin a, int chave) {
    int result = existe(a, chave);
    if(result == 0)
        printf("Elemento não existe\n");
    else
    if(a->chave == chave)
        return a->obj;
    else {
        void *aux = Buscar(a->esq,chave);
        if(aux!=NULL)
            return aux;
        else
            return Buscar(a->dir,chave);
    }
}