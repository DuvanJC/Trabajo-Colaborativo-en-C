/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: willin
 *
 * Created on 29 de junio de 2020, 10:29 a. m.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void numPrimos(int numPrimo){
    int cont=0;
    for(int num=numPrimo; num>=1; num--){
        for(int j=1; j<=num;j++){
            if(num%j==0){
                cont++;
            }
        }if(cont==2){
            printf("Los numeros son: ");
            printf("%d\n",num);
        }
        cont=0;
    }
   
}

void numEgolatra(int numEgolatra){
    int a=numEgolatra/100;
    int b=(numEgolatra-a*100)/10;
    int c=(numEgolatra-a*100-b*10);
    
    int resultado=(a*a*a)+(b*b*b)+(c*c*c);
    if(resultado==numEgolatra){
        printf("El numero es egolatra \n");
    }else{
        printf("El numero no es egolatra \n");
    }
}

void mainMenu(){
   
    int num;
    char option;
    
    char *mainMenu1= "<<<MENU PRINCIPAL>>>\n\n"
    "1. Numeros Primos\n"
    "2. Numero Egolatra\n"   
    "Digite Opcion ([s/S]-Salir)...\n";
    
    do{
        printf(mainMenu1);
        scanf("%c",&option);
        fflush(stdin);
        switch(option){
            case '1': 
                printf("Ha escogido la opcion numero uno \n");
                printf("Digite el numero \n");
                scanf("%d",&num);
                numPrimos(num);
            break;
            
            case '2': 
                printf("Ha escogido la opcion numero udos \n");
                printf("Digite el numero \n");
                scanf("%d",&num);
                numEgolatra(num);
            break;
        }
    }while(toupper(option)!='S');
}


int main(int argc, char** argv) {

    mainMenu();
    return (EXIT_SUCCESS);
}

