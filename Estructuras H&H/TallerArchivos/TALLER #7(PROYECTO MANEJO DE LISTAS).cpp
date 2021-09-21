//Taller #7(Proyecto Manejo De Listas)
//Jennifer Tatiana Cubillos
//Luigi Davian Patiño Cardona
#include <iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
using namespace std;

/*=======================================================================================================================*/
struct nodoPasajero{
    string num_vuelo;
	string cedula;
	string nombre;
	string telefono;
	int estado;
	nodoPasajero *sgte;
};
typedef nodoPasajero *Tlistapasajero;
	

struct nodoVuelo{
	string num_vuelo;
	string origen;
	string destino;
	string matricula_avion;
	string nom_piloto;
	string hora;
	string fecha;
	int estado;
	nodoPasajero *pasajeros;
	nodoVuelo *sgte;
};
typedef nodoVuelo *Tlistavuelo;

void insertarpasajero(Tlistapasajero &k, int n)
{
	int cont=0;
	string cedula;
	string nomb;
	string tel;
	string num_vuelo;
	int est;
	while(cont<n){

		Tlistapasajero z;
		z=new(struct nodoPasajero);
		z->sgte=NULL;
		getchar();

		cout<<"\n Digite numero de vuelo del pasajero #"<<cont+1<<" : ";
		getline(cin,num_vuelo);
		z->num_vuelo=num_vuelo;

		cout<<"\n Digite cedula del pasajero #"<<cont+1<<" : ";
		getline(cin,cedula);
		z->cedula=cedula;

		cout<<"Digite nombre del pasaje #"<<cont+1<<" : ";
        getline(cin, nomb);
		z->nombre=nomb;

		cout<<"Digite telefono del pasajero #"<<cont+1<<" : ";;
        getline(cin,tel);
		z->telefono=tel;

		cout<<"Digite estado del pasajero"<<endl;
		cout<<"\t 1. Vuelo reservado \n \t 2. Vuelo abordado \n \t Opcion: ";
        cin>>est;
		z->estado=est;
		z->sgte=k;
		k=z;
		cout<<"\n Usuario registrado \n";
		system("PAUSE>>NULL");
		cout<<endl<<endl;
		cont++;
	}//cierra while
}


void insertarvuelo(Tlistavuelo &lista,int n)
{
	string numvuelo;
	string nom_origen;
	string nom_dest;
	string matri;
	string nom_piloto;
    string hora_part;
	string fecha_part;
	int m;
	int cont=1;
	while(cont<=n){
        Tlistavuelo q;
        q=new(struct nodoVuelo);
        q->sgte=NULL;
    getchar();
	cout<<"Digite el numero del vuelo 6 caracteres: ";
	getline(cin,numvuelo);
	q->num_vuelo=numvuelo;

	cout<<"Digite el origen del vuelo: ";
	getline(cin,nom_origen);
	q->origen=nom_origen;

	cout<<"Digite el destino del vuelo: ";
    getline(cin,nom_dest);
	q->destino=nom_dest;

	cout<<"Digite el numero de la matricula: ";
	getline(cin, matri);
	q->matricula_avion=matri;

	cout<<"Digite nombre del piloto: ";
	getline(cin, nom_piloto);
	q->nom_piloto=nom_piloto;

	cout<<"Ingrese hora: ";
    getline(cin, hora_part);
	q->hora=hora_part;

	cout<<"Ingrese fecha : ";
	getline (cin, fecha_part);
	q->fecha=fecha_part;

	cout<<"Vuelo"<<endl;
	cout<<"0\t programado"<<endl;
	cout<<"1\t realizado"<<endl;
	int estado;
	cout<<"Opcion: ";
	cin>>estado;
	q->estado=estado;
	getchar();
	cout<<endl<<endl;
	Tlistapasajero k;
	k=new(struct nodoPasajero);
	k->sgte=NULL;
	int comp=1;
	if(q->estado !=comp){
		cout<<"Inserte cantidad de pasajeros: ";
		cin>>m;
		insertarpasajero(k,m);
		q->pasajeros=k;
		cout<<"\n Vuelo registrado \n";
	}
	else{
		q->pasajeros=NULL;
		cout<<"\n Vuelo registrado \n";
	}
	system("PAUSE>>NULL");
	q->sgte=lista;
    lista=q;
	cont++;
	}

}



void listar_pasajeros(Tlistapasajero &lista)
{
    Tlistapasajero aux;
	aux=new(struct nodoPasajero);
	aux=lista;
	int cont=0;
	cout<<"Lista de personas"<<endl<<endl;
	while(aux->sgte!=NULL)
	{
		cout<<"# de vuelo: ";
		cout<<aux->num_vuelo<<endl;
		cout<<"Cedula: ";
		cout<<aux->cedula<<endl;
		cout<<"Nombre: ";
		cout<<aux->nombre<<endl;
		cout<<"Telefono: ";
		cout<<aux->telefono<<endl;
		cout<<"Estado";
		cout<<aux->estado<<endl;
		aux=aux->sgte;
		cont++;
	}
	 if(cont==0)
	 	cout<<"personas no viajaron";
	 	system("PAUSE>>NULL");

}


void listavuelos(Tlistavuelo &lista)
{
	Tlistavuelo aux;
	aux=new(struct nodoVuelo);
	aux=lista;
	int cont=0;
	cout<<endl;
	while(aux->sgte!=NULL)
	{
	    cout<<"Lista de vuelos "<<endl<<endl;
		cout<<"# de vuelo: ";
		cout<<aux->num_vuelo<<endl;
		cout<<"Origen de vuelo: ";
		cout<<aux->origen<<endl;
		cout<<"Destino del vuelo: ";
		cout<<aux->destino<<endl;
		cout<<"Matricula del avion: ";
		cout<<aux->matricula_avion<<endl;
		cout<<"Nombre del piloto: ";
		cout<<aux->nom_piloto<<endl;
		cout<<"Hora de despegue: ";
		cout<<aux->hora<<endl;
		cout<<"Fecha de despegue: ";
		cout<<aux->fecha<<endl<<endl;
		if (aux->pasajeros != NULL)
            listar_pasajeros(aux->pasajeros);
        cont++;
		aux=aux->sgte;
	}
	 if(cont==0)
	 	cout<<"No hay vuelos programados";
	 	system("PAUSE>>NULL");
}
//-------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------
void abrir_archivo_vuelos()
{
	string nro_vuelo[6];
	string origen[8];
	string destino[8];
	string matricula[6];
	string piloto[300];
	string hora_vuelo[10];
	string fecha[20];
	string estado[1];
	int mode=0;
	int pstring=0;
	char c;
	int contador=0;
	ifstream myfile("vuelos.txt");
	if (myfile.is_open())
	{
		
	
	while (myfile.get(c)){
		if(c==';')
		{
			cout<<"\t";
			mode++;
			pstring=0;
		}
		else{
			if (mode==0){
				nro_vuelo[pstring]=c;
				pstring++;
				cout<<c;
			}
			if (mode==1){
				origen[pstring]=c;
				pstring++;
				cout<<c;
			}
			if (mode==2){
				destino[pstring]=c;
				pstring++;
				cout<<c;
			}
			if (mode==3){
				matricula[pstring]=c;
				pstring++;
				cout<<c;
			}
			if (mode==4){
				piloto[pstring]=c;
				pstring++;
				cout<<c;
			}
			if (mode==5){
				hora_vuelo[pstring]=c;
				pstring++;
				cout<<c;
			}
			if (mode==6){
				fecha[pstring]=c;
				pstring++;
				cout<<c;
			}
			if (mode==7){
				estado[pstring]=c;
				pstring++;
				cout<<c;
				mode=0;
			}
	
	}
		
 }
}
	else {
	cout<<"El archivo no se puede abrir ";}
	
	myfile.close();

	//-------------------------------------------------------
}
//-------------------------------------------------------

void abrir_archivo_pasajeros()
{
	string nro_vuelo[6];
	string cedula[20];
	string nombre[30];
	string telefono[10];
	string estado[1];
	int mode=0;
	int pstring=0;
	char c;
	int contador=0;
	ifstream myfile("pasajeros.txt");
	if (myfile.is_open())
	{
		
	
	while (myfile.get(c)){
		if(c==';')
		{
			cout<<"\t";
			mode++;
			pstring=0;
		}
		else{
			if (mode==0){
				nro_vuelo[pstring]=c;
				pstring++;
				cout<<c;
			}
			if (mode==1){
				cedula[pstring]=c;
				pstring++;
				cout<<c;
				
			}
			if (mode==2){
				nombre[pstring]=c;
				pstring++;
				cout<<c;
			}
			if (mode==3){
				telefono[pstring]=c;
				pstring++;
				cout<<c;
			}
			if (mode==4){
				estado[pstring]=c;
				pstring++;
				cout<<c;
				mode=0;
			}
	}
		
 }
}
	else {
	cout<<"El archivo no se puede abrir ";}
	
	myfile.close();

	//-------------------------------------------------------
}
//-------------------------------------------------------


main(){
	

	
	Tlistavuelo q;
	int repet;
	q=new(struct nodoVuelo);
	q->sgte=NULL;
	int accion=100;
	while(accion!=0)
		{cout<<"\t____________AEROLINEA VIAJAR______________\n"<<endl;
		cout<<"\t   -------------        --------------"<<endl;
		cout<<"\n\t             MENU PRINCIPAL"<<endl;
		cout<<"\n\t 1. Cargar vuelos de archivo"<<endl;
		cout<<"\t 2. Crear vuelos"<<endl;
		cout<<"\t 3. Cargar pasajeros del archivo"<<endl;
		cout<<"\t 0. salir"<<endl;
		cout<<"\n\t Opcion: ";
		cin>>accion;
		if(accion==1)
        	abrir_archivo_vuelos();
        	cout<<endl;

   	 if(accion==2){
        cout<<"Inserte cantidad de viajes: ";
        cin>>repet;
        insertarvuelo(q,repet);
        cout<<endl;

    }
    if(accion==3)
    	abrir_archivo_pasajeros();
    	cout<<endl;

}

	system("PAUSE");
}


