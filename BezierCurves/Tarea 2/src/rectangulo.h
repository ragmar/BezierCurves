#pragma once
#include "Bresenham.h"

class rectangulo{
	public:
		point P1,P2;
		float color[3];
		float colorB[3];
		unsigned short raya;
		bool modo;//true primitiva false algoritmo
		float traslacionV;
		float traslacionH;
		float rotacion;
		float escalamiento;
		rectangulo(point p1,point p2,bool modo,float r,float g,float b,unsigned short raya){
			if(p1.x<p2.x){
				P1.x=p1.x;
				P2.x=p2.x;
			}else{
				P2.x=p1.x;
				P1.x=p2.x;
			}
			if(p1.y<p2.y){
				P1.y=p1.y;
				P2.y=p2.y;
			}else{
				P2.y=p1.y;
				P1.y=p2.y;
			}//reorganizo los puntos apra q siempre me qeuden de una manera
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

		void setTransformacion(float rotacion,float traslacionV, float traslacionH, float escalamiento){
			this->rotacion=rotacion;
			this->traslacionV=traslacionV;
			this->traslacionH=traslacionH;
			this->escalamiento=escalamiento;
		};

		point MedioFigura(){
		    point A;
			A.x=(P1.x+P2.x)/2;
			A.y=(P1.y+P2.y)/2;
			return A;
		}

		void Pintar(){
				point P1,P2,PM;
				P1=this->P1;
				P2=this->P2;
				PM=MedioFigura();

			int cont=0;
			point Paux;

			float y;


			glPointSize(escalamiento);


			glBegin(GL_POINTS);
					for(y=P1.y;y<=P2.y;y=y+0.001f){//hago dos fors pintando puntos para las lineas verticales y horizontales
						if(modo&&(y>P1.y+0.0025f)&&(y<=P2.y-0.0015f)){
							glColor3f(color[0],color[1],color[2]);
							DrawHorizonLine(P1.x+0.003f,P2.x-0.001f,y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
						}
						if((raya==0xFFFF)||(raya==0xF0F0&&cont%30<15)||(raya==0x2727&&(cont%50<15||cont%50==30))){
							glColor3f(colorB[0],colorB[1],colorB[2]);
							WritePixel(P1.x,y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
							WritePixel(P2.x,y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
						}
						cont++;
					}

					for(float x=P1.x;x<=P2.x;x=x+0.001f){
						if((raya==0xFFFF)||(raya==0xF0F0&&cont%30<15)||(raya==0x2727&&(cont%50<15||cont%50==30))){
							glColor3f(colorB[0],colorB[1],colorB[2]);
							WritePixel(x,P1.y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
							WritePixel(x,P2.y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
						}
						cont++;
					}
			
				glEnd();
			//}
		}
		~rectangulo(){};

};