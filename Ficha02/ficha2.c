#include <stdio.h>

// 1
float multInt1 (int n, float m) {
	float r;

	for (r = 0; n > 0; n--) {
		r += m;
	}
	return r;	
}

// 1 recursivamente
float multInt1R(int n, float m) {
	if (n == 0) return 0;
	else {
		return (m + multInt1R (n-1, m));
	}
}



// 2

float multInt2 (int n, float m) {

	float r = 0;

	while (n >= 1) {
		
		if (n&1 == 1) { // operaçao bit a bit com o bit menos significativo (lado direito)
			r += m;
		}

		n = n>>1; //shift para a direita de uma unidade. algoritmo de implementar a divisao por 2 muito eficiente
		m = m+m;
	}

	return r;
}

float multInt3 (int n, float m, int * c1) {

	float r = 0;
	*count = 0;

	while (n >= 1) {
		
		if (n%2 == 1) {
			r += m;
			*c1 += 1;
		}

		n = n/2;
		m = m+m;
		*c1 += 1;
	}

	return r;	
}

// 3

int mdc1 (int a, int b) {

	int maior, menor, mdc;

	if (a > b) {
		maior = a;
		menor = b;
	}
	else {
		maior = b;
		menor = a;
	}

	for (int i = 1; i <= menor; i++) {
		if (menor%i == 0 && maior%i == 0) {
			mdc = i;
		}
	}
	return mdc;

}

// 4

int mdc2 (int a, int b) {

	while (a!=0 && b!=0) {
		if (a>b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}

	if (a == 0){
		return b;
	} 
	else return a;
}

int mdc3 (int a, int b, int * c1) {

	while (a!=0 && b!=0) {
		if (a>b) {
			a -= b;
		}
		else {
			b -= a;
		}
		*c1 += 1;
	}

	if (a == 0){
		return b;
	} 
	else return a;
}


// 5
int mdc4 (int a, int b, int * c2) {

	while (a!=0 && b!=0) {
		if (a>b) {
			a %= b;
		}
		else {
			b %= a;
		}
		*c2 += 1;
	}

	if (a == 0){
		return b;
	} 
	else return a;
}

//6
//a

int fib1 (int n) {

	if (n==1 || n==0) {
		return 1;
	}
	else {
		return fib1 (n-1) + fib1 (n-2);
	}

}

//b

int fib2 (int n) {

	int aux1 = 1, aux2 = 1, temp;

	for (int i = 3; i<=n; i++) {
		temp = aux2;
		aux2 += aux1;
		aux1 = temp;
	}

	return aux2;

}



int main()
{  int a,b,r1,r2,r3,r4, 
       c1=0, c2=0;
   float f, f1, f2, f3;
    
   printf ("Introduza dois números para input das funções de multiplicação: ");
   scanf ("%d", &a); scanf ("%f", &f);
   f1 = multInt1 (a,f);
   f2 = multInt2 (a,f);
   f3 = multInt3 (a,f, &c1);
   printf ("Resultados das multiplicações: %f, %f, %f (%d)\n", f1, f2, f3, c1);
   
   printf ("Introduza dois números para input das funções de multiplicaç~ão: ");
   scanf ("%d", &a); scanf ("%d", &b);

   c1 = 0;

   r1 = mdc1 (a,b);
   r2 = mdc2 (a,b);
   r3 = mdc3 (a,b, &c1);
   r4 = mdc4 (a,b, &c2);
   printf ("Resultados do mdc: %d, %d, %d (%d), %d (%d)\n", r1, r2, r3, c1, r4, c2);
   
   printf ("Introduza um número para calcular o fib: ");
   scanf ("%d", &a);
   printf ("FastFib (%d) = %d \n", a, fib2 (a));
   printf ("Fib (%d) = %d \n", a, fib1 (a));
   
   return 0;
}
