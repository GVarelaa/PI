#include <stdio.h>

typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; 
        r->prox = xs;
    }
    return r;
}

typedef struct {
    LInt inicio,fim;
} Queue;

typedef LInt Stack;

void initStack (Stack *s){
    //s = malloc(sizeof(struct slist));
    *s = NULL;
}

int SisEmpty (Stack s){
    return(s==NULL);
}

int push (Stack *s, int x){
    Stack aux = malloc(sizeof(struct slist));
    if(aux==NULL) return 1;

    aux->valor = x;
    aux->prox = *s;

    *s = aux;

    return 0;
}

int pop (Stack *s, int *x){
    if(SisEmpty(*s)) return 1;

    Stack aux = (*s)->prox;
    *x = (*s)->valor;

    free(*s);
    *s = aux;

    return 0;
}

int top (Stack s, int *x){
    if(s==NULL) return 1;

    *x = s->valor;

    return 0;
}

void initQueue (Queue *q){ //dequeue no inicio e enqueue no final
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty (Queue q){
    return(q.inicio==NULL);
}

int frontQ (Queue q, int *x){
    if(q.inicio==NULL) return 1;

    *x = q.inicio->valor;


    return 0;
}

int enqueue (Queue *q, int x){ // inserir no final
    LInt aux = malloc(sizeof(struct slist));

    if(aux==NULL) return 1;

    aux->valor = x;
    aux->prox = NULL;

    if(q->fim==NULL){
        q->inicio = aux;
        q->fim = aux;
    }
    else{
        q->fim->prox = aux;
        q->fim = aux;
    }

    return 0;
}

int dequeue (Queue *q, int *x){ // tirar no inicio

}
