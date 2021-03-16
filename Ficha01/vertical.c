#include <stdio.h>

void triangulo (int x){
	int i,j,k;
	for (i=1; i<=x; i++){
		for(j=0; j<i;j++){
			putchar('#');
		}
		putchar('\n');
	}
	for (;x>0;x--){
		k = x;
		for(;k>0;k--){
			putchar('#');
		}
		putchar('\n');
	}
}



