#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define SIZE 1024
void printPunteros(void);
void masPunteros(void);
void cadenasPunteros(void);
void memoria(void);
void creandoBuffer(void);
void probandoMallocCalloc(void);

// funcion con puntero como parametro
void menos10(int *v);
char* longer(char *s1, char *s2);

int main(){

  probandoMallocCalloc();

  return(0);
}

void probandoMallocCalloc(void)
{
    int n = 3;
    int m = 10;
    char **pm;
    char **pc;

    // Reservando memoria con malloc
    pm = (char **) malloc(n * sizeof(char *));
    if (pm == NULL) return;
    for (int i = 0; i < n; i++)
    {
        *(pm + i) = (char *) malloc(m * sizeof(char));
        puts("Ingresar cadena malloc");
        scanf("%s", *(pm + i));
    }
    // Reservando memoria con calloc
    pc = (char **) calloc(3, sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        *(pc + i) = (char *) calloc(m, sizeof(char));
        puts("Ingresar cadena calloc");
        scanf("%s", *(pc + i));
    }
    
    
    for (int i = 0; i < n; i++)
    {
        printf("Cadena malloc: %s\n", *(pm + i));
        printf("Cadena calloc: %s\n", *(pc + i));
    }
    


    free(pm);
    free(pc);
}

void creandoBuffer(void)
{
    char *buffer;
    buffer = (char*) malloc(sizeof(char) * 24);
    if (buffer == NULL) return;

    puts("Ingresar nombre:");
    fgets(buffer, sizeof(char) * 24, stdin);
    printf("Hola: %s\n", buffer);

    free(buffer);
}

void memoria(void)
{
    
    int *scores, x;
    scores = malloc(sizeof(int) * 4);
    if (scores == NULL)
    {
        return;
    }

    printf("%p\n",scores);
    printf("%p\n",scores + 1);
    printf("%p\n",scores + 2);
    printf("%p\n",scores + 3);

    *(scores) = 1;
    *(scores + 1) = 4;
    *(scores + 2) = 6;
    *(scores + 3) = 8;
    
    printf("%d\n",*(scores));
    printf("%d\n",*(scores + 1));
    printf("%d\n",*(scores + 2));
    printf("%d\n",*(scores + 3));

    free(scores);        

}

char* longer(char *s1, char *s2)
{
    if (strlen(s1) > strlen(s2))
    {
        return s1;
    }
    return s2;
    
}

void menos10(int *v)
{
    *v -= 10;
}

void cadenasPunteros(void)
{
  char *strings[] = {"Hola", "Mundo", "Puntero"};
  char **ppstrings = strings;
  printf("%p\n", strings);
  printf("%s\n", *strings);


  printf("%p\n", ppstrings);
  printf("%p\n", *ppstrings);
  printf("%s\n", *ppstrings);
}


void masPunteros(void)
{

  char* pc = NULL;
  printf("%p\n",pc); // Muestra el "dato" que guarda el punero, es decir, la direccion de memoria, en este caso NULL
  printf("%p\n",&pc);// Muestra la direccion de memoria del punero

  int a, b;
  int *p;

  // Interesante como puedo camibiarle directamente el valor que tiene la direccion de memoria de una variable desde un puntero
  p = &a;
  *p = 1;
  p = &b;
  *p = 2;
  printf("a: %d | b: %d\n",a, b);

  // Secreto: Los array tambien representan un puntero
  int array[] = {1,2,3};
  printf("%p\n",array);
  printf("%d\n",*(array));
  // Se asigna el puntero directamente al array
  int *parry;
  parry = array;
  *(parry) = 3;
  printf("%d\n",*(array));
  // Tambien se puede asignar a un elemento
  parry = &array[1];
  *(parry) = 7;
  printf("%d\n",*(array + 1));

  // Asignar puntero a array de varias dimensiones
  char cadenas [3][7] = {
    "Hola",
    "Dos",
    "Ulti"
  };
  char (*pcadenas)[7];
  pcadenas = cadenas;
  printf("%s\n", *(pcadenas));

  char texto[] = "Hola texto";
  char *ptexto;
  ptexto = texto;
  printf("%s\n", ptexto);// Si le pongo *ptexto lo que hace es pasale el primer caracter como entero

}

/*
  Cuando a una variable normal se le da printf, se muestra el dato que tiene guardado en la direccion de memoria asiganada al variable
  lo que puede ser un int, char, float, etc
  Pero cuando se le da print a un puntero, lo que muestra es la direccion de memoria que tiene en su direccion de memoria
*/
void printPunteros(void)
{
  int a = 3;
  int *b = &a;

  printf("%p\n",&a);
  printf("%p\n",b);
  printf("%d\n",*b);
  printf("%d\n",a);
}
