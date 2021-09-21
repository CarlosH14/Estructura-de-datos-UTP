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
/*
	Nombre Estructura: Pasajero
	Atributos: num_vuelo, cedula, nombre, telefono, estado, sgte Pasajero
	Descripcion: Pasajero de un vuelo con sus datos personales
*/
struct Pasajero{
  string num_vuelo;
	string cedula;
	string nombre;
	string telefono;
	int estado;
	Pasajero *sgte;
};
typedef Pasajero *Tlistapasajero;
	
/*
	Nombre Estructura: Vuelo
	Atributos: num_vuelo, origen, destino, matricula_avion, nom_piloto, hora, fecha, estado, pasajeros, sgte vuelo
	Descripcion: Vuelo con los datos del trayecto y los pasajeros del viaje
*/
struct Vuelo{
	string num_vuelo;
	string origen;
	string destino;
	string matricula_avion;
	string nom_piloto;
	string hora;
	string fecha;
	int estado;
	Pasajero *pasajeros;
	Vuelo *sgte;
};
typedef Vuelo *Tlistavuelo;

Tlistavuelo q; //Lista de vuelos global
//--------------------------------------------------
/*
	Nombre Función: insertarpasajero
	Objetivo: agregar uno o mas pasajeros a un viaje
	Parametro: Tlistapasajero k, entero valor
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: insertarpasajero(k,5) --> agrega 5 pasajeros a la lista de pasajeros 
*/
void insertarpasajero(Tlistapasajero &k, int n)
{	
	fstream archivo;  // objeto de la clase ofstream

    archivo.open("pasajeros1.txt", ios::app);

	int cont=0;
	string cedula;
	string nomb;
	string tel;
	string num_vuelo;
	int est;
	while(cont<n){

		Tlistapasajero z;
		z=new(struct Pasajero);
		z->sgte=NULL;
		getchar();

		cout<<"\n Digite numero de vuelo del pasajero #"<<cont+1<<" : ";
		getline(cin,num_vuelo);
		z->num_vuelo=num_vuelo;
		archivo << z->num_vuelo << ";";

		cout<<"\n Digite cedula del pasajero #"<<cont+1<<" : ";
		getline(cin,cedula);
		z->cedula=cedula;
		archivo << z->cedula << ";";

		cout<<"Digite nombre del pasaje #"<<cont+1<<" : ";
        getline(cin, nomb);
		z->nombre=nomb;
		archivo << z->nombre << ";";

		cout<<"Digite telefono del pasajero #"<<cont+1<<" : ";;
        getline(cin,tel);
		z->telefono=tel;
		archivo << z->telefono << ";";

		cout<<"Digite estado del pasajero"<<endl;
		cout<<"\t 1. Vuelo reservado \n \t 2. Vuelo abordado \n \t Opcion: ";
        cin>>est;
		z->estado=est;
		archivo << z->estado << endl;
		z->sgte=k;
		k=z;
		cout<<"\n Usuario registrado \n";
		system("PAUSE>>NULL");
		cout<<endl<<endl;
		cont++;
	}//cierra while
	archivo.close();
}
//--------------------------------------------------
/*
	Nombre Función: insertarvuelo
	Objetivo: agregar uno o mas vuelos a un viaje
	Parametro: Tlistavuelo lista, entero valor
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: insertarvuelo(lista,5) --> agrega 5 vuelos a la lista de vuelos 
*/
void insertarvuelo(Tlistavuelo &lista,int n)
{	
	fstream archivo;  // objeto de la clase ofstream

    archivo.open("vuelos1.txt", ios::app);
 
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
        q=new(struct Vuelo);
        q->sgte=NULL;
    getchar();
	cout<<"Digite el numero del vuelo 6 caracteres: ";
	getline(cin,numvuelo);
	q->num_vuelo=numvuelo;
	archivo << q->num_vuelo << ";";

	cout<<"Digite el origen del vuelo: ";
	getline(cin,nom_origen);
	q->origen=nom_origen;
	archivo << q->origen << ";";

	cout<<"Digite el destino del vuelo: ";
    getline(cin,nom_dest);
	q->destino=nom_dest;
	archivo << q->destino << ";";

	cout<<"Digite el numero de la matricula: ";
	getline(cin, matri);
	q->matricula_avion=matri;
	archivo << q->matricula_avion << ";";

	cout<<"Digite nombre del piloto: ";
	getline(cin, nom_piloto);
	q->nom_piloto=nom_piloto;
	archivo << q->nom_piloto << ";";

	cout<<"Ingrese hora: ";
    getline(cin, hora_part);
	q->hora=hora_part;
	archivo << q->hora << ";";

	cout<<"Ingrese fecha : ";
	getline (cin, fecha_part);
	q->fecha=fecha_part;
	archivo << q->fecha << ";";

	cout<<"Vuelo"<<endl;
	cout<<"0\t programado"<<endl;
	cout<<"1\t realizado"<<endl;
	int estado;
	cout<<"Opcion: ";
	cin>>estado;
	q->estado=estado;
	archivo << q->estado << endl;
	archivo.close();
	getchar();
	cout<<endl<<endl;
	Tlistapasajero k;
	k=new(struct Pasajero);
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
//--------------------------------------------------
/*
	Nombre Función: listar_pasajeros
	Objetivo: lista los pasajeros del archivo
	Parametro: Tlistapasajero lista
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: listar_pasajeros(lista) --> lista los pasajeros del archivo pasajeros1.txt
*/
void listar_pasajeros(Tlistapasajero &lista)
{
    Tlistapasajero aux;
	aux=new(struct Pasajero);
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
//--------------------------------------------------
/*
	Nombre Función: listavuelos
	Objetivo: lista los vuelos del archivo
	Parametro: Tlistavuelo lista
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: listavuelos(lista) --> lista los vuelos del archivo vuelos1.txt
*/
void listavuelos(Tlistavuelo &lista)
{
	Tlistavuelo aux;
	aux=new(struct Vuelo);
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
//--------------------------------------------------
/*
	Nombre Función: abrir_archivo_vuelos
	Objetivo: abre el archivo de vuelos para la consulta
	Parametro: ninguno
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: abrir_archivo_vuelos() --> abre el archivo de vuelos
*/
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
	ifstream myfile("vuelos1.txt");
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
//--------------------------------------------------
/*
	Nombre Función: abrir_archivo_pasajeros
	Objetivo: abre el archivo de pasajeros para la consulta
	Parametro: ninguno
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: abrir_archivo_pasajeros() --> abre el archivo de pasajeros
*/
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
	ifstream myfile("pasajeros1.txt");
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
//--------------------------------------------------
/*
	Nombre Función: filtroc
	Objetivo: filtra los pasajeros por su cedula
	Parametro: char ced[7]
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: filtroc(1010101) --> muestra los pasajeros con la cedula 1010101
*/
void filtroc(char ced[7]){
	char linea[128];
  long contador = 0L;
	fstream archivo;
	archivo.open("pasajeros1.txt", ios::in);
	while(!archivo.eof())
    {
        archivo.getline(linea, sizeof(linea));
        if(ced[0]==linea[4] && ced[1]==linea[5] && ced[2]==linea[6] && ced[3]==linea[7] && ced[4]==linea[8] && ced[5]==linea[9] && ced[6]==linea[10]){
					cout << linea << endl;
				}
        
        if((++contador % 24)==0)
        {
            cout << "CONTINUA...";
            cin.get();
        }
    }
    archivo.close();
}
//--------------------------------------------------
/*
	Nombre Función: cambioviaje
	Objetivo: cambia el estado de un vuelo
	Parametro: char viaj[4]
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: cambioviaje(123) --> cambia es estado del vuelo 123
*/
void cambioviaje(char viaj[4]){
	char linea[128];
  long contador = 0L;
	fstream archivo;
	archivo.open("vuelos1.txt");
	while(!archivo.eof())
    {
        archivo.getline(linea, sizeof(linea));
        if(viaj[0]==linea[0] && viaj[1]==linea[1] && viaj[2]==linea[2]){
					cout << "Viaje a cambiar :"<<endl << linea << endl;
					cout<<endl<<"Viaje actualizado: "<<endl;
					for(int i=0; i<(strlen(linea)-1); i++){
						cout<<linea[i];
					}
					cout<<1;
				}
        
        if((++contador % 24)==0)
        {
            cout << "CONTINUA...";
            cin.get();
        }
    }
    archivo.close();
}
//--------------------------------------------------
/*
	Nombre Función: cambiobordo
	Objetivo: cambia el estado de un pasajero con respecto a un vuelo
	Parametro: char ced[7], char viaj[4]
	Retorno: es un procedimiento, no retorna nada
	Ejemplo: cambiobordo(1010101, 123) --> cambia es estado del abordaje del pasajero de cedula 1010101 en el viaje 123
*/
void cambiobordo(char ced[7], char viaj[4]){
	char linea[128];
  long contador = 0L;
	fstream archivo;
	archivo.open("pasajeros1.txt");
	while(!archivo.eof())
    {
        archivo.getline(linea, sizeof(linea));
        if(viaj[0]==linea[0] && viaj[1]==linea[1] && viaj[2]==linea[2] && ced[0]==linea[4] && ced[1]==linea[5] && ced[2]==linea[6] && ced[3]==linea[7] && ced[4]==linea[8] && ced[5]==linea[9] && ced[6]==linea[10]){
					cout << "Pasaje a cmabiar :"<<endl << linea << endl;
					cout<<endl<<"Pasaje actualizado: "<<endl;
					for(int i=0; i<(strlen(linea)-1); i++){
						cout<<linea[i];
					}
					cout<<1;
				}
        
        if((++contador % 24)==0)
        {
            cout << "CONTINUA...";
            cin.get();
        }
    }
    archivo.close();
}

main(){
	int repet, repet2;
	char cedu[7];
	char via[4];
	q=new(struct Vuelo);
	q->sgte=NULL;
	int accion=100;
	while(accion!=0)
		{cout<<"\t____________AEROLINEA VIAJAR______________\n"<<endl;
		cout<<"\t   -------------        --------------"<<endl;
		cout<<"\n\t             MENU PRINCIPAL"<<endl;
		cout<<"\n\t 1. Cargar vuelos de archivo"<<endl;
		cout<<"\t 2. Crear vuelos"<<endl;
		cout<<"\t 3. Cargar pasajeros del archivo"<<endl;
		cout<<"\t 4. Crear pasajeros"<<endl;
		cout<<"\t 5. Filtro de cédula"<<endl;
		cout<<"\t 6. Cambio de programado a realizado"<<endl;
		cout<<"\t 7. Cambio de reservado a abordado"<<endl;
		cout<<"\t 0. salir"<<endl;
		cout<<"\n\t Opcion: ";
		cin>>accion;
		if(accion==1){
        	abrir_archivo_vuelos();
        	cout<<endl;}
   	 if(accion==2){
        cout<<"Inserte cantidad de viajes: ";
        cin>>repet;
        insertarvuelo(q,repet);
        cout<<endl;}
    if(accion==3){
    	abrir_archivo_pasajeros();
    	cout<<endl;}
    if(accion==4){
        cout<<"Inserte cantidad de pasajeros: ";
        cin>>repet2;
        insertarpasajero(q->pasajeros,repet2);
        cout<<endl;}
    if(accion==5){
        cout<<"Inserte la cedula del pasajero: ";
        cin>>cedu;
        cout<<endl<<"Lista de Pasajeros:"<<endl<<"Viaje - Cedula - Nombre - Telefono - (1)Reserva (2)Abordado"<<endl;
        filtroc(cedu);       
        cout<<endl;}
    if(accion==6){
        cout<<"Ingrese el codigo del viaje: ";
        cin>>via;
        cambioviaje(via);       
        cout<<endl;}
    if(accion==7){
        cout<<"Inserte la cedula del pasajero: "<<endl;
        cin>>cedu;
        cout<<endl<<"Ingrese el codigo del viaje: "<<endl;
        cin>>via;
        cambiobordo(cedu, via);       
        cout<<endl;}
  
}

	system("PAUSE");
}


