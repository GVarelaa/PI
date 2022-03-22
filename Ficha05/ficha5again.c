#include <math.h>
#include <string.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int nota (Aluno a){
    float miniT = 0;
    float notaR;
    for(int i = 0; i<6; i++){
        miniT += a.miniT[i];
    }
    notaR = miniT/2 + 0.7*a.teste;
    return(round(notaR));
}

int procuraNum (int num, Aluno t[], int N){
    int meio, l = 0, r = N-1;

    while(l<=r){
        meio = (l+r)/2;
        if(t[meio].numero == num) return meio;
        else if (t[meio].numero < num) l = meio +1;
        else r = meio-1;
    }
    return -1;
}

void swap (Aluno *x, Aluno *y){
    Aluno z;
    z = *x; *x=*y; *y=z;
}

void ordenaPorNum (Aluno t [], int N){ //selSort
    int j, i;
    for(j=0; j<N-1;j++){
        for(i=j+1; i<N-1; i++){
            if(t[i].numero < t[j].numero) swap(&t[i], &t[j]); 
        }
    }
}



void criaIndPorNum (Aluno t [], int N, int ind[]){
    
    for(int x = 0; x<N-1; x++){
        ind[x] = x;
    }

    int j, i;
    for(j=0; j<N-1;j++){
        for(i=j+1; i<N-1; i++){
            if(t[ind[i]].numero < t[ind[j]].numero) swap(&ind[i], &ind[j]); 
        }
    }
}


void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f %d\n", a->teste, nota(*a));
}

void imprimeTurma (int ind[], Aluno t[], int N){
    int i;
    for(i=0; i<N; i++){
        imprimeAluno(&t[ind[i]]);
    }
}

int procuraNumInd (int num, int ind[], Aluno t[], int N){
    int meio, l = 0, r = N-1;

    while(l<=r){
        meio = (l+r)/2;
        if(t[ind[meio]].numero == num) return meio;
        else if (t[ind[meio]].numero < num) l = meio +1;
        else r = meio-1;
    }
    return -1;
}

void criaIndPorNome (Aluno t [], int N, int ind[]){
    for(int x = 0; x<N-1; x++){
        ind[x] = x;
    }

    int j, i;
    for(j=0; j<N-1;j++){
        for(i=j+1; i<N-1; i++){
            if(strcmp(&t[ind[i]].nome, &t[ind[j]].nome)>0) swap(&ind[i], &ind[j]); 
        }
    }   
}