#include "./include/ft_printf.h"
#include <stdio.h>
int main()
{
    int total;

    total = 0;
    ft_printf("|--------------------------------PRUEBA FT_PRINTF--------------------------------|\n");
    ft_printf("1. PRUEBA %%c:\n\n");
    
    total = ft_printf("a) ft_printf: %c\n", 'a');
    printf("a) printf: %c\n\n", 'a');
    
    total = ft_printf("b) ft_printf: %c\n", 'Z');
    printf("b) printf: %c\n\n", 'Z');
    
    total = ft_printf("c) ft_printf: %c\n", '0');
    printf("c) printf: %c\n\n", '0');

    /*    
    ft_printf("c) ft_printf: %c\n", "Hola");
    printf("c) printf: %c\n\n", "Hola");
    */
    ft_printf("----------------------------------------------------------------------------------\n");
    ft_printf("2. PRUEBA %%s:\n\n");
    
    total = ft_printf("a) ft_printf: %s\n", "Hola");
    printf("a) printf: %s\n\n", "Hola");
    
    total = ft_printf("b) ft_printf: %s\n", "abcdefghijklmnopqrstuvwxyz");
    printf("b) printf: %s\n\n", "abcdefghijklmnopqrstuvwxyz");
    
    total = ft_printf("c) ft_printf: %s\n", "0123456789 (en caracter)");
    printf("c) printf: %s\n\n", "0123456789 (en caracter)");

    /*    
    ft_printf("c) ft_printf: %c\n", 123);
    printf("c) printf: %c\n\n", 123);
    */

    ft_printf("----------------------------------------------------------------------------------\n");
    ft_printf("4. PRUEBA %%u:\n\n");
    
    total = ft_printf("a) ft_printf:  %u\n", 555);
    printf("a) printf:  %u\n\n", 555);
    
    total = ft_printf("b) ft_printf:  %u\n", -404);
    printf("b) printf:  %u\n\n", -404);
    
    total = ft_printf("c) ft_printf: %u \n", -2147483648);
    printf("c) printf: %u\n\n", -2147483647);

    /*    
    ft_printf("c) ft_printf: %d\n", 21474836487);
    printf("c) printf: %d\n\n", 214748364787);
    */

    ft_printf("----------------------------------------------------------------------------------\n");
    ft_printf("5. PRUEBA %%x/%%X:\n\n");
    
    total = ft_printf("a) ft_printf: El numero %i en hexadecimal es: %x\n", 100, 100);
    printf("a) printf: El numero %i en hexadecimal es: %x\n\n", 100, 100);
    
    total = ft_printf("b) ft_printf: El numero %i en hexadecimal es: %X\n", 42, 42);
    printf("b) printf: El numero %i en hexadecimal es: %X\n\n", 42, 42);
    
    total = ft_printf("c) ft_printf: El numero %i en hexadecimal es: %x en minusculas o %X en mayusculas\n", 2932, 2932, 2932);
    printf("c) printf: El numero %i en hexadecimal es: %x en minusculas o %X en mayusculas\n\n", 2932, 2932, 2932);

    /*    
    ft_printf("c) ft_printf: %c\n", 123);
    printf("c) printf: %c\n\n", 123);
    */

    ft_printf("----------------------------------------------------------------------------------\n");
    ft_printf("6. PRUEBA %%x/%%X:\n\n");
    
	ft_printf("a) ft_printf: La cantidad de caracteres en la prueba son %i y fueron guardados en la direccion de memoria %p\n", total, &total);
    printf("a) printf: La cantidad de caracteres en la prueba son %i y fueron guardados en la direccion de memoria %p\n\n", total, &total);

    ft_printf("----------------------------------FIN DE PRUEBA-----------------------------------\n");
    return 0;
}




    /*ft_printf("Hola mundo\n");
   ft_printf(" %d ",  -51);
    ft_printf("%x", 15);
    printf("%x", 16);
   total = 2;
   ft_printf("%d", 1);
   ft_printf("La frase tiene %d letras\n", total);
   ft_printf("%s\n", "Hola mundo");
   ft_printf("El año es %c uando se invento el pan\n");
    ft_printf("El puntero es %p\n\n", -1);
    //printf("El puntero es %p\n\n", -1);
    printf("El puntero es %x\n\n", 42);
    ft_printf("El numero 100 en hexadecimal es: %x\n\n", 42);
    printf("El puntero es %X\n\n", 42);
    ft_printf("El numero 100 en hexadecimal es: %X\n\n", 42);
    ft_printf("El año es %% cuando se invento el pan\n");
    */
