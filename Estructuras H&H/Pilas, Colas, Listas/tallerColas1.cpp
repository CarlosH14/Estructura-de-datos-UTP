/*
COLAS
1. Invertir los elementos de una cola.

2. Informar si el elemento X se encuentra presente en la cola C.

3. Hacer una función boolean que indique si una cola se encuentra 
ordenada ascendentemente.

4. Indicar si las colas C1 y C2 son iguales (tienen los mismos 
elementos y en el mismo orden).

5. Agrega el elemento X en la posición pos de la cola C, desplazando 
todos los elementos una posición. Solo puede usar los métodos de la 
clase Cola. Ayuda: Utilice otra cola.

6. Recibe una cola C, un elemento X y dos colas vacías C1 y C2, y 
deja en la cola C1 los elementos de C mayores que X y en C2 los otros.

COLAS CON PRIORIDAD
1. Dada una cola con nombres de personas y prioridad, retorne el nombre 
de la persona con mayor prioridad.

2. Dada una cola de nombres de personas cada uno con prioridad, atender 
en orden de prioridad (listando en pantalla los nombres de las personas) 
que están en una cola. Solo puede usar los métodos para manejo de colas. 
AYUDA: utilice otra cola para ir guardando los objetos temporalmente.

3. Hacer el mismo ejercicio anterior, pero aumentando la prioridad (en +1) 
a los objetos que estan antes de aquel que tiene la mayor prioridad. Esto 
con el fin de que todos los objetos sean en algún momento atendidos en el 
caso de tener una aplicación que permita adicionar nuevos. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

struct nodo{
	int nro;
	struct nodo *sgte;
};

struct cola{
	struct nodo *anterior;
	struct  nodo *siguiente;
};

void encolar(struct cola &q,int valor){
	struct nodo *aux;
	aux=new(struct nodo);
	aux->nro=valor;
	aux->sgte=NULL;

	if(q.siguiente==NULL){
		q.siguiente=aux;
	}
	else{
		(q.anterior)->sgte=aux;
	}

	q.anterior=aux;
}

int desencolar(struct cola &q){
	int num;
	struct nodo *aux;
	if(q.siguiente==NULL){
        printf("\n\nCola vacia\n\n");
	}
	else{
        aux=q.siguiente;
        num=aux->nro;
        q.siguiente=(q.siguiente)->sgte;
        printf("\n\nEl numero %i ha sido eliminado de la cola\n\n",(q.siguiente)->nro);
        delete(aux);
	}

	return num;
}

void mostrarcola(struct cola q){
	struct nodo *aux;
	aux=q.siguiente;

	while(aux!=NULL){
		printf("%i\n",aux->nro);
		aux=aux->sgte;
	}
}

void vaciarcola(struct cola &q){
    struct nodo *aux;
    while(q.siguiente != NULL){
        aux=q.siguiente;
        q.siguiente=aux->sgte;
        delete(aux);
    }
    q.siguiente=NULL;
    q.anterior=NULL;
}



void xencola(struct cola p,int x){

    struct nodo *aux;
    aux=p.siguiente;
    int flag=0;
    while(aux!=NULL && flag!=1){
        if(x==aux->nro){
            flag=1;
        }
        else{
            aux=aux->sgte;
        }
    }
    if(flag==1){
        printf("\nel elemento %i se encuentra en la cola\n",x);
    }
    else{
        printf("\nel elemento %i no se encuentra en la cola\n",x);
    }
}

void reves(struct cola p){
	int ayu, o;
	o=0;
	struct cola aux;
	aux=p;
	struct nodo *naux;
	naux=aux.siguiente;
	int V[100];
	while(naux != NULL){
		ayu=desencolar(aux);
		V[o]=ayu;
		o++;
		naux=naux->sgte;
	}
	vaciarcola(aux);
	for(int j=o; j>=0; j--){
		encolar(aux, V[j]);
	}
	
	p=aux;
}

void divide(struct cola C, int X, struct cola C1, struct cola C2){
	int naux=0;
	struct nodo *aux;
	aux=C.siguiente;
	while(aux->sgte != NULL){
		naux=desencolar(C);
		if(naux<=X){
			encolar(C1,naux);
		}else{
			encolar(C2,naux);
		}
		aux=aux->sgte;
	}
	cout<<"Cola1\n";
	mostrarcola(C1);
	cout<<"\nCola2\n";
	mostrarcola(C2);
}

void menu(){
    printf("Implementacion de colas en c++\n\n1.Encolar\n2.Desencolar\n3.Mostrar Cola\n4.Vaciar Cola\n5. Reves\n6.Elemento X en la Cola\n\n0.Salir\n\nIngrese Opcion:");
}

int main(){
    struct cola q;
    q.siguiente=NULL;
    q.anterior=NULL;
    
    struct cola C1;
    C1.siguiente=NULL;
    C1.anterior=NULL;
    
    struct cola C2;
    C2.siguiente=NULL;
    C2.anterior=NULL;
    
    int dato,op,x,y;
    system("color 0b");

    do{
        menu();
        scanf("%i",&op);
        switch(op){

            case 1:
            	printf("\n\nPor favor ingrese el numero a encolar\n\n");
            	scanf("%i",&dato);
            	encolar(q,dato);
            	printf("\n\nEl numero %i ha sido puesto en la cola\n\n",dato);
            	break;
            	

            case 2:
            	x=desencolar(q);
            	break;

            case 3:
            	printf("\n\nMostrando cola\n\n");
                mostrarcola(q);
            	break;

            case 4:
            	vaciarcola(q);
            	printf("Cola eliminada");
            	break;
            
            case 5:
            	reves(q);
            	mostrarcola(q);
            	break;

            case 6:
                printf("Por favor ingrese el elemento a buscar:\n\n-");
                scanf("%i",&y);
                xencola(q,y);
            case 7:
            	divide(q, 5, C1, C2);
            	break;
        }
        system("pause");
        system("cls");
    }while(op!=0);

    return 0;
}
