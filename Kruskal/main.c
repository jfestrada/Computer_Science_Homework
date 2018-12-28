/*
 * File:   main.c
 * Author: pexi
 *
 * Created on 29 de enero de 2011, 17:38
 */

#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"
#include "time.h"

/*
 * 
 */

void WaitKey() {
char Key;
  fflush(stdin);
  printf("\nPara continuar pulsar cualquier tecla\n");
  scanf("%c", &Key);
  scanf("%c", &Key);
  fflush(stdin);
}

void GeneraMatrizAleatoria(int a[][100], int n){
	int i,j,numAleatorio=0;
        srand(time(NULL));
	for(i = 0;i < n; i++)
	{
		for(j = 0;j <= i; j++)
		{
                    do{
                        numAleatorio= rand()%50;
                    }while (numAleatorio==0);

			a[i][j] = a[j][i]=numAleatorio ;
			if( a[i][j]>40)
                            a[i][j]=a[j][i]=999;

		}
	a[i][i] = 999;
	}
	MuestraMatriz(a,n);
}

void MuestraMatriz(int a[][100],int n){
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

int main() {

    int MatrizAdy[100][100],numVert=0;

    do{
        printf("--------------------------------------------------\n");
        printf("PROGRAMA DE DEMOSTRACION PARA ALGORITMO DE KRUSKAL\n");
        printf("--------------------------------------------------\n\n");
        printf("Introduce el número de vertices (max. 100): ");
        scanf("%d",&numVert);
    }while (numVert<0 || numVert>100);

    printf("Ahora se generará la matriz de adyacencias, con pesos generados\n");
    printf("aleatoriamente\n\n");
    GeneraMatrizAleatoria(MatrizAdy,numVert);
    WaitKey();
    kruskal(MatrizAdy, numVert);

    return (EXIT_SUCCESS);
}
