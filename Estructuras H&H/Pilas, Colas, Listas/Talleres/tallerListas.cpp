#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;
//____________________________________________________________________
/*
TALLER DE LISTAS
*/
//_____________________________________________________________________

/*
	Nombre Estructura: Lista
	Atributos: valor, nodo siguiente 
	Descripcion: lista, con el apuntador hacia adelante
*/
struct nodo{
	int nro;
	struct nodo *sgte;
};

typedef nodo *Tlista;
//_____________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: insertaInicio
	Objetivo: Dada una lista de elementos ingresa uno nuevo al inicio
	Parametro: Lista, valor
	Retorno: es un procedimiento
	Ejemplo: insertaInicio(Lista, 5) --> inserta el elemento 5 en la lista
*/
void insertaInicio(Tlista &lista,int valor){
	Tlista q;
	q=new(struct nodo);
	q->nro=valor;
	q->sgte=lista;
	lista=q;
}
//_____________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: insertaFinal
	Objetivo: Dada una lista de elementos ingresa uno nuevo al final
	Parametro: Lista, valor
	Retorno: es un procedimiento
	Ejemplo: insertaFinal(Lista, 5) --> inserta el elemento 5 en la lista
*/
void insertaFinal(Tlista &lista,int valor){
	Tlista t,q=new(struct nodo);
	q->nro=valor;
	q->sgte=NULL;

	if(lista==NULL){
		lista=q;
	}
	else{
		t=lista;
		while(t->sgte != NULL){
			t=t->sgte;
		}
		t->sgte=q;
	}
}
//_____________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: insertaAD
	Objetivo: Elegir la posicion para ingresar
	Parametro: ninguno
	Retorno: la posicion donde se va a insertar
	Ejemplo: insertaAD() --> 1 o 0 segun la posicion
*/
int insertaAD(){
	int op,band;
	printf("\n\t1.antes de la posicion.\n\t2.despues de la posicion\n\n\tingrese opcion");
	scanf("%i",&op);
	if(op==1)
		band=-1;
	else
		band=0;

	return band;
}
//_____________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: insertarelemento
	Objetivo: Dada una lista de elementos ingresa uno nuevo en una posicion especifica
	Parametro: Lista, valor, pos
	Retorno: es un procedimiento
	Ejemplo: insertarelemento(Lista, 5, 3) --> inserta el elemento 5 en la lista en la pos 3
*/
void insertarelemento(Tlista &lista,int valor, int pos){
	Tlista q,t;
	int i;
	q=new(struct nodo);
	q->nro=valor;
	if(pos==1){
		q->sgte=lista;
		lista=q;
	}
	else{
		int x=insertaAD();
		t=lista;
		for(i=1;t!=NULL;i++){
			if(i==pos+x){
				q->sgte=t->sgte;
				t->sgte=q;
				return;
			}
			t=t->sgte;
	}
	}
}
//_____________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: buscarelemento
	Objetivo: Dada una lista de elementos busca uno de ellos
	Parametro: Lista, valor
	Retorno: es un procedimiento
	Ejemplo: buscarelemento(Lista, 5) --> busca el elemento 5 en la lista
*/
void buscarelemento(Tlista lista,int valor){
	Tlista q=lista;
	int i=1,band=0;

	while(q!=NULL){
		if(q->nro==valor){
			cout<<endl<<"encontrada en posicion"<< i <<endl;
			band=1;
		}
		q=q->sgte;
		i++;
	}

	if(band==0){
		printf("\n\nnumero no encontrado..!\n");
	}
}
//_____________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: mostrarlista
	Objetivo: Dada una lista de elementos la imprime en pantalla
	Parametro: Lista
	Retorno: es un procedimiento
	Ejemplo: mostrarlista(Lista) --> muestra la lista
*/
void mostrarlista(Tlista lista){
	int i=0;

	while(lista!=NULL){
		cout<<' '<<i+1<<") "<<lista->nro<<endl;
		lista=lista->sgte;
		i++;
	}
}
//_____________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: eliminarelemento
	Objetivo: Dada una lista de elementos y un número P,
  elimina el valor P en la lista. 
	Parametro: Lista, valor P
	Retorno: es un procedimiento
	Ejemplo: eliminarelemento(Lista[],5) --> elimina 5 en Lista 
*/
void eliminarelemento(Tlista &lista,int valor){

	Tlista p,ant;
	p=lista;
	if(lista!=NULL){
		while(p!=NULL){
			if(p->nro==valor){
				if(p==lista){
					lista=lista->sgte;
				}
				else{
					ant->sgte=p->sgte;
				}
				delete(p);
				return;
			}
			ant=p;
			p=p->sgte;
		}
	}
	else{
		printf("\n\nLista vacia\n");
	}
}
//_____________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: eliminarrepetidos
	Objetivo: Dada una lista de elementos y un número P,
  elimina los valores P repetidos en la lista. 
	Parametro: Lista, valor P
	Retorno: es un procedimiento
	Ejemplo: eliminarrepetidos(Lista[],5) --> elimina las veces que aparece 5 en Lista 
*/
void eliminarrepetidos(Tlista &lista,int valor){
	Tlista q,ant;
	q=lista;
	ant=lista;

	while(q!=NULL){
		if(q->nro==valor){
			if(q==lista){
				lista=lista->sgte;
				delete(q);
				q=lista;
			}
			else{
				ant->sgte=q->sgte;
				delete(q);
				q=ant->sgte;
			}
		}
		else{
			ant=q;
			q=q->sgte;
		}
	}
	printf("\n\nvalores eliminados..!\n");
}
//_____________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: contarrepetidos
	Objetivo: Dada una lista de elementos y un número P,
  devolver el número de veces que está el valor de P en la lista. 
	Parametro: Lista, valor P
	Retorno: numero de ocurrencia de P en Lista
	Ejemplo: contarrepetidos(Lista[],5) --> # de veces que aparece 5 en Lista 
*/
void contarrepetidos(Tlista lista,int valor){
	Tlista q;
	q=lista;
	int cont=0;

	while(q!=NULL){
		if(q->nro==valor){
			cont=cont+1;
			q=q->sgte;
		}
		else{
			q=q->sgte;
		}
	}
	printf("\n\nEl valor ingresado se encuentra %i veces en la lista\n",cont);
}
//_____________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: invertirlista
	Objetivo: Dada una lista, hacer una función que invierta
  sus datos en ella misma y la devuelva invertida. 
	Parametro: Lista
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: invertirlista(Lista) --> Lista pero invertida
*/
void invertirlista(Tlista &lista){
	Tlista aux=NULL;
	int n;
	cout<<"\nLista sin invertir\n";
	mostrarlista(lista);

	while(lista!=NULL){
		n=lista->nro;
		insertaInicio(aux,n);
		lista=lista->sgte;
	}
	cout<<"\nLista invertida\n";
	mostrarlista(aux);
	lista=aux;
}
//_____________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: promedio
	Objetivo: Hacer una función que reciba una lista y 
  devuelva el promedio de los datos de la lista.
	Parametro: Lista
	Retorno: el promedio de los valores
	Ejemplo: promedio(Lista) --> promedio de la lista
*/
void promedio(Tlista lista){
	int cont=0;
	int n=0;
	int i=0;
	while(lista!=NULL){
		n=lista->nro;
		cont=cont+n;
		i=i+1;
		lista=lista->sgte;
	}
	printf("\n\nLos elementos de la lista suman %i y ahi %i elementos.\nEl promedio aproximado de la lista es %i\n",cont,i,(cont/i));
}
//_____________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: mayordelista
	Objetivo: Hacer una función que reciba una lista y
  devuelva el mayor valor datos existentes. 
	Parametro: Lista
	Retorno: el valor mas grande
	Ejemplo: mayordelista(Lista) --> mayor de la lista
*/
void mayordelista(Tlista lista){
	int a=0;
	int n=0;

	while(lista!=NULL){

		if(n<lista->nro){
			a=lista->nro;
			n=lista->nro;
			lista=lista->sgte;

		}
		else{
			a=n;
			lista=lista->sgte;
		}
	}
	printf("El numero mayor de la lista es:\n%i",a);
}
//_____________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: ascendente
	Objetivo: Hacer una función que reciba una lista
  e indique si está ordenada ascendentemente.
	Parametro: Lista
	Retorno: true o false
	Ejemplo: ascendente(Lista) --> true si esta ordenada, false si no
*/
void ascendente(Tlista lista){
	int a=0;
	int n=0;

	while(lista!=NULL && a!=1){

		if(n<lista->nro){
			n=lista->nro;
			lista=lista->sgte;

		}
		else{
			a=1;
		}
	}
	if(a==1){
		printf("\nLa lista no esta ordenada ascendentemente",a);
	}
	else{
		printf("\nLa lista esta ordenada ascendentemente",a);
	}

}

void menu1(){

	printf("\n\t\tTALLER DE LISTAS\n\n");
	printf("\n1. Insertar al inicio");
	printf("\n2. Insertar al final");
	printf("\n3. Insertar en una posicion");
	printf("\n4. Mostrar lista");
	printf("\n5. Buscar elemento");
	printf("\n6. Eliminar elemento 'V'");
	printf("\n7. Eliminar elementos con valor 'V'");
	printf("\n8. Contar elemnetos 'V' repetidos");
	printf("\n9. Invertir lista");
	printf("\n10. Promedio de la lista");
	printf("\n11. Numero mayor de la lista");
	printf("\n12. Lista ordenada ascendentemente?");
	printf("\n\n0. Salir\n");
	printf("\nINGRESE OPCION: ");
}

int main(){
	Tlista lista=NULL;
	int op;		//opcion del menu
	int dato;	//elemento a ingresar
	int pos;	//posicion a insertar

	system("color 0b");

	insertaInicio(lista,1);
	insertaInicio(lista,2);
	insertaInicio(lista,3);
	insertaInicio(lista,4);
	insertaInicio(lista,3);
	insertaInicio(lista,2);
	insertaInicio(lista,2);
	insertaInicio(lista,2);
	insertaInicio(lista,1);


	do{
		menu1();
		cin>>op;

		switch(op){

			case 1:
				cout<< "\n Numero a insertar: ";
				cin>>dato;
				insertaInicio(lista,dato);
				break;

			case 2:
				cout<< "\n Numero a insertar: ";
				cin>>dato;
				insertaFinal(lista,dato);
				break;

			case 3:
				cout<< "\n Numero a insertar: ";
				cin>>dato;
				cout<<"Posicion: ";
				cin>>pos;
				insertarelemento(lista,dato,pos);
				break;

			case 4:
				cout<<"\n\nMostrando lista\n\n";
				mostrarlista(lista);
				break;

			case 5:
				cout<<"\nValor a buscar: ";
				cin>>dato;
				buscarelemento(lista,dato);
				break;

			case 6:
				cout<<"\nValor a eliminar: ";
				cin>>dato;
				eliminarelemento(lista,dato);
				break;

			case 7:
				cout<<"\nValor repetido a eliminar";
				cin>>dato;
				eliminarrepetidos(lista,dato);
				break;

			case 8:
				printf("\nIngrese valor a contar la cantidad de veces que se encuentra en la lista\n");
				cin>>dato;
				contarrepetidos(lista,dato);
				break;

			case 9:
				invertirlista(lista);
				break;

			case 10:
				promedio(lista);
				break;

			case 11:
				mayordelista(lista);
				break;

			case 12:
				ascendente(lista);
				break;
		}
		cout<<endl<<endl;
		system("pause");
		system("cls");
	}while(op!=0);
	return 0;
}
