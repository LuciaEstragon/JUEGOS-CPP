#include "Bomba.h"
#include "glut.h"
#include <iostream>

using namespace std;

Bomba::Bomba()
{
	radio = 1.5f;
	rojo = 100;
	verde = 94;
	azul = 94;
	estado=INICIO;
	contador = 0.0f;
	alcance = 1;
	heExplotado=true;
}
Bomba::~Bomba()
{
}

int Bomba::Dibuja(int alcance)
{
	Estallar();

	if(estado == INICIO)
	{ 
		glColor3ub(rojo, verde, azul);
		glDisable(GL_LIGHTING);
		glTranslatef(2.5, 1.5, 2.5);
		glutSolidSphere(radio, 20, 20);
		glTranslatef(-2.5, -1.5, -2.5);
		glEnable(GL_LIGHTING);
		
		return 0;
	}

	else if(estado == EXPLOSION) 
	{
		explosion.Dibuja(alcance,p_x,p_z);
		return 1;
	}
	else if (estado == FIN)
	{
		return 2;
	}

}

void Bomba::Estallar( )
{
	if(estado==INICIO) 
	{ 
	contador += 0.1f;
		if (contador>5.0f)
		{
			estado = EXPLOSION;
			heExplotado=true;
		}
	}
	else if(estado == EXPLOSION)
	{
		contador += 0.1f;
		if (contador>6.5f)
		{
			estado = FIN;
		}
	}
			
//son segundos (en 5 segundos sale la explosion y en 3 segundos mas se va)
//sin embargo, si me quedo encima de la bomba y no me muevo, por alguna extraña razon la cuenta son mas segundos, casi 8 segundos
//la cuenta solo es valida para 1 bomba, no se ni como ni porqe se mete en la funcion estalla, no la llame
//contador no vuelve a 0
}



/// SETs y GETs ///

void Bomba::SetContador(float c)
{
	contador=c;
}
float Bomba::GetContador()
{
	return contador;
}

void Bomba::SetAlcance(int a)
{
	cout<<"cambbia el alcance en el set"<<alcance<<endl;
	alcance=a;
}

int Bomba::GetAlcance()
{
	cout<<"get bomba"<<alcance<<endl;
	return alcance;
}


void Bomba::SetPosicion(int p_x, int p_z)
{
	this-> p_x= p_x;
	this-> p_z = p_z;
}
int Bomba::GetPos_x(){
	return p_x;
}
int Bomba::GetPos_z(){
	return p_z;
}