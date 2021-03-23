#include <stdio.h>
#include <math.h>

// 1
// a) 1 1 4 ... 2 2 6 ... 3 3 8 ... 4 4 10 ... 5 5 12

// b) 13

// 2
void swapM (int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//3
void swap (int v[], int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

//4
int soma (int v[], int N){
    int soma = 0;

    for (int i = 0; i<N; i++) {
        soma += v[i];
    }

    return soma;
}

int somarec (int v[], int N){
    if (N==1) return v[0];

    return v[0] + somarec (v+1, N-1);
}
//5
void inverteArray (int v[], int N) {

    for (int i = 0; i < (N/2); i++){
        swap (v, i, N-i-1);
    }
}

void inverteArray2 (int v[], int N) {

    for (int i = 0; i < (N/2); i++){
        swapM (v+i, v+N-i-1);
    }

}

int maximum (int v[], int N, int *m) {
    if (N<=0) return 1;
    else {
        *m = v[0];
        for (int i = 0; i < N; i++){
            if (v[i] >= *m) *m = v[i];
        }
        return 0;
    }
}

//7
void quadrados (int q[], int N){

    for (int i = 0; i < N; i++){
        q[i] = i * i;
    }
}

//8
//a

void pascal (int v[], int N){
    if (N==1) v[0] = 1;
    else {
        int array[N-1];
        pascal(array,N-1);
        v[0] = 1;
        v[N-1] = 1;
        for (int i = 1; i < N-1; i++){
            v[i] = array[i-1] + array[i];
        }
    }
}

//b

void replicate (char c, int n){
    for (int i = 0; i<n; i++){
        putchar(c);
    }
}


void printArray (int a[], int N){
    for (int i = 0; i < N; i++){
        printf ("%d ", a[i]);
    }
    putchar('\n');
}

void printPascal (int N){
    for (int i = 1, j = N; i<=N; i++, j--){
        int v[i];
        pascal (v, i);
        replicate (' ', j);
        printArray (v,i);
    }
}



int main (){
    int x = 3, y = 5, array[7] = {0}, soma[5] = {1,2,3,4,5};

    printPascal (7);
    return 0;
}