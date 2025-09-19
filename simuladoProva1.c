#include <stdio.h>


typedef struct{
    int linha, coluna;      
} tupla;

typedef struct{
    int tamanho;
    tupla pos[20];
} lista_tuplas;

int soma_pos(int m[5][5], lista_tuplas lista){
    int i, tamanho, soma =0;
    tamanho = lista.tamanho;

    for(i=0; i < tamanho; i++){
       soma += m[lista.pos[i].linha][lista.pos[i].coluna];
        }
    
    return soma;

}
int main() {

   lista_tuplas  lista_pos = {4, { {1,2} , {0,3} , {2,4} , {4,0} }};

   int M[5][5] ={ {1,2,3,4,5}, {6,7,8,9,10}, {2,4,6,8,10}, {3,6,9,12,15}, {9,6,4,0,2}};

   printf("soma=%d", soma_pos(M , lista_pos));

   return 0;        

}