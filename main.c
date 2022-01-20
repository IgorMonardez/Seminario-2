#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alunos {
    char nome[100];
    int curso;
    int anoIngresso;
}Alunos;

typedef struct professores{
    char nome[100];
    float salario;
    int anoIngresso;
}Professores;

void imprimir(void* objeto,int tipo) {
    switch(tipo) {
    case 1 : {
        Alunos *a= (Alunos*)malloc(sizeof(Alunos));
        a = objeto;
        printf("Curso- %d\n",a->curso);
        printf("Ano de ingresso - %d\n",a->anoIngresso);
    }
    break;
    case 2: {
        Professores *p = (Professores*) malloc(sizeof(Professores));
        p = objeto;
        printf("Salário- %.2f",p->salario);
        printf("Ano de ingresso- %d",p->anoIngresso);
    }
    break;
    }
}

Alunos *AddAluno(char nome[100], int curso, int anoIngresso) {
    struct alunos *a = (struct alunos*)malloc(sizeof(struct alunos));
    strcpy(nome,a->nome);
    a->curso = curso;
    a->anoIngresso = anoIngresso;
    return a;
}



int main() { //aluno
    ArvoreBin a = NULL;
    int resp = 0;
    while (resp!=-1){
        printf("<1>- inserir elemento\n<2>- verificar se elemento existe\n<3>- Imprimir a heap\n<4>- verificar se é balanceada\n<5>- calcular altura\n<6>- IMprimir em largura\n<7>- sair\nresp: ");
        scanf("%d",&resp);
        if (resp==1){
            int resp2,tipo;
            printf("Digite a chave do elemento: ");
            scanf("%d", &resp2);
            printf("Digite o tipo do elemento: ");
            scanf("%d", &tipo);
            if(tipo == 1) {
                    Alunos *alunos = (Alunos*)malloc(sizeof(Alunos));
                    char lado,nome[100];
                    printf("Qual lado: ");
                    scanf("%c ",&lado);
                    printf("Nome do aluno: ");
                    scanf("%s",&nome);
                    int curso, anoIngresso;
                    printf("Digite o código do curso do aluno: ");
                    scanf("%d", &curso);
                    printf("Digite o ano de ingresso do aluno: ");
                    scanf("%d", &anoIngresso);
                    alunos = AddAluno(nome,curso,anoIngresso);
                    inserir(a,lado,tipo,resp2,alunos);
                }
        }
        if(resp==2){
            int resp2;
            printf("Digite o elemento a ser verificado: ");
            scanf("%d", &resp2);
        }
        if(resp==3){
            int resp2;
            printf("Digite o elemento a ser buscado: ");
            scanf("%d", &resp2);
        }
        if(resp==4){

        }
        if(resp==5){

        }
        if(resp==6){

        }
        if(resp==7){
            resp = -1;
        }

    }
    return 0;
}