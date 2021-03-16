#include <stdio.h>

void triangulo (int x){
	int k, i = 1, p;
	for (x; x > 0; x--){
		k = x;
		for (k = k-1; k > 0; k--){
			putchar(' ');
		}
		for (p = i; p > 0; p--){
			putchar('#');
		}
		putchar('\n');
		i = i + 2;
	}
}



