#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Código para crear el archivo .txt con 1 000 000 de datos aleatorios entre 0 y 999
//Archivo guardado como "Datos1000000.txt"

using namespace std;

void LlenarArchivo (FILE* archivo){
     
     archivo=fopen("Datos1000000.txt","a+");
     
     char esp='\n';
     
     int c;
     char s[10];
     
     for(int i=0; i <=1000000 ; i++)
     {
     c=1+ (rand()% (1000-1));
     sprintf(s,  "%d", c);
     fputs(s, archivo);
     fwrite(&esp, sizeof(char), 1, archivo);
     }
     
     fclose(archivo);
     }

void SacarArchivo(FILE* archivo, int Vector[100]){
	archivo=fopen("Datos1000000.txt", "r+");
	char d[3];
	int numero;
	//d[3]='\0';
	
	Vector[100]='\0';
	int c=0;
	while (c <100){
		fgets(d, 5, archivo);
		cout<<d;
    numero=atoi(d);
    Vector[c]=numero;
    c++;
	}
	fclose(archivo);
}

void Mostrar(int Vector[100]){
	for(int i=0; i<100; i++){
		cout<<Vector[i];
	}
}

void Vaciar(int Vector[100]){
	for(int i=0; i<100; i++){
		Vector[i]=0;
	}
}

int main(int argc, char *argv[])
{
    FILE* archivo;
   	int Vector[100];
    int Opc=1;
    
    while(Opc!=0){
    	cout<<"\nSWITCH\n1. LlenarArchivo\n2. Poner en matriz\n3. Vaciar matriz\n";
    	cin>>Opc;
    switch(Opc){
    	case 1:
    		LlenarArchivo (archivo);
    		break;
    	case 2:
    		cout<<"Poner matriz\n";
    		SacarArchivo(archivo, Vector);
    		//Mostrar(Vector);
				break;
    	case 3:
    		cout<<"Vacia matriz";
    		Vaciar(Vector);
    		break;
    	
		}
   }
    
    
    
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
