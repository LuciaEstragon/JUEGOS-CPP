#pragma once
#include "Muro.h"

class Explosion
{
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	int lado;

public:
	Explosion(void);
	~Explosion(void);

	void Dibuja(int alcance, int i, int j);
};

