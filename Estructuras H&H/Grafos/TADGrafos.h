#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct NodoV
  {  int dato;
     struct NodoV *sig;
     int marcado;
        } *ListaVertice;


typedef struct NodoA
  {  int origen;
     int destino;
     int costo;
     struct NodoA *sig;
        } *ListaArco;


typedef struct nodoGrafo{
        ListaVertice v;
        ListaArco a;
        } Grafo;


Grafo crearGrafo()
  {
      Grafo g;
      g.v=NULL;
      g.a=NULL;
      return g;
  }
      


// Funci?n para adicionar un vertice a la lista de v?rtices
Grafo insertarVertice (Grafo g, int x)
{
   ListaVertice nuevo=(ListaVertice) malloc(sizeof (struct NodoV));
   nuevo->sig=g.v;
   nuevo->dato=x;
   nuevo->marcado=0;   // el vertice no esta marcado
   g.v=nuevo;
   return g;
}



void imprimirListaV(Grafo g)
{
     ListaVertice k=g.v;
     while (k!=NULL)
     {
           printf(" \n%d     %d",k->dato, k->marcado);
           k=k->sig;
           }
 }


// Funci?n para adicionar un arco a la lista de arcos
Grafo insertarArco (Grafo g, int x, int y, int z)
{
   ListaArco nuevo=(ListaArco) malloc(sizeof (struct NodoA));
   nuevo->sig=g.a;
   nuevo->origen=x;
   nuevo->destino=y;
   nuevo->costo=z;
   g.a=nuevo;
   return g;
}
        
        
// imprime la lista de arcos
void imprimirListaA(Grafo g)
{
     ListaArco k=g.a;
     while (k!=NULL)
     {
           printf(" \n%d    %d     %d",k->origen, k->destino, k->costo);
           k=k->sig;
           }
 }


      
ListaVertice verticesGrafo (Grafo g)
 {
     return g.v;
 }
    

ListaArco arcosGrafo (Grafo g)
 {
     return g.a;
 }
    

Grafo cambiarListaV (Grafo g, ListaVertice k)
{
   g.v = k;
   return g;
}


Grafo cambiarListaA (Grafo g, ListaArco k)
{
   g.a = k;
   return g;
}


int vacioGrafo (Grafo g)
       // Devuelve verdadero si el grafo es vacio
    {
      if (g.v==NULL)
         return 1;
      else
         return 0;
    }

// elimina un vertice del grafo
Grafo eliminarVertice (Grafo g, int x)
{
    ListaVertice k=g.v, p;

    if (g.v!=NULL)
        {
           if (g.v->dato == x)
             {
              g.v = g.v->sig;
              free(k);
              }
           else
             {
               while ((k->sig != NULL) && (k->sig->dato != x))
                  k=k->sig;
               if (k->sig!=NULL)
                  {
                     p=k->sig;
                     k->sig=p->sig;
                     free(p);
                  }
             }
        }
     return g;
 }

// Elimina un arco que parta del origen x al destino y
Grafo eliminarArco (Grafo g, int x, int y)
{
    ListaArco k=g.a, p;

    if (g.a!=NULL)
        {
           if ((g.a->origen == x) && (g.a->destino == y))
             {
              g.a = g.a->sig;
              free(k);
              }
           else
             {
               while ((k->sig != NULL) && !((k->sig->origen == x) && (k->sig->destino == y)))
                  k=k->sig;
               if (k->sig!=NULL)
                  {
                     p=k->sig;
                     printf("\n el arco a borrar es %d   %d",p->origen,p->destino);
                     k->sig=p->sig;
                     free(p);
                  }
             }
        }
     return g;
 }
 
 
 // retorna el costo del arco desde x hasta y
 int costoArco (Grafo g, int x, int y)
  {
    ListaArco k=g.a;

    while (k != NULL)
      {
       if ((k->origen == x) && (k->destino == y))
          return k->costo;
       k=k->sig;
      }
    return -1;       // no encontr? el arco
  }


// retorna el n?mero de v?rtices asociados al grafo
int ordenGrafo(Grafo g)
  {
    int orden=0;
    ListaVertice k=g.v;

    while (k != NULL)
      {
        orden++;
        k=k->sig;
      }
    return orden;
  }



// marca un vertice de grafo
Grafo marcarVertice (Grafo g, int x)
{
    ListaVertice k=g.v;

    while (k!=NULL)
        {
           if (k->dato == x)
             {
              k->marcado = 1;
              k=NULL;
             }
           else
             k=k->sig;
        }
     return g;
 }


// desmarca un vertice de grafo
Grafo desmarcarVertice (Grafo g, int x)
{
    ListaVertice k=g.v;
    while (k!=NULL)
        {
           if (k->dato == x)
             {
              k->marcado = 0;
              k=NULL;
             }
           else
             k=k->sig;
        }
     return g;
 }

// desmarca todos los vertices del grafo
Grafo desmarcarGrafo (Grafo g)
{
    ListaVertice k=g.v;

    while (k!=NULL)
        {
           k->marcado = 0;
           k=k->sig;
        }
     return g;
 }


//Indica si un v?rtice est? marcado
int marcadoVertice (Grafo g, int x)
{
    ListaVertice k=g.v;
    while (k!=NULL)
        {
           if (k->dato == x)
             {  
              if (k->marcado == 0)
                  return 0;
              else 
                  return 1;
             }
           else
             k=k->sig;
        }
     return 0;
 }    
    
    
  
ListaVertice sucesores(Grafo g, int x)
{
   ListaArco k=g.a;
   ListaVertice ver=NULL, nuevo;

    while (k != NULL)
      {
       if (k->origen == x)
          {  // se agrega a la lista el destino del arco como sucesor de x
            nuevo=(ListaVertice) malloc(sizeof (struct NodoV));
            nuevo->sig=ver;
            nuevo->dato=k->destino;
            nuevo->marcado=0;   // el vertice no esta marcado
            ver=nuevo;
            printf("\n %d  ",nuevo->dato);
          }
       k=k->sig;
      }
   return ver;
}

