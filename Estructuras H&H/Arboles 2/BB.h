using namespace std;

/*****************************************************/
/* LIBRERÍA DE IMPLEMENTACIÓN DE ARBOLES BINARIOS DE BUSQUEDA */
/*****************************************************/
/*
	Nombre Estructura: nodo 
	Atributos: nro, nodo der, nodo izq
	Descripcion: nodo de un árbol binario de busqueda
	con punteros a sus nodos hijos y nodo padre
*/
struct nodo{
     int nro;
     nodo *izq;
	 nodo *der;
};
typedef nodo *ABB;

//--------------------------------------------------
/*
	Nombre Función: crearNodo(int x)
	Objetivo: crear un nodo nuevo con un dato
	Parametro: int x -> entero del nuevo nodo
	Retorno: el nodo con el dato nuevo
	Ejemplo: crearNodo(int 2) --> crea un nodo con el dato 2
*/
ABB crearNodo(int x){
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;
     return nuevoNodo;
}

//-------------------------------------------------------------------
/*
	Nombre Función: insertar(ABB &arbol, int x)
	Objetivo: permite insertar un nodo
	Parametro: Un arbol y un dato de un nodo
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: insertar(ABB &arbol, int x) --> inserta el dato 1 al arbol arbol1
*/
void insertar(ABB &arbol, int x){
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

//-------------------------------------------------------------------
/*
	Nombre Función: preOrden(ABB arbol)
	Objetivo: permite visualizar un arbol en preorden
	Parametro: Un arbol
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: preOrden(ABB arbol1) --> muestra el arbol arbol1 en preorden
*/
void preOrden(ABB arbol){
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

//-------------------------------------------------------------------
/*
	Nombre Función: enOrden(ABB arbol)
	Objetivo: permite visualizar un arbol en inorden
	Parametro: Un arbol
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: enOrden(ABB arbol1) --> muestra el arbol arbol1 en inorden
*/
void enOrden(ABB arbol){
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

//-------------------------------------------------------------------
/*
	Nombre Función: postOrden(ABB arbol)
	Objetivo: permite visualizar un arbol en posorden
	Parametro: Un arbol
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: postOrden(ABB arbol1) --> muestra el arbol arbol1 en posorden
*/
void postOrden(ABB arbol){
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}

//-------------------------------------------------------------------
/*
	Nombre Función: verArbol(ABB arbol, int n)
	Objetivo: mostrar el Arbol en pantalla
	Parametro: ABB arbol->arbol a mostrar, int n->entero de validación
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: verArbol(arbol1, 1) --> muestra el arbol arbol1 en pantalla 
*/
void verArbol(ABB arbol, int n){
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
     //global=n;
}

//-------------------------------------------------------------------
/*
	Nombre Función: buscar(ABB arbol, int dato)
	Objetivo: permite buscar un nodo
	Parametro: Un arbol y un dato de un nodo
	Retorno: TRUE o FALSE
	Ejemplo: buscar(ABB arbol1, int 1) --> busca el dato 1 al arbol arbol1
*/
bool buscar(ABB arbol, int dato){
     int r=0;   // 0 indica que lo encontre

     if(arbol==NULL)
        return r; cout<<"vacio";

     if(dato<arbol->nro)
         r = buscar(arbol->izq, dato);

     else if(dato> arbol->nro)
         r = buscar(arbol->der, dato);

     else
        r = 1;
				cout<<"Encontrado";   // son iguales, lo encontre

     return r;
}

//-------------------------------------------------------------------
/*
	Nombre Función: eliminar(ABB &arbol,int x)
	Objetivo: permite eliminar un nodo
	Parametro: Un arbol y un dato de un nodo
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: eliminar(ABB arbol1,int 1) --> elimina el dato 1 del arbol arbol1
*/
void eliminar(ABB &arbol,int x){
    ABB aux1,aux2;
    if(arbol==NULL) return;
    if(x>arbol->nro)
         eliminar(arbol->der,x);
    if(x<arbol->nro)
        eliminar(arbol->izq,x);
    if(x==arbol->nro)
    {
        if(arbol->der==NULL && arbol->izq==NULL) //Si el nodo es hoja
        {
            arbol=NULL;
            return;
        }
        if(arbol->der!=NULL && arbol->izq==NULL)
        {
            arbol=arbol->der;
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


