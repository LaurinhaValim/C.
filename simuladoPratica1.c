#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[30];
    int poder;
}tpersonagem;

void imprime_tabuleiro(char tab[10][10][15]){
    int i, j;

    for(i=0; i < 10; i++){
        for(j =0; j < 10; j++){
            printf("%s ", tab[i][j]);
        }
        printf("\n");
    }
}

int posiciona(int linha, int coluna, char nome[], char tab[10][10][15]){
    if (linha < 0 || linha > 9 || coluna < 0 || coluna > 9 ){
        printf("Posicao Invalida!\n");
        return 0;}
    else
        {strcpy(tab[linha][coluna], nome);
            printf("1 - Personagem adiconado com sucesso!\n");
            return 1;
        }
    }

int ocorrencias(char nome[], char tab[10][10][15]){
    int i, j, contador =0;

    for(i=0; i < 10; i++){
        for(j =0; j < 10; j++){
            if (strcmp(tab[i][j], nome) == 0){
                contador++;}
            }
        }
    printf("O %s apareceu %d vezes no tabuleiro! \n", nome, contador);
}

void poder_total(tpersonagem personagens[30], char tab[10][10][15]){
    int soma, i, j, k;

    for(i=0; i<10;i++){
        for(j=0;j<10;j++){
            for(k=0; k<15; k++){
                if(strcmp(tab[i][j], personagens[k].nome)==0) soma+= personagens[k].poder;
            }
        }
    }
    printf("A soma dos poderes dos personagens do tabuleiro é %d!\n", soma);
}

int ataca(int linha, int coluna, tpersonagem personagens[30], char tab[10][10][15]){
    int k;

    if (linha < 0 || linha > 9 || coluna < 0 || coluna > 9 ){
        printf("Posicao invalida!\n");
        return 0;}
    else{
        if (strcmp(tab[linha][coluna], "") == 0){
            printf("Posição vazia!");
            return 0;
        }
        else{
            for (k = 0; k < 13; k++){
                if(strcmp(tab[linha][coluna], personagens[k].nome) == 0){
                        printf("O nivel de poder do %s e %d", personagens[k].nome, personagens[k].poder);
                        break;
                }  
             }
        }
    }
}


int main()
{
    char tabuleiro[10][10][15] = {
         {"mago", "", "", "", "", "fada", "", "","","vampiro"},
         {"", "", "dragao", "", "", "bruxa", "", "","",""},
         {"", "", "", "", "mago", "", "", "","",""},
         {"", "", "", "", "", "", "feiticeiro", "wendigo", "",""},
         {"", "", "", "cavaleiro", "", "", "", "","",""},
         {"", "", "", "", "duende", "", "", "","",""},
         {"", "", "", "", "", "", "vampiro",  "","",""},
         {"", "", "", "", "", "anjo", "lobisomem", "","",""},
         {"", "", "gnomo", "", "", "", "", "","",""},
         {"", "", "cavaleiro", "", "", "", "", "","","fada"}};
           

    tpersonagem  personagens[30]= {{"anjo",17},{"bruxa",12},{"cavaleiro",20},{"dragao",18},{"duende",5},
	{"fada",10},{"feiticeiro",12},{"gnomo",8},{"lobisomem",9},{"mago",15},{"princesa",4},
	{"vampiro",13},{"wendigo",16}};
	
    imprime_tabuleiro(tabuleiro);
	
    int linha, coluna;
    char nome_personagem[30];

    printf("Digite a linha que deseja colocar o personagem: ");
    scanf("%d", &linha);
    printf("Digite a coluna que deseja colocar o personagem: ");
    scanf("%d", &coluna);
    printf("Digite o nome do personagem que quer colocar: ");
    scanf(" %[^\n]", nome_personagem);

    posiciona(linha, coluna, nome_personagem ,tabuleiro);

    imprime_tabuleiro(tabuleiro);

    char nome_ocorrencia[30];
    printf("Digite o nome do personagem para contar quantas vezes ele esta no tabuleiro: ");
    scanf(" %[^\n]", nome_ocorrencia);
    ocorrencias(nome_ocorrencia,tabuleiro);

    poder_total(personagens,tabuleiro);
	
    int linha_2, coluna_2;
    printf("Digite a linha que deseja atacar: ");
    scanf("%d", &linha_2);
    printf("Digite a coluna que deseja atacar: ");
    scanf("%d", &coluna_2);
    ataca(linha_2,coluna_2,personagens,tabuleiro);

	return 0;
}
