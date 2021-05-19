#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

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

int charQuantidade (char c, char s[]){
	int r = 0;

	for (int i = 0; s[i] != '\0'; i++){
		if (c == s[i]) r++;
	}
	return r;
}

char charMaisfreq (char s[]){
	int r = 0, t = 0;
	char c;

    if (strlen(s) == 0) return 0;
	else {
		for (int i = 0; s[i] != '\0'; i++){
			if (charQuantidade (s[i], s) > r){
				r = charQuantidade(s[i], s);
				t = i;
			}
		}
		return s[t];
	}
}

//15

int calculaConsecutivos (char s[]){
	int r = 1;

	for (int i = 0; s[i] == s[i+1]; i++, r++);
	return r;
}

int iguaisConsecutivos (char s[]){
	int r = 0;

	for (int i = 0; s[i] != '\0'; i++){
		if(calculaConsecutivos(s+i)>r) r = calculaConsecutivos(s+i);
	}
	return r;
}

//16
int pertenceCarateres (char c, char s2[], int k){
	int i, r = 0;
	for(i = 0; i<k; i++){
		if(s2[i]==c) r=1;
	}
	return r;
}

int difConsecutivos (char s[]){
	int N = strlen(s), i, x, r = 0;

	for(i=0; i<N; i++){
		x = pertenceCarateres(s[i], s, i);
		if (!x){
			r++;
		}
	}
	return r;
}

// 17

int maiorPrefixo (char s1 [], char s2 []){
	int i;
	for(i = 0; s1 && s2 && s1[i]==s2[i]; i++);
	return i;
}

// 18
int maiorSufixo (char s1 [], char s2 []){
	int N1 = strlen(s1), N2=strlen(s2), min, i, r=0;
	if(N1<N2) min = N1;
	else min = N2;

	for(i=min-1; i>=0; i--, N1--, N2--){
		if(s1[N1-1]==s2[N2-1]) r++;
		else break;
	}
	return r;
}

// 19

int checkPosterior (char s1[], char s2[], int k){
	int i, j;
	for(i=k, j=0; s1[i] == s2[j] && s1[i] && s2[j]; i++, j++);
	return i;
}

int sufPref (char s1[], char s2[]){
	int N=strlen(s1), i, j;

	for(i=0; s1[i]; i++){
		if(s1[i]==s2[0]){
			int x = checkPosterior(s1, s2, i);
			if(N==x) return (N-i);
		}
	}
	return 0;
}

// 20
int contaPal (char s[]){
	int i=0,j = 0;
	while(s[i]){
		if(s[i]!=' ' && s[i]!='\n'){
			while(s[i]!=' ' && s[i]) i++;
			j++;
		}
		else i++;
	}
	return j;
}

//21
int contaVogais (char s[]){
	int i = 0, r=0;
	while(s[i]){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i]== 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') r++;
		i++;
	}
	return r;
}

//22
int contida (char a[], char b[]){
	int i = 0, j = 0, r = 0;
	for(j = 0; a[j]; j++){
		for(i = 0; b[i]; i++){
			if(b[i]==a[j]){r++; break;}
		}
	}
	return(r==strlen(a));
}

//23
int palindorome (char s[]){
	int N = 0;
	for(N=0; s[N];N++);
	int i;
	for(i=0; s[i] == s[N-i-1] && i<N/2; i++);
	return(i==N/2);
}

//24
void shiftEsquerda(char s[]){
	int i;
	for(i = 0; s[i]; i++) s[i] = s[i+1];
}

int remRep (char x[]){
	int i = 0, r;
	while(x[i]){
		if(x[i]==x[i+1]){
			shiftEsquerda(x+i);
		} 
		else i++;
	}
	return i;
}

//25
int limpaEspacos (char t[]){
	int i=0;
	while(t[i]){
		if(t[i]==' ' && t[i]==t[i+1]) shiftEsquerda(t+i);
		else i++;
	}
	return i;
}

//26
void shiftDireita(int v[], int N){
	int i;
	for(i=N-1; i>0; i--) v[i] = v[i-1];
}

void insere (int v[], int N, int x){
	int i;
	for(i=0; v[i] && v[i]<x; i++);
	shiftDireita(v+i,N-i+1);
	v[i]=x;
}

// 27
void merge (int r [], int a[], int b[], int na, int nb){
	int i, j, nr;
	for(i = 0, j = 0, nr = 0; i<na && j<nb;){
		if(a[i]<b[j]){ 
			r[nr] = a[i];
			i++;
			nr++;
		}
		else{
			r[nr] = b[j];
			j++;
			nr++;
		}
	}
	if(i==na){
		while(j<nb){
			r[nr] = b[j];
			j++;
			nr++;
		}
	}
	else if (j == nb){
		while(i<na){
			r[nr] = a[i];
			i++;
			nr++;
		}		
	}
}

// 28
int crescente (int a[], int i, int j){
	int r = 1;
	while(i<j){
		if(a[i+1]<a[i]) r = 0;
		i++;
	}
	return r;
}

//29
void shiftEsquerdaArray(int v[], int N){
	int i;
	for(i=0; i<N; i++) v[i] = v[i+1];
}

int retiraNeg (int v[], int N){
	int i;
	for(i=0; i<N;){
		if(v[i]<0){
			shiftEsquerdaArray(v+i, N-i);
			N--;
		}
		else i++;
	}
}

// 30
int frequencia(int v[], int N){
    int i, r=0;
    if(N == 0) return 0;
    for(i=0; i<N-1 && v[i]==v[i+1]; i++) r++;
    return r+1;
}

int menosFreq (int v[], int N){ // 
    int r = frequencia(v, N), i=0, ind = 0;
    while(i<N){
        if(frequencia(v+i, N-i)<r){r = frequencia(v+i, N-i); ind = i; i += r;}
        else{i+= frequencia(v+i, N-i);}
    }
    return v[ind];
}

//31
int maisFreq (int v[], int N){
    int r = frequencia(v, N), i=0, ind = 0;
    while(i<N){
        if(frequencia(v+i, N-i)>r){r = frequencia(v+i, N-i); ind = i; i += r;}
        else{i+= frequencia(v+i, N-i);}
    }
    return v[ind];	
}

//32
int sequencia(int v[], int N){
	int i;
	for(i=0; i<N-1 && v[i]<=v[i+1]; i++);
	return i+1;
}

int maxCresc (int v[], int N){
	int r = sequencia(v,N), i=0;
	while(i<N){
		if(sequencia(v+i,N-i)>r){
			r = sequencia(v+i,N-i);
		}
		i+= sequencia(v+i,N-i);
	}
	return r;
}

// 33

void shiftEsquerdaArray(int v[], int N){
    int i;
    for(i=0; i<N; i++) v[i] = v[i+1];
}

int elimXRep(int x, int v[], int N){
    int i, r =0;
    for(i=0; i<N;){
        if(v[i]==x){ 
            shiftEsquerdaArray(v+i,N-i);
            N--;
            r++;
        }
        else i++;
    }
    return r;
}

int elimRep (int v[], int N){
    int i;
    for(i=0; i<N; i++){
        N -= elimXRep(v[i], v+i+1, N-i-1);
    }
    return N;
}

// 34
int elimRepOrd (int v[], int n){
	int i;
	for(i=0; i<n-1;){
		if(v[i]==v[i+1]){ 
			shiftEsquerdaArray(v+i+1, n-i-1);
			n--;
		}
		else i++;
	}
	return n;
}

// 35
int comunsOrd (int a[], int na, int b[], int nb){
	int r = 0, j = 0, i = 0;

	while(i<na && j<nb){
		if(a[i]==b[j]){
			r++;
			i++;
			j++;
		}
		else if(a[i]>b[j]){
			j++;
		}
		else i++;
	}

	return r;
}

// 36
int comuns (int a[], int na, int b[], int nb){
	int i, j, r=0;
	for(i=0; i<na; i++){
		for(j=0; j<nb; j++){
			if(a[i]==b[j]){
				r++;
				break;
			}
		}
	}
	return r;
}

//37
int minInd (int v[], int n){
	int r=0, i, comp;
	if(n==0) return 0;
	comp = v[0];
	for(i=1; i<n; i++){
		if(comp>v[i]){
			r=i;
			comp = v[i];
		}
	}
	return r;
}

//38
void somasAc (int v[], int Ac [], int N){
	int i, j;
	for(i = 0; i<N; i++){
		int temp = 0;
		for(j=0; j<=i; j++){
			temp += v[j];
		}
		Ac[i] = temp;
	}
}

//39
int triSup (int N, float m [N][N]){
	int r=1, i,j;

	for(i=0; i<N; i++){
		for(j=0; j<i; j++){
			if(m[i][j]!=0){
				r=0;
				break;
			}
		}
	}

	return r;
}

//40
void transposta (int N, float m [N][N]){
	int i,j;
	for(i=0; i<N; i++){
		for(j=0; j<i; j++){
			int temp;
			temp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = temp;
		}
	}
}

//42
int unionSet (int N, int v1[N], int v2[N], int r[N]){
	int len=0, i;
	for(i=0; i<N; i++){
		r[i] = v1[i] || v2[i];
		len += r[i];
	}
	return len;
}

//43
int intersectSet (int N, int v1[N], int v2[N],int r[N]){
	int len=0, i;
	for(i=0; i<N; i++){
		r[i] = v1[i] && v2[i];
		len += r[i];
	}
	return len;	
}

//44
int intersectMSet (int N, int v1[N], int v2[N],int r[N]){
	int len=0, i;
	for(i=0; i<N; i++){
		if(v1[i])
		r[i] = v1[i] && v2[i];
		len += r[i];
	}
	return len;		
}

//47
typedef enum movimento {
	Norte, Oeste, Sul, Este
} Movimento;

typedef struct posicao {
	int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N){
	int i;
	for(i=0; i<N; i++){
		if(mov[i]==Norte) inicial.y++;
		else if(mov[i]==Sul) inicial.y--;
		else if(mov[i]==Este) inicial.x++;
		else inicial.x--;
	}
	return inicial;
}

//48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
	int i, r=0;
	for(i=0; i<N; i++){
		if(inicial.y>final.y){
			mov[i] = Sul;
			inicial.y--;
		}
		else if(inicial.y<final.y){
			mov[i] = Norte;
			inicial.y++;
		}
		else if(inicial.x<final.x){
			mov[i] = Este;
			inicial.x++;
		}
		else if(inicial.x>final.x){
			mov[i] = Oeste;
			inicial.x--;
		}
		else break;
	}

	if(inicial.x!=final.x || inicial.y!=final.y) return -1;
	else return i;
}

//49
float distOrigem(Posicao pos){
	float temp = pow(pos.x,2) + pow(pos.y,2);

	return sqrt(temp);
} 


int maisCentral (Posicao pos[], int N){
	if(N==0) return 0;
	int r,i;
	float dist = distOrigem(pos[0]);
	r=0;

	for(i=1; i<N; i++){
		if(distOrigem(pos[i])<dist){
			dist = distOrigem(pos[i]);
			r = i;
		}
	}
	return r;
}

//50
float dist(Posicao p1, Posicao p2){
	float temp = pow((p1.x-p2.x),2) + pow((p1.y-p2.y),2); 
	return sqrt(temp);
}


int vizinhos (Posicao p, Posicao pos[], int N){
	int i, r=0;
	for(i=0; i<N; i++){
		if(dist(p, pos[i])==1) r++;
	}
	return r;
}

//2 parte

typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;

//51
int length (LInt l){
	int r = 0;
	
	while(l!=NULL){
		r++;
		l=l->prox;
	}

	return r;
}

//52
void freeL (LInt l){
	LInt ant;
	while(l){
		ant = l;
		l=l->prox;
		free(ant);
	}
}

//53
void imprimeL (LInt l){
	while(l){
		printf("%d\n", l->valor);
		l=l->prox;
	}
}

//54
LInt reverseL (LInt l){
	LInt aux = l, aux2;
	int len=0, i, j;

    if(l==NULL) return NULL;

	while(aux->prox!=NULL){
		len++;
		aux=aux->prox;
	}

	LInt ret = aux;
	
	for(i=0; i<len; i++){
	    aux2 = l;
	    j = len-i-1;
	    for(;j>0;j--){
	        aux2=aux2->prox;
	    }
		aux->prox = aux2;
		aux=aux->prox;
	}
    aux->prox = NULL;

	return ret;
}

//55
void insertOrd (LInt *l, int x){
	LInt newNode = malloc(sizeof(struct lligada));
	newNode->valor =  x;
	newNode->prox = NULL;

    if((*l)==NULL){
        (*l)=newNode;
        return;
    }

	while((*l)!=NULL && x > (*l)->valor){
		l=&((*l)->prox);
	}
	
	LInt temp = (*l);
	
	(*l) = newNode;
	newNode->prox = temp;
    
}

//56
int removeOneOrd (LInt *l, int x){
	int r=1;

	while((*l)!=NULL && (*l)->valor!=x){
		l=&((*l)->prox);
	}

	if((*l)!=NULL && (*l)->valor == x){
		(*l)=(*l)->prox;
		r=0;
	}

	return r;
}

//57
void merge (LInt *r, LInt a, LInt b){
	while(a && b){
		if(a->valor < b->valor){
			(*r) = a;
			a=a->prox;
			r=&((*r)->prox);
		}
		else{
			(*r) = b;
			b=b->prox;
			r=&((*r)->prox);			
		}
	}

	if(a){
		while(a){
			(*r) = a;
			a=a->prox;
			r=&((*r)->prox);			
		}
	}
	else if(b){
		while(b){
			(*r) = b;
			b=b->prox;
			r=&((*r)->prox);			
		}
	}
}

//58
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
	while(l!=NULL){
		if(l->valor<x){
			(*mx) = l;
			mx = &((*mx)->prox);
		}
		else{
			(*Mx) = l;
			Mx = &((*Mx)->prox);
		}
		l=l->prox;
	}
	*mx = NULL;
	*Mx = NULL;
}

//59
LInt parteAmeio (LInt *l){
	int len=length(*l);
    LInt ret=*l, prev=NULL;
    
	int meio = len/2;

    if(meio==0) return NULL;

	while(meio>0){
		prev = *l; 
		(*l) = (*l)->prox;
		meio--;
	}
	prev->prox = NULL;

	return ret;
 }

//60
 int removeAll (LInt *l, int x){
	int r = 0;

	while(*l){
		if((*l)->valor == x){
			(*l) = (*l)->prox;
			r++;
		}
		else l=&((*l)->prox);
	}

	return r;
 }

//61
int removeDups (LInt *l){
	int ret = 0;
	while(*l){
		LInt *aux = &((*l)->prox);
		while(*aux){
			if((*aux)->valor == (*l)->valor){
				(*aux) = (*aux)->prox;
				ret++;
			}
			else aux=&((*aux)->prox);
		}
		l=&((*l)->prox);
	}

	return ret;
}

//62
int removeMaiorL (LInt *l){
	LInt *aux = &((*l)->prox);
	int maior = (*l)->valor;

	while(*aux){
		if((*aux)->valor > maior) maior = (*aux)->valor;
		aux=&((*aux)->prox);
	}

	while(*l){
		if((*l)->valor == maior){
			(*l) = (*l)->prox;
			break;
		}
		else l = &((*l)->prox);
	}

	return maior;
}

//63
void init (LInt *l){
	if(*l==NULL) return;

	while((*l)->prox){
		l=&((*l)->prox);
	}
	*l = NULL;
}

//64
void appendL (LInt *l, int x){
	LInt new = malloc(sizeof(struct lligada));
	new->valor = x;
	new->prox = NULL;

	if(*l == NULL){
		*l = new;
		return;
	}

	while((*l)->prox){
		l=&((*l)->prox);
	}
	(*l)->prox = new;
}

//65
void concatL (LInt *a, LInt b){
	LInt *aux;
	if(*a==NULL){
	    *a = b;
	    return;
	}
	else{
		while((*a)->prox){
			a = &((*a)->prox);
		}
		(*a)->prox = b;
	}

}

//66
LInt cloneL (LInt l){
	if(l==NULL) return NULL;

	LInt ret = malloc(sizeof(struct lligada));
	ret->valor = l->valor;
	ret->prox = cloneL(l->prox);
	return ret;
}

//67
LInt cloneRev (LInt l){
	LInt ret=NULL, aux = l, ret2;
	int len=0, i;

	while(aux){
		len++;
		aux=aux->prox;
	}
	
	for(; len>0; len--){
		aux = l;
		int j = len;
		while(j-1>0){
			aux=aux->prox;
			j--;
		}

		LInt new = malloc(sizeof(struct lligada));
		new->valor = aux->valor;
		new->prox = NULL;

		if(ret==NULL){
			ret2 = new;
			ret = ret2;
		}
		else{
			ret2->prox = new;
			ret2=ret2->prox;
		}
	}
	
	return ret;

}

//68
int maximo (LInt l){
	int max = l->valor;
	
	l=l->prox;
	
	while(l){
		if(l->valor > max) max = l->valor;
		l=l->prox;
	}	

	return max;
}

//69
int take (int n, LInt *l){
	LInt prev;
	int ret = 0;

	while(*l && n>0){
		l = &((*l)->prox);
		n--;
		ret++;
	}

	while(*l){
		prev = *l;
		(*l) = (*l)->prox;
		free(prev); 
	}

	return ret;
}

//70
int drop (int n, LInt *l){
	LInt prev, lenl = *l;
	int ret = 0;

	while(*l && n>0) {
		prev = *l;
		(*l) = (*l)->prox;
		free(prev);
		n--;
		ret++;
	}

	return ret;
}

//71
LInt Nforward (LInt l, int N){
	while(l && N){
		l=l->prox;
		N--;
	}
	return l;
}

//72
int listToArray (LInt l, int v[], int N){
	int ret = 0,i;

	for(i=0; l && i<N; i++, ret++){
		v[i] = l->valor;
		l=l->prox;
	}

	return ret;
}

//73
LInt arrayToList (int v[], int N){
	int i;
	LInt l=NULL, ret=NULL;
	
	for(i=0; i<N; i++){
		LInt newL = malloc(sizeof(struct lligada));
		newL->valor = v[i];
		newL->prox = NULL;
		
		if(l==NULL){
		    l = newL;
		    ret = l;
		} 
		else{
		    l->prox = newL;
		    l=l->prox;
		}
	}

	return ret;
}

LInt arrayToList2 (int v[], int N){

	if(N==0) return NULL;

	LInt new = malloc(sizeof(struct lligada));
	new->valor = v[0];
	new->prox = arrayToList2(v+1, N-1);

	return new;
}

//74
LInt somasAcL (LInt l){
	LInt ret=NULL, aux=NULL;
	int i, j , soma=0, len=0;

	while(l){

		soma += l->valor;

		LInt new = malloc(sizeof(struct lligada));
		new->valor = soma;
		new->prox = NULL;

		if(ret==NULL) {
			aux = new;
			ret = aux;
		}
		else{
			aux->prox = new;
			aux=aux->prox;
		}
		l=l->prox;
	}

	return ret;
}

//75
void remreps (LInt l){
	while(l){
		LInt aux = l->prox;
		int cmp = l->valor;
		while(aux){
			if(aux->valor == l){
				l->prox = aux->prox;
				free(aux);
			}
			else{
				aux=aux->prox;				
			}
		}
		l=l->prox;
	}
}

//76
LInt rotateL (LInt l){
	if(l == NULL || l->prox == NULL) return l;

	LInt aux = l, ret = l->prox;

	while(aux->prox){
		aux = aux->prox;
	}

    aux->prox = l;
    l->prox=NULL;

	return ret;
}

//77
LInt parte (LInt l){

	if(l==NULL || l->prox == NULL) return NULL;

	LInt ret;

	ret = l;

	l->prox = l->prox->prox;

	ret->prox = parte(l->prox);

	return ret;
}


typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} *ABin;

//78
int altura (ABin a){
	int r1=0, r2=0;

	if(a==NULL) return 0;

	r1 = 1 + altura(a->esq);
	r2 = 1 + altura(a->dir);

	if(r1>r2) return r1;
	else return r2;
}

//79
ABin cloneAB (ABin arv){

	if(arv==NULL) return NULL;

	ABin ret = malloc(sizeof(struct nodo));
	ret->valor = arv->valor;
	ret->esq = cloneAB(arv->esq);
	ret->dir = cloneAB(arv->dir);

	return ret;
}

//80
void mirror (ABin *arv){
	if(*arv == NULL) return;

	ABin temp = (*arv)->esq;
	(*arv)->esq = (*arv)->dir;
	(*arv)->dir = temp;

	mirror(&((*arv)->esq));
	mirror(&((*arv)->dir));
}












int main(){

    char str1[30] = "Guilherme Varela";

    int x = contaPal("a a");
	printf("%d", x);
    return 0;
}