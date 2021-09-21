#include <cstdlib>
#include <iostream>
#define TRUE 1
#define FALSE 0

using namespace std;
/*****************************************************/
/* LIBRERÍA DE IMPLEMENTACIÓN DE ARBOLES VL */
/*****************************************************/
/*
	Nombre Estructura: nodoAVL 
	Atributos: nro, Factor Equilibrio, nodoAVL der, nodoAVL izq, nodoAVL padre
	Descripcion: nodo de un árbol AVL
	con punteros a sus nodos hijos y nodo padre
*/
struct nodoAVL{
       int nro;
       int FE;
       struct nodoAVL *der;
       struct nodoAVL *izq;
       struct nodoAVL *padre;
       };

typedef struct nodoAVL *AVL; //Puntero de tipo nodoAVL

//--------------------------------------------------
/*
	Nombre Función: verArbol(AVL arbol, int n)
	Objetivo: mostrar el Arbol en pantalla
	Parametro: AVL arbol->arbol a mostrar, int n->entero de validación
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: verArbol(arbol1, 1) --> muestra el arbol arbol1 en pantalla 
*/
void verArbol(AVL arbol, int n){
     if(arbol==NULL)
        return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro<<endl;

     verArbol(arbol->izq, n+1);
}

//--------------------------------------------------
/*
	Nombre Función: RDD(AVL &r, AVL nodoAVL)
	Objetivo: Rotación doble derecha
	Parametro: Nodo pivote de rotación y ramificación
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: RDD(AVL &r, AVL nodoAVL) --> rota doble a la derecha con respecto al nodo r
*/
void RDD(AVL &r, AVL nodoAVL){//Rotación doble derecha
   AVL padre = nodoAVL->padre;
   AVL A = nodoAVL;     //nodoAVL desequilibrado
   AVL B = A->izq;   //Hijo izq del nodoAVL desequilibrado
   AVL C = B->der;   //Hijo der de B
   AVL CI = C->izq;  //Hijo izq de C
   AVL CD = C->der;  //Hijo der de C
   if(padre){//Si no es la ra?z
            if(padre->der == A)
                padre->der = C;
            else
                 padre->izq = C;
            }
   else r = C; //Si es ra?z

   //ROTAR
   B->der = CI;
   A->izq = CD;
   C->izq = B;
   C->der = A;
   C->padre = padre;
   A->padre = B->padre = C;
   if(CI)
     CI->padre = B;
   if(CD)
     CD->padre = A;

  //ACTUALIZAR FACTORES DE EQUILIBRIO
  switch(C->FE)
  {
      case -1: B->FE = 0;
               A->FE = 1;
               break;

      case 0:  B->FE = 0;
               A->FE = 0;
               break;

      case 1:  B->FE = -1;
               A->FE = 0;
               break;
  }
   C->FE = 0;
}

//--------------------------------------------------
/*
	Nombre Función: RDI(AVL &r, AVL nodoAVL)
	Objetivo: Rotación doble izquierda
	Parametro: Nodo pivote de rotación y ramificación
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: RDI(AVL &r, AVL nodoAVL) --> rota doble a la izquierda con respecto al nodo r
*/
void RDI(AVL &r, AVL nodoAVL){//Rotación doble izquierda
   AVL padre = nodoAVL->padre;
   AVL A = nodoAVL;
   AVL B = A->der;
   AVL C = B->izq;
   AVL CI = C->izq;
   AVL CD = C->der;
   if(padre)
            if(padre->der == A)
                 padre->der = C;
            else
                 padre->izq = C;
   else r = C;

   //ROTAR
   A->der = CI;
   B->izq = CD;
   C->izq = A;
   C->der = B;
   C->padre = padre;
   A->padre = B->padre = C;
   if(CI)
     CI->padre = A;
   if(CD)
     CD->padre = B;

   //ACTUALIZAR FACTORES DE EQUILIBRIO
   switch(C->FE)
    {
      case -1: A->FE = 0;
               B->FE = 1;
               break;

      case 0:  A->FE = 0;
               B->FE = 0;
               break;

      case 1:  A->FE = -1;
               B->FE = 0;
               break;
   }
   C->FE = 0;
}

//--------------------------------------------------
/*
	Nombre Función: RSD(AVL &r, AVL nodoAVL)
	Objetivo: Rotación simple derecha
	Parametro: Nodo pivote de rotación y ramificación
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: RSD(AVL &r, AVL nodoAVL) --> rota simple a la derecha con respecto al nodo r
*/
void RSD(AVL &r, AVL nodoAVL){//Rotación simple derecha
   AVL padre = nodoAVL->padre;
   AVL A = nodoAVL;
   AVL B = A->izq;
   AVL C = B->der;
   if(padre)
       if(padre->der == A)
             padre->der = B;
       else
             padre->izq = B;
   else 
       r = B;
   //ROTAR
   A->izq = C;
   B->der = A;
   A->padre = B;
   if(C)
     C->padre = A;

   B->padre = padre;
   //ACTUALIZAR FACTORES DE EQUILIBRIO
   A->FE = 0;
   B->FE = 0;
}

//--------------------------------------------------
/*
	Nombre Función: RSI(AVL &r, AVL nodoAVL)
	Objetivo: Rotación simple izquierda
	Parametro: Nodo pivote de rotación y ramificación
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: RSI(AVL &r, AVL nodoAVL) --> rota simple a la izquierda con respecto al nodo r
*/
void RSI(AVL &r, AVL nodoAVL){//Rotación simple izquierda
   AVL padre = nodoAVL->padre;
   AVL A = nodoAVL;
   AVL B = A->der;
   AVL C = B->izq;
   if(padre){
        if(padre->der == A)
            padre->der = B;
        else
            padre->izq = B;
   }
   else  
      r = B;
   //ROTAR
   A->der = C;
   B->izq = A;
   A->padre = B;
   if(C)
      C->padre = A;
   B->padre = padre;
   //ACTUALIZAR FACTORES DE EQUILIBRIO
   A->FE = 0;
   B->FE = 0;
}

//--------------------------------------------------
/*
	Nombre Función: esHoja(AVL nodoAVL)
	Objetivo: permite identificar los nodos hojas
	Parametro: Nodo de un arbol
	Retorno: entero 1 si es hoja, 0 si no es hoja
	Ejemplo: esHoja(AVL nodo1) --> 1 -> si nodo1 es hoja, 0 -> si nodo1 no es hoja
*/
int esHoja(AVL nodoAVL){
   return !nodoAVL->der && !nodoAVL->izq;
}

//--------------------------------------------------
/*
	Nombre Función: altura(AVL arbol)
	Objetivo: permite identificar la altura de un árbol
	Parametro: Un árbol
	Retorno: entero igual a la altura del árbol
	Ejemplo: altura(AVL arbol1) --> # equivalente a la altura del árbol arbol1
*/
int altura(AVL arbol){
    if(arbol==NULL) return 0;
    else{
         if (arbol->izq==NULL && arbol->der==NULL) return 1;
         int altIzq=0;
         int altDer=0;
         if(arbol->izq) altIzq=altura(arbol->izq);
         if(arbol->der) altDer=altura(arbol->der);

         if(altIzq>altDer)
               return altIzq+1;
         else
               return altDer+1;
         }
}

//--------------------------------------------------
/*
	Nombre Función: equilibrar(AVL &r, AVL &nodoAVL)
	Objetivo: permite equilibrar un árbol
	Parametro: Un nodo de pivote y la ramificación
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: equilibrar(AVL &r, AVL &nodoAVL) --> se equilibra la ramificación con respecto al nodo r
*/
void equilibrar(AVL &r, AVL &nodoAVL){
   int salir = FALSE;

   while(nodoAVL && salir!=TRUE)
   {
    nodoAVL->FE=altura(nodoAVL->der)-altura(nodoAVL->izq);
   //COMPROBAR FACTOR DQUILIBRIO DE LOS nodoAVLS
   if(nodoAVL->FE == 0) salir = TRUE;
   else
       if(nodoAVL->FE == -2) {
                   if(nodoAVL->izq->FE == 1) RDD(r, nodoAVL);
                   else RSD(r, nodoAVL);
                   salir = TRUE;
                   }
       else if(nodoAVL->FE == 2){
                   if(nodoAVL->der->FE == -1)RDI(r, nodoAVL);
                   else RSI(r, nodoAVL);
                   salir = TRUE;
                   }
     nodoAVL = nodoAVL->padre; //Avanzar hacia arriba del arbol comprobando el factor equilibrio
   }
}

//--------------------------------------------------
/*
	Nombre Función: eliminarNodo(AVL &n, int dato)
	Objetivo: permite eliminar un nodo
	Parametro: Un arbol y un dato de un nodo
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: eliminarNodo(AVL arbol1, int 1) --> elimina el dato 1 del arbol arbol1
*/
void eliminarNodo(AVL &n, int dato){
   AVL padre = NULL;
   AVL actual;
   AVL nodoAVL;

   int aux;
   actual = n;

   while(actual!=NULL)
   {
      if(dato == actual->nro)
      {
         if(esHoja(actual)) //Si el nodoAVL actual es hoja, eliminar directamente
         {
             if(padre==NULL){//Eliminar la ra?z cuando es hoja
                    n=NULL;
                    return;
             }
            if(padre){ //Si no es la ra?z
                       if(padre->der == actual)
                                padre->der = NULL;
                       else
                           if(padre->izq == actual)
                                 padre->izq = NULL;
                       }
            free(actual);
            actual= NULL;

            if((padre->der == actual && padre->FE == 1) || (padre->izq == actual && padre->FE == -1)) //El nodoAVL a eliminar es el ?nico hijo del padre
            {
               padre->FE = 0;
               actual = padre;
               padre = actual->padre;
            }
            if(padre)
                           equilibrar(n, padre);
            cout<<"\n\n\tARBOL ACTUALIZADO\n";
            verArbol(n, 0);
            return;
         }else{ //Si no es hoja el nodoAVL a eliminar
                  padre = actual;
                  if(actual->der)
                  {
                       nodoAVL = actual->der;
                       while(nodoAVL->izq){
                                        padre = nodoAVL;
                                        nodoAVL = nodoAVL->izq;
                                        }
                  }
                  else{
                       nodoAVL = actual->izq;
                       while(nodoAVL->der){
                                        padre = nodoAVL;
                                        nodoAVL = nodoAVL->der;
                                        }
                       }
                  aux = actual->nro;
                  actual->nro = nodoAVL->nro;
                  nodoAVL->nro = aux;
                  actual = nodoAVL;
                  }

         }else{//Si dato no es igual al n?mero actual
                padre = actual;
                if(dato > actual->nro) actual = actual->der;
                else if(dato < actual->nro) actual = actual->izq;
                }
   }//While
}

//--------------------------------------------------
/*
	Nombre Función: insertar(AVL &nodoAVL, int dato)
	Objetivo: permite insertar un nodo
	Parametro: Un arbol y un dato de un nodo
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: insertar(AVL &nodoAVL, int dato) --> inserta el dato 1 al arbol arbol1
*/
void insertar(AVL &nodoAVL, int dato){
   AVL padre = NULL;
   AVL actual = nodoAVL;
   while(actual!=NULL && dato!=actual->nro)
   {
      padre=actual;

      if(dato < actual->nro) actual = actual->izq;
      else if(dato > actual->nro) actual = actual->der;
   }
   if(actual!=NULL) return; //Actual ya apunta a un nro, salimos

  if(padre==NULL) //El nro a insertar ser? la ra?z
  {
      nodoAVL = (AVL)malloc(sizeof(struct nodoAVL));
      nodoAVL->nro = dato;
      nodoAVL->izq = nodoAVL->der = NULL;
      nodoAVL->padre = NULL;
      nodoAVL->FE = 0;
  }

  else if(dato < padre->nro)
       {
            actual=(AVL)malloc(sizeof(struct nodoAVL));
            padre->izq = actual;
            actual->nro = dato;
            actual->izq=actual->der = NULL;
            actual->padre = padre;
            actual->FE = 0;
            equilibrar(nodoAVL, padre);
       }else{
              if(dato > padre->nro)
              {
                    actual = (AVL)malloc(sizeof(struct nodoAVL));
                    padre->der = actual;
                    actual->nro = dato;
                    actual->izq = actual->der = NULL;
                    actual->padre = padre;
                    actual->FE = 0;
                    equilibrar(nodoAVL, padre);
              }
              }
   cout<<"\n\n\tEl numero ha sido insertado\n\n";
}

//--------------------------------------------------
/*
	Nombre Función: buscar(AVL nodoAVL, int dato)
	Objetivo: permite buscar un nodo
	Parametro: Un arbol y un dato de un nodo
	Retorno: un nodo con el dato
	Ejemplo: buscar(AVL arbol1, int 1) --> busca el dato 1 al arbol arbol1
*/
AVL buscar(AVL nodoAVL, int dato){
   AVL actual = nodoAVL;
   if(nodoAVL==NULL){
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



