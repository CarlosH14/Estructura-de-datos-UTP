
/*

*/

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#define ARCHIVO "Datos1000000.txt"

using namespace std;

void delay(int secs) {
for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

FILE *archivo;

void Mburbuja(long Vector[], int maxdatos,int c){
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
	    
	printf("\n\n-_-)Vector con sus elementos ordenados por medio del metodo de burbuja\n\n");
	for(i=0; i<=c-1; i++)
	{
		printf("%i - ",Vector[i]);
	}
}

void Mincersion(long Vector[],int maxdatos,int c){
	int i,j,aux;

	for (i = 1; i <= maxdatos; i++)
		{
			 aux = Vector[i];
			 j = i - 1;
			 while (j >= 0 && Vector[j] > aux)
			 {
				  Vector[j + 1] = Vector[j];
				  j--;
			 }

			 Vector[j + 1] = aux;
	  }
	printf("\n\n-_-)Vector con sus elementos ordenados por medio del metodo de incersion directa\n\n");

	for(i=0; i<=c-1; i++)
	{
		printf("%i - ",Vector[i]);
	}
}

void Mquick(long Vector[],int izq,int der){

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
		Mquick( Vector,izq,j);
	if( i < der )
		Mquick( Vector,i,der);
}

void Mshell(long Vector[],int maxdatos,int c){

	int i,j,k,aux;

	for(k = 1 ; k<=maxdatos;k=k*3+1);

	while (k > 0)
	  {
		  for (i=k; i <= maxdatos; i++)
		  {
				j = i;
				aux = Vector[i];
				while ((j >= k) && (Vector[j-k] > aux))
				{
					Vector[j] = Vector[j - k];
					j = j - k;
				}

				Vector[j] = aux;
		  }

		  k/= 2;
	  }
	printf("\n\n-_-)Vector con sus elementos ordenados por medio del metodo de shellsort\n\n");

	for(i=0; i<=c-1; i++)
	{
		printf("%i - ",Vector[i]);
	}
}

void interface()
{
	char d[3];
	int numero;
	d[3]='\0';
	int maxdatos;
	printf("Por favor ingrese el numero de elementos que desea ordenar\n-");
	scanf("%i",&maxdatos);
	long int Vector[maxdatos];
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
	printf("\n-_-)Vector con sus elementos sin ordenar\n\n");
	delay(5);
	for(int i=0; i<=(c-1) ; i++)
	{
		printf("%i - ",Vector[i]);
	}
	int index=0;
	int i=0;
	printf("\n___________________________________________________________________________________");
	printf("\n\n\nIngrese el numero correspondiente al metodo de ordenamiento que desea usar\n\n1.)Incersion Directa\n2.)Burbuja\n3.)QuickSort\n4.)ShellSort\n\n5.)Salir\n\n");
	printf("___________________________________________________________________________________\n");
	scanf("%i",&index);
	switch(index){

		case 1:
			Mincersion(Vector,maxdatos,c);
			printf("\n");
			break;

		case 2:
			Mburbuja(Vector,maxdatos,c);
			printf("\n");
			break;

		case 3:
			Mquick(Vector,0,maxdatos);
			printf("\n\n-_-)Vector con sus elementos ordenados por medio del metodo Quicksort\n\n");

			for(i=0; i<=c-1; i++)
				{
					printf("%i - ",Vector[i]);
				}
			printf("\n");
			break;

		case 4:
			Mshell(Vector,maxdatos,c);
			break;

		case 5:
			break;

		default:
			printf("Opcion no valida\n");
			break;
	}


	printf("\n");
}

int main ()
{
	interface();
	//getche();
	system("pause");
}

//lo maximo es 516979
