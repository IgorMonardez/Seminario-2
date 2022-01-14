#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct arvoreABB {
    void* chave;
    struct arvore *dir,*esq;
}ArvoreABB;

int altura(ArvoreABB *a) {
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

int balanceamento(ArvoreABB *a) {
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
            return balanceamento(a->dir)
        }
    }
}