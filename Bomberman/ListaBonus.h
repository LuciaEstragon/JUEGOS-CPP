#pragma once
#include "Bonus.h"

class ListaBonus
{
private:
	Bonus* lista[13][15];
public:
ListaBonus(void);
~ListaBonus(void);

void Agregar(Bonus *b, int i, int j);	
void Estallar();
void Eliminar(int i, int j);
void Eliminar(Bonus *b);
void Dibuja(int i, int j);

};