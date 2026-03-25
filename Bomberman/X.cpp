#include "X.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
using namespace std;

X::X(void)
{
}


X::~X(void)
{
}

void X::Dibuja()
{
	Celda::Dibuja();
	cout<<"Dibuja M"<<endl;

glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING); 
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Images/Muro.png").id);
	glTranslatef(2.5,2.5,2.5);
	glutSolidCube(lado);
	glTranslatef(-2.5, -2.5, -2.5);
	glBegin(GL_QUADS);
		// Frontal
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0,  lado);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( lado, 0,  lado);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( lado,  lado,  lado);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0,  lado,  0);	
		// Trasera
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0, 0);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0,  lado, 0);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( lado,  lado, 0);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( lado, 0, 0);	
		// Superior
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0,  lado, 0);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0,  lado,  lado);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( lado,  lado,  lado);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( lado,  lado, 0);	
		// Inferior
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 0, 0);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( lado, 0, 0);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( lado, 0,  lado);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0,  lado);	
		// Derecha face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( lado, 0, 0);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( lado,  lado, 0);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( lado,  lado,  lado);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( lado, 0,  lado);	
		// Izquierda Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0,  lado);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0,  lado,  lado);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0,  lado, 0);	
	glEnd();
	
	glDisable(GL_TEXTURE_2D);
}