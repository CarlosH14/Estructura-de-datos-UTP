#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>


/*
1. Dada una lista de elementos y un número P,
 devolver el número de veces que está el 
 valor de P en la lista. 

2. Dada una lista, hacer una función que invierta
 sus datos en ella misma y la devuelva invertida. 

3. Hacer una función que reciba una lista y 
 devuelva el promedio de los datos de la lista.

4. Hacer una función que reciba una lista y
 devuelva el mayor valor datos existentes. 

5. Hacer una función que reciba una lista
 e indique si está ordenada ascendentemente.
*/
using namespace std;

//--------------------------------------------------
/*
	Nombre Función: ocurrencia
	Objetivo: Dada una lista de elementos y un número P,
  devolver el número de veces que está el valor de P en la lista. 
	Parametro: Lista, valor P
	Retorno: numero de ocurrencia de P en Lista
	Ejemplo: ocurrencia(Lista[],5) --> # de veces que aparece 5 en Lista 
*/
int ocurrencia(int Lista[], int P, int limite){
	int oc=0;
	for(int i=0; i<limite; i++){
		if(Lista[i]==P){
			oc++;
		}
	}
	return oc;

}
//--------------------------------------------------
/*
	Nombre Función: invertida
	Objetivo: Dada una lista, hacer una función que invierta
  sus datos en ella misma y la devuelva invertida. 
	Parametro: Lista
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: invertida(Lista) --> Lista pero invertida
*/
void invertida(int Lista[], int Lista2[], int limite){
	int aux=0;
	int val;
	for(int i=limite-1; i>=0; i--){
		val=Lista[i];
		Lista2[aux]=val;
		aux++;
	}
	Lista = Lista2;
}
//--------------------------------------------------
/*
	Nombre Función: promedio
	Objetivo: Hacer una función que reciba una lista y 
  devuelva el promedio de los datos de la lista.
	Parametro: Lista
	Retorno: el promedio de los valores
	Ejemplo: promedio(Lista) --> promedio de la lista
*/
int promedio(int Lista[], int limite){
	int prom=0;
	for(int i=0; i<limite; i++){
		prom=prom+Lista[i];
	}
	int x=prom/limite;
	return x;
}
//--------------------------------------------------
/*
	Nombre Función: mayor
	Objetivo: Hacer una función que reciba una lista y
  devuelva el mayor valor datos existentes. 
	Parametro: Lista
	Retorno: el valor mas grande
	Ejemplo: mayor(Lista) --> mayor de la lista
*/
int mayor(int Lista[], int limite){
	int may=0;
	for(int i=0; i<limite; i++){
		if (Lista[i]>may){
			may=Lista[i];
		}
	}
	return may;
}
//--------------------------------------------------
/*
	Nombre Función: ascendente
	Objetivo: Hacer una función que reciba una lista
  e indique si está ordenada ascendentemente.
	Parametro: Lista
	Retorno: true o false
	Ejemplo: ascendente(Lista) --> true si esta ordenada, false si no
*/
bool ascendente(int Lista[]){
	int limite = (sizeof(Lista)/sizeof(Lista[0])); //Parametro para el resto de funciones, indica la longitud de la lista
	for (int i=0; i<limite-1;i++){
		if (Lista[i]>Lista[i+1]){
			return false;
		}
		}
	return true;
	}

void menu(){
    printf("Taller de listas en c++\n\n1.Ocurrencia\n2.Invertida\n3.Promedio\n4.Mayor\n5.Ascendete\n0.Salir\n\nIngrese Opcion:");
}

int main(){

    int Lista[10]={1,2,3,4,5,6,7,8,9,10};
    int Listainv[10];
    int Lista2[5]={2,4,6,8,10};
    int Lista3[5]={9,7,5,3,1};
    int Lista4[10]={1,2,2,3,3,3,4,4,4,4};
    int dato=0,op,x=0,y=0,w=0;
    system("color 0b");

    do{
        menu();
        scanf("%i",&op);
        switch(op){
            case 1:
            	printf("\n\nPor favor ingrese el numero a buscar\n\n");
            	cin>>dato;
            	x=ocurrencia(Lista4,dato,10);
            	printf("\n\nEl numero esta %i veces\n\n",x);
            	break;

            case 2:
            	cout<<"\nAntes de invertir\n";
            	for(int i=0; i<10; i++){
								cout<<(Lista[i])<<endl;
							}
            	invertida(Lista,Listainv,10);
            	cout<<"\nDespues de invertir\n";
            	for(int i=0; i<10; i++){
								cout<<(Listainv[i])<<endl;
							}
            	break;

            case 3:
            	printf("\nPromedio\n");
              y=promedio(Lista,10);
              cout<<y;
            	break;

            case 4:
            	printf("\nMayor\n");
              w=mayor(Lista,10);
              cout<<w;
            	break;

            case 5:
            	printf("\n¿Ascendente?\n");
              bool f=ascendente(Lista3);
              if(f==true){
              	printf("\nSi esta ordenada ascendente\n");
							}else{
								printf("\nNo esta ordenada ascendente\n");
							}
            	break;
        }
        system("pause");
        system("cls");
    }while(op!=0);

    return 0;

}
