#include <stdio.h>
#include <string.h>
#include "lista.h"
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
  TipoLista Lista;
  char  Texto[255];
  char  Opc;

  CrearLista(&Lista);
  do{
    printf("----------------------------------\n");
    printf("PROGRAMA DE DEMOSTRACION DE LISTAS\n");
    printf("----------------------------------\n");
    printf("  1 - Insertar elemento\n");
    printf("  2 - Eliminar elemento\n");
    printf("  3 - Listar contenido\n");
    printf("  4 - Vaciar lista\n");
    printf("  5 - Buscar elemento\n");    
    printf("  0 - Salir\n\n");
	  scanf("%c",&Opc);
    switch (Opc) {
      case '1' : printf("Texto a insertar: ");
                 scanf("%s",Texto);
                 if(NuevoElemento(Texto, &Lista))
		               printf("El elemento ya existe\n");
		             else
		               printf("El elemento se agrego correctamente\n");
		             WaitKey();
		             break;
      case '2' : printf("Texto a eliminar: ");
		             scanf("%s",Texto);
                 if(EliminaElemento(Texto, &Lista))
		               printf("El elemento no se elimino correctamente\n\n");
		             else
		               printf("El elemento se elimino correctamente\n\n");
		             WaitKey();
		             break;
      case '3' : printf("Orden - Contenido\n");
                             ListarLista(Lista);
		             WaitKey();
		             break; 
      case '4' : EliminaLista(&Lista);
		             printf("La lista ha sido vaciada...\n");
		             WaitKey();
		             break;
      case '5' : printf("Elemento a buscar : ");

		            scanf("%s",Texto);
                            BuscarLista(Texto,Lista);
                            WaitKey();
		            break;
    } 
  } while(Opc != '0');
  EliminaLista(&Lista);
}
//-----------------------------------------------------------------------FIN
