#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//--------------------------------------------------------------------------
typedef struct TDatosColaPri {
	char Nombre[20];
	int Prioridad;
} TDatosColaPri;

typedef struct TNodoColaPri {
	TDatosColaPri Info;
	struct TNodoColaPri *Izdo;
	struct TNodoColaPri *Dcho;
} TNodoColaPri;

typedef struct TNodoCola {
	TNodoColaPri *Info;
	struct TNodoCola *Next;
} TNodoCola;
//--------------------------------------------------------------------------
void InsColaP(TNodoColaPri **ColaPri, TDatosColaPri Elemento);
void SupColaP(TNodoColaPri **ColaPri, TDatosColaPri *Elemento);
void MuestraColaPri(TNodoColaPri *ColaPri);
void LimpiarColaP(TNodoColaPri **ColaPri);

void InsertarCola(TNodoCola **Cola, TNodoColaPri *Elemento);
void SacarCola(TNodoCola **Cola, TNodoColaPri **Elemento);
void LimpiaCola(TNodoCola **Cola);
//-----------------------------------------------------------------------FIN
