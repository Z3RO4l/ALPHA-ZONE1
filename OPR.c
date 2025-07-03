#include <stdio.h>

int main (){

    char produtoA [50] = "Produto A";
    char produtoB [50] = "Produto B";

    unsigned int estoqueA = 1000;
    unsigned int estoqueB = 2000;

    float valorA = 10.50;
    float valorB = 20.40;

    unsigned int estoqueMinimoA = 500;
    unsigned int EstoqueMinimoB = 1000;

    double valortotalA ;
    double valortotalB ;

    int resultadoA,resultadoB;

// Exibir Informações Dos Produtos ;

    printf("Produto %s tem em estoque %u e valor unitario é  R$ %.2f\n", produtoA,estoqueA,valorA);

    printf("Produto %s tem em estoque %u e valor unitario é  R$ %.2f\n",produtoB, estoqueB,valorB);

//Comparações Com o Valor Minimo Do Estoque; 
     
resultadoA = estoqueA > estoqueMinimoA;
resultadoB = estoqueB > EstoqueMinimoB;

printf(" O produto %s tem estoque minimo %d\n", produtoA, resultadoA);
printf("O produto %s tem estoque minimo %d\n",produtoB, resultadoB);

//Comparação dos valores totais dos produtos 

printf(" O valor total de A (R$ %.2f) é maior que o total de B (R$ %.2f), %d\n", estoqueA * valorA ,
                                                                estoqueB * valorB ,
                                                                (estoqueA = valorA) > (estoqueB * valorB));


}

