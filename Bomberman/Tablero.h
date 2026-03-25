#pragma once

#include "Muro.h"
#include "Bloque.h"
#include "Suelo.h"
#include "Personaje.h"
#include "ListaEnemigos.h"
#include "ListaBombas.h"
#include "Bonus.h"

class Tablero
{
private:
	int numfilas;
	int numcolumnas;
	Celda*** laberinto;
	Personaje personaje;
	ListaEnemigos enemigos;
	ListaBombas bombas;
	Bonus bonus;

public:
	Tablero();
	~Tablero();

	void creaLaberinto();
	void leerfichero(istream &is);
	void leerPersonajeYEnemigo(int queEres, int i, int j);
	void Dibuja();
	void DestruyeTablero(int i, int j);
	int compruebaLab(int x, int z);
	void Mueve();
	void TeclaEspecial(unsigned char key);
	void PonerBomba();
	void EfectoBonus();

	void SetLaberinto(Celda ***lab);
	Celda GetLaberinto();
	void SetFilas(int filas);
	int GetFilas();
	void SetColumnas(int columnas);
	int GetColumnas();
	int GetMiVida();
	int GetAlcance();
	int GetMaxBomb();
	int GetNumeroEnemigos();
};
