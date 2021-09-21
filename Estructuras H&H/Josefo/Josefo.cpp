#include<stdio.h>
#include<stdlib.h>

/*
	Nombre Estructura: nodo
	Atributos: dato, nodo siguiente 
	Descripcion: nodo de una lista circular, con
	el dato que almacena y con el apuntador
	al nodo siguiente
*/
struct nodo{
	char valor;
	struct nodo *sgte;
};
typedef struct nodo nodo;

// Definición de funciones
nodo *crearNodo();
int insertar(nodo ** ,char );
void crearlista(nodo * );
char josefo(nodo * ,char ,int ,int );


int main()
{
	nodo *primero = NULL;
	int i,n,cont;
	char c,res,inicia;
	system("cls");
	fflush(stdin);
	printf("ALGORTIMO DE JOSEFO\nIngrese el numero de soldados\n");
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		printf("Ingrese una letra por soldado, todas deben ser distintas (soldado #%i):\n",i+1);
		scanf("\n%c",&c);
		insertar(&primero,c);   //cabeza por referencia para cambiar su valor en la funcion principl desde la funcion
	}
	system("cls");
	printf("\nPor favor ingrese el nombre del soldado que inicia\n");
	scanf("\n%c",&inicia);
	printf("\n\nPor favor ingrese el numero equivalente al intervalo\n");
	scanf("\n%d",&cont);
	res = josefo(primero,inicia,cont,n);
	printf("La persona que queda viva es: %c\n",res);
	return 0;
}

//--------------------------------------------------
/*
	Nombre Función: crearNodo
	Objetivo: agregar un nuevo nodo
	Parametro: sin parametros
	Retorno: un nodo n
	Ejemplo: crearNodo() --> nodo n 
*/
nodo *crearNodo()
{
	nodo *n;
	n = (nodo *) malloc(sizeof(nodo));
	return n;
}

//--------------------------------------------------
/*
	Nombre Función: insertar
	Objetivo: agregar un nuevo nodo a una lista circular
	Parametro: nodo p, char c
	Retorno: retorna 1 siempre que inserta
	Ejemplo: insertar(nodo p,"K") --> agrega "K" a la lista circular 
*/
int insertar(nodo ** primero,char c)
{
	nodo *temp,*p;
	p = *primero;
	temp = crearNodo();
	temp->valor = c;
	temp->sgte = NULL;
	if(*primero == NULL)
	{
		*primero = temp;
		return 1;
	}
	while(p->sgte !=NULL)
	{
		p = p->sgte;
	}
	p->sgte = temp;
	return 1;
}

//--------------------------------------------------
/*
	Nombre Función: crearlista
	Objetivo: crea una lista circular
	Parametro: nodo primero
	Retorno: es  un procedimiento, no retorna nada
	Ejemplo: crearlista(nodo p) --> crea una lista circular apuntando el nodo final al primer nodo
*/
void crearlista(nodo *primero)
{
	nodo *p=primero;
	while(p->sgte != NULL)
		p=p->sgte;
	p->sgte = primero;
}

//--------------------------------------------------
/*
	Nombre Función: josefo
	Objetivo: determina el superviviente del algortimo
	Parametro: nodo primero,char inicia,int c,int n
	Retorno: el valor char del nodo de la persona que sobrevivió
	Ejemplo: josefo(nodo p, char "K", 9, 2) --> 
	De una lista circular cuyo primer nodo es p, inicia buscando el
	nodo que tenga el valor "K", cuando lo encuentra inicia el intervalo
	y hace apuntar el nodo actual dos posiciones mas adelante, dejando el
	nodo siguiente sin apuntar a nada y nada apuntando hacia él.
	Al final, cuando no hay mas nodos para eliminar, retorna el valor char del
	nodo que queda
*/
char josefo(nodo *primero,char inicia,int c,int n)
{
	crearlista(primero);
	nodo *p = primero;
	nodo *q = primero;
	int cont =c;
	while(1)
	{
		if(p->valor == inicia)
			break;
		p=p->sgte;
	}
	while(1)
	{
		//ya que estoy parado en un nodo, debo decrementar
		cont = c-1;
		while(1)
		{
			cont--;
			if(cont==0)
				break;
			p = p->sgte;      //aqui se detiene antes de lo que se va a eliminar
		}
		p->sgte = p->sgte->sgte;
		p = p->sgte;
		n--;
		if(n==1)
			break;
	}
	return p->valor;
}
