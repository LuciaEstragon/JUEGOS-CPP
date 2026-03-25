#pragma once
#include "Enemigo.h"
#define MAX_ENEMIGOS 3

class ListaEnemigos
{
private:
	Enemigo * lista[MAX_ENEMIGOS];
	int numero;
public:
	ListaEnemigos(void);
	~ListaEnemigos(void);

	bool Agregar(Enemigo *e, int i, int j);
	void Eliminar(Enemigo *e, int indice);
	void Dibuja();
	void Mueve();
	bool compruebaPos(int a, int b);
	void ChequeaExplosion(int a, int b);
	int GetNumeroEnemigos();
	int GetPosicionSiguiente_x(int indice);
	int GetPosicionSiguiente_z(int indice);
	void CalculaSiguiente(int indice);
	void SetPosicion(int indice,int p1,int p2);
};