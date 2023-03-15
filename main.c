#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

void lervect(int, int []); // num, vetor
void cod(int, int [], int []); // num, vetor de lervect, vetor codificado
void decod(int []); // vetor codificado
void removersubseq(char*, int); //sequencia, k a remover

int main(void)
{
    int num = 0, vect[MAX_SIZE] = {0}, vectcod[MAX_SIZE] = {0};
    printf("Tamanho do numero: ");
    scanf("%d", &num);
    lervect(num, vect);
    cod(num, vect, vectcod);
    decod(vectcod);
    printf("\n");

    //remove subsequencias duma sequencia inicial
    char str[1000];
    int k;
    printf("Insira uma sequencia de numeros: ");
    scanf("%s", str);
    printf("Introduza um k: ");
    scanf("%d", &k);
    removersubseq(str, k);
    return 0;
}

// le o vetor
void lervect(int num1, int vectin[]){
    int aux = 0;
    printf("Insira a sequencia:\n");
    for (aux = 0; aux < num1; aux++){
        scanf("%d", &vectin[aux]);
    }
    return;
}

// codifica o vetor
void cod(int num1, int vectcod[], int vectfin[]){
    int aux = 0, j = 0, r = 1;

    for (aux = 1; aux < num1; aux++) {
        if (vectcod[aux] == vectcod[aux - 1]) {
            r++;
        } else {
            while (r > 9) {
                vectfin[j++] = 9;
                vectfin[j++] = vectcod[aux-1];
                r -= 9;
            }
            vectfin[j++] = r;
            vectfin[j++] = vectcod[aux-1];
            r = 1;
        }
    }
    while (r > 9) {
        vectfin[j++] = 9;
        vectfin[j++] = vectcod[num1-1];
        r -= 9;
    }
    vectfin[j++] = r;
    vectfin[j++] = vectcod[num1-1];
    for (aux = 0; aux < j; aux++) {
        printf("%d", vectfin[aux]);
    }
    printf("\n");
    return;
}

// descodifica o vetor
void decod(int vectcod1 []){
    int aux = 0, i = 0;
    do{
        for(i = vectcod1[aux]; i > 0;i--){
            printf("%d",vectcod1[aux+1]);
        }
        aux = aux + 2;
    }
    while(vectcod1[aux] != '\0');
}

//remove subsequence
void removersubseq(char* str, int k) {
    int len = strlen(str);
    int count = 1;
    int j = 0;
    for (int i = 1; i <= len; i++) {
        if (i == len || str[i] != str[i-1]) {
            if (count <= k) {
                for (int l = 0; l < count; l++) {
                    str[j++] = str[i-1];
                }
            }
            count = 1;
        } else {
            count++;
        }
    }
    str[j] = '\0';
    printf("%s\n", str);
}

