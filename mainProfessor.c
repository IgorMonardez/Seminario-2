#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct professores{
    char nome[100];
    float salario;
}Professores;

void imprimir(void* pVoid) {
    Professores *p;
    p = (Professores*) pVoid;
    printf("Nome - %s\n",p->nome);
    printf("Salario - %.2f\n",p->salario);
}

Professores *AddProfessor(char nome[100],float salario) {
    Professores *p = (Professores*)malloc(sizeof(Professores));
    strcpy(p->nome,nome);
    p->salario = salario;
    return p;
}

ArvoreBin inserirElemento(ArvoreBin a, char lado, int chave, int noPai){
    int matricula;
    double salario;
    char nome[100];
    fflush(stdin);
    printf("> Digite o nome do professor: ");
    scanf(" %s",nome);
    fflush(stdin);
    printf("> Digite o Salario do professor: ");
    scanf("%lf", &salario);
    fflush(stdin);
    return inserir(a, lado, chave, AddProfessor(nome,salario), noPai);
}

int main() { //aluno
    ArvoreBin a = NULL;
    int resp = 0;
    while (resp!=-1){
        printf("<1>- Inserir elemento\n<2>- Verificar se elemento existe\n<3>- Buscar o elemento e imprimi-lo\n<4>- Verificar se e balanceada\n<5>- Calcular altura\n<6>- Imprimir em largura\n<7>- Sair\nresp:");
        scanf("%d",&resp);
        if (resp==1) {
            int resp2,noPai;
            printf("> Digite a chave do elemento:");
            scanf("%d", &resp2);
            char lado;
            printf("> De qual no pai: ");
            scanf("%d",&noPai);
            if(existe(a,noPai)||noPai==-1) {
                if(noPai!=-1) {
                    printf("> Qual lado (d-direito, e- esquerdo): ");
                    scanf(" %c", &lado);
                    fflush(stdin);
                }
                    a = inserirElemento(a, lado, resp2, noPai);
            }
            else
                printf("No pai nao existe!\n");
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
            Professores *professores;
            professores = (struct professores *)Buscar(a,resp2);
            if(professores!=NULL)
                imprimir(professores);
            else
                printf("Professor nao existe!\n");
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
            a = Destruir(a);
        }
    }
    return 0;
}