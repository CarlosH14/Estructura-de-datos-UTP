#include <iostream>
#include "TADGrafos.h"
using namespace std;
Grafo migrafo;

// Funcion BFS
void BFS(Grafo g){
	int Vert[5]={1,2,3,4,5}; //Arreglo de vertices, para comprobar los vertices visitados
	Grafo Gaux; //Grafo auxiliar para no modificar el grafo original
	Gaux = g;
	ListaVertice k = Gaux.v; //Lista de vertices del grafo
	ListaArco j = Gaux.a; // Lista de arcos del grafo
	cout<<"BFS : "<<k->dato; //Se imprime el primer dato, que es el inicial
	for(int i=0; i<5; i++){ // Cambio el valor del vertice en el arreglo de vertices para marcarlo como visitado
		if(k->dato==Vert[i]){
			Vert[i]=0;
		}
	}	
	while(k!=NULL){ // Itero en la lista de Vertices
		while(j!=NULL){ // Itero en la lista de Arcos
			if(k->dato==j->origen){ // Evaluo el vertice con el primer nodo de la lista de arcos
				for(int i=0; i<5; i++){ 
					if(j->destino==Vert[i]){ //Verifico que el destino del nodo de lista de arcos no haya sido visitado
						Vert[i]=0; //Marco como visitado el vertice
						cout<<", "<<j->destino; //imprimo en pantalla el vertice visitado
						
					}
				}
				
			}
			j=j->sig; // Siguiente nodo de la lista de arcos
		}
		k=k->sig; // Siguiente nodo de la lista de vertices
		j = Gaux.a; // Reinicio la lista de arcos para evaluarlos desde cero
	}
}


//Funcion DFS
void DFS(Grafo g){
	int Vert[5]={1,2,3,4,5}; //Arreglo de vertices, para comprobar los vertices visitados
	Grafo Gaux; //Grafo auxiliar para no modificar el grafo original
	Gaux = g;
	ListaVertice k = Gaux.v; //Lista de vertices del grafo
	ListaArco j = Gaux.a; // Lista de arcos del grafo
	cout<<"DFS : "<<k->dato; //Se imprime el primer dato, que es el inicial
	for(int i=0; i<5; i++){ // Cambio el valor del vertice en el arreglo de vertices para marcarlo como visitado
		if(k->dato==Vert[i]){
			Vert[i]=0;
		}
	}	
	while(k!=NULL){ // Itero en la lista de Vertices
		while(j!=NULL){ // Itero en la lista de Arcos
			if(k->dato==j->origen){ // Evaluo el vertice con el primer nodo de la lista de arcos
				for(int i=0; i<5; i++){ 
					if(j->destino==Vert[i]){ //Verifico que el destino del nodo de lista de arcos no haya sido visitado
						Vert[i]=0; //Marco como visitado el vertice
						cout<<", "<<j->destino; //imprimo en pantalla el vertice visitado
						
					}
				}
				
			}
			j=j->sig; // Siguiente nodo de la lista de arcos
		}
		k=k->sig; // Siguiente nodo de la lista de vertices
		j = Gaux.a; // Reinicio la lista de arcos para evaluarlos desde cero
	}
}
  

//Funcion Dijkstra
void DJ (Grafo g){
	int Vert[5]={1,2,3,4,5}; // Arreglo de vertices, para comprobar los vertices visitados
	ListaVertice k = g.v;// Lista de vertices del grafo
	ListaArco j = g.a;// Lista de arcos del grafo
	int orAux, deAux;// variables auxiliares de origen y destino menores
	orAux=0; deAux=0; //inicializadas en cero
	cout<<"DJ: "<<k->dato; // Se imprime el primer dato, que es el inicial
	for(int i=0; i<5; i++){ // Cambio el valor del vertice en el arreglo de vertices para marcarlo como visitado
		if(k->dato==Vert[i]){
			Vert[i]=0;
		}
	}	
	int min=100; // Variable minimo para evaluar los costos
	while(k!=NULL){ //Itero en la lista de vertices
		while(j!=NULL){//Itero en la lista de arcos
			if(k->dato==j->origen){ //Evaluo si el vertices es igual al origen del arco
				if(j->costo <= min){ //Evaluo su costo con el minimo en primera iteracion
					for(int i=0; i<5; i++){ // Recorro el arreglo de vertices para marcar como visitado el vertice iterado
						if(k->dato==Vert[i]){
							if(j->costo <= min){ //Reevaluo el costo para asignar los valores a las variables auxiliares
								deAux=j->destino;
								orAux=j->origen;
							min=j->costo;
							}
							
						}
					}	
					
				}
			}
			j=j->sig; // Siguiente arco
		}
		cout<<", "<<deAux; // Imprimo en pantalla el destino de menor costo del vertice origen
		for(int i=0; i<5; i++){
		if(orAux==Vert[i]){ // Recorro el arreglo de vertices para marcarlo como visitado
			Vert[i]=0;
		}
	}	
		orAux=0; deAux=0; //Reinicio las variable auxiliares
		min=100; //Restauro el valor para comparar los minimos costos
		j=g.a; // Reinicio el nodo inicial de la lista de arcos
		k=k->sig;// Siguiente vertice
	}
}

main (){    
    migrafo=crearGrafo();    
    migrafo=insertarVertice(migrafo,1);
    migrafo=insertarVertice(migrafo,2);
    migrafo=insertarVertice(migrafo,3);
    migrafo=insertarVertice(migrafo,4);
    migrafo=insertarVertice(migrafo,5);
    
    migrafo=insertarArco(migrafo,1,2,3);
    migrafo=insertarArco(migrafo,1,5,1);
    migrafo=insertarArco(migrafo,2,4,2);
    migrafo=insertarArco(migrafo,3,1,0);
    migrafo=insertarArco(migrafo,3,2,4);   
    migrafo=insertarArco(migrafo,4,5,2);
    migrafo=insertarArco(migrafo,5,3,1);
    
    
    
    
    imprimirListaV(migrafo);
    imprimirListaA(migrafo);
    
    cout<<endl<<"-----------------------------------------"<<endl;
    
    BFS(migrafo);
    cout<<endl;
    DFS(migrafo);
    cout<<endl;
    DJ(migrafo);
    cout<<endl;
    
    system("pause");
}
