#include "Celda.h"

Celda::Celda()
{
	pos_x = 0;
	pos_z = 0;
	lado = 5;
	tieneBomba = false;
	tieneBonus = false;
	sePuedePasar = false;
	sePuedeRomper = false;
}

Celda::~Celda()
{
}

void Celda::Dibuja()
{
}

void Celda::SetTieneBomba(bool bomba)
{
	tieneBomba = bomba;
}

void Celda::SetTieneBonus(bool bonus)
{
	tieneBonus = bonus;
}

void Celda::SetSePuedePasar(bool sePasa)
{
	sePuedePasar = sePasa;
}

void Celda::SetSePuedeRomper(bool seRompe)
{
	sePuedeRomper = seRompe;
}

bool Celda::GetTieneBomba()
{
	return tieneBomba;
}
bool Celda::GetTieneBonus()
{
	return tieneBonus;
}
bool Celda::GetSePuedePasar()
{
	return sePuedePasar;
}
bool Celda::GetSePuedeRomper()
{
	return sePuedeRomper;
}