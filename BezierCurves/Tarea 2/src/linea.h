#pragma once

#include "Bresenham.h"
using namespace std;


class linea{
	public:
		point P0,P1;
		float color[3];
		unsigned short raya;
		float traslacionV;
		float traslacionH;
		float rotacion;
		float escalamiento;
		linea(point p1,point p2,bool modo,float r,float g,float b,unsigned short raya){
			P0=p1;
			P1=p2;

			color[0]=r;
			color[1]=g;
			color[2]=b;
			this->raya=raya;
			traslacionV=0.0f;
			traslacionH=0.0f;
			rotacion=0.0f;
			escalamiento=1.0f;
		};
		void Setcolor(float r,float g,float b){
			color[0]=r;
			color[1]=g;
			color[2]=b;
		}

		void Setraya(unsigned short raya){
			this->raya=raya;
		};

		void setTransformacion(float rotacion,float traslacionV, float traslacionH, float escalamiento){
			this->rotacion=rotacion;
			this->traslacionV=traslacionV;
			this->traslacionH=traslacionH;
			this->escalamiento=escalamiento;
		};


		point MedioFigura(){
			point A;
			A.x=(P0.x+P1.x)/2;
			A.y=(P0.y+P1.y)/2;
			return A;
		}

		void Pintar(){
			glColor3f(color[0],color[1],color[2]);
			point P0,P1,PM;
			P0=this->P0;
			P1=this->P1;
			PM=MedioFigura();

			glPointSize(escalamiento);


				DrawLine(P0.x,P0.y,P1.x,P1.y,raya,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);		
		}

		~linea(){};

};