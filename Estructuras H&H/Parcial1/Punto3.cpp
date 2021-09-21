#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//--------------------------------------------------
/*
	Nombre Función: aMayus(char *l) 
	Objetivo: convertir todos los caracteres de una cadena 
	en mayuscullas 
	Parametro: char *l --> direccion de la cadena a convertir 
	Retorno: no retorna nada, solo cambia la cadena 
	Ejemplo: aMayus("az123 hola") --> AZ123 HOLA (no retorna, solo cambia) 
*/

void aMayus(char *l){
	while(*l){
		*l=toupper(*l);
		l++;
	}
}

main()
{
	char cad1[80];
  cout << "Ingrese la cadena: "<<endl;
  cin.getline(cad1,80);
  aMayus(cad1);
  cout << "Cadena en mayusculas: " << cad1 << endl;
  
}
