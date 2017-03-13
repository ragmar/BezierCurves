#pragma once

#include "Bresenham.h"

class circulo{
	public:
		point C;
		float radio;
		float color[3];
		float colorB[3];
		unsigned short raya;
		bool modo;//true primitiva false algoritmo
		float traslacionV;
		float traslacionH;
		float rotacion;
		float escalamiento;
		circulo(point c,point radio,bool modo,float r,float g,float b,unsigned short raya){
			C=c;
			this->radio=(radio.x-c.x)*(radio.x-c.x)+(radio.y-c.y)*(radio.y-c.y);
			this->radio=sqrt(this->radio);
			color[0]=r;
			color[1]=g;
			color[2]=b;
			this->raya=raya;
			this->modo=modo;
			traslacionV=0.0f;
			traslacionH=0.0f;
			rotacion=0.0f;
			escalamiento=1.0f;
		};

		void Setradio(float radio){
			this->radio=radio;
		}
		void Setcolor(float r,float g,float b){
			color[0]=r;
			color[1]=g;
			color[2]=b;
		}
		void SetcolorB(float r,float g,float b){
			colorB[0]=r;
			colorB[1]=g;
			colorB[2]=b;
		}
		void Setmodo(bool modo){
			this->modo=modo;

		};
		void Setraya(unsigned short raya){
			this->raya=raya;
		};

		point MedioFigura(){
			return C;
		}

		void setTransformacion(float rotacion,float traslacionV, float traslacionH, float escalamiento){
			this->rotacion=rotacion;
			this->traslacionV=traslacionV;
			this->traslacionH=traslacionH;
			this->escalamiento=escalamiento;
		};



		void Pintar(){
			float radio;
			point P;
			P=C;
			radio=this->radio*escalamiento;


			glPointSize(escalamiento);
			glBegin(GL_POINTS);
			glColor3f(color[0],color[1],color[2]);
			int cont=0;
			float x=0,auxX=-1,auxY=radio;
			float y=radio;
			float d=1-radio;
			Draw8Pixels(x,y,P.x,P.y,modo,raya,cont,colorB,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
			cont++;
			while(y>x){
				if(d<0){
					d=d+2.0f*x+0.0003f;
					x=x+0.0001f;
					if(modo){
						if(auxX+0.001f<x){
							glColor3f(color[0],color[1],color[2]);
							DrawHorizonLine(-y+0.002f+P.x,y-0.002f+P.x,-x+P.y,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
							DrawHorizonLine(-y+0.002f+P.x,y-0.002f+P.x,x+P.y,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
							auxX=x;
						}
					}
				}else{
					d=d+2.0f*(x-y)+0.0005f;
					y=y-0.0001f;
					x=x+0.0001f;
					if(modo){
						glColor3f(color[0],color[1],color[2]);
						if(auxY-0.001f>y){
							DrawHorizonLine(-x+0.002f+P.x,x-0.002f+P.x,y+P.y-0.002f,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
							DrawHorizonLine(-x+0.002f+P.x,x-0.002f+P.x,-y+P.y+0.002f,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
							auxY=y;
						}
						if(auxX+0.001f<x){
							DrawHorizonLine(-y+0.002f+P.x,y-0.002f+P.x,-x+P.y,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
							DrawHorizonLine(-y+0.002f+P.x,y-0.002f+P.x,x+P.y,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
							auxX=x;
						}
					}
				}
				Draw8Pixels(x,y,P.x,P.y,modo,raya,cont,colorB,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
				cont++;
			}
			glEnd();
		}
		~circulo(){};

};