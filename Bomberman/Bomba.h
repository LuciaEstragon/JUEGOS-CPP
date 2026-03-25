#pragma once
#include "Explosion.h"


class Bomba
{
private:
	Explosion explosion;
	enum Estado {INICIO, EXPLOSION, FIN}; 
	Estado estado;
	bool heExplotado;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	float radio;
	float contador;
	int estallar;
	int alcance;

	int p_x;
	int p_z;

public:
	Bomba();
	~Bomba();
	bool haExplotado(){return heExplotado;}
	void resetExplosion(){heExplotado=false;}
	int Dibuja(int alcance);
	void Estallar();

	void DestruyeDisparo(int x, int y);

	void SetContador(float c);
	float GetContador();

	void SetAlcance(int a);
	int GetAlcance();

	void SetPosicion(int p_x, int p_z);
	int GetPos_x();
	int GetPos_z();
};