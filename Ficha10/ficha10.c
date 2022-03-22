#include <stdio.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

//1
ABin removeMenor (ABin *a){
    while((*a)->esq){
        a=&((*a)->esq);
    }

    ABin aux;
    aux = *a;
    *a = (*a)->dir;
    aux->dir = NULL;

    return aux;
}

//2
void removeRaiz (ABin *a){ //vamos buscar o menor elemento da direita
    if((*a)->dir ==NULL){
        ABin temp = *a;
        (*a) = (*a)->esq;

        free(temp);
    }
    else{
        ABin menor = removeMenor(&(*a)->dir);
        (*a)->valor = menor->valor;

        free(menor);
    }
}

//3
int removeElem (ABin *a, int x){
    int ret = -1;

    while(*a && (*a)->valor!=x){
        if((*a)->valor > x) a=&((*a)->esq);
        else a=&((*a)->dir);
    }

    if(*a == NULL) return 1;

    removeRaiz(a);
    return 0;
}

//4 recursivamente
void promoveMenor (ABin *a){ //encontrar apontador para ultimo node e rodar. De seguida, voltar pra tras e repetir ate chegar a raiz.

}