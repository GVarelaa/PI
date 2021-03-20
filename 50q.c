#include <stdio.h>
#include <string.h>

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




int main(){

    char str1[20] = "Ola", str2[10] = " tas bem?";

    printf ("%ld\n", strlen (str1));

    return 0;
}