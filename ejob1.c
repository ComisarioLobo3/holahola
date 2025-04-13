#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void imprimir_bcd(const char bcd[], size_t digitos) {
    size_t separadores = digitos / 3;
    size_t ceros_izquierdos = digitos % 3;
    size_t indices_totales = digitos + separadores + ceros_izquierdos; // Tamaño total del vector con separadores y ceros a la izquierda    
    size_t indice_bcd = digitos - 1;
    
    char nuevo_vector[indices_totales];
    for(size_t i = 0; i < indices_totales; i++) {
        if(i < ceros_izquierdos) { // Agregar ceros a la izquierda
            nuevo_vector[i] = '0';
        } else if ((i - ceros_izquierdos) % 4 == 3 && i != indices_totales - 1) { // Cada 3 dígitos, agregar un '_'
            nuevo_vector[i] = '_';
        } else {
            nuevo_vector[i] = bcd[indice_bcd--];
        }
    }
    // Imprimir el número formateado
    for(size_t i = 0; i < indices_totales; i++) { 
        printf("%c", vector[i]);
    }
    putchar('\n');
}

 

int main() {
    char numero[100];
    printf("Ingrese un numero: ");
    fgets(numero, 100, stdin); 
    size_t longitud = strlen(numero);
     // Eliminar el carácter de nueva línea (\n) si está presente
    if (numero[longitud - 1] == '\n') {
        numero[longitud - 1] = '\0';
        longitud--;
    }
    imprimir_bcd(numero, longitud);
    return 0;
}
