#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//--------------------------------------------------------------------------
typedef struct TAristaGrafo {
	int VAdy1;
        int VAdy2;
	int Peso;
} TAristaGrafo;

typedef struct TNodoColaPri {
	TAristaGrafo Info;
	struct TNodoColaPri *Izdo;
	struct TNodoColaPri *Dcho;
} TNodoColaPri;

typedef struct TNodoCola {
	TNodoColaPri *Info;
	struct TNodoCola *Next;
} TNodoCola;
//--------------------------------------------------------------------------
void InsColaP(TNodoColaPri **ColaPri, TAristaGrafo Elemento);
void SupColaP(TNodoColaPri **ColaPri, TAristaGrafo *Elemento);
void MuestraColaPri(TNodoColaPri *ColaPri);
void LimpiarColaP(TNodoColaPri **ColaPri);

void InsertarCola(TNodoCola **Cola, TNodoColaPri *Elemento);
void SacarCola(TNodoCola **Cola, TNodoColaPri **Elemento);
void LimpiaCola(TNodoCola **Cola);
//-----------------------------------------------------------------------FIN
