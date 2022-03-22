#include <stdio.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

//1
void libertaLista (Palavras l){
    Palavras temp;
    if(l==NULL) return;
    while(l!=NULL){
        temp = l;
        free(temp);
        l=l->prox;
    }
}

//2
int checkWord(Palavras l, char *s){
    int r = 0;
    while (l!=NULL && r == 0){
        if(!strcmp(s, l->palavra)) r = 1;
    }
    return r;
}

int quantasP (Palavras l){
    int r=0, length = 0;
    while(l!=NULL){
        if(!checkWord(l->prox,l->palavra)) r++;
        l=l->prox;
    }
    return r;   
}

//3
void listaPal (Palavras l){
    while(l!=NULL){
        printf("Palavra : %s | Ocorrencias : %d\n", l->palavra, l->ocorr);
        l=l->prox;
    }  
}

//4
char * ultima (Palavras l){
    if(l==NULL) return NULL;
    while (l->prox!=NULL)
    {
        l=l->prox;
    }
    return l->palavra;
}

//5
Palavras acrescentaInicio (Palavras l, char *p){
    Palavras newNode = malloc(sizeof(struct celula));
    if(newNode==NULL) return NULL;
    newNode->palavra = p;
    newNode->ocorr = 1;
    newNode->prox = l;
    return newNode;
}

//6
Palavras acrescentaFim (Palavras l, char *p){
    Palavras r = l;
    Palavras newNode = malloc(sizeof(struct celula));
    newNode->palavra = p;
    newNode->ocorr = 1;
    newNode->prox = NULL;
    if(l==NULL) return newNode;
    while(l->prox!=NULL){
        l=l->prox;
    }
    l->prox = newNode;
    return r;
}

//7
Palavras acrescenta (Palavras l, char *p){
    Palavras temp = l;
    while(temp!=NULL){
        if(!strcmp(temp->palavra, p)){
            temp->ocorr++;
            return l;
        }
        temp=temp->prox;
    }
    
    Palavras temp2 = l;
    Palavras prev;
    Palavras newNode = malloc(sizeof(struct celula));
    newNode->palavra = p;
    newNode->ocorr =1 ;

    while(temp2 != NULL){
        if(strcmp(temp2->palavra, p)<0){
            prev = temp2;
            prev->prox = newNode;
            newNode->prox = temp2;
            return l;
        }
        temp2=temp2->prox;
    }
    //acrescentar no fim
    return l;
}

//8