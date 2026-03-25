#include "Tablero.h"
#include "glut.h"
#include <iostream>
#include <fstream>
#include "ETSIDI.h"
using namespace std;

Tablero::Tablero()
{
}

Tablero::~Tablero()
{
}

void Tablero::creaLaberinto()
{
	laberinto = new Celda**[numfilas];
	for (int i = 0; i < numfilas; i++)
		laberinto[i] = new Celda*[numcolumnas];
}

void Tablero::leerfichero(istream &is)
{
	is >> numfilas >> numcolumnas;
	creaLaberinto();

	int queEres;
	for (int i = 0;i < numfilas;i++){
		for (int j = 0; j< numcolumnas; j++) {
			is >> queEres;
			switch(queEres)
			{
				case 0:
					laberinto[i][j] = new Suelo;	
					break;
				case 6:
					laberinto[i][j] = new Bloque;	
					break;
				case 8:
					laberinto[i][j] = new Muro;		
					break;
				default:
					leerPersonajeYEnemigo(queEres, i, j);
			}
		}
	}
}

void Tablero::leerPersonajeYEnemigo(int queEres, int i, int j)
{
	switch(queEres)
	{
		case 1:
			laberinto[i][j] = new Suelo;
			personaje.SetPosicion_x(i);
			personaje.SetPosicion_z(j);
			break;
		case 7:
			laberinto[i][j] = new Suelo;
			Enemigo *e = new Enemigo;
			enemigos.Agregar(e,i,j);
			break;		
	}
}

void Tablero::Dibuja()
{
	int x = 0;
	int z = 0;

	for (int i = 0; i< numfilas; i++) {
		for (int j = 0; j< numcolumnas; j++) {

			glTranslated(x, 0, z);

			laberinto[i][j]->Dibuja();

			if(personaje.compruebaPos(i, j)){
				personaje.Dibuja();
			}
			if(enemigos.compruebaPos(i, j)){
				enemigos.Dibuja();
			}
			if(laberinto[i][j]->GetTieneBonus()){
				bonus.Dibuja();
			}
			if(laberinto[i][j]->GetTieneBomba()){
				int estado = bombas.Dibuja(i,j);
				int YaMeMataste=0;
				if(estado== 1) // estado es Explosion
				{
					//estallar bloques y pregunta por personaje o enemigos afectados
					DestruyeTablero(i,j);
					if (personaje.GetInmunidad()==0)
						personaje.ChequeaExplosion(i,j); //nota: solo hacemos este chequea aqui.
													//es la poscion encima de la boba (i,j), las demas las puede leer en la funcion destruye tablero
				}
				if(estado== 2) // estado es FIN
				{
					personaje.SetInmunidad(0);
					laberinto[i][j]->SetTieneBomba(false);
					bombas.Eliminar(i,j);
				}
			}

			glTranslated(0, 0, 0);

			x = 5;
			z = 0;
		}
		x = -5*(numcolumnas-1);
		z = 5;
	}
}

void Tablero::DestruyeTablero(int i, int j)
{
	int falloCaso0=0;
	int falloCaso1=0;
	int falloCaso2=0;
	int falloCaso3=0;

	int alcance = bombas.GetAlcance(); //como minimo siempre es 1

	for (int x=1; x<=alcance; x++)
	{ 
	int mira=0;
	do{
		switch(mira)
		{
		case 0:
			if (falloCaso0==1 || !laberinto[i-x][j]->GetSePuedeRomper() && !laberinto[i-x][j]->GetSePuedePasar()) //si pasa una de las dos cosas estoy en muro
			{
				falloCaso0=1;
			}
			else if (laberinto[i-x][j]->GetSePuedeRomper() && falloCaso0==0)
			{
				delete laberinto[i-x][j];
				laberinto[i-x][j] = new Suelo;
				if (bonus.crearBonus())
					laberinto[i-x][j]->SetTieneBonus(true);
			}
			else if (falloCaso0==0 && personaje.GetInmunidad()==0)
			{
				//comprobacion que hace personaje para saber si pisa explosion
				personaje.ChequeaExplosion(i-x,j);
				//comprobacion que hace enemigo para saber si pisa explosion
				enemigos.ChequeaExplosion(i-x,j);
			}
			mira=1;
			break;

		case 1:
			if (falloCaso1==1 || !laberinto[i+x][j]->GetSePuedeRomper() && !laberinto[i+x][j]->GetSePuedePasar()) //si pasa una de las dos cosas estoy en muro
				{
					falloCaso1=1;
				}
			else if (laberinto[i+x][j]->GetSePuedeRomper() && falloCaso1==0)
			{
				delete laberinto[i+x][j];
				laberinto[i+x][j] = new Suelo;
				if (bonus.crearBonus())
					laberinto[i+x][j]->SetTieneBonus(true);
			}
			else if(falloCaso1==0 && personaje.GetInmunidad()==0)
			{
				//comprobacion que hace personaje para saber si pisa explosion
				personaje.ChequeaExplosion(i+x,j);
				//comprobacion que hace enemigo para saber si pisa explosion
				enemigos.ChequeaExplosion(i+x,j);
			}
			mira=2;
			break;

		case 2:
			if (falloCaso2==1 || !laberinto[i][j-x]->GetSePuedeRomper() && !laberinto[i][j-x]->GetSePuedePasar()) //si pasa una de las dos cosas estoy en muro
			{
				falloCaso2=1;
			}
			else if (laberinto[i][j-x]->GetSePuedeRomper() && falloCaso2==0)
			{
				delete laberinto[i][j-x];
				laberinto[i][j-x] = new Suelo;
				if (bonus.crearBonus())
					laberinto[i][j-x]->SetTieneBonus(true);
			}
			else if (falloCaso2==0 && personaje.GetInmunidad()==0)
			{
				//comprobacion que hace personaje para saber si pisa explosion
				personaje.ChequeaExplosion(i,j-x);
				//comprobacion que hace enemigo para saber si pisa explosion
				enemigos.ChequeaExplosion(i,j-x);
			}
			mira=3;
			break;

		case 3:
			if (falloCaso3==1 || !laberinto[i][j+x]->GetSePuedeRomper() && !laberinto[i][j+x]->GetSePuedePasar()) //si pasa una de las dos cosas estoy en muro
				{
					falloCaso3=1;
				}
			else if (laberinto[i][j+x]->GetSePuedeRomper() && falloCaso3==0)
			{
				delete laberinto[i][j+x];
				laberinto[i][j+x] = new Suelo;
				if (bonus.crearBonus())
					laberinto[i][j+x]->SetTieneBonus(true);
			}
			else if (falloCaso3==0 && personaje.GetInmunidad()==0)
			{
				//comprobacion que hace personaje para saber si pisa explosion
				personaje.ChequeaExplosion(i,j+x);
				//comprobacion que hace enemigo para saber si pisa explosion
				enemigos.ChequeaExplosion(i,j+x);
			}
			mira=4;
			break;
		}
	}while(mira!=4);
	}
}

int Tablero::compruebaLab(int x, int z)
{
	/*Devuelve:
		0-> Si no hay nada, hay suelo
		1-> Hay muro, bloque o bomba
		2-> Hay bonus
	*/
	
	if(!laberinto[x][z]->GetSePuedePasar()){
		return 1;
	}
	else{
		if(laberinto[x][z]->GetTieneBonus()){
			return 2;
		}
		return 0;
	}
}

void Tablero::Mueve()
{
	bonus.mueve();

	//Enemigo mueve
	for(int i=0; i<enemigos.GetNumeroEnemigos();i++){
		int p1,p2;  //esta es la posicion a la que queremos movernos en cada caso, la devuelve el enemigo
		enemigos.CalculaSiguiente(i);
		p1 = enemigos.GetPosicionSiguiente_x(i);
		p2 = enemigos.GetPosicionSiguiente_z(i);
		//si combrueba, mediante una lectura de laberinto, que podemos acceder a la casilla que pretendemos, el enemigo se movera.
		int comprobacion = compruebaLab(p1,p2);
		switch(comprobacion)
		{
			case 0: //pasa el enemigo
				enemigos.SetPosicion(i,p1,p2);
				break;	
			case 1://muro, bloque o bomba
				break;
			case 2://bonus

				break;
		}
	}
}

//Para el movimiendo del personaje
void Tablero::TeclaEspecial(unsigned char key)	
{
	int p1,p2;  //esta es la posicion a la que queremos movernos en cada caso, la devuelve el personaje
	personaje.CalculaSiguiente(key);
	p1 = personaje.GetPosicionSiguiente_x();
	p2 = personaje.GetPosicionSiguiente_z();
	
	//si combrueba, mediante una lectura de laberinto, que podemos acceder a la casilla que pretendemos, el personaje se movera.
	int comprobacion = compruebaLab(p1,p2);
	switch(comprobacion)
	{
		case 0: //pasa el personaje
			personaje.SetPosicion_x(p1);
			personaje.SetPosicion_z(p2);
			break;	
		case 1://muro, bloque o bomba
			break;
		case 2://bonus
			personaje.SetPosicion_x(p1);
			personaje.SetPosicion_z(p2);
			EfectoBonus();
			laberinto[p1][p2]->SetTieneBonus(false);
			break;
	}
}

void Tablero::PonerBomba()
{
	int i=personaje.GetPosicion_x();
	int j=personaje.GetPosicion_z();

	Bomba* bomba = new Bomba();
	if(bombas.Agregar(bomba,i,j))
	{
		bomba->SetPosicion(i, j);
		laberinto[i][j]->SetTieneBomba(true);
	}

}

void Tablero::EfectoBonus()
{

	int efecto = bonus.Efecto();
	bool moneda= ETSIDI::lanzaMoneda();
	switch (efecto)
	{
		case 0:
			bombas.SetTopeBombas(bombas.GetTopeBombas() + 1);
			break;	
		case 1:
			if(personaje.GetMiVida()<5)
			{
			personaje.SetMiVida(personaje.GetMiVida() + 1);
			}
			else
				if(moneda=true)
					bombas.SetTopeBombas(bombas.GetTopeBombas() + 1);
				else
					bombas.SetAlcance(bombas.GetAlcance() + 1);
			break;
		case 2:
			bombas.SetAlcance(bombas.GetAlcance() + 1);
			break;
	}
}

/////////SETs y Gets//////////

void Tablero::SetLaberinto(Celda ***lab){
	laberinto = lab;
}

Celda Tablero::GetLaberinto(){
	return ***laberinto;
}

void Tablero::SetFilas(int filas){
	numfilas = filas;
}

int Tablero::GetFilas(){
	return numfilas;
}

void Tablero::SetColumnas(int columnas){
	numcolumnas = columnas;
}

int Tablero::GetColumnas(){
	return numcolumnas;
}

int Tablero::GetMiVida(){
	return personaje.GetMiVida();
}

int Tablero::GetNumeroEnemigos(){
	return enemigos.GetNumeroEnemigos();
}

int Tablero::GetAlcance(){
	return bombas.GetAlcance();
}
int Tablero::GetMaxBomb(){
	return bombas.GetTopeBombas();
}


//////////////////////////////