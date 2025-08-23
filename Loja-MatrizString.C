#include <stdio.h>

int main(){

    int i, j;
    char vendedores[5][40] = {"Alencar","Meireles","Verissimo", "Machado", "Lobato"};

    float vendas[5][4] = {
    {1140.00, 630.00, 944.00, 1173.00},  // Vendedor 11
    {784.00, 662.00, 853.00, 1144.00},  // Vendedor 14
    {1069.00, 797.00, 1242.00, 710.00}, // Vendedor 23
    {984.00, 1297.00, 863.00, 1136.00}, // Vendedor 45
    {691.00, 765.00, 1172.00, 1181.00}  // Vendedor 57
    };
        
    
    // total de vendas:
    float total;
    total = 0;
    for (i = 0; i < 5; i++)
        for(j =0; j < 4; j++){
            total += vendas[i][j];
        }
    printf("O total de vendas foi R$ %.2f\n", total);
    
    printf("\n");


    // total de vendas por semana:
    float total_semana;
    int melhor_semana = 0;

    for (i = 0; i < 4; i++){
        total_semana = 0;
        for(j =0; j < 5; j++){
            total_semana += vendas[j][i];}
        printf("O total de vendas da semana %d foi R$ %.2f\n", i+1, total_semana);
        if (melhor_semana < total_semana) melhor_semana = i+1;
        }

    printf("\nA melhor semana de vendas foi %d\n", melhor_semana);

    printf("\n");

    // total vendas por vendedor
    float total_vendedor;
    float lista_total[5];

    for (i = 0; i < 5; i++){
        total_vendedor = 0;
        for(j =0; j < 4; j++){
            total_vendedor += vendas[i][j];}
        
        lista_total[i] = total_vendedor;
        printf("O total de vendas do %s foi R$ %.2f\n", vendedores[i], total_vendedor);}
        
        
    printf("\n");
    // maior venda de todas:
    float maior = 0;
    int indice_nome = 0;
    for (i = 0; i < 5; i++)
        for(j =0; j < 4; j++){
            if (vendas[i][j] > maior) 
                {maior = vendas[i][j];
                indice_nome = i;}
        }
    printf("A maior venda da loja foi %.2f, do vendedor %s \n", maior, vendedores[indice_nome]);

    printf("\n");
    //Maior salario:

    float salario_inicial = 2000, salario_final, maior_salario = 0, soma_salario = 0;
    int nome_maior = 0;
    
    for (i=0; i<5; i++){
        salario_final = (lista_total[i] / 10) + salario_inicial;
        soma_salario += salario_final;
        if (salario_final > maior_salario){
            maior_salario = salario_final;
            nome_maior = i;
        }
    }
    printf("O maior salario foi R$%.2f, do %s\n", maior_salario, vendedores[nome_maior]);

    printf("\n");
    // lucro da loja:

    float lucro_total;
    lucro_total = total - soma_salario;
    printf("O lucro total da loja foi R$%.2f", lucro_total);


    return 0;
}
