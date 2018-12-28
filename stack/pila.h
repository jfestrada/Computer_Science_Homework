#include <stdlib.h>
//--------------------------------------------------------------------------

typedef  char TipoInfoNodo[255];

typedef struct TipoNodo {
        TipoInfoNodo Texto;
	struct TipoNodo  *Siguiente;
} TipoNodo;

typedef struct TipoPila {
        TipoNodo *Nodo;
} TipoPila;
//--------------------------------------------------------------------------	                    
void CrearPila(TipoPila *Pila);
void LimpiarPila(TipoPila *Pila);
void  Push(char *Texto, TipoPila *Pila);
int  Pop(TipoPila *Pila);
void ListarPila(TipoPila Pila);
void Cabecera(TipoPila Pila);
//-----------------------------------------------------------------------FIN
