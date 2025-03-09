#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void main ()
{
    char cadena[32] = "";
    int ch, i;
    puts("Ingresar cadena");    

    i = 0;
    while ((ch = getchar()) != '\n')
    {
        cadena[i] = ch;
        i++;
        if(i == 31) break;
    }
    cadena[i] = '\0';

    i = 0;
    while (putchar(cadena[i++]))
    {
       ;
    }
     

}
