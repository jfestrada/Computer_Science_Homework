#include <memory.h>
#include <string.h>
#include <stdio.h>
#include "pila.h"

//--------------------------------------------------------------------------
void CrearPila(TipoPila *Pila) {
  Pila->Nodo  = NULL;
}
//--------------------------------------------------------------------------
void LimpiarPila(TipoPila *Pila) {
 int fin = 0;
 if(Pila->Nodo != NULL)
  {
  while(fin!=-1)
      fin = Pop(Pila);
 }else
     printf("\nLa pila está vacía\n");
}
//--------------------------------------------------------------------------
void Push(char *Texto, TipoPila *Pila) {
  if(Pila->Nodo == NULL) //quiere decir que es el primero de la Pila
  {
      Pila->Nodo = (TipoNodo *)malloc(sizeof(TipoNodo));
      strcpy(Pila->Nodo->Texto, Texto);
      Pila->Nodo->Siguiente = NULL;
  } 
  else //se inserta al final
  {
      TipoNodo *Temp;
      Temp = (TipoNodo *)malloc(sizeof(TipoNodo));
      strcpy(Temp->Texto, Texto);
      Temp->Siguiente=Pila->Nodo;
      Pila->Nodo=Temp;
  }
}
//--------------------------------------------------------------------------
int Pop(TipoPila *Pila) {
  if(Pila->Nodo == NULL)
  {
      printf("\nLa pila está vacía\n");
    return -1;//la pila está vacía por lo que no hacemos nada
  } 
  else//buscamos el último elemento en entrar
  {
      TipoNodo *Temp;
      Temp = (TipoNodo *)malloc(sizeof(TipoNodo));
      Temp = Pila->Nodo;
      Pila->Nodo=Pila->Nodo->Siguiente;
      printf("\nSe saca el elemento: %s\n",Temp->Texto);
      free(Temp);
  }
  return 0;
}
//--------------------------------------------------------------------------
void ListarPila(TipoPila Pila) {
  int fin=1;
  TipoNodo  *Temp = Pila.Nodo;
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
      printf("La pila está vacía\n");
}
//--------------------------------------------------------------------------
void Cabecera(TipoPila Pila) {
  TipoNodo  *Temp = Pila.Nodo;
  if (Temp!=NULL){//devuelve un puntero al último elemento
    printf("--> %s\n",Temp->Texto);
  }else
      printf("La pila está vacía\n");

}
//-----------------------------------------------------------------------FIN
