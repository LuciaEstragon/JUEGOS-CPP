#pragma once
#include "Bomba.h"

class ListaBombas
{
private:
	Bomba* lista[13][15];
	Bomba bomba;
	int numero;
	int topeBombas;
	int totalBombas;

public:
	ListaBombas(void);
	~ListaBombas(void);

	bool Agregar(Bomba *b, int i, int j);
	int Dibuja(int i, int j);
	void Eliminar(int i, int j);

	int GetBombaPos_x(int i, int j);
	int GetBombaPos_z(int i, int j);
	void SetTopeBombas(int tope);
	int GetTopeBombas();
	void SetAlcance(int a);
	int GetAlcance();
};

