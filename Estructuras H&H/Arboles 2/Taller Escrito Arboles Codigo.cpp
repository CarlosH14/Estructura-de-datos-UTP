#include <time.h>
#include <cstdlib>
#include <iostream>
#include "RN.h"
#include "BB.h"
#include "VL.h"

using namespace std;
/*****************************************************
                  IMPLEMENTACIÓN DE 
            ARBOLES BINARIOS DE BUSQUEDA, 
                ARBOLES ROJO - NEGROS 
                     Y ARBOLES VL                    
*****************************************************/
//--------------------------------------------------
/*
	Nombre Función: alturaAB(ABB arbol)
	Objetivo: permite identificar la altura de un árbol
	Parametro: Un árbol
	Retorno: entero igual a la altura del árbol
	Ejemplo: alturaAB(ABB arbol1) --> # equivalente a la altura del árbol arbol1
*/
int alturaAB(ABB arbol){
    int AltIzq, AltDer;

    if(arbol==NULL)
        return -1;
    else
    {
        AltIzq = alturaAB(arbol->izq);
        AltDer = alturaAB(arbol->der);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}

//--------------------------------------------------
/*
	Nombre Función: contarHojas(ABB arbol)
	Objetivo: permite identificar cuantas hojas tiene un árbol
	Parametro: Un árbol
	Retorno: entero igual a la cantidad de hojas del árbol
	Ejemplo: contarHojas(ABB arboL1) --> # equivalente a la cantidad de hojas del árbol arbol1
*/
int contarHojas(ABB arbol){
        if (arbol==NULL)
        {
                return 0;
        }
        if ((arbol->der ==NULL)&&(arbol->izq ==NULL))
        {
                return 1;
        }
        else
        {
                return contarHojas(arbol->izq) + contarHojas(arbol->der);
        }
}

//--------------------------------------------------
/*
	Nombre Función: delay(int secs)
	Objetivo: función para congelar la pantalla por x segundos
	solo para mejorar la presentación
	Parametro: numero de segundos
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: delay(int 2) --> congela la pantalla 2 segundos
*/
void delay(int secs) {
for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

//--------------------------------------------------
/*
	Nombre Función: padreAB(ABB arbol, int x)
	Objetivo: consultar el padre de un nodo
	Parametro: Un árbol y un dato de un nodo
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: padreAB(ABB arbol1, int 5) --> busca el nodo padre del nodo 5 en árbol arbol1
*/
void padreAB(ABB arbol, int x){
	if(arbol==NULL){
		return;
	}
	if(arbol->nro==x){
		cout<<"Sin padre, raiz"; return;
	}
	if(x>arbol->nro){
		if(arbol->der->nro==x){
			cout<<"Padre:\t"<<arbol->nro;
		}
		padreAB(arbol->der, x);
	}else{
		if(arbol->izq->nro==x){
			cout<<"Padre:\t"<<arbol->nro;
		}
		padreAB(arbol->izq, x);
	}
}

//--------------------------------------------------
/*
	Nombre Función: iguales(ABB a, ABB b)
	Objetivo: verifica si dos arboles son iguales
	Parametro: Un árbol a y un árbol b
	Retorno: Devuelve 1 si a y b son iguales, de lo contrario 0
	Ejemplo: iguales(ABB a, ABB b) --> 1 si a y b son iguales, 0 si a y b no son iguales
*/
int iguales(ABB a, ABB b){
        if(a == NULL && b ==NULL){
		return 0;
	} else {
		if(a == NULL || b == NULL){
			return 1;
		} else {
			if(a->nro == b->nro){
				iguales(a->izq, b->izq);
				iguales(a->der, b->der);
				return 0;
			} else {
				return 1;
			}
		}
	}
}

//--------------------------------------------------
/*
	Nombre Función: nivel(ABB t)
	Objetivo: buscar el nivel de un elemento
	Parametro: Un nodo t
	Retorno: Devuelve un número igual al nivel del nodo
	Ejemplo: nivel(ABB 5) --> # equivalente al nivel del nodo 5
*/
int nivel(ABB t){
int a,b;
if (t->izq == NULL && t->der == NULL)
     return 1;
else
{
    a=nivel(t->izq);
    b= nivel(t->der);
    if (a<b) return b+1;
    else return a+1;
}
}

//--------------------------------------------------
/*
	Nombre Función: peso(ABB a)
	Objetivo: buscar el peso de un elemento
	Parametro: Un nodo t
	Retorno: Devuelve un número igual al peso del nodo
	Ejemplo: peso(ABB 5) --> # equivalente al peso del nodo 5
*/
int peso(ABB a){
	int p=0;
	if(a==NULL){
		p=p+1;
	}else{
		peso(a->izq);
		peso(a->der);
	}
	return p;
}

//--------------------------------------------------
/*
	Nombre Función: eshermano(struct nodo *raiz, struct nodo *a, struct nodo *b)
	Objetivo: Función recursiva para comprobar si dos nodos son hermanos
	Parametro: Un nodo raiz, un nodo a y un nodo b
	Retorno: Devuelve 1 si a y b son hermanos, de lo contrario 0
	Ejemplo: eshermano(raiz, nodo 4, nodo 5) --> 1 si 4 y 5 son hermanos, 0 si 4 y 5 no son hermanos
*/
int eshermano(struct nodo *raiz, struct nodo *a, struct nodo *b) { 
    // Caso Base
    if (raiz==NULL)  return 0; 
  
    return ((raiz->izq==a && raiz->der==b)|| 
            (raiz->izq==b && raiz->der==a)|| 
            eshermano(raiz->izq, a, b)|| 
            eshermano(raiz->der, a, b)); 
} 
  
//--------------------------------------------------
/*
	Nombre Función: nivel(struct nodo *raiz, struct nodo *ptr, int lev) 
	Objetivo: Función recursiva para encontrar el nivel del nodo 'ptr' en un árbol binario
	Parametro: Un nodo raiz, un nodo ptr a buscar y un integer
	Retorno: Número del nivel del nodo 'ptr' en un árbol binario
	Ejemplo: nivel(nodo raiz, nodo 2, int 5)  --> # equivalente al nivel del nodo 2
*/
int nivel(struct nodo *raiz, struct nodo *ptr, int lev) { 
    // base cases 
    if (raiz == NULL) return 0; 
    if (raiz == ptr)  return lev; 
  
    //retorno si el nodo está presente en el subárbol izquierdo
    int l = nivel(raiz->izq, ptr, lev+1); 
    if (l != 0)  return l; 
  
    //sino buscar en el subárbol derecho 
    return nivel(raiz->der, ptr, lev+1); 
} 
  
//--------------------------------------------------
/*
	Nombre Función: esprimo(struct nodo *raiz, struct nodo *a, struct nodo *b)
	Objetivo: Función recursiva para comprobar si dos nodos son primos
	Parametro: Un nodo raiz, un nodo a y un nodo b
	Retorno: Devuelve 1 si a y b son primos, de lo contrario 0
	Ejemplo: esprimo(nodo raiz, nodo 7, nodo 8) --> 1 si 7 y 8 son primos, 0 si 7 y 8 no son primos
*/
int esprimo(struct nodo *raiz, struct nodo *a, struct nodo *b) { 
   	 // 1. Los dos nodos deben estar en el mismo nivel en el árbol binario 2. Los dos nodos no deben ser hermanos significa que deben no tener el mismo nodo padre.
    if ((nivel(raiz,a,1) == nivel(raiz,b,1)) && !(eshermano(raiz,a,b))) 
        return 1; 
    else return 0; 
} 

//--------------------------------------------------
/*
	Nombre Función: estable(ABB arbol)
	Objetivo: Determinar la establidad de un árbol
	Parametro: Un árbol
	Retorno: Devuelve 1 si es estable o 0 si no es estable
	Ejemplo: estable(ABB arbol1) --> 1 si arbol1 es estable, 0 si arbol1 no es estable
*/
int estable(ABB arbol){ 
	if(arbol->izq==NULL && arbol->der!=NULL){
		estable(arbol->der);
		return 1;
	}else{
		return 0;
	}
}

//--------------------------------------------------
/*
	Nombre Función: mayor(ABB arbol)
	Objetivo: Determinar el mayor valor de un árbol
	Parametro: Un árbol
	Retorno: Devuelve el número del nodo mayor de un árbol
	Ejemplo: mayor(ABB arbol) --> # equivalente al dato mas grande del árbol arbol1
*/
int mayor(ABB arbol){
	int aux=arbol->nro;
	if(arbol->der!=NULL){
		aux=arbol->der->nro;
		mayor(arbol->der);
	}
	return aux;
}

//----------------------------------------------------------------------------------------------------------------//
void punto1(ABB arbol){
	insertar( arbol, 8);
	insertar( arbol, 9);
	insertar( arbol, 11);
	insertar( arbol, 15);
	insertar( arbol, 19);
	insertar( arbol, 20);
	insertar( arbol, 21);
	insertar( arbol, 7);
	insertar( arbol, 3);
	insertar( arbol, 2);
	insertar( arbol, 1);
	insertar( arbol, 5);
	insertar( arbol, 6);
	insertar( arbol, 4);
	insertar( arbol, 13);
	insertar( arbol, 14);
	insertar( arbol, 10);
	insertar( arbol, 12);
	insertar( arbol, 17);
	insertar( arbol, 16);
	insertar( arbol, 18);
	cout << "\n\n En orden   :  ";   enOrden(arbol);
  	cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
  	cout << "\n\n Post Orden :  ";   postOrden(arbol);
  	cout << endl << endl;
  	verArbol( arbol, 0);
}

void punto2(ABB arbol){
	insertar( arbol, 4);
	insertar( arbol, 10);
	insertar( arbol, 19);
	insertar( arbol, 7);
	insertar( arbol, 49);
	insertar( arbol, 100);
	insertar( arbol, 20);
	insertar( arbol, 22);
	insertar( arbol, 12);
	cout << endl << endl;
  verArbol( arbol, 0);
  cout << endl << endl;
	int h = alturaAB(arbol);
  cout << " La altura es : "<< h << endl;
  int l = contarHojas(arbol);
  cout << " El peso es : "<< peso<<endl;
  cout << " El numero de niveles es : "<< h+1<<endl;
  cout << " El numero de hojas es : "<< l << endl;
  int m = mayor(arbol);
  cout << " El numero mayor es : "<< m << endl;
  
}

void punto3(ABB arbol){
	insertar( arbol, 50);
	insertar( arbol, 25);
	insertar( arbol, 75);
	insertar( arbol, 10);
	insertar( arbol, 40);
	insertar( arbol, 60);
	insertar( arbol, 90);
	insertar( arbol, 35);
	insertar( arbol, 45);
	insertar( arbol, 70);
	insertar( arbol, 42);
	cout << endl << endl;
  verArbol( arbol, 0);
  cout << endl << endl;
	int h = alturaAB(arbol);
  cout << " La altura es : "<< h << endl;
  int l = contarHojas(arbol);
  cout << " El peso es : "<< peso<<endl;
  cout << " El numero de niveles es : "<< h+1<<endl;
  cout << " El numero de hojas es : "<< l << endl;
  int m = mayor(arbol);
  cout << " El numero mayor es : "<< m << endl;
}

void punto4(ABB arbol){
	insertar( arbol, 10);
	insertar( arbol, 75);
	insertar( arbol, 34);
	insertar( arbol, 22);
	insertar( arbol, 64);
	insertar( arbol, 53);
	insertar( arbol, 41);
	insertar( arbol, 5);
	insertar( arbol, 25);
	insertar( arbol, 74);
	insertar( arbol, 20);
	insertar( arbol, 15);
	insertar( arbol, 90);
	cout << endl << endl;
  verArbol( arbol, 0);
  cout << endl << endl;
	int h = alturaAB(arbol);
  cout << " La altura es : "<< h << endl;
  int l = contarHojas(arbol);
  cout << " El peso es : "<< peso<<endl;
  cout << " El numero de niveles es : "<< h+1<<endl;
  cout << " El numero de hojas es : "<< l << endl;
  int m = mayor(arbol);
  cout << " El numero mayor es : "<< m << endl;
}


void punto5(ABB arbol, AVL arbol2){
	insertar( arbol, 3);
	insertar( arbol, 2);
	insertar( arbol, 18);
	insertar( arbol, 5);
	insertar( arbol, 20);
	insertar( arbol, 90);
	insertar( arbol, 77);
	insertar( arbol, 40);
	insertar( arbol, 34);
	insertar( arbol, 12);
	cout << endl << endl<< "ABB"<<endl;
  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol2, 3);
	insertar( arbol2, 2);
	insertar( arbol2, 18);
	insertar( arbol2, 5);
	insertar( arbol2, 20);
	insertar( arbol2, 90);
	insertar( arbol2, 77);
	insertar( arbol2, 40);
	insertar( arbol2, 34);
	insertar( arbol2, 12);
	cout << endl << endl<< "AVL"<<endl;
  verArbol( arbol2, 0);
  cout << endl << endl;
}


void punto6(AVL arbol){
	insertar( arbol, 4);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol, 5);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol, 7);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol, 2);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol, 1);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol, 3);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol, 6);
	  verArbol( arbol, 0);
  cout << endl << endl;
  
	
}


void punto7(AVL arbol){
	insertar( arbol, 8);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,9);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,11);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,15);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,19);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,20);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,21);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,7);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,3);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,2);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,1);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,5);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,6);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,4);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,13);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,14);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,10);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,12);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,17);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,16);
	  verArbol( arbol, 0);
  cout << endl << endl;
	insertar( arbol,18);
	  verArbol( arbol, 0);
  cout << endl << endl;
  
	
} 

void punto8(RBT arbol){
	insertar( arbol, 20);
	insertar( arbol, 10);
	insertar( arbol, 30);
	insertar( arbol, 40);
	insertar( arbol, 27);
	insertar( arbol, 35);
	insertar( arbol, 40);
	insertar( arbol, 50);
	insertar( arbol, 60);
	insertar( arbol, 67);
	insertar( arbol, 80);
	insertar( arbol, 62);
	insertar( arbol, 70);
	insertar( arbol, 83);
	insertar( arbol, 84);
	insertar( arbol, 85);
	cout << endl << endl<<endl;
  verArbol( arbol, 0);
  cout << endl << endl;
	
}

void punto9(RBT arbol){
	insertar( arbol, 50);
	insertar( arbol, 55);
	insertar( arbol, 40);
	insertar( arbol, 60);
	insertar( arbol, 62);
	insertar( arbol, 51);
	insertar( arbol, 20);
	insertar( arbol, 10);
	insertar( arbol, 8);
	insertar( arbol, 9);
	insertar( arbol, 15);
	insertar( arbol, 5);
	insertar( arbol, 2);
	insertar( arbol, 3);
	cout << endl << endl<<endl;
  verArbol( arbol, 0);
  cout << endl << endl;
	
}

void punto10(RBT arbol){
	insertar( arbol, 10);
	insertar( arbol, 8);
	insertar( arbol, 15);
	insertar( arbol, 18);
	insertar( arbol, 14);
	insertar( arbol, 20);
	insertar( arbol, 3);
	insertar( arbol, 4);
	insertar( arbol, 2);
	insertar( arbol, 9);
	insertar( arbol, 20);
	insertar( arbol, 25);
	insertar( arbol, 7);
	insertar( arbol, 16);
	insertar( arbol, 29);
	insertar( arbol, 28);
	insertar( arbol, 26);
	cout << endl << endl<<endl;
  verArbol( arbol, 0);
  cout << endl << endl;
	
}
//Ejecutar Puntos
int main(){
	ABB binario = NULL;
	ABB binario2 = NULL;
	AVL vl = NULL;
	RBT rojonegro = NULL;
	
	//punto1(binario);
	//punto2(binario);
	//punto3(binario);
	//punto4(binario);
	//punto5(binario, vl);
	//punto6(vl);
	//punto7(vl);
	//punto8(rojonegro);
	//punto9(rojonegro);
	punto10(rojonegro);
}



