#include <stdlib.h>
#define Max 100

typedef struct staticStack {
    int sp;
    int values [Max];
} STACK, *SStack;

typedef struct staticQueue {
    int front;
    int length;
    int values [Max];
} QUEUE, *SQueue;

// 1
// A
void SinitStack (SStack s){
    s->sp = 0;
}

int SisEmpty (SStack s){
    return(s->sp ==0);
}

int Spush (SStack s, int x){
    int r =0;
    if(s->sp=Max) r=1;
    else{
        s->values[s->sp++] = x;
        //s->sp++;
    }
    return r;
} 

int Spop (SStack s, int *x){
    int r = 0;
    if(s->sp==0) r=1;
    else{
        *x = s->values[s->sp];
        s->sp--;
    }
    return r;
}

int Stop (SStack s, int *x){
    int r = 0;
    if(s->sp==0) r=1;
    else{
        *x = s->values[s->sp];
    }
    return r;    
}

//////////

void SinitQueue (SQueue q){
    q->length = 0;
    q->front = 0;
}

int SisEmptyQ (SQueue q){
    return(q->length==0);
}

int Senqueue (SQueue q, int x){
    int r= 0;
    if(q->length == Max) r=1;
    else{
        q->values[(q->front+q->length)%Max] = x;
        q->length++;
    }
    return r;
}


int Sdequeue (SQueue q, int *x){ // em vez de fazer shift, avancar o front (s->front+s->length) %MAx
    int r= 0;
    if(q->length==0) r=1;
    else{
        *x=q->values[q->front];
        q->front = (q->front+1)%Max;
    }
    return r;
}

int Sfront (SQueue q, int *x){
    int r= 0;
    if(q->length==0) r=1;   
    else{
        *x=q->front;
    }
    return r;
}

typedef struct dinStack {
    int size; 
    int sp;
    int *values;
} *DStack;

void DinitStack (DStack s){
    s->sp=0;
    s->size = 1; 
    s->values = (int *) malloc(s->size * sizeof(int));
}

int DisEmpty (DStack s){
    return(s->sp==0);
}

int Dpush (DStack s, int x){ //usar dupStack
    int r =0;
    if(s->sp=s->size){
        int *v = (int *) malloc(2*s->size*sizeof(int));
        for(int i = 0; i < s->size; i++) v[i] = s->values[i];
        free(s->values);
        s->values = v;
        s->size = 2*s->size;
        r=1;
    }
    else{
        s->values[s->sp++] = x;
        //s->sp++;
    }
    return r;
}

/*
int Dpush (DStack s, int x){ //usar dupStack
    int r =0;
    if(s->sp==s->size){
        r = dupStack(s);
    }
    if(r==0){
        s->values[s->sp] = x;
        s->sp++;
    }
    return r;
}
*/

