#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;


struct transaccion
{	int nTrans; //Numero transacción
	int nCuenta; //Numero cuenta
	int tipoTrans; //Tipo de transaccion 0=retiro 1=consignacion
	int Valor; //Valor
}; 

//--------------------------------------------------
/*
	Nombre Función: Saldo(int Sal, int Cuenta, transaccion t)
	Objetivo: Calcular el saldo de una cuenta
	Parametro: int Sal es el saldo, int Cuenta la cuenta, transaccion t la transaccion
	Retorno: el saldo despues de la transaccion
	Ejemplo: SaldoT= Saldo(1000, 1001,{1,1001,1,1000}); --> retorna 2000
*/

int Saldo(int Sal, int Cuenta, transaccion t){

	if (t.nCuenta =Cuenta){
		if(t.tipoTrans == 0){
			Sal=Sal-t.Valor;
		}
		if(t.tipoTrans == 1){
			Sal=Sal+t.Valor;	
	}
	
	}else{
		cout<<"Cuenta no corresponde a transacciones"<<endl;
		return 0;
	}
	
	return Sal;
}



main()

{
	transaccion t1={1,1001,1,1000};
	transaccion t2={2,1001,1,1000};
	transaccion t3={3,1001,1,1000};
	transaccion t4={4,1001,1,1000};
	transaccion t5={5,1001,1,1000};
	transaccion t6={6,1001,0,100};
	transaccion t7={7,1001,0,100};
	transaccion t8={8,1001,0,100};
	transaccion t9={9,1001,0,100};
	transaccion t10={10,1001,0,100};
	int SaldoT=0;
	
	transaccion t[10]={t1,t2,t3,t4,t5,t6,t7,t8,t9,t10};
	
	for(int i=0; i<10; i++){
		SaldoT= Saldo(SaldoT, 1001,t[i]);
	}
	
	cout<<"Saldo final: "<<SaldoT<<endl;
	
}
