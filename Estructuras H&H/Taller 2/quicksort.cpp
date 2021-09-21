#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#define ARCHIVO "trabajo.txt"


using namespace std;


FILE *archivo;

void quicksort(int Vector[],int izq, int der )
	{
	int i, j, x , aux;
	i = izq;
	j = der;
	x = Vector[ (izq + der) /2 ];
	do{
		while( (Vector[i] < x) && (j <= der) )
			{
				i++;
			}

		while( (x < Vector[j]) && (j > izq) )
			{
				j--;
			}

		if( i <= j )
			{
				aux = Vector[i];
				Vector[i] = Vector[j];
				Vector[j] = aux;
				i++;
				j--;
			}

	}while( i <= j );

	if( izq < j )
		quicksort( Vector, izq, j );
	if( i < der )
		quicksort( Vector, i, der );
}

void interface()
{
	char d[3];
	int numero;
	d[3]='\0';
	int maxdatos;
	printf("Por favor ingrese el numero de elementos que desea ordenar\n-");
	scanf("%i",&maxdatos);
	int Vector[maxdatos];
	Vector[maxdatos]='\0';
	maxdatos=maxdatos-1;
	int c=0;
	char espa;
	archivo = fopen(ARCHIVO,"r+");
	if (archivo==NULL)
      {
		printf("Se ha ocasionado algun problema al abrir el archivo\n");
      }

    system("cls");

	while (c <= maxdatos)
	{
		fgets(d, 6, archivo);
    	numero=atoi(d);
    	Vector[c]=numero;
    	c+=1;
	}

	fclose(archivo);

	///////////////////////////////////////////////////////
	//QuickSort

	int datosO[999];
	int numero2;
	system("cls");
	printf("\n\n-_-)Vector con sus elementos sin ordenar\n\n");
	for(int i=0; i<=(c-1) ; i++)
	{
		printf("%i - ",Vector[i]);
	}
	//system("cls");
	int izq,der,i=0;
	izq=0;


	quicksort(Vector,izq,maxdatos);

	////////////////////////////////////////////////////////
	printf("\n\n\n\n-_-)Vector con sus elementos ordenados por medio del metodo Quicksort\n\n");

	for(i=0; i<=c-1; i++)
	{
		printf("%i - ",Vector[i]);
	}
	printf("\n");
}

int main ()
{
	interface();
	getche();
}
