#include <stdio.h>
#include <string.h>

// 1

void maiorElem() {
	int i, maior;

	assert (scanf("%d", &i) == 1);
	if (i==0){
		printf("Não é possivel executar\n");
	}
	else {
		maior = i;
	}

	while (i!=0){
		assert (scanf("%d", &i) == 1);
		if (i > maior){
			maior = i;
		}
	}
	printf("%d\n",maior);
}

// 2 

void media() {
	int i, media;

	assert (scanf("%d",&i) == 1);

	if (i == 0){
		printf("Média é 0");
	}
	else {
		media = i;
	}

	while (i != 0) {
		assert (scanf("%d",&i) == 1);
		media = media + i;
	}
	printf ("Média é %.2lf\n", media/2.0);
}

// 3

void sndMaior() {

	int fst,snd,i;

	assert (scanf ("%d", &i) == 1);

	if (i==0) {
		printf("O segundo maior é 0\n");
		return ;
	}
	else {
		fst = i;
	}

	assert (scanf ("%d", &i) == 1);

	if (i==0) {
		if (fst > i) {
			printf("O segundo maior é %d\n", i);
			return ;
		}
		else {
			printf("O segundo maior é %d\n", fst);
			return ;
		}
	}
	else {
		snd = i;
	}

	while (i != 0) {
		assert (scanf ("%d", &i) == 1);

		if (i>=fst && i<=snd) {
			fst = i;
		}
		else if (i>=snd && i<=fst) {
			snd = i;
		}
		else if (i >= fst && i >= snd && fst >= snd) {
			snd = i;
		}
		else if (i >= fst && i >= snd && fst <= snd) {
		 	fst = i;
		}
	}

	if (fst > snd) {
		printf("O segundo maior é %d\n", snd);
	}
	else {
		printf("O segundo maior é %d\n", fst);
	}
}




// 4
int bitsUm (unsigned int n){
	int x = 0;
	if (n == 0){
		return 0;
	}
	else{
		while (n > 1){
		if (n%2 != 0){
			x++;
		}
		n = n/2;
	}
	return (x+1);
	}
}

// 5
	
int trailingZ (unsigned int n) {

	int x = 0;

	if (n==0) {
		return 0;
	}
	else {
		while (n>1) {
			if (n%2 == 0) {
				x++;	
			}
			n = n/2;
		}
		return x;
	}
}


// 6
int qDig (unsigned int n){
	int x = 0;
	if (n == 0){
		return 1;
	}
	else{
		while (n >= 1){
			x++;
			n = n/10;
		}
		return x;
	}
}


//7
char *mystrcat (char s1[], char s2[]) {
    int i, j;
    for (i = 0; s1[i] != '\0'; i++);

    for (j = 0; s2[j] != '\0'; j++){
        s1[j+i] = s2[j];
    }

    s1[j+i] = '\0';

    return s1;
}

//8
char *mystrcpy (char *dest, char source[]){
    int l = strlen (source), i;

    for (i = 0; i < l; i++){
        dest[i] = source [i];
    }

    dest[i] = '\0';
    return dest;
}

//9
/*int mystrcmp (char s1[], char s2[]){
    int l1 = strlen (s1), l2 = strlen (s2), i, r;
    
    if (l1 == l2) {
        for (i = 0; i<l1 && s1[i]==s2[i]; i++);
        if (i == l1) return 0;

        for (i = 0; i<l1; i++){
            if (s1[i]<s2[i]) return -1;
            if (s1[i]>s2[i]) break;
        }

        return 1;
    }
    else {
        if (l1>l2) r=l2;
        r=l1;
        for (i = 0; i<r; i++){
            if (s1[i]<s2[i]) return -1;
            if (s1[i]>s2[i]) break;
        }
        if (l1<l2 && i == r) return -1;

        return 1;
    }

}*/

int mystrcmp (char s1[], char s2[]){
    int i;
    for (i = 0; s1[i]==s2[i] && s1[i] != '\0'; i++);
    return (s1[i] - s2[i]);
}

//10

char *mystrstr (char s1[], char s2[]){
    int len1 = strlen (s1), len2 = strlen (s2), i, j;
    
    if (s2[0] == '\0') return s1;    
    
    if (len2>len1) return NULL;

    for (i = 0; i <= len1; i++){
        if (s1[i] == s2[0]){
            for (j = 0; j < len2 && s1[i+j]==s2[j]; j++);
            if (j==len2) return &s1[i];
        }
    }
    return NULL;
}

//11
void strrev (char s[]){
    int l1 = strlen (s), i, temp;

    for (i = 0; i < l1/2; i++){
        temp = s[i];
        s[i] = s[l1-1-i];
        s[l1-1-i] = temp;
    }
    
}

//12
void strnoV (char s[]){
    int l1 = strlen (s), i, j=0;
    char *s1;

    while (*s != '\0'){
        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' || *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U') {
            s1 = s;
            for (; *s1 != '\0'; s1++){
                *s1 = *(s1+1);
            }
        }
        else {
            s++;    
        }
    }
}

//13

void tiraElem (char s[]){
    while (*s != '\0'){
        *s = *(s+1);
        s++;
    }
}

void truncW (char t[], int n){

    int i, wordLen = 0;

    while (*t != '\0'){

        if (*t == ' '){
            t++; wordLen = 0;   
        }
        else {
            wordLen++;
            if (wordLen > n) tiraElem (t);
            else t++;
        }
    }
}

//14
char charMaisfreq (char s[]){
    if (*s == '')
}



int main(){

    char str1[20] = "Ola", str2[10] = " tas bem?";

    printf ("%ld\n", strlen (str1));

    return 0;
}