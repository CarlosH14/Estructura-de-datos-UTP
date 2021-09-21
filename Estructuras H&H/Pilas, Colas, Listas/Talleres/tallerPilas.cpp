#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;
/*
	Nombre Estructura: nodo
	Atributos: dato, nodo siguiente 
	Descripcion: nodo de una pila, con
	el dato que almacena y con el apuntador
	al nodo siguiente
*/
struct nodo{

    int dato;
    struct nodo *ste;
};
typedef nodo *ptrPila;
//--------------------------------------------------
/*
	Nombre Función: push
	Objetivo: agregar un nuevo nodo a una pila
	Parametro: pila p, entero valor
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: push(p,5) --> agrega 5 a la pila p 
*/
void push(ptrPila &p, int valor){

	ptrPila aux;
	aux=new(struct nodo);
	aux->dato=valor;
	aux->ste=p;
	p=aux;

}
//--------------------------------------------------
/*
	Nombre Función: pop
	Objetivo: eliminar un nuevo nodo a una pila
	Parametro: pila p
	Retorno: el valor eliminado
	Ejemplo: pop(p) --> elimina el nodo siguiente de la pila p 
*/
int pop(ptrPila &p){

	int num;
	ptrPila aux;
	aux=p;
	if(aux==NULL){
        printf("\n\nPila vacia\n\n");
	}
	else{
        num=aux->dato;
        p=aux->ste;
	    printf("\n\nel numero %i ha sido desapilado\n\n",aux->dato);
        delete(aux);
	}


	return(num);
}
//--------------------------------------------------
/*
	Nombre Función: pop2
	Objetivo: eliminar un nuevo nodo a una pila
	Parametro: pila p
	Retorno: el valor eliminado
	Ejemplo: pop2(p) --> elimina el nodo siguiente de la pila p 
*/
int pop2(ptrPila &p){

	int num;
	ptrPila aux;
	aux=p;
	if(aux==NULL){
        printf("\n\nPila vacia\n\n");
	}
	else{
        num=aux->dato;
        p=aux->ste;
        delete(aux);
	}


	return(num);
}
//--------------------------------------------------
/*
	Nombre Función: mostrar_pila
	Objetivo: mostrar la pila en pantalla
	Parametro: pila p
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: mostrar_pila(p) --> muestra en pantalla los valores de la pila p
*/
void mostrar_pila(ptrPila p){

	ptrPila aux;
	aux=p;
	while(aux!=NULL){
		printf("%i\t",aux->dato);
		aux=aux->ste;
	}
}
//--------------------------------------------------
/*
	Nombre Función: destruir_pila
	Objetivo: destruye una pila
	Parametro: pila p
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: destruir_pila(p) --> destruye la pila p
*/
void destruir_pila(ptrPila &p){
	ptrPila aux;

	while(p!=NULL){
		aux=p;
		p=aux->ste;
		delete(aux);
	}
}
//--------------------------------------------------
/*
	Nombre Función: invertir
	Objetivo: invertir una pila
	Parametro: pila p
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: invertir(p) --> muestra en pantalla la pila invertida
*/
void invertir(ptrPila p){
	ptrPila l=NULL;
	ptrPila aux;
	aux=p;
	int n;
	printf("\nPila sin invertir\n");
	mostrar_pila(aux);
	while(aux!=NULL){
		n=pop2(aux);
		push(l,n);
	}
	printf("\n\nPila invertida\n");
	mostrar_pila(l);
	aux=l;
	p=aux;
	destruir_pila(l);
}
//--------------------------------------------------
/*
	Nombre Función: xenpila
	Objetivo: busca el valor x en una pila p
	Parametro: pila p, valor x
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: xenpila(p) --> muestra si el valor se encuentra en la pila o no
*/
void xenpila(ptrPila p,int x){

	ptrPila aux;
	aux=p;
	int flag=0;
	while(aux!=NULL && flag!=1){
		if(x==aux->dato){
			flag=1;
		}
		else{
			aux=aux->ste;
		}
	}
	if(flag==1){
		printf("\nel elemento %i se encuentra en la pila\n",x);
	}
	else{
		printf("\nel elemento %i no se encuentra en la pila\n",x);
	}
}
//--------------------------------------------------
/*
	Nombre Función: pilasorden
	Objetivo: verifica si las pilas son iguales
	Parametro: pila p1, pila p2
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: pilasorden(p1, p2) --> muestra si lass pilas son iguales o no
*/
void pilasorden(ptrPila p1,ptrPila p2){

	ptrPila aux1;
	ptrPila aux2;
	aux1=p1;
	aux2=p2;
	while(aux1!=NULL && aux2!=NULL){
		if(aux1->dato==aux2->dato){
			aux1=aux1->ste;
			aux2=aux2->ste;
		}
		else{
			printf("\nLas pilas no se encuentran ordenadas igual\n");
			return;
		}
	}
	printf("\nLas pilas se encuentran ordenadas igual\n");
	return;
}
//--------------------------------------------------
/*
	Nombre Función: xenpila_borrar
	Objetivo: borra un elemento x de una pila
	Parametro: pila p, valor x
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: xenpila_borrar(p1, 4) --> elimina el elemento 4 de la pila p
*/
void xenpila_borrar(ptrPila p, int x){
	ptrPila aux;
	aux=p;
	int flag=0;
	while(aux!=NULL && flag!=1){
		if(x==aux->dato){
			flag=1;
		}
		else{
			aux=aux->ste;
		}
	}
	ptrPila aux2;
	ptrPila aux3=NULL;
	aux2=p;
	while(aux2!=NULL){
		if(x==aux2->dato){
			aux2=aux2->ste;
		}
		else{
			push(aux3, aux2->dato);
			aux2=aux2->ste;
		}
	}
	printf("\nPila antes de eliminar\n");
	mostrar_pila(p);
	printf("\nPila despues de eliminar\n");
	mostrar_pila(aux3);
	p=aux3;
}
//--------------------------------------------------
/*
	Nombre Función: push_pos
	Objetivo: agrega un elemento x en una posicion pos de una pila p
	Parametro: pila p, valor x, valor por
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: push_pos(p1, 4, 2) --> agrega el valor 4 en la posicion 2 de la pila p
*/
void push_pos(ptrPila p, int x, int pos){
	ptrPila aux;
	ptrPila aux2=NULL;
	aux=p;
	int i=0;
	int n;
	while(aux!=NULL){
		if(pos==i){
			n=aux->dato;
			push(aux2,x);
			push(aux2,n);
			i++;
			aux=aux->ste;
		}else{
			n=aux->dato;
			push(aux2,n);
			i++;
			aux=aux->ste;
		}
	}
	printf("\nPila antes de agregar\n");
	mostrar_pila(p);
	printf("\nPila despues de agregar\n");
	mostrar_pila(aux2);
	p=aux2;
	
}
//--------------------------------------------------
/*
	Nombre Función: separar
	Objetivo: separa una pila p en dos pilas de mayores y menores(p1 y p2) segun un valor x
	Parametro: pila p, pila p1, pila p2, valor x
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: separar(p, p1, p2, 5) --> muestra la pila original p, muestra la pila con los mayores a x en p1
	y la pila con los menores a x en p2
*/
void separar(ptrPila p, ptrPila p1, ptrPila p2, int x){
	
	
	ptrPila aux;
	aux=p;
	while(aux!=NULL){
		if(aux->dato>=x){
			push(p1,aux->dato);
			aux=aux->ste;
		}else{
			push(p2,aux->dato);
			aux=aux->ste;
		}
	}
	printf("\nPila original\n");
	mostrar_pila(p);
	printf("\nPila mayores\n");
	mostrar_pila(p1);
	printf("\nPila menores\n");
	mostrar_pila(p2);
	
	
}

void menu(){
    printf("Implementacion de pilas en c++\n\n1.Apilar\n2.Desapilar\n3.Mostrar Pila\n4.Destruir Pila\n5.Invertir Pila\n6.Elemento X en la Pila\n7.Pilas ordenadas\n8.Borrar x en pila\n9.Agregar con posicion\n10.Separar mayores y menores\n\n0.Salir\n\nIngrese Opcion:");
}

int main(){

    ptrPila p=NULL;
    ptrPila p2=NULL;
    ptrPila p1=NULL;
    int dato,op,x,y,w;
    system("color 0b");

    do{
        menu();
        scanf("%i",&op);

        switch(op){

            case 1:
            	printf("\n\nPor favor ingrese el numero a apilar\n\n");
            	scanf("%i",&dato);
            	push(p,dato);
            	printf("\n\nEl numero %i ha sido apilado\n\n",dato);
            	break;

            case 2:
            	x=pop(p);
            	break;

            case 3:
            	printf("\n\nMostrando Pila\n\n");

            	if(p!=NULL){
            		mostrar_pila(p);
            	}
            	else{
            		printf("\n\nPila vacia\n\n");
            	}
            	break;

            case 4:
            	destruir_pila(p);
            	printf("Pila eliminada");
            	break;

            case 5:
            	invertir(p);
            	break;

            case 6:
            	printf("Por favor ingrese el elemento a buscar:\n\n-");
            	scanf("%i",&y);
            	xenpila(p,y);
            	break;
            case 7:
            	printf("Pilas a comparar:\n");
            	p2=p;
            	printf("\nPila 2:\n");
            	mostrar_pila(p);
            	printf("\nPila 2:\n");
            	mostrar_pila(p2);
            	pilasorden(p,p2);
            	break;
            case 8:
            	printf("Por favor ingrese el elemento a borrar:\n\n-");
            	scanf("%i",&y);
            	xenpila_borrar(p,y);
            	break;
            case 9:
            	printf("Por favor ingrese el elemento a adicionar:\n\n-");
            	scanf("%i",&y);
            	printf("Por favor ingrese la posicion a adicionar:\n\n-");
            	scanf("%i",&w);
            	push_pos(p,y,w);
            	break;
            case 10:
            	printf("Por favor ingrese el elemento a separar:\n\n-");
            	scanf("%i",&y);
            	separar(p,p1,p2,y);
            	break;
        }
        system("pause");
        system("cls");
    }while(op!=0);

    return 0;

}
