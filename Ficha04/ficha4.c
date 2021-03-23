#include <stdio.h>
#include <string.h>

// 1
int contaVogais (char *s){
	int r;

	for (r=0; *s != '\0'; s++){
		if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' || *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U'){
		r++;
		}
	}
	return r;
}

//2
int retiraVogaisRep (char *s){

	char *temp;
	int r = 0;

	while (*s != '\0'){
		if ((*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' || *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U') && (*(s+1) == *s)){
			for (temp = s+1; *temp != '\0'; temp++){
				*temp = *(temp+1);
			}
			r++;
		}
		else s++;
	}
	return r;	
}

int retiraVogaisRep2 (char *s){
	int n = strlen(s), r = 0, i = 0;
	char auxiliar[n] , *t;
	
	t = s;

	while (*s != '\0'){
		if ((*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' || *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U') && (*(s+1) == *s)){
			s++;
			r++;
		}
		else{
			auxiliar[i] = *s;
			s++;
			i++;
		}
	}

	auxiliar[i] = '\0';
	
	for (i = 0; auxiliar[i] != '\0'; i++){
		t[i] = auxiliar[i];
	}
	
	t[i]='\0';
	return r;
}


int main(){

	char s[40]="Estaa e umaa string coom duuuplicadoos";

	retiraVogaisRep2(s);

	printf("%s\n", s);
	return 0;
}