#pragma once

#include "Bresenham.h"

class point{
	public:
		float x;
		float y;
		float color[3];
		float traslacionV;
		float traslacionH;
		float rotacion;
		float escalamiento;

		point(float x,float y,float r,float g,float b){
			this->x=x;
			this->y=y;
			color[0]=r;
			color[1]=g;
			color[2]=b;
			traslacionV=0.0f;
			traslacionH=0.0f;
			rotacion=0.0f;
			escalamiento=1.0f;
		};
		point(){
			x=0;
			y=0;
		};
		~point(){
		};
		void operator=(point punto){//igualo puntos
			x=punto.x;
			y=punto.y;
		};

		void operator*(point punto){
			x=x*punto.x;
			y=y*punto.y;
		};

		void operator+(point punto){
			x=x+punto.x;
			y=y+punto.y;
		};
		void operator-(point punto){
			x=x-punto.x;
			y=y-punto.y;
		};


		void setTransformacion(float rotacion,float traslacionV, float traslacionH, float escalamiento){
			this->rotacion=rotacion;
			this->traslacionV=traslacionV;
			this->traslacionH=traslacionH;
			this->escalamiento=escalamiento;
		};




		void Setcolor(float r,float g,float b){
			color[0]=r;
			color[1]=g;
			color[2]=b;
		}

		point MedioFigura(){
			point A;
			A.x=x;
			A.y=y;
			return A;
		}

		void Pintar(){
			point P; point PM;
			PM=this->MedioFigura();
			P.x=x;
			P.y=y;
			
			glColor3f(color[0],color[1],color[2]);

			glPointSize(escalamiento);
			glBegin(GL_POINTS);

				WritePixel(P.x,P.y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
			glEnd();
		};
};