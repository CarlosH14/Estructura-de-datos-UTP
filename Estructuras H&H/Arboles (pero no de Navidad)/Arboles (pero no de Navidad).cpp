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


//MENÚ PRINCIPAL
int main(){
	
	ABB binario = NULL;
	ABB binario2 = NULL;
	
	AVL vl = NULL;
	RBT rojonegro = NULL;
	int op;
	cout<<"----------MENU----------\n\n"; delay(1);
	cout<<"1. ABB (Arboles Binarios de Busqueda)\n2. AVL (Arboles AVL\n3. ARN (Arboles Roji-Negros)\n4. Salir\n";
	cin>>op;
	do{
	switch(op){
		case 1:
			delay(1);cout<<"\n\n.";delay(1);cout<<".";delay(1);cout<<".";delay(1);
			system("cls");
			cout<<"----------SUBMENU ABB----------\n\n";
			cout<<" 1. Insertar\n\n 2. Eliminar\n\n 3. Buscar\n\n 4. Ver el Arbol\n\n 5. Recorrer el arbol en En-orden\n\n 6. Recorrer el arbol en Pre-orden\n\n 7. Recorrer el arbol en Post-orden\n\n 8. Calcular el Peso del arbol\n\n 9. Altura del arbol\n\n 10. Contar Cuantas hojas Tiene el arbol\n\n 11. Padre de un Nodo\n\n 12. Indicar con una funcion boolean, si dos arboles binarios son iguales.\n\n 13. Indicar con una funcion boolean, si dos arboles binarios son isomorfos (tienen la misma forma).\n\n 14. Indicar con una funcion boolean si dos arboles binarios son semejantes \n (tienen los mismos elementos aunque no tengan la misma forma)\n\n 15. Hacer una funcion boolean que indique si un arbol binario esta lleno.\n\n 16. Calcular el nivel de un elemento en un arbol binario.\n\n 17.Hacer una funcion que indique cuantos elementos tiene un arbol binario en un nivel dado.\n\n 18.Hacer una funcion que reciba dos elementos e indique si son primos (sus padres son hermanos) NO FUNCIONA.\n\n 19.Un arbol de valores enteros es estable, si para todo elemento su padre es mayor. \n Hacer una funcion que reciba un arbol binario de enteros e indique si es estable.\n\n 20.Hacer una funcion que retorne el mayor elemento del arbol.\n\n 21.Hacer una funcion que retorne una lista con los elementos del nivel dado N. \n\n 22. Elimina del arbol binario un elemento dado, conservando su recorrido en inorden salvo por elemento retirado.\n\n 23. Atras.\n\n";
			int opabb;
			cin>>opabb;
			switch(opabb){
				case 1:
					int inserabb;
					delay(1);cout<<"\n\n.";delay(1);cout<<".";delay(1);cout<<".";delay(1);
					system("cls");
					cout<<"Ingrese número a insertar:\t"; cin>>inserabb;
					insertar(binario, inserabb);
					break;
				case 2:
					int elimabb;
					delay(1);cout<<"\n\n.";delay(1);cout<<".";delay(1);cout<<".";delay(1);
					system("cls");
					cout<<"Ingrese número a eliminar:\t"; cin>>elimabb;
					eliminar(binario, elimabb);
					break;
				case 4:
					system("cls");
					verArbol(binario, 0);
					cout<<"\n\n";
					system("pause");
					break;
				case 3:
					int busabb;
					delay(1);cout<<"\n\n.";delay(1);cout<<".";delay(1);cout<<".";delay(1);
					system("cls");
					cout<<"Ingrese número a buscar:\t"; cin>>busabb;
					buscar(binario, busabb);
					cout<<"\n\n";
					system("pause");
					break;
				case 5:
					system("cls");
					enOrden(binario);
					cout<<"\n\n";
					system("pause");
					break;
				case 6:
					system("cls");
					preOrden(binario);
					cout<<"\n\n";
					system("pause");
					break;
				case 7:
					system("cls");
					postOrden(binario);
					cout<<"\n\n";
					system("pause");
					break;
				case 8:
					system("cls");
					cout<<peso(binario);
					cout<< "es el peso\n\n";
					system("pause");
					break;
				case 9:
					int x;
					x=alturaAB(binario);
					cout<<"Altura:\t";
					cout<<x;
					cout<<"\n\n";
					system("pause");
					break;
				case 10:
					int y;
					y=contarHojas(binario);
					cout<<"Numero de hojas:\t";
					cout<<y;
					cout<<"\n\n";
					system("pause");
					break;
				case 11:
					int padabb;
					system("cls");
					cout<<"Padre del nodo?:\t"; cin>>padabb;
					system("cls");
					padreAB(binario, padabb);
					cout<<"\n\n";
					system("pause");
					break;
				case 12:
					system("cls");
					cout<<"Iguales?\t";
					if(iguales(binario, binario2)==0){
						cout<<"Son iguales\n\n";
					}else{
						cout<<"No son iguales\n\n";
					}
					system("pause");
					break;
				case 13:
					system("cls");
					cout<<"Isoformos?\t";
					if(iguales(binario, binario2)==0){
						cout<<"Son isoformos\n\n";
					}else{
						cout<<"No son isoformos\n\n";
					}
					system("pause");
					break;
				case 14:
					system("cls");
					cout<<"Semejantes?\t";
					if(iguales(binario, binario2)==0){
						cout<<"Son semejantes\n\n";
					}else{
						cout<<"No son semejantes\n\n";
					}
					system("pause");
					break;
				case 15:
					system("cls");
					cout<<"Los arboles son estrucutras de datos dinamicas por lo que nunca estaran llenos\n\n";
					system("pause");
					break;
				case 16:
					system("cls");
					cout<<nivel(binario);
					cout<< " son los niveles\n\n";
					system("pause");
					break;
				case 18:
					
					// ESTA FUNCIÓN NO FUNCIONA CORRECTAMENTE
					// AUNQUE LA LÓGICA PARECE ESTAR BIEN
					// VER FUNCIÓN esprimo()
					
					/*system("cls");
					cout<<"Cuales son primos?\t";
					int pr,prr, ww;
					cin>>pr>>prr;
					ww=esprimo(binario,pr,&prr);
					if(ww==1){
						cout<<"Es primo\n\n";
					}else{
						cout<<"No es primo\n\n";
					}
					system("pause");
					break;*/
				case 17:
					int yy;
					y=contarHojas(binario);
					cout<<"Numero de elementos:\t";
					cout<<yy;
					cout<<"\n\n";
					system("pause");
					break;
				case 19:
					system("cls");
					int est;
					est=estable(binario);
					if(est==1){
						cout<<"Es estable\n\n";
					}else{
						cout<<"No es estable\n\n";
					}
					system("pause");
					break;
				case 20:
					system("cls");
					int may;
					may=mayor(binario);
					cout<<"El mayor es "<<may<<endl<<endl;
					system("pause");
					break;
				case 21:
					//LISTA ARBOL
					break;
				case 22:
					int elimabbb;
					delay(1);cout<<"\n\n.";delay(1);cout<<".";delay(1);cout<<".";delay(1);
					system("cls");
					cout<<"Ingrese número a eliminar:\t"; cin>>elimabbb;
					eliminar(binario, elimabbb);
					cout<<"\n\nRecorrido inorden\n\n";
					enOrden(binario);
					cout<<"\n\n";
					system("pause");
					break;
				case 23:
					system("cls");
					cout<<"----------MENU----------\n\n"; delay(1);
					cout<<"1. ABB (Arboles Binarios de Busqueda)\n2. AVL (Arboles AVL\n3. ARN (Arboles Roji-Negros)\n4. Salir\n";
					cin>>op;
					break;
			}
			break;
		case 2:
			delay(1);cout<<"\n\n.";delay(1);cout<<".";delay(1);cout<<".";delay(1);
			system("cls");
			cout<<"----------SUBMENU AVL----------\n\n";
			cout<<" 1. Insertar\n\n 2. Eliminar\n\n 3. Buscar\n\n 4. Ver el Arbol\n\n 5. Atras\n\n";
			int opvl;
			cin>>opvl;
			switch(opvl){
				case 1:
					int inservl;
					delay(1);cout<<"\n\n.";delay(1);cout<<".";delay(1);cout<<".";delay(1);
					system("cls");
					cout<<"Ingrese número a insertar:\t"; cin>>inservl;
					insertar(vl, inservl);
					break;
				case 2:
					int elimvl;
					delay(1);cout<<"\n\n.";delay(1);cout<<".";delay(1);cout<<".";delay(1);
					system("cls");
					cout<<"Ingrese número a eliminar:\t"; cin>>elimvl;
					eliminarNodo(vl, elimvl);
					break;
				case 4:
					system("cls");
					verArbol(vl, 0);
					cout<<"\n\n";
					system("pause");
					break;
				case 3:
					int busvl;
					delay(1);cout<<"\n\n.";delay(1);cout<<".";delay(1);cout<<".";delay(1);
					system("cls");
					cout<<"Ingrese número a buscar:\t"; cin>>busvl;
					buscar(vl, busvl);
					cout<<"\n\n";
					system("pause");
					break;
				case 5:
					system("cls");
					cout<<"----------MENU----------\n\n"; delay(1);
					cout<<"1. ABB (Arboles Binarios de Busqueda)\n2. AVL (Arboles AVL\n3. ARN (Arboles Roji-Negros)\n4. Salir\n";
					cin>>op;
					break;
			}
			break;
		
		case 3:
			delay(1);cout<<"\n\n.";delay(1);cout<<".";delay(1);cout<<".";delay(1);
			system("cls");
			cout<<"----------SUBMENU RBT----------\n\n";
			cout<<" 1. Insertar\n\n 2. Eliminar\n\n 3. Buscar\n\n 4. Ver el Arbol\n\n 5. Atras\n\n";
			int oprn;
			cin>>oprn;
			switch(oprn){
				case 1:
					int inserrn;
					delay(1);cout<<"\n\n.";delay(1);cout<<".";delay(1);cout<<".";delay(1);
					system("cls");
					cout<<"Ingrese número a insertar:\t"; cin>>inserrn;
					insertar(rojonegro, inserrn);
					break;
				case 2:
					int elimrn;
					delay(1);cout<<"\n\n.";delay(1);cout<<".";delay(1);cout<<".";delay(1);
					system("cls");
					cout<<"Ingrese número a eliminar:\t"; cin>>elimrn;
					eliminar_rbt(rojonegro, elimrn);
					break;
				case 4:
					system("cls");
					verArbol(rojonegro, 0);
					cout<<"\n\n";
					system("pause");
					break;
				case 3:
					int busrn;
					delay(1);cout<<"\n\n.";delay(1);cout<<".";delay(1);cout<<".";delay(1);
					system("cls");
					cout<<"Ingrese número a buscar:\t"; cin>>busrn;
					buscar(rojonegro, busrn);
					cout<<"\n\n";
					system("pause");
					break;
				case 5:
					system("cls");
					cout<<"----------MENU----------\n\n"; delay(1);
					cout<<"1. ABB (Arboles Binarios de Busqueda)\n2. AVL (Arboles AVL\n3. ARN (Arboles Roji-Negros)\n4. Salir\n";
					cin>>op;
					break;
			}
			break;
		
		
		
		case 4:
			break;
	}
}while(op!=4);
	system("pause");
	return 0;
}



