#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

struct nodo{
	int nro;
	struct nodo *sgte;
};
typedef nodo *ptrPila;
void push(ptrPila &p, int valor){

    ptrPila aux;
    aux=new(struct nodo);
    aux->nro=valor;
    aux->sgte=p;
    p=aux;

}
int pop(ptrPila &p){

    int num;
    ptrPila aux;
    aux=p;
    if(aux==NULL){
        printf("\n\nPila vacia\n\n");
    }
    else{
        num=aux->nro;
        p=aux->sgte;
        printf("\n\nel numero %i ha sido desapilado\n\n",aux->nro);
        delete(aux);
    }


    return(num);
}
int pop2(ptrPila &p){

    int num;
    ptrPila aux;
    aux=p;
    if(aux==NULL){
        printf("Error");
    }
    else{
        num=aux->nro;
        p=aux->sgte;
        delete(aux);
    }


    return num;
}
void mostrar_pila(ptrPila p){

    ptrPila aux;
    aux=p;
    while(aux!=NULL){
        printf("%i\t",aux->nro);
        aux=aux->sgte;
    }
}
int mostrar_pila2(ptrPila p){

    ptrPila aux;
    aux=p;
    int n=0;
    while(aux!=NULL){
        n=n+1;
        printf("%i\t",aux->nro);
        aux=aux->sgte;
    }
    return n;
}
int cuantospila(ptrPila p){

    ptrPila aux;
    aux=p;
    int n=0;
    while(aux!=NULL){
        n=n+1;
        aux=aux->sgte;
    }
    return n;
}
void destruir_pila(ptrPila &p){
    ptrPila aux;

    while(p!=NULL){
        aux=p;
        p=aux->sgte;
        delete(aux);
    }
}
void invertirpila(ptrPila p){
    ptrPila l=NULL;
    int n,r,i=0;
    r=cuantospila(p);
    while(r!=i){
        n=pop2(p);
        push(l,n);
        i++;
    }
    p=l;
    destruir_pila(l);
    }

//____________________________________________________________________
/*
1. Invertir los elementos de una cola.
2. Informar si el elemento X se encuentra presente en la cola C.
3. Hacer una función boolean que indique si una cola se encuentra ordenada
ascendentemente.
4. Indicar si las colas C1 y C2 son iguales (tienen los mismos elementos y en el
mismo orden).
5. Agrega el elemento X en la posición pos de la cola C, desplazando todos los
elementos una posición. Solo puede usar los métodos de la clase Cola. Ayuda:
Utilice otra cola.
6. Recibe una cola C, un elemento X y dos colas vacías C1 y C2, y deja en la cola
C1 los elementos de C mayores que X y en C2 los otros.
*/
//_____________________________________________________________________

/////////////////////////////////////////////////////////////////////////////////

/*
	Nombre Estructura: nodo
	Atributos: dato, nodo siguiente 
	Descripcion: nodo de una cola, con
	el dato que almacena y con el apuntador
	al nodo siguiente

struct nodo{
	int nro;
	struct nodo *sgte;
};*/
/*
	Nombre Estructura: cola
	Atributos: nodo anterior, siguiente 
	Descripcion: cola, con el apuntador
	hacia atras y adelante
*/
struct cola{
	struct nodo *anterior;
	struct  nodo *siguiente;
};
//--------------------------------------------------
/*
	Nombre Función: encolar
	Objetivo: agregar un nuevo nodo a una cola
	Parametro: cola q, entero valor
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: encolar(q,5) --> agrega 5 a la cola q 
*/
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
//--------------------------------------------------
/*
	Nombre Función: desencolar
	Objetivo: eliminar un nodo de una cola
	Parametro: cola q
	Retorno: elemento desencolado
	Ejemplo: desencolar(q) --> elimina el ultimo elemento de la cola q 
*/
int desencolar(struct cola &q){
	int num;
	struct nodo *aux;
	if(q.siguiente==NULL){
        printf("\n\nCola vacia\n\n");
	}
	else{
        printf("\n\nEl numero %i ha sido eliminado de la cola\n\n",(q.siguiente)->nro);
        aux=q.siguiente;
        num=aux->nro;
        q.siguiente=(q.siguiente)->sgte;
        delete(aux);
	}

	return num;
}
//--------------------------------------------------
/*
	Nombre Función: desencolar2
	Objetivo: eliminar un nodo de una cola
	Parametro: cola q
	Retorno: elemento desencolado
	Ejemplo: desencolar2(q) --> elimina el ultimo elemento de la cola q 
*/
int desencolar2(struct cola &q){
    int num;
    struct nodo *aux;
    if(q.siguiente==NULL){
        printf("\n\nCola vacia\n\n");
    }
    else{
        aux=q.siguiente;
        num=aux->nro;
        q.siguiente=(q.siguiente)->sgte;
        delete(aux);
    }

    return num;
}
//--------------------------------------------------
/*
	Nombre Función: desencolar3
	Objetivo: eliminar un nodo de una cola
	Parametro: cola q
	Retorno: elemento desencolado
	Ejemplo: desencolar3(q) --> elimina el ultimo elemento de la cola q 
*/
int desencolar3(struct cola &q){
    int num;
    struct nodo *aux;
    if(q.siguiente!=NULL){
        aux=q.siguiente;
        num=aux->nro;
        q.siguiente=(q.siguiente)->sgte;
        delete(aux);
    }

    return num;
}
//--------------------------------------------------
/*
	Nombre Función: mostrarcola
	Objetivo: muestra la cola en pantalla
	Parametro: cola q
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: mostrarcola(q) --> muestra la cola q
*/
void mostrarcola(struct cola q){
	struct nodo *aux;
	aux=q.siguiente;

	while(aux!=NULL){
		printf("%i\n",aux->nro);
		aux=aux->sgte;
	}
}
//--------------------------------------------------
/*
	Nombre Función: vaciarcola
	Objetivo: eliminar una cola
	Parametro: cola q
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: vaciarcola(q) --> elimina la cola q 
*/
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
//______________________________________________________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: invetircola
	Objetivo: invierte una cola
	Parametro: cola q
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: invetircola(q) --> invierte la cola q 
*/
void invetircola(struct cola &q){
    struct nodo *aux;
    ptrPila p=NULL;
    aux=q.siguiente;

    int n,l,flag=0,i=0;
    printf("\n\nCola sin invertir\n\n");
    mostrarcola(q);

    while(aux!=NULL){
        n=aux->nro;
        push(p,n);
        aux=aux->sgte;
        i++;
    }

    l=cuantospila(p);
    i=0;
    vaciarcola(q);

    while(l!=i){
        n=pop2(p);
        encolar(q,n);
        i++;
    }

    printf("\n\nCola invertida\n\n");
    mostrarcola(q);
}
//______________________________________________________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: xencola
	Objetivo: busca el elemento x en una cola
	Parametro: cola q, valor x
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: xencola(q, 5) --> busca el elemento 5 en la cola q
*/

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
//______________________________________________________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: ascendente
	Objetivo: Hacer una función que reciba una cola
  e indique si está ordenada ascendentemente.
	Parametro: cola
	Retorno: 1 true o 0 false
	Ejemplo: ascendente(q) --> 1 true si esta ordenada, 0 false si no
*/
int ascendente(struct cola q){
    struct nodo *aux;
    aux=q.siguiente;
    int n=0;
    int i=0;
    while(aux!=NULL && i==0){
        if(n<=aux->nro){
            n=aux->nro;
            aux=aux->sgte;
        }
        else{
            i=1;
        }
    }
    return i;
}
//______________________________________________________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: mismas
	Objetivo: verifica si las colas son iguales
	Parametro: cola q1, cola q2
	Retorno: 1 true o 0 false
	Ejemplo: mismas(q1, q2) --> muestra si las colas son iguales o no
*/
int mismas(struct cola q,struct cola k){
    struct nodo *auxq;
    struct nodo *auxk;
    auxq=q.siguiente;
    auxk=k.siguiente;
    int qq=0;
    int kk=0;
    int i;
    qq=auxq->nro;
    kk=auxk->nro;

    while(auxq!=NULL && auxk!=NULL && i==0){
        i=0;
        if(qq==kk){
            qq=auxq->nro;
            kk=auxk->nro;
            auxq=auxq->sgte;
            auxk=auxk->sgte;
        }
        else{
            i=1;
        }
    }
    if(i==0){
        mostrarcola(q);
        mostrarcola(k);
        printf("Las dos colas tienen los mismos valores");
    }
    else{
        mostrarcola(q);
        mostrarcola(k);
        printf("Las dos colas no son iguales");
    }
    return i;
}
//______________________________________________________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: posxcola
	Objetivo: inserta un valor x en una posicion pos en una cola q
	Parametro: cola q
	Retorno: cola con elemento en la posicion indicada
	Ejemplo: posxcola(q) --> cola qu con x en pos
*/
int posxcola(struct cola &q){
    struct nodo *aux;
    aux=q.siguiente;
    ptrPila p=NULL;
    ptrPila m=NULL;
    int V[100];
    int i=0,flag=0,l;
    int pos,x;
    int n,index=1;
    printf("Por favor ingrese el Elemento y la posicion donde desea que quede ubicado\n\nElemento: ");
    scanf("%i",&x);
    printf("\nPosicion: ");
    scanf("%i",&pos);
    printf("\nCola sin el elemento\n");
    mostrarcola(q);

    while(aux!=NULL){
        n=aux->nro;
        push(p,n);
        index++;
        if(pos==index){
            push(p,x);
        }

        aux=aux->sgte;
        i++;
        V[1]=i;

    }
   // l=mostrar_pila2(p);
    l=cuantospila(p);
    i=0;
    vaciarcola(q);
    while(l!=i){
        n=pop2(p);
        push(m,n);
        i++;
    }
    i=0;
    while(l!=i){
        n=pop2(m);
        encolar(q,n);
        i++;
    }
    printf("\ncola con el elemento\n");
    mostrarcola(q);

}

//______________________________________________________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: divide
	Objetivo: divide una cola en mayores y menores
	Parametro: cola q, valor x, cola c1 y c2 de mayores y menores
	Retorno: colas con mayores y menores que x
	Ejemplo: divide(q, 5, c1,c2) --> cola q con x en pos
*/
void divide(struct cola C, int X, struct cola C1, struct cola C2){
    int naux=0;
    struct nodo *aux;
    aux=C.siguiente;
    while(aux != NULL){
        naux=aux->nro;
        if(naux<=X){
            encolar(C1,naux);
        }else{
            encolar(C2,naux);
        }
        aux=aux->sgte;
    }
    cout<<"Cola1\n\n";
    mostrarcola(C1);
    cout<<"\nCola2\n\n";
    mostrarcola(C2);
}
//______________________________________________________________________________________________________________________

void menu(){
    printf("Implementacion de colas en c++\n\n1.Encolar\n2.Desencolar\n3.Mostrar Cola\n4.Vaciar Cola\n5.Invertir cola\n6.Elemento X en la Cola\n7.Cola ascendente?\n8.Colas iguales\n9.Ingresar un valor X en cierta posicion de la cola\n      (estando el primero en entrar en la primer posicion).\n10.Dividir una cola en dos\n\n0.Salir\n\nIngrese Opcion:");
}

int main(){
    struct cola q;
    struct cola k;
    k.siguiente=NULL;
    k.anterior=NULL;
    //////////////////////
    struct cola m;
    m.siguiente=NULL;
    m.anterior=NULL;

    struct cola n;
    n.siguiente=NULL;
    n.anterior=NULL;
    /////////////////////////////////
    q.siguiente=NULL;
    q.anterior=NULL;
    int dato,op,x,y,pos;
    system("color 0b");
    encolar(q,1);
    encolar(q,2);
    encolar(q,3);
    encolar(q,5);

    encolar(k,1);
    encolar(k,2);
    encolar(k,3);
    encolar(k,55);
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
                invetircola(q);
                break;

            case 6:
                printf("Por favor ingrese el elemento a buscar:\n\n-");
                scanf("%i",&y);
                xencola(q,y);
                break;

            case 7:
                if(ascendente(q)==1){
                    printf("false\n");
                }
                else{
                    printf("true\n");
                }
                break;

            case 8:
                mismas(q,k);
                break;

            case 9:
                posxcola(q);
                break;

            case 10:
                printf("\npor favor ingrese el numero a evaluar para dividir las colas\n");
                scanf("%i",&y);
                divide(q,y,m,n);
        }
        system("pause");
        system("cls");
    }while(op!=0);

    return 0;
}
