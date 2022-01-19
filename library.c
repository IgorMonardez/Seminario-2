#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct alunos{
    int curso;
    int anoIngresso;
};

struct professores{
    float salario;
    int anoIngresso;
};

struct arvoreBin {
    int chave;
    int tipo;
    void *obj;
    struct arvoreBin *dir,*esq;
};

int AddAluno(int curso,int anoIngresso) {

}

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

ArvoreBin inserir(ArvoreBin a, char lado, int chave, void* objeto) {
    if(a == NULL) {
        a = (ArvoreBin*) malloc(sizeof(ArvoreBin));
        a->chave = chave;
        a->obj = objeto;
        a->esq = NULL;
        a->dir = NULL;
    }else{
        if(a->dir==NULL && a->esq==NULL && lado=='e')
            a->esq = inserir(a, lado, chave, objeto);
        else if(a->dir==NULL && a->esq==NULL && lado=='d')
            a->dir = inserir(a, lado, chave, objeto);
        else{
            a->esq = inserir(a, lado, chave, objeto);
            a->dir = inserir(a, lado, chave, objeto);
        }
    }
    return a;
}

void ImprimirNivel(ArvoreBin a,int cont, int nivel){
    if(a!=NULL) {
        if(cont == nivel)
            printf("%d ",a->chave);
        else {
            ImprimirNivel(a->esq,cont+1,nivel);
            ImprimirNivel(a->dir,cont+1,nivel);
        }
    }
}

void imprimirLargura(ArvoreBin a,int nivel) {
    if(a != NULL) {
        int h =  altura(a);
        if(nivel<h) {
            ImprimirNivel(a,0,nivel);
            printf("\n");
            imprimirLargura(a,nivel+1);
        }
    }
}

void* Buscar(ArvoreBin a, int chave){
    int result = existe(a, chave);
    if(result == 0)
        printf("Elemento não existe\n");
    else
        if(a->chave == chave)
            return a->obj;
        else {
            return Buscar(a->esq,chave);
            return Buscar(a->dir,chave);
        }
}