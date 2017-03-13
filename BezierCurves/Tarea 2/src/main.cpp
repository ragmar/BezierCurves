#pragma comment (lib,"lib/freeglut.lib")//incluyo al libreria de free glut
#pragma comment (lib,"lib/AntTweakBar.lib")
#include "../tools/GL/freeglut.h"
#include "../tools/AntTweakBar/AntTweakBar.h"
#include <vector>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "punto.h"
#include "linea.h"
#include "triangulo.h"
#include "rectangulo.h"
#include "circulo.h"
#include "elipse.h"
#include "Bezier.h"

using namespace std;
char open[200];
char save[200];

short clic=0;
float color[3];//empieza en blanco
float colorB[3];
float colorC[3];
float colorLienzo[3];//empieza en negro
unsigned short raya=0xFFFF;//empieza continuo
int w=700;
int h=700;

float traslacionV=0.0f;
float traslacionH=0.0f;
float rotacion=0.0f;
float escalamiento=1.0f;


unsigned short dibujo=49;//empeiza haciendo un punto
bool modo=false;

struct Figura{
	int figura;
	unsigned int PosicionVector;
};
point clicks[3];
//vectores que almacenaran la informacion de los puntos
vector<point> puntos;
vector<linea> lineas;
vector<triangulo> triangulos;
vector<rectangulo> rectangulos;
vector<circulo>circulos;
vector<elipse>elipses;
vector<Bezier> Beziers;
vector<Figura> Dibujar;


#include "barras.h" //toda la informacion de anttweakbar
#include "Pintar.h" //todo lo que hago para pintar

void movimiento(int x,int y){
	if(!TwEventMouseMotionGLUT(x,y) ){
	}
	glutPostRedisplay();

}

void reinizializartransformacion(){

		escalamiento=1.0f;
		traslacionV=0.0f;
		traslacionH=0.0f;
		rotacion=0.0f;
}

void teclado(unsigned char key, int x, int y){
	if(	!TwEventKeyboardGLUT(key,x,y)){
	
	}
	glutPostRedisplay();
}

void teclado_especiales(int key, int x, int y){
	if(	!TwEventSpecialGLUT(key,x,y)){
	
	}
	glutPostRedisplay();
}


void renderScene(void) {//renderizar
	glEnable(GL_LINE_STIPPLE);//realiza el rayado interlineado y punteado
	glClearColor(colorLienzo[0],colorLienzo[1],colorLienzo[2],1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	PintarFigura();

	TwDraw();
	glutSwapBuffers();
}


void click_izquierdo(int boton, int estado, int x, int y) 
{
	float x1 =2.0f*(float)x/(float)w-1.0f;//redimenciono los puntos al tamaño de mi ventana
	float y1= - (2.0f*(float)y/h - 1.0f);
	if( !TwEventMouseButtonGLUT(boton,estado,x,y) )  // send event to AntTweakBar
	{

		Figura Fig;

		if((estado == GLUT_DOWN)&&(boton== GLUT_LEFT_BUTTON)&&(dibujo==49)){//puntos
			point P(x1,y1,color[0],color[1],color[2]);
			puntos.push_back(P);
			Fig.figura=0;
			Fig.PosicionVector=puntos.size()-1;
			Dibujar.push_back(Fig);
			TwDefine("Opciones/Transformacion  readonly=false \n");
			reinizializartransformacion();

		}
		if(dibujo==50){//lineas
			if((estado == GLUT_DOWN)&&(boton== GLUT_LEFT_BUTTON)){
				clicks[clic].x=x1;
				clicks[clic].y=y1;
				clic++;
				if((clic==2)){
						linea L(clicks[0],clicks[1],modo,color[0],color[1],color[2],raya);
						lineas.push_back(L);
						Fig.figura=1;
						Fig.PosicionVector=lineas.size()-1;
						Dibujar.push_back(Fig);
						TwDefine("Opciones/Transformacion  readonly=false \n");
						reinizializartransformacion();
				}
			}
			if(clic==2) clic=0;
		}
		if(dibujo==52){//triangulos
			if((estado == GLUT_DOWN)&&(boton== GLUT_LEFT_BUTTON)){
				clicks[clic].x=x1;
				clicks[clic].y=y1;
				clic++;
				if((clic==3)){
/*						point P0,P1,P2;
						P0.x=0.5f; P0.y=0.5f;
						P1.x=-0.5f; P1.y=0.5f; 
						P2.x=0.5f; P2.y=0.0f;
						triangulo T(P0,P1,P2,modo,color[0],color[1],color[2],raya);*/
						triangulo T(clicks[0],clicks[1],clicks[2],modo,color[0],color[1],color[2],raya);
						triangulos.push_back(T);
						Fig.figura=2;
						Fig.PosicionVector=triangulos.size()-1;
						Dibujar.push_back(Fig);
						TwDefine("Opciones/Transformacion  readonly=false \n");
						reinizializartransformacion();
					
				}
			}
			if(clic==3) clic=0;
		
		}
		if(dibujo==54){//rectangulos
			if((estado == GLUT_DOWN)&&(boton== GLUT_LEFT_BUTTON)){
				clicks[clic].x=x1;
				clicks[clic].y=y1;
				clic++;
				if((clic==2)){
						rectangulo R(clicks[0],clicks[1],modo,color[0],color[1],color[2],raya);
						rectangulos.push_back(R);
						Fig.figura=3;
						Fig.PosicionVector=rectangulos.size()-1;
						Dibujar.push_back(Fig);
						TwDefine("Opciones/Transformacion  readonly=false \n");
						reinizializartransformacion();
				}
			}
			if(clic==2) clic=0;
		
		}
		if(dibujo==56){//circulos
			if((estado == GLUT_DOWN)&&(boton== GLUT_LEFT_BUTTON)){
				clicks[clic].x=x1;
				clicks[clic].y=y1;
				clic++;
				if((clic==2)){
					circulo C(clicks[0],clicks[1],modo,color[0],color[1],color[2],raya);
					circulos.push_back(C);
					Fig.figura=4;
					Fig.PosicionVector=circulos.size()-1;
					Dibujar.push_back(Fig);
					TwDefine("Opciones/Transformacion  readonly=false \n");
					reinizializartransformacion();
				}
			}
			if(clic==2) clic=0;
		
		}
		if(dibujo==57){//elipses
			if((estado == GLUT_DOWN)&&(boton== GLUT_LEFT_BUTTON)){
				clicks[clic].x=x1;
				clicks[clic].y=y1;
				clic++;
				if((clic==2)){
					elipse E(clicks[0],clicks[1],modo,color[0],color[1],color[2],raya);
					elipses.push_back(E);
					Fig.figura=5;
					Fig.PosicionVector=elipses.size()-1;
					Dibujar.push_back(Fig);
					TwDefine("Opciones/Transformacion  readonly=false \n");
					reinizializartransformacion();
				}
			}
			if(clic==2) clic=0;
		
		}
		if(dibujo==58){
			if(estado == GLUT_DOWN && boton == GLUT_LEFT_BUTTON){
				if(clic==0){
					clic=Beziers[Beziers.size()-1].PuntoTomado(x1,y1);
				}else{
					Beziers[Beziers.size()-1].modificarPunto(x1,y1,clic);
					clic=0;
				}
			}
		}
	}
	glutPostRedisplay();
}

void reshape(int w1, int h1){//redimensiono la pantalla
	w=w1;
	h=h1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,w,h);
	glOrtho(-1.0, 1.0,-1.0, 1.0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	TwWindowSize(w, h);
}


//Main Principal
int main(int argc, char *argv[])
{
	color[0]=1.0f; color[1]=1.0f;	color[2]=1.0f;
	colorC[0]=1.0f; colorC[1]=0.0f;	colorC[2]=0.0f;
	colorB[0]=1.0f;	colorB[1]=1.0f;	colorB[2]=1.0f;
	colorLienzo[0]=0.0f; colorLienzo[1]=0.0f;colorLienzo[2]=0.0f;
	strcpy_s(open,"42");
	strcpy_s(save,"42");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(w,h);
	glutCreateWindow("Tarea 2");

	glOrtho(-1.0, 1.0,-1.0, 1.0, 0, 1);

	glutDisplayFunc(renderScene);
	glutMouseFunc(click_izquierdo);
	glutMotionFunc(movimiento);//para mover el mouse con AntTweakBar fluidamente
	glutKeyboardFunc(teclado);//para usar el teclado con AntTweakBar fluidamente
	glutSpecialFunc(teclado_especiales);
	glutReshapeFunc(reshape);

	//AntTweakBar
	AntTweakMain();
	glutMainLoop();
}
