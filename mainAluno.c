#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alunos{
 int matriculaAluno;
 char nomeAluno[100];
 char curso[20];
 int anoIngresso;
}Alunos;

void imprimir(void* pVoid) {
    Alunos *a;
    a = (Alunos*) pVoid;
    printf("Matricula - %d\n",a->matriculaAluno);
    printf("Nome - %s\n",a->nomeAluno);
    printf("Curso - %s\n",a->curso);
    printf("Ano Ingresso - %d\n",a->anoIngresso);
}

Alunos *AddAluno(int matricula,char nomeAluno[100],char curso[20], int anoIngresso) {
    Alunos *a = (Alunos*)malloc(sizeof(Alunos));
    a->matriculaAluno = matricula;
    strcpy(a->nomeAluno,nomeAluno);
    strcpy(a->curso,curso);
    a->anoIngresso = anoIngresso;
    return a;
}

int main() { //aluno
    ArvoreBin a = NULL;
    int resp = 0;
    while (resp!=-1){
        printf("<1>- Inserir elemento\n<2>- Verificar se elemento existe\n<3>- Buscar o elemento e imprimi-lo\n<4>- Verificar se e balanceada\n<5>- Calcular altura\n<6>- Imprimir em largura\n<7>- Sair\nresp:");
        scanf("%d",&resp);
        if (resp==1){
            int resp2,noPai;
            printf("Digite a chave do elemento:");
            scanf("%d", &resp2);
            char lado;
            if(a!=NULL){
                printf("Qual lado (d-direito, e- esquerdo): ");
                scanf(" %c",&lado);
                fflush(stdin);
                printf("De qual nó pai (chave): ");
                scanf("%d",&noPai);
            }
            char curso[20], nome[100];
            int matriculaAluno, anoIngresso;
            printf("Digite a matricula do aluno:");
            scanf("%d", &matriculaAluno);
            fflush(stdin);
            printf("Digite o nome do aluno: ");
            scanf(" %s", nome);
            fflush(stdin);
            printf("Digite o curso do aluno: ");
            scanf(" %s", curso);
            fflush(stdin);
            printf("Digite o ano de ingresso do aluno: ");
            scanf("%d", &anoIngresso);
            a = inserir(a,lado,resp2,AddAluno(matriculaAluno,nome,curso,anoIngresso),noPai);
        }
        if(resp==2){
            int resp2;
            printf("Digite o elemento a ser verificado:");
            scanf("%d", &resp2);
            if(existe(a,resp2))
                printf("O elementos %d existe\n",resp2);
            else
                printf("O elementos %d nao existe\n",resp2);
        }
        if(resp==3){
            int resp2;
            printf("Digite o elemento a ser buscado:");
            scanf("%d", &resp2);
            Alunos *alunos;
            alunos = Buscar(a,resp2);
            imprimir(alunos);
        }
        if(resp==4){
            if(balanceamento(a))
                printf("A arvore esta balanceada\n");
            else
                printf("A arvore nao esta balanceada\n");
        }
        if(resp==5){
            printf("Altura- %d\n",altura(a));
        }
        if(resp==6){
            imprimirLargura(a,0);
        }
        if(resp==7){
            resp = -1;
        }

    }
    return 0;
}