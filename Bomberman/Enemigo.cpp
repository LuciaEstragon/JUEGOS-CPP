#include "Enemigo.h"
#include "glut.h"
#include <iostream>

using namespace std;

Enemigo::Enemigo(void)
{
	pos_x=0;
	pos_z=0;
	altura = 4.0f;
	rojo = 255;
	verde = 255;
	azul = 0;
	VidaEnemigo=1;
	ultimoMovimiento=0;
}


Enemigo::~Enemigo(void)
{
}

void Enemigo::Dibuja()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3ub(rojo,verde,azul);
	glTranslatef(2.5,2,2.5);
	glutSolidCube(altura);
	glTranslatef(-2.5,-2,-2.5);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void Enemigo::SetPosicion_x(int a)
{
	pos_x=a;
}


void Enemigo::SetPosicion_z(int b)
{
	pos_z=b;
}

int Enemigo::GetPosicion_x(){
	return pos_x;
}
int Enemigo::GetPosicion_z(){
	return pos_z;
}
int Enemigo::GetPosicionSiguiente_x(){
	return posSig_x;
}
int Enemigo::GetPosicionSiguiente_z(){
	return posSig_z;
}

void Enemigo::setUltimoMovimiento(int mov)
{
	ultimoMovimiento=mov;
}
int Enemigo::getUltimoMovimiento(){
	return ultimoMovimiento;
}

//void Enemigo::SetVidaEnemigo(int VidaEnemigo)
//{
//	this-> VidaEnemigo = VidaEnemigo;
//}

int Enemigo::GetVidaEnemigo()
{
	return VidaEnemigo;
}

bool Enemigo::compruebaPos(int a, int b)
{
	if(pos_x == a && pos_z == b){
			return true;
		}
	return false;
}

void Enemigo::CalculaSiguiente()//Para el movimiendo del enemigo
{
	int movimiento = rand() % 13;// va de 0 a 12	
	if (movimiento > 4 && movimiento < 8)
	{
		movimiento = ultimoMovimiento;
	}
	ultimoMovimiento = movimiento;

	switch (movimiento)
	{
	case 0://arriba
		posSig_x=pos_x-1;
		posSig_z=pos_z;
		break;

	case 1://derecha
		posSig_x=pos_x;
		posSig_z=pos_z+1;
		break;

	case 2://abajo
		posSig_x=pos_x+1;
		posSig_z=pos_z;
		break;

	case 3://izquierda
		posSig_x=pos_x;
		posSig_z=pos_z-1;
		break;

	default:
		//no hagas nada.
		break;

	}
}

void Enemigo::ChequeaExplosion(int a,int b)
{
	if(pos_x==a && pos_z==b){
		VidaEnemigo=VidaEnemigo-1;
	}
}
