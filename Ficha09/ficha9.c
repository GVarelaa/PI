#include <stdio.h>
#include <math.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

//1
//a
int altura (ABin a){
    int r1 = 0, r2 = 0;
    if(a==NULL) return 0;

    r1 = 1 + altura(a->esq);
    r2 = 1 + altura(a->dir);
    if(r1>r2) return r1;
    else return r2;
}

//b
int nFolhas (ABin a){
    int r = 0;
    if(a==NULL) return r;

    if(a->esq == NULL && a->dir==NULL) r++;
    r += nFolhas(a->esq) + nFolhas(a->dir);

    return r;
}

//c
ABin maisEsquerda (ABin a){
    ABin ant;

    if(a==NULL) return NULL;    

    while(a != NULL){
        ant = a;
        a=a->esq;
    }
    return ant;
}

//d
void imprimeNivel (ABin a, int l){
    if(a==NULL) return;
    
    if(l==0) printf("%d ", a->valor);
    else{
        imprimeNivel(a->esq, l-1);
        imprimeNivel(a->dir, l-1);
    }
}


//e
int procuraE (ABin a, int x){
    int r = 0;
    if(a == NULL) return r;

    if(x==a->valor) r=1;
    else{
        r = procuraE(a->esq, x) || procuraE(a->dir, x);
    }
    return r;
}

//f
struct nodo *procura (ABin a, int x){

    while(a!=NULL && a->valor!=x){
        if(x < a->valor) a = a->esq;
        else a = a->dir;       
    }

    return a;
}

//g
int nivel (ABin a, int x){
    int r = 0;

    while(a != NULL && a->valor != x){
        r++;
        if(x < a->valor) a = a->esq;
        else a = a->dir;
    }

    if(a==NULL) return -1;
    else return r; 

}

//h
void imprimeAte (ABin a, int x){
    while(a!=NULL && x < a->valor){
        a=a->esq;
    }

    if(a==NULL) return;

    imprimeAte(a->esq, x);
    printf("%d ", a->valor);
    imprimeAte(a->dir, x);

}

void imprimeAteProf (ABin a, int x){
    if(a){
        if(x<a->valor) imprimeAteProf(a->esq, x);
        else if(x==a->valor){
            imprimeAteProf(a->esq, x);
            printf("%d ", a->valor);
        }
        else{
            imprimeAteProf(a->esq, x);
            printf("%d ", a->valor);
            imprimeAteProf(a->dir, x);
        }
    }
}