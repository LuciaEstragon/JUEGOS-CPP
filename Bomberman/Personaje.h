#pragma once
class Personaje
{
private:
	float altura;
	int MiVida;
	int Inmunidad;

	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	int pos_x;
	int pos_z;

	int posSig_x;
	int posSig_z;

public:
	Personaje();
	~Personaje();

	void Dibuja();

	void SetPosicion_x(int a);
	void SetPosicion_z(int b);
	int GetPosicion_x();
	int GetPosicion_z();
	int GetPosicionSiguiente_x();
	int GetPosicionSiguiente_z();
	void SetMiVida(int MiVida);
	int GetMiVida();
	void SetInmunidad(int Inmunidad);
	int GetInmunidad();

	bool compruebaPos(int a, int b);
	void CalculaSiguiente(unsigned char key);

	void ChequeaExplosion(int a,int b);
};


