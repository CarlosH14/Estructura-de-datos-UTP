#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//--------------------------------------------------
/*
	Nombre Función: llenaVector(char *l) 
	Objetivo: crear un vector de tamaño N con los numeros desde
	el 1 y creciendo multiplicando x2 el anterior numero 
	Parametro: Vec[] --> Vector a llenar  N--> tamaño
	Retorno: el Vector lleno 
	Ejemplo: llenaVector(Vec, 4) --> {1,2,4,8} 
*/

int llenaVector(int Vec[], int N){
	int aux;
	Vec[0]=1;
	for(int i=1; i<N; i++){
		aux = Vec[i-1];
		Vec[i] = aux*2;
	}
	return *Vec;
}

main()
{
	int N;
  cout << "Ingrese N: "<<endl;
  cin>>N;
  int Vector[N];
  *Vector = llenaVector(Vector, N);
  cout << "Vector lleno: "<< endl;  
	for(int i=0; i<N; i++){
		cout<<(Vector[i])<<endl;
	}
  
}
