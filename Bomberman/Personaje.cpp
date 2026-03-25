#include "Personaje.h"
#include "glut.h"
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
using namespace std;

Personaje::Personaje()
{
	altura = 4.0f;
	rojo = 255;
	verde = 0;
	azul = 0;
	MiVida=2;
	Inmunidad=0;
}

Personaje::~Personaje()
{
}

void Personaje::SetPosicion_x(int a)
{
	pos_x=a;
}


void Personaje::SetPosicion_z(int b)
{
	pos_z=b;
}

int Personaje::GetPosicion_x(){
	return pos_x;
}
int Personaje::GetPosicion_z(){
	return pos_z;
}

int Personaje::GetPosicionSiguiente_x(){
	return posSig_x;
}
int Personaje::GetPosicionSiguiente_z(){
	return posSig_z;
}

void Personaje::SetMiVida(int MiVida)
{
	this-> MiVida = MiVida;
}

int Personaje::GetMiVida()
{
	return MiVida;
}

void Personaje::SetInmunidad(int Inmunidad)
{
	this-> Inmunidad = Inmunidad;
}
int Personaje::GetInmunidad()
{
	return Inmunidad;
}

bool Personaje::compruebaPos(int a, int b)
{
	if(pos_x == a && pos_z == b)
			return true;

	return false;
}

void Personaje::Dibuja()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(2.5,2,2.5);
	glColor3ub(rojo,verde,azul);
	glutSolidCube(altura);
	glTranslatef(-2.5,-2,-2.5);
	glEnable(GL_LIGHTING);
	glPopMatrix();

}

void Personaje::CalculaSiguiente(unsigned char key)//Para el movimiendo del personaje
{
	//esta es la posicion a la que queremos movernos en cada caso
	//si combrueba, mediante una lectura de laberinto, que podemos acceder a la casilla que pretendemos, el personaje se movera.
	switch (key)
	{
	case GLUT_KEY_LEFT:
		posSig_x=pos_x;
		posSig_z=pos_z-1;
		break;

	case GLUT_KEY_RIGHT:
		posSig_x=pos_x;
		posSig_z=pos_z+1;
		break;

	case GLUT_KEY_UP:
		posSig_x=pos_x-1;
		posSig_z=pos_z;
		break;

	case GLUT_KEY_DOWN:
		posSig_x=pos_x+1;
		posSig_z=pos_z;
		break;
	default:
		break;
	}

}

void Personaje::ChequeaExplosion(int a,int b)
{
	if(pos_x==a && pos_z==b){
		MiVida=MiVida-1;
		Inmunidad=1;
	}
}
