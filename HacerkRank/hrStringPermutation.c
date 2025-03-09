#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cambio(char *s1, char *s2)
{
    char *temp = s2;
    s1 = s2;
    s2 = temp;
}

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/

    puts("==============================");
    int k = -1;
    // Aqui parece que se esta comparando si el elemento previo es menor que el siguiente
    // si llega al final y no se econtro un elemento previo menor que el siguiente, entonces ya no hay nada que ordenar
    // esto busca el utlimo elemento menor
    for (int i = 0; i < n-1; i++)
    {
        if (strcmp(s[i], s[i+1]) < 0)
            k = i;
    }
    if (k == -1) return 0;

    int l = -1;
    // Este busca el ultimo elemento mayor comenzando desde el ultimo menor
    for (int i = k+1; i < n; i++)
    {
        if(strcmp(s[k], s[i]) < 0)
            l = i;
    }

    char *tmp = s[k];
    s[k] = s[l];
    s[l] = tmp;

    puts("Cadena despues del primer cambio");
	for (int i = 0; i < n; i++)
		printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    // i seria el siguiente elemento del menor, j seria la ultima cadena
    int i = k+1, j = n-1;
    // Mientras la cadena siguiente a la que era la menor, sea diferente del ultimo elmento
    while (i < j) {
        // Cuando hay un 1 de diferencia, quedan iguales
        // todavia no lo entiendo bien
        tmp = s[i];
        s[i++] = s[j];
        s[j--] = tmp;
    }


    puts("==============================");
    return 1;
}

int next_permutation2(int n, char **s)
{
    puts("==============================");
    /*
        Las cadenas son recibidas en orden de menor a mayor 
        En la primer iteracion, el programa valida si la 1 es mayor que la 2, lo que es falso por el orden en que se recibieron, 
        entonces a i no se le resta y agarra el valor de la derecha = 2

        Despues trata de buscar el elemento mas a la derecha de i-1 donde i-1 sea mayor, que en esta primera iteracion tampoco existe
        J queda como 2

        Luego se realiza el cambio de de i-1 con j, esto hace que la mayor quede de primero, lo cual hara que en la proxima iteracion le reste 1 a i

        Despues viene lo de la reversa, si i<j implica que se encontro una cadena mayor antes que una menor en el array
        
    */ 
     // Find non-increasing suffix
    int i = n - 1;
    while(i > 0 && strcmp(s[i - 1],s[i]) >= 0) 
        i--;    // find key
    if (i <= 0) 
    return 0;
    
    // Swap key with its successor in suffix
    int j = n - 1;
    while(strcmp(s[i - 1],s[j]) >= 0) 
        j--;    // find rightmost successor to key
    
    /*
        Lo que se quiere es tener la cadena ordenada de mayor a menor, es recibida de menor a mayor
        este primer swap lo que hace es pasar de (menor, mayor) => (mayor, menor)
        Luego de este cambio, i tiene el valor del (menor)
    */
    char *tmp = s[i - 1];
    s[i - 1] = s[j];
    s[j] = tmp;

	for (int i = 0; i < n; i++)
		printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    
    // Reverse the suffix
    j = n - 1;
    while(i < j) 
    {
        // si hubo un cambio, en este caso, i contiene la (menor)
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
        for (int i = 0; i < n; i++)
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    }

    puts("============Permutada==================");
    return 1;
     

}

void mi_permutacion(int n, char **s)
{
    // Numero de permutaciones = n!
    for (int i = n; i < n - 1; i++)
    {
        cambio(s[i], s[i + 1]);
		printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    }
    
}

int main()
{
	char **s;
	int n;

    puts("Ingresar numero:");
	scanf("%d", &n);
    // calloc, a diferencia de malloc, reserva un espacion de mameria para n elementos de sizeof, malloc reserva el espacio completo de memoria
    // reserva espacion para n punteros tipo char
	s = (char **) calloc(n, sizeof(char*));

	for (int i = 0; i < n; i++)
	{
		s[i] = (char *) calloc(11, sizeof(char));
        puts("Ingresar cadena menor a 11 chars");
		scanf("%s", s[i]);
	}

	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation2(n, s));

	for (int i = 0; i < n; i++)
		free(s[i]);

	free(s);
	return 0;
}