#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void operaciones(void);
void validarDigito(void);
void cadenas(void);
void leyendoBuffer(void);
void arreglos(void);
void estructuras(void);
void variables(void);

int main(){

  return(0);
}

void variables(void)
{
  char a;  // 1 byte
  short b; // 2 byte
  int c;   // 4 byte
  long d;  // 8 byte
  float e; // 4 byte
  double f;// 8 byte


  char* pa;  // 8 byte
  short* pb; // 8 byte
  int* pc;   // 8 byte
  long* pd;  // 8 byte
  float* pe; // 8 byte
  double* pf;// 8 byte

  printf("char %lu \n short %lu \n int %lu \n long %lu \n float %lu \n double %lu \n",
    sizeof(a), sizeof(b), sizeof(c), sizeof(d), sizeof(e), sizeof(f)
    );

  // Parece que todos los punteros son de size 8 bytes
  printf("pchar %lu \n pshort %lu \n pint %lu \n plong %lu \n pfloat %lu \n pdouble %lu \n",
    sizeof(pa), sizeof(pb), sizeof(pc), sizeof(pd), sizeof(pe), sizeof(pf)
    );

}

void estructuras(void)
{
  struct bankStruct {
    int account;
    float balance;
  };
  struct bankStruct bank;
  struct bankStruct balance = {
    5234,
    898.325
  };

  bank.account = 1234;
  bank.balance = 525.987;

  printf("El account: %d tiene balance: %f\n", 
    bank.account, bank.balance
    );
  printf("El account: %d tiene balance: %f\n", 
    balance.account, balance.balance
    );

}

void arreglos(void)
{
  int i[] = {1,2,3}; 
  int *p = i;
  char nombres [4][7] = {
    "uno",
    "dos",
    "tres",
    "cuatro"
  };

  printf("%p\n",i);
  printf("%p\n",p);


  for (int j = 0; j < 3; j++)
  {
    printf("%d\n", *(p + j));
  }

  for (int j = 0; j < 4; j++)
  {
    printf("%s\n",nombres[j]);
  }
   

}


void leyendoBuffer(void)
{
  char input[64];
  printf("Ingresar instrucciones: \n");
  fgets(input, 64, stdin);
  printf("Longitud de caden: %d", (int)strlen(input));
}

void cadenas(void)
{
  char string[] = "Cadena larga";
  int len;

  len = strlen(string);
  printf("Longitud de la cadena: \n");
  puts(string);
  printf("es %d",len);

}
// Valida que los caracteres digitados sean digitos
void validarDigito(void){
  int acter;
  do
  {
    acter = getchar();
    if(isdigit(acter))
      putchar(acter);

  } while (acter != '\n');
  
}

void operaciones(void){
  printf("Raiz cuadrada de 2: %f \n", sqrt(2));
  printf("2 a la 8: %f \n", pow(2.0, 8.0));
}