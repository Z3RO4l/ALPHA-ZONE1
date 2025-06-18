#include <stdio.h>
 
int main() {
    
 float nota1, nonta2, nota3 ;
float media ;

    printf("===========Programa de Calculo da Media===========\n");
    
    printf("Digite a Primeira nota: \n");
    scanf("%f", &nota1);

     printf("Digite a segunda nota: \n");
    scanf("%f", &nonta2);

     printf("Digite a terceira nota: \n");
    scanf("%f", &nota3);

 media = (float) ( nota1 + nonta2 + nota3) /3;

    printf(" a media é : %.1f", media);

    printf("\n===============================\n");

return 0 ;

}