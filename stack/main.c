#include <stdio.h>
#include <string.h>
#include "pila.h"
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
  TipoPila Pila;
  char  Texto[255];
  char  Opc;

  CrearPila(&Pila);
  do{
    printf("----------------------------------\n");
    printf("PROGRAMA DE DEMOSTRACION DE PILAS\n");
    printf("----------------------------------\n");
    printf("  1 - Push\n");
    printf("  2 - Pop\n");
    printf("  3 - Mostrar la pila\n");
    printf("  4 - Mostrar la cabecera\n");
    printf("  5 - Vaciar Pila\n");
    printf("  0 - Salir\n\n");
	  scanf("%c",&Opc);
    switch (Opc) {
      case '1' : printf("Texto a insertar: ");
        scanf("%s",Texto);
        Push(Texto, &Pila);
         WaitKey();
         break;
      case '2' :
         if(Pop(&Pila))
           printf("El elemento no se elimino correctamente\n\n");
         else
           printf("El elemento se elimino correctamente\n\n");
         WaitKey();
         break;
      case '3' : printf("Contenido\n");
         ListarPila(Pila);
         WaitKey();
         break;
      case '4' : printf("Cabecera\n");
         Cabecera(Pila);
         WaitKey();
         break;
      case '5' : LimpiarPila(&Pila);
         printf("La Pila ha sido vaciada...\n");
         WaitKey();
         break;
    } 
  } while(Opc != '0');
  LimpiarPila(&Pila);
}
//-----------------------------------------------------------------------FIN
