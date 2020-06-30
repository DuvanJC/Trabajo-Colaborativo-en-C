#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

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

int main()
{
    
    int number = 0;
    int veces = 0;
    char p[128];
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

    

    return 0;
}
