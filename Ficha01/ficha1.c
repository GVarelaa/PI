//            1

// 1 - Output é 12 16

// 2 - Output é 0 (número aleatório)

// 3 - Output é A 65, B 66 2 50, b 98

// 4 - Output é 100 200


//             2

// 1 - Output é 3 5

// 2 - Output é 11 66

// 3 - Output é _#_#_#_#_#_#_#_#_#_#

// 4 - Output é 1, 01, 11, 001, 101, 011, 111, 0001, 1001, 0101, 1101, 0011 ...


//				3

// 1

#include <stdio.h>
#include <math.h>

void quadrado (int x) {
	int i;
	for (i=0; i < x; i++){
		printf("#####\n");
	}
}

void quadrado2 (int x) {
	int i,j;
	for (j=0; j < x; j++){
		for (i=0; i < x; i++){
			putchar('#');
		}
		putchar('\n');
	}
}

void linhaPar (int x){
	int i;
	for(i=0; i<x; i++){
		if (i%2 == 0){
			putchar('#');
		}
		else {
			putchar('_');
		}
	}
}

void linhaImpar (int x){
	int i;
	for(i=0; i<x; i++){
		if (i%2 == 0){
			putchar('_');
		}
		else {
			putchar('#');
		}
	}
}

void xadrez (int x){
	int j;
	for (j=0; j < x; j++){
	if (j%2 == 0){
		linhaPar (x);
	}
	else{
		linhaImpar (x);
	}
	putchar('\n');
	}
}

void replicate (int n, char c) {
	int i;

	for (i=0; i<n; i++){
		putchar(c);
	}
}


int circulo (int r) {
	int linha, coluna, contador=0;

	for (linha = 1; linha <= 2*r+1; linha++){

		for (coluna = 1; coluna <= 2*r+1; coluna++){
			if (pow(linha-r-1,2) + pow(coluna-r-1,2) <= pow (r,2)){
				putchar ('#');
				contador++;
			}
			else{
				putchar (' ');
			}
		}
		putchar ('\n');
	}
	return contador;
}



int main() {
	printf("%d\n", circulo(10));
	return 0;
}	







