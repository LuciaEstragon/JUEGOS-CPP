#pragma once
#include <iostream>
using namespace std;

class Celda
{
protected:
	int pos_x;
	int pos_z;
	
	int lado;

	bool tieneBomba;
	bool tieneBonus;
	bool sePuedePasar;
	bool sePuedeRomper;

	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	Celda();
	virtual ~Celda();
	
	virtual void Dibuja();
	
	int GetLado();
	virtual void SetTieneBomba(bool bomba);
	void SetTieneBonus(bool bonus);
	void SetSePuedePasar(bool sePasa);
	void SetSePuedeRomper(bool seRompe);
	bool GetTieneBomba();
	bool GetTieneBonus();
	bool GetSePuedePasar();
	bool GetSePuedeRomper();
};