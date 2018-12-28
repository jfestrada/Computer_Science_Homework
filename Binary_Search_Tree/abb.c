#include "abb.h"
//--------------------------------------------------------------------------
TipoInfoABB *BuscarABB(TipoNodoABB *Arbol, char Texto) {
  if(Arbol == NULL)
    return NULL;
  else if(Arbol->Info.Letra < Texto)
    return BuscarABB(Arbol->hijo_d, Texto);
  else if(Arbol->Info.Letra > Texto)
    return BuscarABB(Arbol->hijo_i, Texto);
  else
    return &(Arbol)->Info;
}

//--------------------------------------------------------------------------
void CrearABB(TipoNodoABB **Arbol) {
  *Arbol = NULL;
}
//--------------------------------------------------------------------------
void InsertarABB(TipoNodoABB **Arbol, TipoInfoABB *Info) {
  if(*Arbol == NULL)
  {
    *Arbol = (TipoNodoABB*)malloc(sizeof(TipoNodoABB));
    memcpy(&((*Arbol)->Info), Info, sizeof(TipoInfoABB));
    (*Arbol)->hijo_i  = NULL;
    (*Arbol)->hijo_d = NULL;
  } 
  else if(((*Arbol)->Info.Letra < Info->Letra))
  {
    InsertarABB(&(*Arbol)->hijo_d, Info);
  } 
  else if(((*Arbol)->Info.Letra>Info->Letra))
  {
    InsertarABB(&(*Arbol)->hijo_i, Info);
  }
}
//--------------------------------------------------------------------------
void ReemplazaABB(TipoNodoABB **Arbol, TipoNodoABB **Aux, TipoNodoABB *Padre) {
  if ((*Arbol)->hijo_d == NULL)
  {
    memcpy(&((*Aux)->Info), &((*Arbol)->Info), sizeof(TipoInfoABB));
    (*Aux)=(*Arbol);
    if(*Aux!=((Padre)->hijo_i))
            free(Padre->hijo_i);
    Padre->hijo_i=NULL;
  } 
  else
  {
    ReemplazaABB(&(*Arbol)->hijo_d, Aux,*Arbol);
  }
}
//--------------------------------------------------------------------------
void EliminarABB(TipoNodoABB **Arbol, char *Texto) {
  if(*Arbol == NULL) return;

  if(strcmp(&(*Arbol)->Info.Letra, Texto) < 0)
  {
    EliminarABB(&(*Arbol)->hijo_d, Texto);
  } 
  else if(strcmp(&(*Arbol)->Info.Letra, Texto) > 0)
  {
    EliminarABB(&(*Arbol)->hijo_i, Texto);
  } 
  else if(strcmp(&(*Arbol)->Info.Letra, Texto) == 0)
  {
    TipoNodoABB *Aux = *Arbol;
    if((*Arbol)->hijo_i == NULL)
    {
      *Arbol = (*Arbol)->hijo_d;
    } else if((*Arbol)->hijo_d == NULL)
        {
            *Arbol = (*Arbol)->hijo_i;
        }
        else
        {
            ReemplazaABB(&(*Arbol)->hijo_i, &Aux,*Arbol);
        }
    free(Aux);
  }
}
//------------------------------------------------------------------------
void LimpiaArbol(TipoNodoABB **Arbol){
    if (*Arbol==NULL) return;
	LimpiaArbol(&(*Arbol)->hijo_i);
	LimpiaArbol(&(*Arbol)->hijo_d);
	EliminaLista(&(*Arbol)->Info.ListaLetra);
	free(*Arbol);
	*Arbol=NULL;
}
//-----------------------------------------------------------------------FIN
