#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alunos {
    int curso;
    int anoIngresso;
}Alunos;

typedef struct professores{
    float salario;
    int anoIngresso;
}Professores;

void imprimir(void* pVoid, int tipo) {
    switch(tipo) {
        case 1 : {
            Alunos *a;
            a = (Alunos*) pVoid;
            printf("Curso - %d\n",a->curso);
            printf("Ano de ingresso - %d\n",a->anoIngresso);
        }
            break;
        case 2: {
            Professores *p;
            p = (Professores*)pVoid;
            printf("Salário- %.2f",p->salario);
            printf("Ano de ingresso- %d",p->anoIngresso);
        }
            break;
    }
}

Alunos *AddAluno(int curso, int anoIngresso) {
    Alunos *aux = (Alunos*)malloc(sizeof(Alunos));
    aux->curso = curso;
    aux->anoIngresso = anoIngresso;
    return aux;
}



int main() { //aluno
    ArvoreBin a = NULL;
    int resp = 0;
    while (resp!=-1){
        printf("<1>- Inserir elemento\n<2>- Verificar se elemento existe\n<3>- Buscar o elemento e imprimi-lo\n<4>- Verificar se e balanceada\n<5>- Calcular altura\n<6>- Imprimir em largura\n<7>- Sair\nresp:");
        scanf("%d",&resp);
        if (resp==1){
            int resp2,tipo;
            printf("Digite a chave do elemento:");
            scanf("%d", &resp2);
            printf("Digite o tipo do elemento:");
            scanf("%d", &tipo);
            if(tipo == 1) {
                char lado;
                if(a!=NULL){
                    printf("Qual lado (d-direito, e- esquerdo):");
                    scanf(" %c",&lado);
                    fflush(stdin);
                }
                int curso, anoIngresso;
                printf("Digite o codigo do curso do aluno:");
                scanf("%d", &curso);
                printf("Digite o ano de ingresso do aluno:");
                scanf("%d", &anoIngresso);
                a = inserir(a,lado,tipo,resp2,AddAluno(curso, anoIngresso));
            }
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
            int i = BuscarTipo(a, resp2);
            if(i == 1) {
                Alunos *alunos;
                alunos = Buscar(a,resp2);
                imprimir(alunos, i);
            }
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