 #include<stdio.h>

int main(){

    int numero1 = 1, resultado ;

    printf("Antes do encremento: %d\n", numero1);

    resultado = numero1++;

    printf("Apoa Pos incremento - numero 1: %d - resultado - %d\n", numero1,resultado);

    resultado = ++numero1;

     printf("Apoa Pre incremento - numero 1: %d - resultado - %d\n", numero1,resultado);


     resultado = numero1--;
      printf("Apoa Pos incremento - numero 1: %d - resultado - %d\n", numero1,resultado);


      resultado = --numero1;
       printf("Apoa Pre incremento - numero 1: %d - resultado - %d\n", numero1,resultado);

return 0 ;

    }