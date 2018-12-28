#include <stdio.h>
#include <stdlib.h>
#include "monticulo.h"
//--------------------------------------------------------------------------
int main() {
    char Opcion;
    int sobre=0,notab=0,aprob=0,suspen=0,total=0;
    TNodoColaPri *ColaPri = NULL;
    TDatosColaPri Elemento;

    do
    {
        printf("----------------------------------------------\n");
        printf("PROGRAMA DE DEMOSTRACION DE COLAS DE PRIORIDAD\n");
        printf("----------------------------------------------\n\n");
        printf("  1 - Insertar un nuevo niño en la cola de prioridad\n");
        printf("  2 - Mostrar el niño con mayor prioridad\n");
        printf("  3 - Visualizar cola de niños\n");
        printf("  4 - Limpiar la cola\n");
        printf("  0 - Salir\n");
        fflush(stdin);
        scanf("%s",&Opcion);
        fflush(stdin);
                    
        switch(Opcion)
        {
            case '1' :
                printf("Nombre del niño: ");
                scanf("%s",Elemento.Nombre);
                do
                {
                    printf("Numero de sobresalientes: ");
                    scanf("%d",&sobre);
                }while(sobre>10);
                total = sobre;
                if (total<10)
                {
                    do
                    {
                        printf("Numero de notables: ");
                        scanf("%d",&notab);
                    }while((total+notab)>10);
                    total = total+notab;

                    if (total<10)
                    {
                        do
                        {
                            printf("Numero de aprobados: ");
                            scanf("%d",&aprob);
                        }while((total+aprob)>10);
                        total=total+aprob;
                        if(total<10)
                        {
                            do
                            {
                                printf("Numero de suspensos: ");
                                scanf("%d",&suspen);
                            }while((total+suspen)!=10);
                        }
                    }
                }

                Elemento.Prioridad = ((sobre*3)+(notab*2)+(aprob*1))-(suspen*3);
                InsColaP(&ColaPri, Elemento);
                break;

            case '2' :
                printf("El niño %s tiene una prioridad de %d\n",ColaPri->Info.Nombre, ColaPri->Info.Prioridad);
                SupColaP(&ColaPri, &Elemento);
                break;
                            
            case '3' :
                MuestraColaPri(ColaPri);
                break;
                            
            case '4' :
                LimpiarColaP(&ColaPri);
                break;
        }
    } while(Opcion != '0');

    return 0;
}
//-----------------------------------------------------------------------FIN

