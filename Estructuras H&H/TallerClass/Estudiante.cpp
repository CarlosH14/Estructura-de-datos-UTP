#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct estudiante
{	int cod;
	char nom[10];
	float n1, n2 ,n3;	
};

estudiante e[5];

//--------------------------------------------------

void Add_Est(int n )
{
    float prom,nd;
    prom=0;
	for (int i=0; i<n;i++ )
	{
		cout<<"Datos del estudiante #"<<i+1<<endl;
		cout<<"Codigo : ";
		cin>>e[i].cod;
		cout<<"Nombre : ";
		cin>>e[i].nom;
		cout<<"Nota 1 : ";
		cin>>e[i].n1;
		cout<<"Nota 2 : ";
		cin>>e[i].n2;
		cout<<"Nota 3 : ";
		cin>>e[i].n3;
		nd=(e[i].n1+e[i].n2+e[i].n3)/3;
		cout<<"Promedio :"<<nd<<endl;
		prom=nd+prom;		
	}
	prom=prom/n;
	cout<<"Promedio de grupo :"<<prom;
}


/*Elaborar los siguientes metodos al TAD Estudiante:
    - Modificar los datos de un estudiante
    - Consultar los datos de un estudiante
  Realizar un menu que permita llamar los tres metodos
    1 .add (n)
	   2. consultar (cod)   
	   3. modificar (cod)
	   4. Salir   
	   if (strcmp(e[i],cod)==0)
*/    

//-----------------------------------------------

void Consultar_Est(int n, int codigo)

{		
		for(int i=0; i<=n; i++){
			
			if(e[i].cod == codigo){
				
				cout<<endl;
				cout<<"*** Datos del estudiante ***"<<endl;
				cout<<"Codigo : ";
				cout<<e[i].cod;
				cout<<endl;
				cout<<"Nombre : ";
				cout<<e[i].nom;
				cout<<endl;
				cout<<"Nota 1 : ";
				cout<<e[i].n1;
				cout<<endl;
				cout<<"Nota 2 : ";
				cout<<e[i].n2;
				cout<<endl;
				cout<<"Nota 3 : ";
				cout<<e[i].n3;
				cout<<endl;
				float prom=(e[i].n1+e[i].n2+e[i].n3)/3;
				cout<<endl;
				cout<<"Promedio :"<<prom<<endl;
			}
			
		}
		
	}
	
	void Modificar_Est(int n, int codigo)

{		
		for(int i=0; i<=n; i++){
			
			if(e[i].cod == codigo){
				
				cout<<endl;
				cout<<"*** Ingrese los datos nuevos ***"<<endl;
				cout<<"Codigo : ";
				cin>>e[i].cod;
				cout<<endl;
				cout<<"Nombre : ";
				cin>>e[i].nom;
				cout<<endl;
				cout<<"Nota 1 : ";
				cin>>e[i].n1;
				cout<<endl;
				cout<<"Nota 2 : ";
				cin>>e[i].n2;
				cout<<endl;
				cout<<"Nota 3 : ";
				cin>>e[i].n3;
				cout<<endl;
				float prom=(e[i].n1+e[i].n2+e[i].n3)/3;
				cout<<endl;
				cout<<"Promedio :"<<prom<<endl;
			}
			
		}
		
	}



main()

{
	bool fin=false;
	int addop=0;
	int conop;
	int modop;
	while(fin==false){
	
	cout<<"*-*-*-*-* Menu *-*-*-*-*"<<endl;
	cout<<"1 .add (n)\n2. consultar (cod)\n3. modificar (cod)\n4. Salir "<<endl;
	int op;
	cin>>op;
	switch(op){
		case 1:
			
			cout<<"Ingrese n:\n";
			cin>>addop;
			Add_Est(addop);
			break;
		case 2:
			
			cout<<"Ingrese codigo:\n";
			cin>>conop;
			if(addop>0){
				Consultar_Est(addop,conop);
			}
			break;
		case 3:
			
			cout<<"Ingrese codigo:\n";
			cin>>modop;
			if(addop>0){
				Modificar_Est(addop,modop);
			}
			break;
		case 4:
			cout<<"Adios\n";
			fin=true;
			break;			
	}
}
}
