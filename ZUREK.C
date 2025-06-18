 #include<stdio.h>

int main(){

/*
soma(+)
multiplicacao(8)
subtracao(-)
divisao(/)
*/


int numero1,numero2;
int soma, subtracao,multiplicacao;
float divisao;


printf("Entre com um numero : ");
scanf("%d", &numero1);
printf("entre com um numero  : ");
scanf("%d", &numero2);

//Operaçãode soma
soma = numero1 + numero2;

//Operação de subtração 
subtracao = numero1 - numero2;

//Operação de multiplicação
multiplicacao = numero1 *  numero2 ;

//Operação de divisão 
divisao = numero1/ numero2;

printf(" A soma é: %d\n", soma);
printf(" A multiplicação é: %d\n", multiplicacao);
printf(" A divisão é: %2.F \n",divisao);
printf(" A subtração é: %d\n", subtracao);


return 0;


}