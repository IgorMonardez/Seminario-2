#include "library.h"
#include <stdio.h>
#include <stdlib.h>

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
            Alunos alunos;
            char lado;
            lado = getc(stdin);
            int curso, anoIngresso;
            printf("Digite o código do curso do aluno: ");
            scanf("%d", &alunos.curso);
            printf("Digite o ano de ingresso do aluno: ");
            scanf("%d", &alunos.anoIngresso);
            inserir(a,lado,tipo,resp2,alunos);
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