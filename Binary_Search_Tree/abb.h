#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "lista.h"
//--------------------------------------------------------------------------

typedef char Texto[255];

typedef struct TipoInfoABB{
    char Letra;
    TipoLista ListaLetra;
}TipoInfoABB;

typedef struct TipoNodoABB {
        TipoInfoABB Info;
	struct TipoNodoABB  *hijo_i;
        struct TipoNodoABB  *hijo_d;
} TipoNodoABB;


TipoInfoABB *BuscarABB(TipoNodoABB *Arbol, char Texto);
void CrearABB(TipoNodoABB **Arbol);
void InsertarABB(TipoNodoABB **Arbol, TipoInfoABB *Info);
void EliminarABB(TipoNodoABB **Arbol, char *Texto);
void LimpiaArbol(TipoNodoABB **Arbol);

//-----------------------------------------------------------------------FIN