#include <stdlib.h>
//--------------------------------------------------------------------------

typedef  char TipoInfoNodo[255];

typedef struct TipoNodo {
        TipoInfoNodo Texto;
	struct TipoNodo  *Siguiente;
} TipoNodo;

typedef struct TipoCola {
        TipoNodo *Inicio;
        TipoNodo *Fin;
} TipoCola;
//--------------------------------------------------------------------------	                    
void CrearCola(TipoCola *Cola);
void LimpiarCola(TipoCola *Cola);
void InsCola(char *Texto, TipoCola *Cola);
int SupCola(TipoCola *Cola);
void ListarCola(TipoCola Cola);
void PrimerElemento(TipoCola Cola);
void UltimoElemento(TipoCola Cola);
//-----------------------------------------------------------------------FIN
