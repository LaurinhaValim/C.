#include <stdio.h>
#include <string.h>

typedef struct{
   char letra;
   int quantidade;
}armazenar;

void conta_letras(char frase[200], armazenar contador[26]){
    int i, encontrado, j;

    for (j = 0; j < 26; j++) {
        contador[j].letra = '\0';
        contador[j].quantidade = 0;
    }

   
    for(i=0; i < strlen(frase); i++){
        if (frase[i] != ' '){
            encontrado=0;
            for (j = 0; j < 26; j++)
                if(contador[j].letra == frase[i]){
                    contador[j].quantidade += 1;
                    encontrado = 1;
                    break;
                }
            
            if (!encontrado){
                contador[i].letra = frase[i];
                contador[i].quantidade = 1;}
        }
    }
}

int main(){
    char frase[200];
    printf("Digite uma frase para visualizar a quantidade de cada letra nela: \n");
    scanf(" %[^\n]", frase);

    armazenar contador[26];
    conta_letras(frase, contador);

    int i;
    for (i =0; i <26 ; i++){
        if (contador[i].quantidade != 0){
        printf("%c: %d, ", contador[i].letra, contador[i].quantidade);
    }
}}