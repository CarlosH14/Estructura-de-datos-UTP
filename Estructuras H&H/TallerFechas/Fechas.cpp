#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;


/*
	Nombre Estructura: fecha 
	Atributos: day, month, year 
	Descripcion: Clase fecha, con 3 atributos 
	enteros de dia, mes y a�o luego se crea 
	una funci�n para validar si la fecha es correcta 
*/
struct fecha
{	int day;
	int month;
	int year;	
};



//--------------------------------------------------
/*
	Nombre Funci�n: validarBisiesto(int year) 
	Objetivo: validar si un a�o es un a�o bisiesto
	es decir, tiene 1 dia adicional en febrero 
	Parametro: int year --> a�o a validar 
	Retorno: retonar falso o verdadero segun corresponda 
	Ejemplo: validarBisiesto(2000) --> retorna True 
*/

bool validarBisiesto(int year){
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0 )
        return true;
    else
        return false;
}

//--------------------------------------------------
/*
	Nombre Funci�n: validaFecha(fecha n) 
	Objetivo: validar si los atributos de una clase fecha son
	correctos, es decir, cumplen las restricciones de dias, meses
	y a�os seg�n las diferentes situaciones
	Parametro: fecha n --> fecha a validar 
	Retorno: retonar falso o verdadero segun corresponda 
	Ejemplo: 
	//fecha independencia={20,7,1810};
	validaFecha(independencia) --> retorna True 
*/
bool validaFecha(fecha n)
{
   if (n.year>=1){
   	if(n.month>0 && n.month<13){
   		if(n.month==1 || n.month==3 || n.month==5 || n.month==7 || n.month==8 || n.month==10 || n.month==12){
   			if(n.day>0 && n.day<32){
   				return true;
				 }else{
				 	return false;
				 }
			 }else if(n.month==4 || n.month==6 || n.month==9 || n.month==11){
				 	if (n.day>0 && n.day<31){
				 		return true;
					 }else{
					 	return false;
					 }
				 }else if(n.month == 2){
				 	if (validarBisiesto(n.year)==true){
				 		if (n.day>0 && n.day<30){
				 		return true;
					 }else{
					 	return false;
					 }
					 }else{
					 	if (n.day>0 && n.day<29){
				 		return true;
					 }else{
					 	return false;
					 }
					 }
				 }
		 }
	 }
}



main()

{
	fecha hoy;
	fecha cero={1,1,2000};
	hoy=cero;
	
	bool fin=false;
	int addop=0;
	int conop;
	int modop;
	while(fin==false){
	//Men� para a�adir fechas, se validan al momento de ingresarlas
	//Se muestran seg�n el formato indicado
	cout<<"*-*-*-*-* Menu *-*-*-*-*"<<endl;
	cout<<"1 .Nueva fecha\n2. Mostrar fecha\n3. Salir "<<endl;
	int op;
	cin>>op;
	switch(op){
		case 1:
			
			cout<<"D�a:\n";
			cin>>hoy.day;
			cout<<"Mes:\n";
			cin>>hoy.month;
			cout<<"A�o:\n";
			cin>>hoy.year;
			
			if (validaFecha(hoy)==true){
				cout<<"Fecha Valida\n";
			}else{
				cout<<"Fecha no valida\n";
				hoy=cero;
			}
			break;
		case 2:		
			cout<<"Fecha (dd-mm-aaaa)\n";
			cout<<hoy.day<<"-"<<hoy.month<<"-"<<hoy.year<<endl;
			break;
		case 3:
			cout<<"Adios\n";
			fin=true;
			break;			
	}
}
}
