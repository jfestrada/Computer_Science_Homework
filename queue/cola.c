#include <memory.h>
#include <string.h>
#include <stdio.h>
#include "cola.h"

//--------------------------------------------------------------------------
void CrearCola(TipoCola *Cola) {
  Cola->Fin  = NULL;
  Cola->Inicio = NULL;
}
//--------------------------------------------------------------------------
void LimpiarCola(TipoCola *Cola) {
  int fin = 0;
 if(Cola->Inicio != NULL)
  {
  while(fin!=-1){
      fin = SupCola(Cola);
  }
  Cola->Fin=Cola->Inicio;
 }else
     printf("\nLa cola está vacía\n");
}
//--------------------------------------------------------------------------
void InsCola(char *Texto, TipoCola *Cola) {
  if(Cola->Inicio == NULL) //quiere decir que es el primero de la Cola
  {
      Cola->Inicio = (TipoNodo *)malloc(sizeof(TipoNodo));
      strcpy(Cola->Inicio->Texto, Texto);
      Cola->Inicio->Siguiente = NULL;
      Cola->Fin = (TipoNodo *)malloc(sizeof(TipoNodo));
      Cola->Fin= Cola->Inicio;
      Cola->Fin->Siguiente=NULL;
  } 
  else //se inserta al final
  {
      TipoNodo *Temp;
      Temp = (TipoNodo *)malloc(sizeof(TipoNodo));
      strcpy(Temp->Texto, Texto);
      Temp->Siguiente=NULL;
      Cola->Fin->Siguiente=Temp;
      Cola->Fin=Temp;
  }
}
//--------------------------------------------------------------------------
int SupCola(TipoCola *Cola) {
  if(Cola->Inicio == NULL)
  {
    return -1;//la pila está vacía por lo que no hacemos nada
  } 
  else//movemos cola->inicio una posición atrás y liberamos el inicio
  {
      TipoNodo *Temp;
      Temp = Cola->Inicio;
      Cola->Inicio=Cola->Inicio->Siguiente;
      printf("\nSe saca el elemento: %s\n",Temp->Texto);
      free(Temp);
  }
  return 0;
}
//--------------------------------------------------------------------------
void ListarCola(TipoCola Cola) {
  int fin=1;
  TipoNodo  *Temp = Cola.Inicio;
if (Temp!=NULL){
 while (fin!=-1) 
 {
     printf("--> %s\n",Temp->Texto);
     if(Temp->Siguiente==NULL)
     {
         fin = -1;
     }
     else
     {
        fin++;
        Temp=Temp->Siguiente;
     }
 }
}else
      printf("La cola está vacía\n");
}
//--------------------------------------------------------------------------
void PrimerElemento(TipoCola Cola) {

  TipoNodo  *Temp = Cola.Inicio;
  if (Temp!=NULL)//devuelve un puntero al último elemento
    printf("--> %s\n",Temp->Texto);
  else
    printf("La cola está vacía\n");

}

void UltimoElemento(TipoCola Cola) {

  TipoNodo  *Temp = Cola.Fin;
  if (Temp!=NULL)//devuelve un puntero al último elemento
    printf("--> %s\n",Temp->Texto);
  else
    printf("La cola está vacía\n");

}
//-----------------------------------------------------------------------FIN
