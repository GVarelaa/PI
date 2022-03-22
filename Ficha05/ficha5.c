#include <math.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int nota (Aluno a){
    int notaR = 0, miniT;
    float minisT;

    for(int i = 0; i<6; i++){
        miniT += a.miniT[i];
    }
    minisT = (((float)miniT)/12)*20;

    notaR = round(minisT*0.3 + 0.7*a.teste);

    if(a.teste < 8 || minisT < 8) return 0;
    return notaR;
}

int procuraNum (int num, Aluno t[], int N){
    int meio;
    int r = N-1;
    int l = 0;
    while (l <= r){
        meio = r/2;
        if(t[meio].numero == num) return meio;
        else if (t[meio].numero < num) l = meio +1;
        else r = meio -1 ;
    }
}

void swap (Aluno *x, Aluno *y){
    Aluno z;
    z = *x; *x=*y; *y=z;
}

void ordenaPorNum (Aluno t[], int N){
    int j, i, flag = 1;
    while (flag){
        flag = 0;
        for (i=0; i<N-1; i++){
            if(t[i].numero>t[i+1].numero) {swap (&t[i], &t[i+1]); flag=1;}
        }
        N--;
    }
}

void criaIndPorNum (Aluno t[], int N, int ind[]){
 // falta
}

int procuraNumInd (int num, int ind[], Aluno t[], int N){
    int meio;
    int r = N-1;
    int l = 0;
    while (l <= r){
        meio = r/2;
        if(t[ind[meio]].numero == num) return ind[meio];
        else if (t[ind[meio]].numero < num) l = meio +1;
        else r = meio -1 ;
    }
}

void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f %d\n", a->teste, nota(*a));
}

void imprimeTurmaInd (int ind[], Aluno t[], int N){
    for(int i = 0; i<N; i++){
        imprimeAluno(&t[ind[i]]);
    }
}

int main(){
    return 0;
}