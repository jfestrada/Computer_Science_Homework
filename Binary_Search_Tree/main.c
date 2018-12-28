#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "abb.h"
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
void ListarPalabras(TipoNodoABB *ABBPalabras){
    if(ABBPalabras->hijo_i!=NULL)
	ListarPalabras(ABBPalabras->hijo_i);
    if(ABBPalabras!=NULL)
	ListarLista(ABBPalabras->Info.ListaLetra);
    if(ABBPalabras->hijo_d!=NULL)
	ListarPalabras(ABBPalabras->hijo_d);
}
//--------------------------------------------------------------------------

int main() {
  TipoNodoABB *ABBPalabras;
  TipoInfoABB InfoABB;
  TipoInfoABB *PInfoABB;
  char Datos[200], Palabra[255], Opcion, Letra;

  CrearABB(&ABBPalabras);
  do {
	  printf("--------------------------------------------------------\n");
	  printf("  PROGRAMA DE DEMOSTRACION PARA GESTION DE UN ARBOL BINARIO  \n");
	  printf("--------------------------------------------------------\n\n");
	  printf("  1 - Listar todas las palabras que empiecen por una letra\n");
	  printf("  2 - Añadir una nueva palabra\n");
	  printf("  3 - Crear una nueva letra\n");
	  printf("  4 - Eliminar una palabra\n");
	  printf("  5 - Limpiar el arbol\n");
	  printf("  6 - Listar palabras en orden alfabetico\n");
	  printf("  0 - Salir\n");
	  printf("--------------------------------------\n");
	  fflush(stdin);
	  scanf("%c",&Opcion);
	  fflush (stdin);
	  switch(Opcion) {
            case '1' :
                printf("Letra que desea listar: ");
                fflush (stdin);
                scanf("%s", &InfoABB.Letra);
                //utilizo solo mayusculas para no duplicar las letras
                InfoABB.Letra=toupper(InfoABB.Letra);
                PInfoABB = BuscarABB(ABBPalabras, InfoABB.Letra);

                if(PInfoABB == NULL)
                    printf("No se encontró la letra solicitada...\n");
                else
                {
                    ListarLista(PInfoABB->ListaLetra);
                }
                WaitKey();

                break;

            case '2' :
                printf("Introduzca la letra por la que empieza la palabra: ");
                fflush (stdin);
                scanf("%s", &InfoABB.Letra);
                InfoABB.Letra=toupper(InfoABB.Letra);
                PInfoABB = BuscarABB(ABBPalabras, InfoABB.Letra);
                if(PInfoABB == NULL)
                    printf("No se encontró la letra solicitada ...\n");
                else
                {
                    printf("Palabra a insertar: ");
                    fflush(stdin);
                    scanf("%s",&Datos);
                    sprintf(Palabra, "%s",Datos);
                    NuevoElemento(Palabra, &(PInfoABB->ListaLetra));
                }
                WaitKey();

                break;

            case '3' :
                printf("Letra a insertar: ");
                fflush (stdin);
                scanf("%s", &InfoABB.Letra);
                InfoABB.Letra=toupper(InfoABB.Letra);
                if(BuscarABB(ABBPalabras, InfoABB.Letra) != NULL)
                    printf("La letra ya existe...\n");
                else
                {
                    CreaLista(&InfoABB.ListaLetra);
                    InsertarABB(&ABBPalabras, &InfoABB);
                    printf("La letra ha sido creada correctamente...\n");
                }

                WaitKey();
                
                break;

            case '4' :
                printf("Letra por la que empieza la palabra a eliminar: ");
                fflush (stdin);
                scanf("%s", &InfoABB.Letra);
                InfoABB.Letra=toupper(InfoABB.Letra);
                PInfoABB = BuscarABB(ABBPalabras, InfoABB.Letra);
                if(PInfoABB == NULL)
                    printf("La letra no existe...\n");
                else
                {
                    printf("Palabra a eliminar: ");
                    fflush(stdin);
                    scanf("%s",&Datos);
                    if(EliminaElemento(Datos, &(PInfoABB->ListaLetra))==0)
                        printf("La palabra ha sido eliminada correctamente...\n");
                    else
                        printf("La palabra no se ha eliminado ya que no existe...\n");
                    if(PInfoABB->ListaLetra.Nodo==NULL)
                        EliminarABB(&ABBPalabras,&(PInfoABB->Letra));
                }

                WaitKey();

                break;
	      	
            case '5':
                LimpiaArbol(&ABBPalabras);

                break;

            case '6':
                ListarPalabras(ABBPalabras);

                break;

	  }
  } while(Opcion != '0');
  return 0;
}
