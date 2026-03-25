#include "ListaEnemigos.h"
#include <iostream>

using namespace std;


ListaEnemigos::ListaEnemigos(void)
{
	numero=0;
	for(int i=0;i<MAX_ENEMIGOS;i++)
		lista[i]=0;
}


ListaEnemigos::~ListaEnemigos(void)
{
}

bool ListaEnemigos::Agregar(Enemigo *e, int i, int j)
{
	/*Enemigo e = *new Enemigo(i,j);*/

	//for(int i=0;i<numero;i++)//para evitar que se añada una esfera ya existente
	//	if(lista[i]==e)
	//		return false;

	if(numero<MAX_ENEMIGOS){
	   lista[numero]=e;
	   cout<<"crearEnemigos"<<numero<<endl;
	   numero = numero +1;
	   e->SetPosicion_x(i);
	   e->SetPosicion_z(j);
	 }
	else 
		return false;
	return true;
}

void ListaEnemigos::Eliminar(Enemigo *e, int indice)
{
	
	for(int i=indice;i<numero;i++){
		lista[i]=lista[i+1];
	}
	numero--;
}

void ListaEnemigos::Dibuja(/*int a, int b*/)
{
	for(int i=0;i<numero;i++){
		Enemigo *e = lista[i];
			lista[i]->Dibuja();
	}	
}

void ListaEnemigos::Mueve()
{
	for(int i=0;i<numero;i++)
		lista[i]->CalculaSiguiente();
}


bool ListaEnemigos::compruebaPos(int a, int b)
{
	for(int i=0;i<numero;i++){
		Enemigo *e = lista[i];
		if((e->GetPosicion_x() == a)&&(e->GetPosicion_z() == b)){
			e->compruebaPos(a,b);
			return true;
		}
	}
	return false;
}

void ListaEnemigos::ChequeaExplosion(int a, int b)
{
	for(int i=0;i<numero;i++){
		lista[i]->ChequeaExplosion(a,b);
		if(lista[i]->GetVidaEnemigo() == 0){
			Eliminar(lista[i],i);
		}
	}
}

int ListaEnemigos::GetNumeroEnemigos()
{
	return numero;
}

int ListaEnemigos::GetPosicionSiguiente_x(int indice)
{
	return lista[indice]->GetPosicionSiguiente_x();
}
int ListaEnemigos::GetPosicionSiguiente_z(int indice)
{
	return lista[indice]->GetPosicionSiguiente_z();
}
void ListaEnemigos::CalculaSiguiente(int indice)
{
	lista[indice]->CalculaSiguiente();
}
void ListaEnemigos::SetPosicion(int indice,int p1,int p2)
{
	lista[indice]->SetPosicion_x(p1);
	lista[indice]->SetPosicion_z(p2);
}