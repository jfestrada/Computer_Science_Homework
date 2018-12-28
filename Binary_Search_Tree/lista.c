#include <memory.h>
#include <string.h>
#include <stdio.h>
#include "lista.h"

//--------------------------------------------------------------------------
void CreaLista(TipoLista *Lista) {
  Lista->Nodo  = NULL;
}
//--------------------------------------------------------------------------
void EliminaLista(TipoLista *Lista) {
  TipoNodo *Temp;
  int fin = 1;

  while(fin!=-1)//Lista->Nodo->Siguiente !=NULL)
  {
      if(Lista->Nodo!=NULL)
      {
        Temp = Lista->Nodo;
        Lista->Nodo = Temp->Siguiente;
        free(Temp);
      }else
        fin=-1;
  }
}
//--------------------------------------------------------------------------
int NuevoElemento(char *Texto, TipoLista *Lista) {
  if(Lista->Nodo == NULL) //quiere decir que es el primero de la lista
  {
      Lista->Nodo = (TipoNodo *)malloc(sizeof(TipoNodo));
      strcpy(Lista->Nodo->Texto, Texto);
      Lista->Nodo->Siguiente = NULL;
  } 
  else //hay que buscar el lugar adecuado
  {
	TipoNodo *Temp = Lista->Nodo;
	if(strcmp(Lista->Nodo->Texto, Texto) == 0)
            return -1; //el elemento a insertar ya existe por lo que se para
    
        if(strcmp(Lista->Nodo->Texto, Texto) > 0) //el elemento a insertar será el primero
        {
	  Lista->Nodo = (TipoNodo *)malloc(sizeof(TipoNodo));
	  strcpy(Lista->Nodo->Texto, Texto);
	  Lista->Nodo->Siguiente = Temp;
	} 
        else
        {
	  TipoNodo *Ant  = (TipoNodo*)&(Lista->Nodo);
          while(Temp != NULL)
          {
              if(strcmp(Temp->Texto, Texto) == 0)
                  return -1; //el elemento ya existe y salimos de la función
              if(strcmp(Temp->Texto, Texto) > 0)
                  break;//hemos encontrado su lugar y salimos para la asignación
              Ant = Temp;
              Temp = Temp->Siguiente;
	  }
          Ant->Siguiente = (TipoNodo *)malloc(sizeof(TipoNodo));
	  strcpy(Ant->Siguiente->Texto, Texto);
	  Ant->Siguiente->Siguiente = Temp;
	}
  }
  return 0;
}
//--------------------------------------------------------------------------
int EliminaElemento(char *Texto, TipoLista *Lista) {
  if(Lista->Nodo == NULL)
  {
    return -1;//la lista está vacía por lo que no hacemos nada
  } 
  else
  {
    TipoNodo *Temp = Lista->Nodo;
    if(strcmp(Lista->Nodo->Texto, Texto) == 0) //lo hemos encontrado a la primera
    {
        Lista->Nodo = Temp->Siguiente;
        free(Temp);
        return 0;
    } 
    else
    {
        TipoNodo *Ant = Lista->Nodo;
        while(Temp != NULL)
        {
            if(strcmp(Temp->Texto, Texto) == 0)
                break; //lo hemos encontrado y salimos para eliminarlo
            Ant = Temp;
	    Temp = Temp->Siguiente;
        }
        if(Temp == NULL)
            return -1;
        Ant->Siguiente = Temp->Siguiente;
        free(Temp);
        return 0;
    }
  }
}
//--------------------------------------------------------------------------
void ListarLista(TipoLista Lista) {
  int fin=1;
  TipoNodo  *Temp = Lista.Nodo;
if (Temp!=NULL){
 while (fin!=-1) 
 {
     printf("%5d - %s\n", fin, Temp->Texto);
     if(Temp->Siguiente==NULL)
         fin = -1;
     else
     {
        fin++;
        Temp=Temp->Siguiente;
     }
 }
}else
      printf("La lista está vacía\n");
}
//--------------------------------------------------------------------------
void BuscarLista(char *Texto, TipoLista Lista) {

  int fin=1;
  TipoNodo  *Temp = Lista.Nodo;
  if (Temp!=NULL){
 while (fin!=-1)
 {
     if(strcmp(Texto,Temp->Texto)==0)
     {
         printf("%5d - %s\n", fin, Temp->Texto);
         fin = -1;
     }
     else if(Temp->Siguiente==NULL)
     {
         fin = -1;
         printf("No se ha encontrado el elmento buscado\n");
     }
     else
     {
        fin++;
        Temp=Temp->Siguiente;
     }
 }
  }else
      printf("La lista está vacía\n");

}
//-----------------------------------------------------------------------FIN
