#include "ListaBonus.h"


ListaBonus::ListaBonus(void)
{
}


ListaBonus::~ListaBonus(void)
{
}

void ListaBonus::Agregar(Bonus *b, int i, int j)
{
	lista[i][j] = b;
}

void ListaBonus::Eliminar(int i, int j)
{
	delete lista[i][j];
}
 
void ListaBonus::Dibuja(int i, int j)
{
	return lista[i][j]->Dibuja();
}

