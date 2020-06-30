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
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/*
 * 
 */

int size(int number){
    int size=1;
     while(number/10>0){
        number=number/10;
        size++;
    }
    return size;
}

int menoraMayor(int magic){
    int number = magic;
    int tam = size(number);
   
    int  *arrayNumber  = (int*)malloc(tam*sizeof(int));   
    for (int i = 0; i < tam; i++) {       
        arrayNumber[i]=number%10;
        number=number/10;
    }
    char cadenanumero [tam];
    int aux=0;
    for (int i = 0; i < tam; i++) { 
        for (int j = 0; j < tam; j++) {
            if (arrayNumber[i]<arrayNumber[j]) {
                aux=arrayNumber[i];
                arrayNumber[i]=arrayNumber[j];
                arrayNumber[j]=aux;
            }
        }
    }
    for (int i = 0; i < tam; i++) {        
        cadenanumero[i]=arrayNumber[i]+'0';
    }
    return atoi(cadenanumero);
}

int mayoraMenor(int magic){
    int number = magic;
    int tam = size(number);
    int  *arrayNumber  = (int*)malloc(tam*sizeof(int));   
    for (int i = 0; i < tam; i++) {       
        arrayNumber[i]=number%10;
        number=number/10;
    } 
    char cadenanumero [tam];
    int aux=0;
    for (int i = 0; i < tam; i++) { 
        for (int j = 0; j < tam; j++) {
            if (arrayNumber[i]>arrayNumber[j]) {
                aux=arrayNumber[i];
                arrayNumber[i]=arrayNumber[j];
                arrayNumber[j]=aux;
            }
        }
    }
    for (int i = 0; i < tam; i++) {        
        cadenanumero[i]=arrayNumber[i]+'0';
    }
    return atoi(cadenanumero);
}

char* IMC(int peso, double estatura, int genero){  
    
    char* niveldePeso;
    estatura=estatura/100;
    int calculoIMC=peso/(estatura*estatura);
    printf("entra a  IMC");
    if (genero==1){
        if (calculoIMC<=16) {
            niveldePeso = "Desnutricion";
        }else if(calculoIMC>16 && calculoIMC<=20){
            niveldePeso = "Bajo Peso";
        }else if(calculoIMC>20 && calculoIMC<=24){
            niveldePeso = "Normal";
        }else if(calculoIMC>24 && calculoIMC<=29){
            niveldePeso = "Sobrepeso";
        }else if(calculoIMC>29 && calculoIMC<=34){
            niveldePeso = "Obesidad";
        }else if(calculoIMC>34 && calculoIMC<=39){
            niveldePeso = "Obesidad Marcada";
        }else if(calculoIMC>39){
            niveldePeso = "Obesidad Morbida";
        }
      
    } else {
        if (calculoIMC<=17) {
            niveldePeso = "Desnutricion";
        }else if(calculoIMC>17 && calculoIMC<=20){
            niveldePeso = "Bajo Peso";
        }else if(calculoIMC>20 && calculoIMC<=25){
            niveldePeso = "Normal";
        }else if(calculoIMC>25 && calculoIMC<=30){
            niveldePeso = "Sobrepeso";
        }else if(calculoIMC>30 && calculoIMC<=35){
            niveldePeso = "Obesidad";
        }else if(calculoIMC>35 && calculoIMC<=40){
            niveldePeso = "Obesidad Marcada";
        }else if(calculoIMC>40){
            niveldePeso = "Obesidad Morbida";
        } 
    } 
    return niveldePeso;
}

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

int validarLetras(char *validar){
    int i=0, sw =0, j;
    
    j=strlen(validar);
    
    while(i<j && sw==0){
        if(isalpha(validar[i])!=0){
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
            printf("El numero es egolatra \n\n");
        }else{
            printf("El numero no es egolatra \n");
        }
    }else{
        printf("Digite solo numeros \n\n");
    }
}

int cadenaCalificar(char *expresion){
    int sw=validarLetras(expresion);
    int cont=0;
    int cadena=0;
    int sum=0;
    int conaux=0;
    if(sw==0){
        for(int i=0; i<=strlen(expresion); i++){
            char letras= tolower(expresion[i]); 
            if(letras=='x' || letras =='o') {
                if(letras=='o'){
                    cont++;
                    sum=cont+sum;
                    conaux=sum;
                }else{
                    cont=0;
                }
            }
        }
    }else{
         printf("Digite solo letras 'X' 'O' \n\n");
    }
    return conaux;
     
}

void numExcluido(char *inicio, char *fin, char *excluido){
    int sInicio=validarNumeros(inicio);
    int sFin=validarNumeros(fin);
    int sExcluido=validarNumeros(excluido);
    if(sInicio==0 && sFin==0 && sExcluido==0){
        int inicio1 = atoi(inicio); 
        int fin1= atoi(fin);
        int excluido1= atoi(excluido);
        if(inicio1<fin1){
            int sum=0;
            int cont=0;
            int posicion=0;
            int separar=0;
            for(int i=inicio1; i<=fin1;i++){
                posicion=i;
                while(posicion){
                    separar=posicion%10;
                    posicion=posicion/10;
                    if(separar==excluido1){
                        cont=cont+1;
                    }else{
                        sum=sum+separar;
                    }
                }
            }
            printf("El total de la suma es: %i y los digitos ignorados fueron: %i \n", sum, cont);
        }else{
            printf("El numero del final debe ser mayor al numero de inicio\n");
        }     
    }else{
        printf("Digite solo numeros\n");
    }
}

char* Fibonacci(int n) {
    
        char* cadena = " ";
        char* s1 = " ";
        char* s2 = " ";
        if(n == 0) {
            cadena = "0";
        }

        if(n == 1) {
            cadena = "1";
        }

        if(n >= 2) {
            s1 = Fibonacci(n - 1);
            s2 = Fibonacci(n - 2);
            const size_t len1 = strlen(s1);
            const size_t len2 = strlen(s2);
            char* resultado = malloc(len1 + len2 + 1);
            memcpy(resultado, s1, len1);
            memcpy(resultado + len1, s2, len2 + 1);
            cadena = resultado;
        }
    return cadena;
        
    

    
}

int Find(char* cadena1, char* cadena2) {
    char* busqueda = NULL;
    busqueda = strstr(cadena1, cadena2);
    int i = 0;
    while (busqueda!= 0) {
        i++;
        busqueda = strstr(busqueda + 1, cadena2);
    }
    return i;

}


void mainMenu(){
   
    int peso, numbero, genero;
    double estatura;
    char *validar;
    char *validar2;
    char *validar5;
    char *validar51;
    char *validar52;
    char *validar7;
    char option;
    int number = 0;
    int veces = 0;
    char p[128];
    

    char *mainMenu1= "<<<MENU PRINCIPAL>>>\n\n"
    "1. Numeros Primos\n"
    "2. Numero Egolatra\n" 
    "3. Numero Magico\n"
    "4. Indice de Masa Corporal\n"
    "5. Suma de digitos no C\n"
    "6. Secuencia de Palabras Fibonacci\n"
    "7. Cadena para Calificar\n"
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
            
            case '3':
                printf( "\nHa seleccionado Numero Magico\n");
                printf( "\nIntroduzca un numero entero:");   
                
                    scanf( "%d", &numbero );
                    if (numbero<0||numbero>32767) {
                        printf("Error!... el numero es menor a cero(0) o demasiado grande.");
                        
                } else {
                        printf("Numero valido :)\n");
                        int answer= mayoraMenor(numbero)-menoraMayor(numbero);
                        printf("%d - %d = %d\n",mayoraMenor(numbero),menoraMayor(numbero),answer);
                        if (numbero==answer) {
                            printf("%d  Es un Numero magico!!!\n", numbero);
                    } else {
                            printf("%d NO es un numero magico :c\n", numbero);
                    }       
                }
                break;
                
            case '4':
                printf( "\nHa seleccionado Indice de Masa Coprporal\n");
                printf( "Peso (kg):  ");
                scanf( "%d", &peso );
                printf( "Estatura(cm):  ");
                scanf( "%lf", &estatura );                
                printf( "Genero (1)femenino o (2)masculino Ingrese Numero: ");             
                scanf( "%d", &genero );
                        
               

                if (genero==1||genero==2) {                   
                    printf("Resultado IMC: %s\n",IMC(peso,estatura, genero));
                    printf("termina if de genero\n");
                } else {
                    printf("Genero %d No valido\n",genero);
                }
                break;
                
            case '5':
                printf("Ha escogido la opcion numero cinco \n");
                printf("Digite el numero de inicio \n");
                scanf("%s", &validar5);
                fflush(stdin);
                
                printf("Digite el numero de fin \n");
                scanf("%s", &validar51);
                fflush(stdin);
                
                printf("Digite el numero a no tener en cuenta \n");
                scanf("%s", &validar52);
                fflush(stdin);
                
                numExcluido(&validar5 , &validar51, &validar52);
                break;
                
            case '6':
                printf("\nIngrese numero de sucecion Fibonacci menor a 13: ");
                scanf("%d", &number);
                if (number<=13) {
                    char* res = Fibonacci(number);
                    printf("%s", res);
                    printf("\nIngrese secuencia de bits: ");
                    scanf("%s", p, sizeof(p));
                    veces = Find(res, p);
                    printf("Se encuentra la secuencia %s - %d veces", p, veces);
                    getchar();
                }else{
                    printf("Error!...  El numero debe ser menor a 13");
                    }
                break;
                
                 
            case '7':
                printf("Ha escogido la opcion numero siete \n");
                printf("Digite la expresion a calcular \n");
                scanf("%s",&validar7);
                fflush(stdin);
                int cout=cadenaCalificar(&validar7);
                if(cout>0){
                    printf("El resultado de la prueba fue de: %d  \n", cout);        
                }
                break;
        }
    }while(toupper(option)!='S');
}


int main(int argc, char** argv) {

    mainMenu();
    return (EXIT_SUCCESS);
}

