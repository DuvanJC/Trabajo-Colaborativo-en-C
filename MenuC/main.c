/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: willin
 *
 * Created on 20 de junio de 2020, 4:55 p. m.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int calculateMCD(int less, int higher){
    
}

void calcFibonacci(){
    printf("Calcular termino de la serie de fibonacci\n Enter para continuar");
    getchar();
}

void calcMCD(){
    printf("Calcular Maximo comun Divisor\nEnter Para Continuar");
}

void mainMenu(){
    char option;
    
    char *mainMenu1= "<<<MENU PRINCIPAL>>>\n\n"
    "1. Serie de Fibonacci\n"
    "2. Maximo comun Divisor\n"
    "3. Numeros primos\n"
    "4. Numeros Amigos\n\n"
    "Digite Opcion ([s/S]-Salir)...";
    
    do{
        printf(mainMenu1);
        scanf("%c",&option);
        fflush(stdin);
        switch(option){
            case '1': calcFibonacci();
            break;
            
            case '2': calcMCD();
            break;
        }
    }while(toupper(option)!='S');
}


int main(int argc, char** argv) {

    mainMenu();
    
    return (EXIT_SUCCESS);
}

