#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <math.h>

#define ROJO 'r'
#define NEGRO 'n'
using namespace std;
/*****************************************************/
/* LIBRERÍA DE IMPLEMENTACIÓN DE ARBOLES ROJOS - NEGROS */
/*****************************************************/


//Función con librerias para el uso de posiciones cartesianas
void posicion (int x, int y){
  HANDLE hConsoleOutput;
  COORD coord;
  hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
  coord.X = x, coord.Y = y;
  SetConsoleCursorPosition (hConsoleOutput, coord);
}
/*****************************************************/
//Función con librerias para el uso de colores
void color(int c){  
  SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),c);
}
/*****************************************************/

/*
	Nombre Estructura: nodoRBT (Red-Black Tree)
	Atributos: nro, color, nodo padre, nodo der, nodo izq
	Descripcion: nodo de un árbol binario de busqueda
	con punteros a sus nodos hijos y nodo padre
*/
struct nodoRBT{
    int nro;
    char color;
    struct nodoRBT *padre;
    struct nodoRBT *izq;
    struct nodoRBT *der;
};

typedef struct nodoRBT *RBT;

//--------------------------------------------------
/*
	Nombre Función: buscar(RBT nodoRBT, int dato)
	Objetivo: permite buscar un nodo
	Parametro: Un arbol y un dato de un nodo
	Retorno: un nodo con el dato
	Ejemplo: buscar(RBT arbol1, int 1) --> busca el dato 1 al arbol arbol1
*/
RBT buscar(RBT nodoRBT, int dato){
   RBT actual = nodoRBT;
   if(nodoRBT==NULL){
    cout<<"\n\t??  El arbol esta vacio  ??"<<endl<<endl;
    return NULL;
   }
   while(actual!= NULL)
   {
      if(dato == actual->nro)
      {
        cout<<"\n\tEl numero "<<dato<<" existe en el arbol\n";
        return actual;
      }
      else if(dato < actual->nro)
         actual = actual->izq;
      else if(dato > actual->nro)
         actual = actual->der;
   }
   cout<<"\n\tEl numero "<<dato<<" NO existe en el arbol\n";
   return NULL;
}

//-------------------------------------------------------------------
/*
	Nombre Función: verArbol(RBT arbol, int n)
	Objetivo: mostrar el Arbol en pantalla
	Parametro: RBT arbol->arbol a mostrar, int n->entero de validación
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: verArbol(RBT arbol1, int 1) --> muestra el arbol arbol1 en pantalla 
*/
void verArbol(RBT arbol, int n){
     if(arbol==NULL)
        return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     if(arbol->color==ROJO)color(12);
     else if(arbol->color==NEGRO)color(8);
    cout<< arbol->nro<<endl;

     verArbol(arbol->izq, n+1);
     color(15);
}

//--------------------------------------------------
/*
	Nombre Función: abuelo(RBT n)
	Objetivo: permite buscar un nodo abuelo de un nodo n
	Parametro: Un nodo n
	Retorno: El nodo del abuelo del nodo n
	Ejemplo: abuelo(RBT 5) --> retorna el nodo abuelo del nodo 5
*/
RBT abuelo(RBT n){
	if ((n != NULL) && (n->padre != NULL))
		return n->padre->padre;
	else
		return NULL;
}

//--------------------------------------------------
/*
	Nombre Función: tio(RBT n)
	Objetivo: permite buscar un nodo tio de un nodo n
	Parametro: Un nodo n
	Retorno: El nodo del tio del nodo n
	Ejemplo: tio(RBT n) --> retorna el nodo tio del nodo 5
*/
RBT tio(RBT n){
	RBT a = abuelo(n);
	if (n->padre == a->izq)
		return a->der;
	else
		return a->izq;
}

//--------------------------------------------------
/*
	Nombre Función: rotar_dcha(RBT &r, RBT &nodoRBT)
	Objetivo: Rotación simple derecha
	Parametro: Nodo pivote de rotación y ramificación
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: rotar_dcha(RBT &r, RBT &nodoRBT) --> rota simple a la derecha con respecto al nodo r
*/
void rotar_dcha(RBT &r, RBT &nodoRBT){ //Rotación simple derecha

   RBT padre = nodoRBT->padre;
   RBT A = nodoRBT;
   RBT B = A->izq;
   RBT C = B->der;
   if(padre)
            if(padre->der == A)
                  padre->der = B;
            else
                 padre->izq = B;
   else r = B;

   //ROTAR
   A->izq = C;
   B->der = A;
   A->padre = B;
   if(C)
     C->padre = A;

   B->padre = padre;
}


//--------------------------------------------------
/*
	Nombre Función: rotar_izda(RBT &r, RBT &nodoRBT)
	Objetivo: Rotación simple izquierda
	Parametro: Nodo pivote de rotación y ramificación
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: rotar_izda(RBT &r, RBT &nodoRBT) --> rota simple a la izquierda con respecto al nodo r
*/
void rotar_izda(RBT &r, RBT &nodoRBT){
   RBT padre = nodoRBT->padre;
   RBT A = nodoRBT;
   RBT B = A->der;
   RBT C = B->izq;
   if(padre){
            if(padre->der == A)
                 padre->der = B;
            else
                 padre->izq = B;
            }
   else  r = B;

   //ROTAR
   A->der = C;
   B->izq = A;
   A->padre = B;
   if(C)
      C->padre = A;
   B->padre = padre;
}

/*                 CASOS DE INSERCIÓN                 */

/*

Caso 1: El nuevo nodo N es la raíz del árbol.

Caso 2: El padre del nuevo nodo (esto es, el nodo P) 
es negro, así que la propiedad 4 (ambos hijos de cada 
nodo rojo son negros) se mantiene.

Caso 3: Si el padre P y el tío U son rojos, entonces 
ambos nodos pueden ser repintados de negro y el abuelo 
G se convierte en rojo para mantener la propiedad 5 
(todos los caminos desde cualquier nodo dado hasta 
sus hojas contiene el mismo número de nodos negros).

Caso 4: El nodo padre P es rojo pero el tío U es negro; 
también, el nuevo nodo N es el hijo derecho de P, y P 
es el hijo izquierdo de su padre G.

Caso 5: El padre P es rojo pero el tío U es negro, el 
nuevo nodo N es el hijo izquierdo de P, y P es el 
hijo izquierdo de su padre G.

*/
void insercion_caso1(RBT &n, RBT &arbol);
void insercion_caso2(RBT &n, RBT &arbol);
void insercion_caso3(RBT &n, RBT &arbol);
void insercion_caso4(RBT &n, RBT &arbol);
void insercion_caso5(RBT &n, RBT &arbol);
/*****************************************************/
void insercion_caso5(RBT &n, RBT &arbol){
	RBT a = abuelo(n);

	n->padre->color = NEGRO;
	a->color = ROJO;
	if ((n == n->padre->izq) && (n->padre == a->izq)) {
		rotar_dcha(arbol, a);
	} else {
			rotar_izda(arbol, a);
	}
}
/*****************************************************/
void insercion_caso4(RBT &n, RBT &arbol){
	RBT a = abuelo(n);

	if ((n == n->padre->der) && (n->padre == a->izq)) {
		rotar_izda(arbol, n->padre);
		n=n->izq;
	} else if ((n == n->padre->izq) && (n->padre == a->der)) {
		rotar_dcha(arbol, n->padre);
		n=n->der;
	}
	insercion_caso5(n, arbol);
}
/*****************************************************/
void insercion_caso3(RBT &n, RBT &arbol){
	RBT t = tio(n), a;

	if ((t != NULL) && (t->color == ROJO)) {
		n->padre->color = NEGRO;
		t->color = NEGRO;
		a = abuelo(n);
		a->color = ROJO;
		insercion_caso1(a, arbol);
	} else {
		insercion_caso4(n, arbol);
        }
}
/*****************************************************/
void insercion_caso2(RBT &n, RBT &arbol){
	if (n->padre->color == NEGRO)
		return; /* ?rbol v?lido. */
	else
		insercion_caso3(n, arbol);
}
/*****************************************************/
void insercion_caso1(RBT &n, RBT &arbol){
	if (n->padre == NULL)
		n->color = NEGRO;
	else
		insercion_caso2(n, arbol);
}
/*****************************************************/

//-------------------------------------------------------------------
/*
	Nombre Función: insertar(RBT &arbol, int dato)
	Objetivo: permite insertar un nodo dependiendo del caso
	Parametro: Un arbol y un dato de un nodo
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: insertar(RBT &arbol1, int 1) --> inserta el dato 1 al arbol arbol1
*/
void insertar(RBT &arbol, int dato){
   RBT padre = NULL;
   RBT actual = arbol;
   while(actual!=NULL && dato!=actual->nro)
   {
      padre=actual;

      if(dato < actual->nro) actual = actual->izq;
      else if(dato > actual->nro) actual = actual->der;
   }
   if(actual!=NULL) return; //Actual ya apunta a un nro, salimos

  if(padre==NULL) //El nro a insertar ser? la ra?z
  {
      arbol = (RBT)malloc(sizeof(struct nodoRBT));
      arbol->nro = dato;
      arbol->izq = arbol->der = NULL;
      arbol->padre = NULL;
      arbol->color = ROJO;
      actual=arbol;
  }

  else if(dato < padre->nro)
       {
            actual=(RBT)malloc(sizeof(struct nodoRBT));
            padre->izq = actual;
            actual->nro = dato;
            actual->izq=actual->der = NULL;
            actual->padre = padre;
            actual->color = ROJO;
       }else{
              if(dato > padre->nro)
              {
                    actual = (RBT)malloc(sizeof(struct nodoRBT));
                    padre->der = actual;
                    actual->nro = dato;
                    actual->izq = actual->der = NULL;
                    actual->padre = padre;
                    actual->color = ROJO;
              }
                }
    insercion_caso1(actual, arbol);
   cout<<"\n\n\tEl numero ha sido insertado\n\n";
}
/*****************************************************/

//-------------------------------------------------------------------
/*
	Nombre Función: eliminar_rbt (RBT &arbol, int x)
	Objetivo: permite eliminar un nodo
	Parametro: Un arbol y un dato de un nodo
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: eliminar_rbt (RBT &arbol1, int 1) --> elimina el dato 1 del arbol arbol1
*/
void eliminar_rbt (RBT &arbol, int x){
    RBT aux1,aux2;
    if(arbol==NULL)
        return;
    if(x<arbol->nro)
        eliminar_rbt(arbol->izq,x);
    if(x>arbol->nro)
        eliminar_rbt(arbol->der,x);
    if(x==arbol->nro)
    {
        if(arbol->izq==NULL&&arbol->der==NULL)
            {
                arbol=NULL;
                return;
            }
        if(arbol->izq==NULL)
        {
            arbol=arbol->der;
            return;
        }
        if(arbol->der==NULL)
        {
            arbol=arbol->izq;
            return;
        }
            aux1=arbol;
            aux2=arbol->izq;
            while(aux2->der!=NULL)
            {
                aux1=aux2;
                aux2=aux2->der;
            }
            arbol->nro=aux2->nro;
            if(aux1==arbol)
                arbol->izq=aux2->izq;
            else
            aux1->der=aux2->izq;
    }
}


