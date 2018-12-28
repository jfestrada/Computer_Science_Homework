#include "kruskal.h"
#define CICLO " \033[1;31mproboca ciclo y no se añade\033[0m"
#define ARBOL " \033[1;32mse añade al arbol\033[0m "

void kruskal(int MatrizAdy[][100], int numVert){
    int i,j,peso,ciclo[100][100],fin_sin_exito=0;
    TNodoColaPri *ColaPri = NULL;
    TAristaGrafo Arista;

    printf("\nProcesando la matriz de adyacencias.\n");
    //para cada arista se va cargando el tipo de datos y
    //se inserta en el monticulo
    for(i=0;i<numVert;i++)
    {
        for(j=0;j<=i;j++)
        {
            Arista.Peso=MatrizAdy[i][j];
            Arista.VAdy1=i+1;
            Arista.VAdy2=j+1;
            InsColaP(&ColaPri, Arista);
        }
    }
    printf("\nLa matriz de adyacencias ha sido procesada.\n\n");
    peso=0;
    for(i=0;i<(numVert)-1; i++)
    {
        SupColaP(&ColaPri, &Arista);
        if(Arista.Peso!=999){
        if(CompruebaCiclo(Arista.VAdy1,Arista.VAdy2,&ciclo, numVert)==0)
        {
            peso = peso+Arista.Peso;
            printf("La arista que conecta el vertice %d con el vertice %d y pesa %d%s\n",Arista.VAdy1,Arista.VAdy2, Arista.Peso,ARBOL);
        }
        else
        {
            printf("La arista que conecta el vertice %d con el vertice %d%s\n",Arista.VAdy1,Arista.VAdy2,CICLO);
            i--;
        }
        }
        else{
            fin_sin_exito = 1;    
        }
    }

    int arboles=0;
    for(i=0;i<numVert;i++){
        if(ciclo[i][0]!=NULL)
            arboles++;
    }
    if((fin_sin_exito==0)&&(arboles=1))
        printf("\nEl peso total del arbol es %d\n", peso);
    else
        printf("\nEl grafo no es conexo por lo que el algoritmo no puede obter un arbol\n");
/*
    printf("\nExisten %d subarboles",arboles);
*/
    LimpiarColaP(&ColaPri);
}

int CompruebaCiclo (int vertAdy1, int vertAdy2,int *ciclo[100][100], int n){
    //char  *Texto;
    int i,j;
//intentamos insertr en la lista j y luego i, si ambas fallan produce ciclo
    //sino es correcto y podemos continuar

    int encontrado1=-1,encontrado2=-1,insertado1=-1,insertado2=-1,k,salida=0;

    for(i=0;i<n;i++){
        if(encontrado1!=-1) break;
        for(j=0;j<n;j++){
            if(ciclo[i][j]==vertAdy1){
                encontrado1=i;
                break;
            }
        }
    }
    for(i=0;i<n;i++){
        if(encontrado2!=-1) break;
        for(j=0;j<n;j++){
            if(ciclo[i][j]==vertAdy2){
                encontrado2=i;
                break;
            }
        }
    }

    if((encontrado1==encontrado2)&&(encontrado1!=-1)) return 1;
    else if (encontrado1!=-1){
        for(i=0;i<n;i++){
            if(insertado2!=-1) break;
            for(j=0;j<n;j++){
                if(insertado2!=-1) break;
                if(ciclo[i][j]==vertAdy1){
                    for(k=0;k<n;k++){
                        if(ciclo[i][k]==NULL){
                            ciclo[i][k]=vertAdy2;
                            insertado2=k;
                            break;
                        }
                    }
                }
            }
        }
        salida = 0;
    }else if (encontrado2!=-1){
        for(i=0;i<n;i++){
            if(insertado1!=-1) break;
            for(j=0;j<n;j++){
                if(insertado1!=-1) break;
                if(ciclo[i][j]==vertAdy2){
                    for(k=0;k<n;k++){
                        if(ciclo[i][k]==NULL){
                            ciclo[i][k]=vertAdy1;
                            insertado1=k;
                            break;
                        }
                    }
                }
            }
        }
        salida = 0;
    }else if((encontrado1==-1)&&(encontrado2==-1)){
        for(i=0;i<n;i++){
            if(ciclo[i][0]==NULL){
                ciclo[i][0]=vertAdy1;
                ciclo[i][1]=vertAdy2;
                break;
            }
        }
        salida = 0;
    }

    if((encontrado1!=encontrado2)&&(encontrado1!=-1)&&(encontrado2!=-1)){
        //hay que unirlos recorriendo el vector de 2 al reves
        for(j=0;j<n;j++){
            if(ciclo[encontrado1][j]==NULL){
                for(k=n-1;k>=0;k--){
                    if((ciclo[encontrado2][k]!=NULL)&&ciclo[encontrado2][k]!=vertAdy2){
                        ciclo[encontrado1][j]=ciclo[encontrado2][k];
                        ciclo[encontrado2][k]=NULL;
                        j++;
                    }else if (ciclo[encontrado2][k]!=vertAdy2)
                        ciclo[encontrado2][k]=NULL;
                }
                break;
            }
        }
    }
    return salida;
}