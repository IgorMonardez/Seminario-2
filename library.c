#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct arvoreABB {
    void* chave;
    struct arvoreABB *dir,*esq;
};

int AddAluno(int curso,int anoIngresso)


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

int Existe(ArvoreABB a, void *x){
	if(a == NULL){
		return 0;
	}else if(a == x) {
		return 1;
	}else {
		int ret = Existe(a->esq,x);
		if(ret == 1) {
			return 1;
		}
		return Existe(a->dir,x);
	}
}