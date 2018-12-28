#include <stdlib.h>
//--------------------------------------------------------------------------

typedef  char TipoInfoNodo[255];

typedef struct TipoNodo {
        TipoInfoNodo Texto;
	struct TipoNodo  *Siguiente;
} TipoNodo;

typedef struct TipoLista {
        TipoNodo *Nodo;
} TipoLista;
//--------------------------------------------------------------------------	                    
void CreaLista(TipoLista *Lista);
void EliminaLista(TipoLista *Lista);
int  NuevoElemento(char *Texto, TipoLista *Lista);
int  EliminaElemento(char *Texto,TipoLista *Lista);
void ListarLista(TipoLista Lista);
void BuscarLista(char *Texto, TipoLista Lista);
//-----------------------------------------------------------------------FIN
