
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

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
int menu(){
    int peso, number, genero;
    double estatura;
   
    int opcion;
    do{
         printf( "\n\n\tOPCIONES\n");
        printf( "3. Numero magico.\n");
        printf( "4. Indice de Masa Corporal.\n");
        printf( "5. Salir.\n" );
        printf( "\nIngrese su opcion: \n\n");

        scanf( "%d", &opcion );
        switch ( opcion ){
            case 3:                
                printf( "\nHa seleccionado Numero Magico\n");
                printf( "\nIntroduzca un numero entero:");   
                
                    scanf( "%d", &number );
                    if (number<0||number>32767) {
                        printf("Error!... el numero es menor a cero(0) o demasiado grande.");
                        
                } else {
                        printf("Numero valido :)\n");
                        int answer= mayoraMenor(number)-menoraMayor(number);
                        printf("%d - %d = %d\n",mayoraMenor(number),menoraMayor(number),answer);
                        if (number==answer) {
                            printf("%d  Es un Numero magico!!!\n", number);
                    } else {
                            printf("%d NO es un numero magico :c\n", number);
                    }       
                }
                    
                break;

            case 4: 
                
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
            case 5:
                printf("Programa Terminado.");
                break;        
            default:
                printf("Opcion No valida");
        }

         

    } while ( opcion != 5 );

    return 0;
} 

int main(int argc, char** argv) {
    menu();   
    return (EXIT_SUCCESS);
}

