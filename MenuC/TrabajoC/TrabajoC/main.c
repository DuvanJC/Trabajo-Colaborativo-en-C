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
#include <string.h>
#include <ctype.h>

/*
 * 
 */

int validarNumeros(char *validar){
    int i=0, sw =0, j;
    
    j=strlen(validar);
    
    while(i<j && sw==0){
        if(isdigit(validar[i])!=0){
            i++;
        }else{
            sw=1;
        }
    }
    return sw;
    
}
void numPrimos(char *numPrimo){
    int sw=validarNumeros(numPrimo);
    
    if(sw==0){
        int ia = atoi(numPrimo);  
        int cont=0;
        for(int num=ia; num>=1; num--){
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
    }else{
        printf("Digite solo numeros \n\n");
    }
}

void numEgolatra(char *numEgolatra){
     int sw=validarNumeros(numEgolatra);
    
    if(sw==0){
        int ia = atoi(numEgolatra);  
        int a=ia/100;
        int b=(ia-a*100)/10;
        int c=(ia-a*100-b*10);
    
        int resultado=(a*a*a)+(b*b*b)+(c*c*c);
        if(resultado==ia){
            printf("El numero es egolatra \n");
        }else{
            printf("El numero no es egolatra \n");
        }
    }else{
        printf("Digite solo numeros \n\n");
    }
}

void mainMenu(){
   
    char validar;
    char validar2;
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
                scanf("%s",&validar);
                fflush(stdin);
                numPrimos(&validar);  
            break;
            
            case '2': 
                printf("Ha escogido la opcion numero dos \n");
                printf("Digite el numero \n");
                scanf("%s",&validar2);
                fflush(stdin);
                numEgolatra(&validar2);
            break;
        }
    }while(toupper(option)!='S');
}


int main(int argc, char** argv) {

    mainMenu();
    return (EXIT_SUCCESS);
}

