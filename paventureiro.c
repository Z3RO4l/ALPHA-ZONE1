#include <stdio.h>

int main (){

    printf("desafio das cartas - super trunfo _CARTA A01\n") ;

// DADOS DA CARTA A01 

char Estado1 [40];
char Codigo1 [10];
char Cidadea [50];
int Populacao1 ;
int Ponto_Turistico1 ;
float Area1;
float PIB1 ;
float Densidade_Populacional1;
float PIB_Percapita1;
float SUPER_PODER1;
// DADOS DA CARTA B02

char Estado2 [40];
char Codigo2 [40];
char Cidadeb [50];
int Populacao2 ;
int Pontos_Turisticos2;
float Area2;
float PIB2 ;
float Densidade_Populacional2;
float PIB_Percapita2;
float SUPER_PODER2;
//ENTRADA DE DADOS _ CARTAS 
//CARTA A01
 // dados de carta A01   

     printf("============Cadastro da Carta 1:==============\n");

    printf("Estado: ");
    scanf(" %[^\n]", Estado1);

    printf("Código da carta: ");
    scanf(" %[^\n]", Codigo1);

    printf("Nome da cidade: \n");
    scanf(" %[^\n]", Cidadea);

     printf(" populacao do Estado A01: \n ");
     scanf("%d", &Populacao1 );

     printf(" area do Estado A01: \n");
     scanf("%f", &Area1 );

     printf(" o PIB do Estado A01: \n");
     scanf("%f", &PIB1);
  
     printf("pontos turisticos do Estado A01: \n");
     scanf("%d", &Ponto_Turistico1);
     
     Densidade_Populacional1 = (float) (Populacao1 + Area1) /2;

     PIB_Percapita1 = (float) (PIB1 + Populacao1 ) /2;

     SUPER_PODER1 = (Populacao1 + Area1 + PIB1 + PIB_Percapita1 + Ponto_Turistico1 );

    

    //entrada de dados carta 2  
    
    printf("\nCadastro da Carta 2:\n");

    printf("Estado: \n");
    scanf(" %[^\n]", Estado2);

    printf("Código da carta: \n");
    scanf(" %[^\n]", Codigo2);

    printf("Nome da cidade: \n");
    scanf(" %[^\n]", Cidadeb);

    printf("numero da populacao: \n");
    scanf("%d", &Populacao2);

    printf(" área do Estado : \n");
    scanf("%f", &Area2);

    printf(" PIB do Estado : \n");
    scanf("%f", &PIB2);

    printf("Pontos_turísticos do Estado : \n");
    scanf("%d", &Pontos_Turisticos2);

    Densidade_Populacional2 = (float) (Populacao2 + Area2) /2;

     PIB_Percapita2 = (float) (PIB2 + Populacao2) /2;
     
     SUPER_PODER2 = (Populacao2 + Area2 + PIB2 +PIB_Percapita2 + Pontos_Turisticos2 ) ;

     //exibicao de Dados da carta 
     //saida de dados A01
     
     printf("\n ========== CARTA A01 =============\n");

     printf("Estado:%s\n", Estado1);

     printf("Código: %s\n", Codigo1 );

     printf("Cidade: %s\n", Cidadea);

     printf("populacao: %d habitantes \n", Populacao1 );

     printf("Area: %.2f  km2 \n", Area1);

     printf("PIB: US$ %.2f trilhoes \n", PIB1 );

     printf("numero de pontos turisticos: %d\n" , Ponto_Turistico1);   
     
     printf("Densidade Populacional: %.2f\n", Densidade_Populacional1);

     printf("PIB Percapita: %.2f\n", PIB_Percapita1);

     printf("SUPER POWER %f \n",SUPER_PODER1);



     printf("==============================\n");

//Saida de dados B02

    printf("\n=========== CARTA B02 ============\n");

    printf("Estado: %s\n", Estado2);

    printf("Código: %s\n", Codigo2);

    printf("Cidade: %s\n", Cidadeb);

    printf("População: %d habitantes \n", Populacao2);

    printf("Área: %.2f km²\n", Area2);

    printf("PIB: US$ %.2f bilhões\n", PIB2);

    printf("Pontos turísticos: %d\n", Pontos_Turisticos2);

    printf("Densidade Populacional: %.2f\n", Densidade_Populacional2);

     printf("PIB Percapita: %.2f\n", PIB_Percapita2);

     printf("Super Power %f\n", SUPER_PODER2);
    
    printf("=============================\n");


    printf("\n==================COMPARAÇÃO DE CARTAS==================\n");
    printf("POPULAÇÃO : %s\n" ,(Populacao1 > Populacao2 ? "carta 1 venceu":  
                                 (Populacao1 < Populacao2 ? "carta 2 venceu" : "Empate" )));

    printf("AREA : %s\n", (Area1 > Area2 ? "carta 1 venceu":
                           ( Area1 < Area2 ? "carta 2 venceu" : "Empate" )));

    printf("PIB: %s\n", (PIB1 > PIB2 ? " carta 1 venceu":
                          ( PIB1 < PIB2 ? " carta 2 venceu": "Empate" )));


    printf("PONTOS TURISTICOS : %s\n", (Ponto_Turistico1 > Pontos_Turisticos2 ?"carta 1 venceu" : 
                                                     ( Ponto_Turistico1 < Pontos_Turisticos2 ? "carta 2 venceu": "Empate")));

    printf("DENSIDADE POPULACIONAL - A01 > B02: %s\n", ( Densidade_Populacional1 > Densidade_Populacional2 ? "carta 1 venceu" :
                                                           (Densidade_Populacional1 < Densidade_Populacional2 ? "carta 2 venceu" :"Empate" )));

    printf(" PIB PER CAPTA - A01 > B02:   %s\n", (PIB_Percapita1 > PIB_Percapita2 ? "carta 1 venceu":
                                                    (PIB_Percapita1 < PIB_Percapita2 ? " carta 2 venceu": "Empate")));

    printf("SUPER PODER: %s\n", (SUPER_PODER1 > SUPER_PODER2 ? " carta 1 venceu" :
                                  (SUPER_PODER1 < SUPER_PODER2 ? "carta 2 venceu": "Empate")));
    printf("\n=====================================================");

    return 0; 
     
}
