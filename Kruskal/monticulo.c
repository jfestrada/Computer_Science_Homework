#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monticulo.h"
//--------------------------------------------------------------------------
void InsColaP(TNodoColaPri **ColaPri, TAristaGrafo Elemento)
{
    TNodoCola *Cola1 = NULL;
    TNodoCola *Cola2 = NULL;
    TNodoCola *Aux;
    TNodoColaPri *Ptr, *Nuevo;
    int Posicion, i;
    
    if(*ColaPri == NULL)
    {
        *ColaPri = (TNodoColaPri *)malloc(sizeof(TNodoColaPri));
	(*ColaPri)->Info = Elemento;
	(*ColaPri)->Izdo=NULL;
        (*ColaPri)->Dcho=NULL;
        return;
    }

    Ptr = *ColaPri;
    InsertarCola(&Cola1, Ptr);
    while(1)
    {
        SacarCola(&Cola1, &Ptr);
        InsertarCola(&Cola2, Ptr);
        if (Ptr->Izdo != NULL)
            InsertarCola(&Cola1,Ptr->Izdo);
        else
        {
            Ptr->Izdo = (TNodoColaPri *)malloc(sizeof(TNodoColaPri));
            Ptr->Izdo->Info = Elemento;
            Ptr->Izdo->Izdo = NULL;
            Ptr->Izdo->Dcho = NULL;
            Nuevo = Ptr->Izdo;
            break;
        }

        if(Ptr->Dcho != NULL)
            InsertarCola(&Cola1, Ptr->Dcho);
        else
        {
            Ptr->Dcho = (TNodoColaPri *)malloc(sizeof(TNodoColaPri));
            Ptr->Dcho->Info = Elemento;
            Ptr->Dcho->Izdo = NULL;
            Ptr->Dcho->Dcho = NULL;
            Nuevo = Ptr->Dcho;
            break;
        }
    }
  //Al llegar aqui tengo el nodo insertado en el ultimo nivel, lo mas a la izquierda posible
    if((Nuevo->Info).Peso < (Ptr->Info).Peso)
    {
        Nuevo->Info = Ptr->Info;
        Ptr->Info = Elemento;
        Aux = Cola2->Next;
        Posicion = 1;

        while(Aux->Info != Ptr)
        {
            Posicion++;
            Aux = Aux->Next;
	}
		
        while(Posicion >= 1)
        {
            Posicion = Posicion / 2;
            Aux = Cola2->Next;
            for(i = 1; i < Posicion; i++)
                Aux = Aux->Next;
			
            if(Ptr->Info.Peso < Aux->Info->Info.Peso)
            {
                Ptr->Info=(Aux->Info)->Info;
                Aux->Info->Info = Elemento;
                Ptr = Aux->Info;
            }
            else
            {
                break;
            }
        }
    }

    LimpiaCola(&Cola1);
    LimpiaCola(&Cola2);
}
//--------------------------------------------------------------------------
void SupColaP(TNodoColaPri **ColaPri, TAristaGrafo *Elemento)
{        

    TNodoCola *Cola = NULL;
    TNodoColaPri *Ptr;
    TNodoColaPri *NodoUltimo;
    TNodoColaPri *NodoPenultimo;
    TNodoColaPri *Aux;
    TAristaGrafo Ultimo;

    if (*ColaPri == NULL) return;
	
    *Elemento = (*ColaPri)->Info;

    if((*ColaPri)->Izdo == NULL)
    {
        free(*ColaPri);
        *ColaPri = NULL;
        return;
    }

    Ptr = *ColaPri;
    InsertarCola(&Cola, Ptr);
    NodoUltimo = Ptr;
    NodoPenultimo = NULL;
    
    while (1)
    {
        SacarCola(&Cola,&Ptr);
	
        if (Ptr->Izdo != NULL)
        {
            InsertarCola(&Cola, Ptr->Izdo);
            NodoUltimo = Ptr->Izdo;
            NodoPenultimo = Ptr;
	} 
        else
        {
            break;
        }

	if (Ptr->Dcho != NULL )
        {
            InsertarCola(&Cola, Ptr->Dcho);
            NodoUltimo = Ptr->Dcho;
            NodoPenultimo = Ptr;
        }
        else
        {
            break;
        }
    }

    Ultimo = NodoUltimo->Info;
    if(NodoPenultimo->Izdo == NodoUltimo)
        NodoPenultimo->Izdo = NULL;
    else
        NodoPenultimo->Dcho = NULL;

	//free(NodoUltimo);
    (*ColaPri)->Info = Ultimo;
    Ptr = *ColaPri;
    while (1)
    {
        if(Ptr->Izdo != NULL)
        {
            Aux = Ptr->Izdo;
            if(Ptr->Dcho != NULL)
            {
                if(Ptr->Dcho->Info.Peso < Aux->Info.Peso)
                {
                    Aux = Ptr->Dcho;
                }
            }

            if(Aux->Info.Peso < Ptr->Info.Peso )
            {
                Ptr->Info = Aux->Info;
		Aux->Info = Ultimo;
            }
            else
            {
                break;
            }

            Ptr = Aux;

        }
        else
        {
            break;
        }
    }
}
//--------------------------------------------------------------------------
void MuestraNodo(TNodoColaPri *Nodo, unsigned char *Text, int *Stat, int Deep)
{
    if(Nodo == NULL) return;

    if((Nodo->Izdo != NULL) || (Nodo->Dcho != NULL))
        Text[Deep] = 194;
    else
        Text[Deep] = 196;

    Text[Deep + 1] = 0;
    printf(" %s> %d,%d (%d)\n", Text, Nodo->Info.VAdy1, Nodo->Info.VAdy2, Nodo->Info.Peso);

    if(Text[Deep -1] != 192)
        Text[Deep-1] = 179;

    if((Nodo->Izdo != NULL) && (Nodo->Dcho != NULL))
    {
        Stat[Deep] = 1;
        Text[Deep] = 195;
    }
    else
        Text[Deep] = 192;

    if((Deep >0) && (Stat[Deep-1] != 1))
        Text[Deep-1] = 32;

    MuestraNodo(Nodo->Izdo, Text, Stat, Deep + 1);
    Stat[Deep] = 0;
    Text[Deep] = 192;
    MuestraNodo(Nodo->Dcho, Text, Stat, Deep + 1);
    Text[Deep] = 0;
}
//--------------------------------------------------------------------------
void MuestraColaPri(TNodoColaPri *ColaPri)
{
  char  *Text;
  int   *Stat;
  if(ColaPri != NULL)
  {
    Text = (char *)calloc(sizeof(char), 1000);
    Stat = (int *) calloc(sizeof(int), 1000);
    MuestraNodo(ColaPri, Text, Stat, 0);
  }else
  {
      printf("La cola de prioridad está vacía\n");
  }
}
//--------------------------------------------------------------------------
void LimpiarColaP(TNodoColaPri **ColaPri)
{
    TAristaGrafo Aux;

   // printf("Elementos eliminados (en orden de prioridad): \n");
    
    while(*ColaPri != NULL)
    {
        SupColaP(ColaPri, &Aux);
	//printf("(%s, %d)\n",  Aux.Nombre, Aux.Peso);
    }
}
//--------------------------------------------------------------------------
void InsertarCola(TNodoCola **Cola, TNodoColaPri *Elemento)
{
    TNodoCola  *Nuevo;
    Nuevo = (TNodoCola*)malloc(sizeof(TNodoCola));
    Nuevo->Info = Elemento;
    if(*Cola == NULL)
    {
        *Cola = Nuevo;
        (*Cola)->Next = *Cola;
    }
    else
    {
        Nuevo-> Next = (*Cola)->Next;
        (*Cola)->Next = Nuevo;
        *Cola = Nuevo;
    }
}
//--------------------------------------------------------------------------
void SacarCola(TNodoCola **Cola, TNodoColaPri **Elemento)
{
    TNodoCola *Aux;
    Aux = (*Cola)->Next;
    *Elemento = Aux->Info;

    if(Aux == *Cola)
    {
        free(Aux);
	*Cola = NULL;
    }
    else
    {
        (*Cola)->Next = Aux->Next;
	free(Aux);
    }
}
//--------------------------------------------------------------------------
void LimpiaCola(TNodoCola **Cola)
{
    TNodoCola *Aux;
    Aux = *Cola;

    if(*Cola != NULL)
    {
        *Cola = (*Cola)->Next;
        Aux->Next = NULL;
        while(*Cola != NULL)
        {
            Aux = (*Cola)->Next;
            free(*Cola);
            *Cola = Aux;
        }
    }
}
//-----------------------------------------------------------------------FIN
  
  
