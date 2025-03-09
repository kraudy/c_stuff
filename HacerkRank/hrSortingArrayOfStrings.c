#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lexicographic_sort(const char* a, const char* b)
{
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return -strcmp(a, b);
}

int countDistinctCharacters(const char *str) {
    int seen[256] = {0}; // Assuming ASCII characters
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (seen[(unsigned char)str[i]] == 0) {
            seen[(unsigned char)str[i]] = 1;
            count++;
        }
    }

    return count;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {

    if (countDistinctCharacters(a) == countDistinctCharacters(b))
    {
        return lexicographic_sort(a, b);
    }

    if (countDistinctCharacters(a) > countDistinctCharacters(b))
    {
        return 1;
    }

    return 0;

}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a) == strlen(b))
    {
        return lexicographic_sort(a, b);
    }
    
    if (strlen(a) > strlen(b))
    {
        return 1;
    }

    return 0;

}


void string_sort(char **arr, const int len, int (*comp_fnc)(const char* a, const char* b))
{
    //qsort(arr, len, sizeof(char *), (*comp_fnc));
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if ((*comp_fnc)(arr[j], arr[j + 1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

//int compareStrings(const void *a, const void *b) {
//    return strcmp(*(const char **)a, *(const char **)b);
//}

int main()
{

    int n;
    puts("Ingresar entero: ");
    scanf("%d", &n);
    
    // Esto se hace de esta forma porque se quiere crear el array dinamicmaente
    // sino seria simplemente declarar el array de string y asignarle un puntero
    char** arr;
    // Aqui primero asigna memoria para un array de punteros segun el tamanio de un puntero char
    // como malloc retorna void**, le hace un cast a char**
    arr = (char**) malloc(n * sizeof(char*)); // Importante notar que sizeof se usa con char*(8byte) y no con char
    if (arr == NULL)
    {
        printf("Error de alocacion \n");
        return (1);
    }
    puts("Address of arr:");
    printf("%p\n", arr);
    

    for (int i = 0; i < n; i++)
    {
        // Aqui le esta asigando espacio de memoria a cada puntero segun el tamanio de un char
        // *arr apunta a la direccion de memoria del array de punteros
        // Hay algo que quiero aclarar, *(arr + 1) representa una direccion de memoria, por eso a prinf la agarra bien, sin necesidad de &
        *(arr + i) = (char*)malloc(32 * sizeof(char));
        printf("Addr del puntero %d\n",i);
        printf("%p\n",*(arr + i));

        puts("Ingresar cadena");
        scanf("%s", *(arr + i));

        *(arr + i) = (char*)realloc(*(arr + i), (strlen(*(arr + i)) + 1)* sizeof(char));
    }

    
    string_sort(arr, n, lexicographic_sort);
    puts("Orden Lexicographic");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", *(arr + i));
    }
    
    string_sort(arr, n, lexicographic_sort_reverse);
    puts("Orden Inverso Lexicographic");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", *(arr + i));
    }

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    puts("Orden Por caracteres dieferentes");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", *(arr + i));
    }

    string_sort(arr, n, sort_by_length);
    puts("Orden Por longitud");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", *(arr + i));
    }

    free(arr); 

    return (0);
}
