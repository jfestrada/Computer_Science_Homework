#include <stdio.h>
#include <string.h>
#include "cola.h"
//--------------------------------------------------------------------------
void WaitKey() {
  char Key;
  fflush(stdin);
  printf("Pulse INTRO para continuar...");
  scanf("%c", &Key);
  scanf("%c", &Key);
  fflush(stdin);
}
//--------------------------------------------------------------------------
int main() { 
  TipoCola Cola;
  char  Texto[255];
  char  Opc;

  CrearCola(&Cola);
  do{
    printf("----------------------------------\n");
    printf("PROGRAMA DE DEMOSTRACION DE COLAS\n");
    printf("----------------------------------\n");
    printf("  1 - Insertar elemento\n");
    printf("  2 - Sacar elemento\n");
    printf("  3 - Mostrar la cola\n");
    printf("  4 - Mostrar primer elemento\n");
    printf("  5 - Mostrar último elemento\n");
    printf("  6 - Vaciar Cola\n");
    printf("  0 - Salir\n\n");
	  scanf("%c",&Opc);
    switch (Opc) {
      case '1' : printf("Texto a insertar: ");
        scanf("%s",Texto);
        InsCola(Texto, &Cola);
         WaitKey();
         break;
      case '2' : 
         if(SupCola(&Cola))
           printf("El elemento no se elimino correctamente\n\n");
         else
           printf("El elemento se elimino correctamente\n\n");
         WaitKey();
         break;
      case '3' : printf("Contenido\n");
         ListarCola(Cola);
         WaitKey();
         break;
      case '4' : printf("Primer Elemento\n");
         PrimerElemento(Cola);
         WaitKey();
         break;
      case '5' : printf("Último Elemento\n");
         UltimoElemento(Cola);
         WaitKey();
         break;
      case '6' : LimpiarCola(&Cola);
         printf("La Cola ha sido vaciada...\n");
         WaitKey();
         break;
    } 
  } while(Opc != '0');
  LimpiarCola(&Cola);
}
//-----------------------------------------------------------------------FIN
