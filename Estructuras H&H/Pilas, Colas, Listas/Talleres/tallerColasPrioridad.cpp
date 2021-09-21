#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


//____________________________________________________________________
/*

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
//_____________________________________________________________________

/*
	Nombre Estructura: nodo
	Atributos: dato, nodo siguiente, prioridad 
	Descripcion: nodo de una cola, con
	el dato que almacena su prioridad y 
	con el apuntador al nodo siguiente
*/
struct nodo
{
    string dato;
    int priori;        // prioridad del nodo
    struct nodo *sgte;
};

//____________________________________________________________________________

/*
	Nombre Estructura: cola
	Atributos: nodo anterior, siguiente 
	Descripcion: cola, con el apuntador
	hacia atras y adelante
*/

struct cola
{
    nodo *delante;
    nodo *atras  ;
};

//____________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: crearNodo
	Objetivo: crear un nuevo nodo
	Parametro: string x, entero valor
	Retorno: el nodo creado
	Ejemplo: crearNodo('francisco',5) --> crea el nodo francisco con prioridad 5 
*/
struct nodo *crearNodo( string x, int pr)
{
    struct nodo *nuevoNodo = new(struct nodo);
    nuevoNodo->dato = x;
    nuevoNodo->priori = pr;
    return nuevoNodo;
};

//____________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: encolar
	Objetivo: agregar un nuevo nodo a una cola
	Parametro: pila p, entero valor, entero prioridad
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: encolar(q,5,2) --> agrega 5 con prioridad 2 a la cola q 
*/
void encolar( struct cola &q, string valor, int priori )
{

    struct nodo *aux = crearNodo(valor, priori);
    aux->sgte = NULL;

    if( q.delante == NULL)
        q.delante = aux;   // encola el primero elemento
    else
        (q.atras)->sgte = aux;

    q.atras = aux;        // puntero que siempre apunta al ultimo elemento
}

//____________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: desencolar
	Objetivo: eliminar un nodo de una cola
	Parametro: cola q
	Retorno: elemento desencolado
	Ejemplo: desencolar(q) --> elimina el ultimo elemento de la cola q 
*/
void desencolar(struct cola &q){
    struct nodo *aux;
    if(q.delante==NULL){
        printf("\n\nCola vacia\n\n");
    }
    else{
        aux=q.delante;
        q.delante=(q.delante)->sgte;
        delete(aux);
    }

}

//____________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: mostrarcola
	Objetivo: muestra la cola en pantalla
	Parametro: cola q
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: mostrarcola(q) --> muestra la cola q
*/
void muestraCola( struct cola q )
{
     struct nodo *aux;
     int i=1;
     aux = q.delante;

     while( aux != NULL )
     {
            printf("%i). ",i);
            cout<<aux->dato;
            printf("\t\t prioridad: %i\n",aux->priori);
            aux = aux->sgte;
            i++;
     }
     cout<<endl;
}

//____________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: aumentaPrioridad
	Objetivo: aumentar en 1 la prioridad de cada nodo de una cola
	Parametro: cola q
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: aumentaPrioridad(q) --> la cola q tiene nuevas prioridades
*/
void aumentaPrioridad( struct cola &q )
{
    struct nodo *aux;
    int i=1;
    aux = q.delante;

    while( aux != NULL ){
        if(aux->priori==0){
            aux->priori=0;
        }
        else{
            aux->priori=(aux->priori)+1;
            }
        aux = aux->sgte;
    }
}

//____________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: atiendeCola2
	Objetivo: define quien es el proximo a atender en una cola
	Parametro: cola q
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: atiendeCola2(q) --> define el proximo nodo que se tiene que atender
*/
void atiendeCola2( struct cola &q )
{
     struct nodo *aux;
     int i=1,flag=0,n;
     aux = q.delante;

     while( aux != NULL && flag!=1)
     {
            printf("%i).La persona ",i);
            cout<<aux->dato;
            printf(" fue atendida\n\n",aux->priori);

            flag=1;
            
            system("pause");
            system("cls");
            aux->priori=0;
            aux = aux->sgte;
            i++;
     }
     cout<<endl;
}

//____________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: atiendeCola
	Objetivo: define quien es el proximo a atender en una cola
	Parametro: cola q
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: atiendeCola(q) --> define el proximo nodo que se tiene que atender
*/
void atiendeCola( struct cola &q )
{
     struct nodo *aux;
     int i=1,flag=0,n;
     aux = q.delante;

     while( aux != NULL && flag!=1)
     {
            printf("%i).La persona ",i);
            cout<<aux->dato;
            printf(" fue atendida\n\n",aux->priori);
            printf("\n\n\nPRESIONE 1 PARA ATENDER OTRA PERSONA, 0 EN OTRO CASO\n\n");
            cin>>n;
            if(n!=1){
                flag=1;
            }
            system("pause");
            system("cls");
            aux->priori=0;
            aux = aux->sgte;
            i++;
     }
     cout<<endl;
}

//____________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: ordenarPrioridad
	Objetivo: ordena una cola segun la prioridad
	Parametro: cola q
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: ordenarPrioridad(q) --> cola q ordenada por prioridad
*/
void ordenarPrioridad( struct cola &q ){
    struct nodo *aux1, *aux2;
    int p_aux;
    string c_aux;
    aux1 = q.delante;
    while( aux1->sgte != NULL){
        aux2 = aux1->sgte;

        while( aux2 != NULL){
            if( aux1->priori < aux2->priori ){
                p_aux = aux1->priori;
                c_aux = aux1->dato;

                aux1->priori = aux2->priori;
                aux1->dato   = aux2->dato;

                aux2->priori = p_aux;
                aux2->dato   = c_aux;
            }

            aux2 = aux2->sgte;
        }

        aux1 = aux1->sgte;
     }
}




//____________________________________________________________________________
//--------------------------------------------------
/*
	Nombre Función: insertar
	Objetivo: agrega un nuevo nodo a la cola
	Parametro: cola q, string y prioridad
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: insertar(q, 'alejandro', 5) --> agrega a la cola q a alejandro con prioridad 5
*/
void insertar( struct cola &q, string c, int pr){
    encolar( q, c, pr );
    ordenarPrioridad( q );
}

//____________________________________________________________________________
void menu(){
    cout<<"\n\t COLAS CON PRIORIDAD EN C++ \n\n";
    cout<<" 1. ENCOLAR                           "<<endl;
    cout<<" 2. MOSTRAR                           "<<endl;
    cout<<" 3. PERSONA CON MAYOR PRIORIDAD       "<<endl;
    cout<<" 4. DESENCOLAR                        "<<endl;
    cout<<" 5. ATENDER POR PRIORIDAD             "<<endl;
    cout<<" 6. ATENDER POR PRIORIDAD AUMENTANDO EN UNO LA MISMA DE LOS DEMAS\n"<<endl;
    cout<<" 0. SALIR   \n                          "<<endl;
    cout<<"\n INGRESE OPCION: ";
}


int main(){
    struct cola q;
    q.delante = NULL;
    q.atras   = NULL;
    string c ;     // caracter a encolar
    int pr;      // prioridad del caracter
    int op;      // opcion del menu
    int x ;      // numero que devuelve la funcon pop

    insertar(q,"Francisco Alejandro",1);
    insertar(q,"Laura Lopez",2);
    insertar(q,"Jose Franco",3);
    insertar(q,"Brayan Correa",4);

    do{
        menu();
        cin>> op;
        switch(op){

            case 1:
                cout<< "\n Ingrese nombre: ";
                cin>> c;
                fflush(stdin);
                cout<< "\n Ingrese prioridad:\nNOTA:\n\tPrioridad 0: atendido.\n\tPrioridad 1: persona sin discapacidad\n\tPrioridad 2: mujeres con ninos y ancianos.\n\tPrioridad 3: persona con discapacidades moviles.\n\tPrioridad 4: personas con orden de atencion\n\n";
                cin>> pr;
                insertar( q, c, pr );
                cout<<"\n\n\tPersona '" << c << "' puesta en la cola...\n\n";
                break;

            case 2:
                cout << "\n\n MOSTRANDO COLA DE PRIORIDAD\n\nNOTA:  \n\tPrioridad 0: atendido.\n\tPrioridad 1: persona sin discapacidad\n\tPrioridad 2: mujeres con ninos y ancianos.\n\tPrioridad 3: persona con discapacidades moviles.\n\tPrioridad 4: personas con orden de atencion\n\n";
                if(q.delante!=NULL)
                    muestraCola( q );
                else
                    cout<<"\n\n\tCola vacia...!"<<endl;
                break;

            case 3:
                printf("\nLa persona ");
                cout<<(q.delante)->dato;
                printf(" es quien tiene mayor prioridad\n\n");
                break;

            case 4:
                desencolar(q);
                muestraCola(q);
                break;

            case 5:
                atiendeCola(q);
                ordenarPrioridad(q);
                break;

            case 6:
                aumentaPrioridad(q);
                atiendeCola2(q);
                ordenarPrioridad(q);
                break;

            default:
                if(op=0){
                    cout<<"\n\tOpcion incorecta..!"<<endl;
                }
                break;

         }

        system("pause");
        system("cls");

    }while(op!=0);

    return 0;
}
