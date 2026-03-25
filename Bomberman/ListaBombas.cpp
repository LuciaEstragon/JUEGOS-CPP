#include "ListaBombas.h"
#include <iostream>

using namespace std;


ListaBombas::ListaBombas(void)
{
	numero=0;
	topeBombas = 1;
	totalBombas = 0;
}

ListaBombas::~ListaBombas(void)
{
}

bool ListaBombas::Agregar(Bomba *b, int i, int j)
{
	if(totalBombas < topeBombas){
		lista[i][j] = b;
		totalBombas = totalBombas + 1;
		return true;
	}
	else{
		return false;
	}
}

int ListaBombas:: Dibuja(int i, int j)
{
	return lista[i][j]->Dibuja(GetAlcance());
}

void ListaBombas::Eliminar(int i, int j)
{
	totalBombas = totalBombas - 1;
	delete lista[i][j];
}


/////////SETs y Gets//////////

int ListaBombas:: GetBombaPos_x(int i, int j)
{
	return lista[i][j]->GetPos_x();
}
int ListaBombas:: GetBombaPos_z(int i, int j)
{
	return lista[i][j]->GetPos_z();
}

void ListaBombas:: SetTopeBombas(int tope)
{
		topeBombas = tope;
}
int ListaBombas:: GetTopeBombas()
{
	return topeBombas;
}

void ListaBombas::SetAlcance(int a)
{
	bomba.SetAlcance(a);
}
int ListaBombas::GetAlcance()
{
	return bomba.GetAlcance();
}