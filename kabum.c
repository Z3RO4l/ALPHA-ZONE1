#include <stdio.h> 

int main (){

 int idade;

 printf("digite sua idade: ");
 scanf("%d", &idade);

  if (idade < 12){
         printf("voce ainda é uma criança ! \n");
  } else if ( idade >= 12 && idade < 18){
         printf("voce é um adolescente \n");
  } else if (idade >= 18 && idade < 60){
         printf("voce é um adulto depressivo CLT \n");
  } else{
    printf("voce é um velho brocha \n");
  }

  


}