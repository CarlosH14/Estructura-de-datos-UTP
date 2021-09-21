#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#define ARCHIVO "trabajo.txt"


using namespace std;


FILE *archivo;

void interface()
{
	char d[3];
	int numero;
	d[3]='\0';
	int maxdatos;
	printf("Por favor ingrese el numero de elementos que desea ordenar\n-");
	scanf("%i",&maxdatos);
	long Vector[maxdatos];
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

	int datosO[999];
	int numero2;
	system("cls");
	printf("\n\n-_-)Vector con sus elementos sin ordenar\n\n");
	for(int i=0; i<=(c-1) ; i++)
	{
		printf("%i - ",Vector[i]);
	}

	///////////////////////////////////////////////////////
	//Burbuja

	  int i,j,aux;
	        for(i=0; i<maxdatos ;i++){
	            for(j=i+1; j<=maxdatos ; j++){
	                if(Vector[i]>Vector[j]) {
	                    aux=Vector[j];
	                    Vector[j]=Vector[i];
	                    Vector[i]=aux;

	            }
	        }
	    }

	/////////////////////////////////////////////////////////

	printf("\n\n\n\n-_-)Vector con sus elementos ordenados por medio del metodo de burbuja\n\n");

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

