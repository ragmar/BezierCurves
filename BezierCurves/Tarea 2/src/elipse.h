#pragma once
#include "Bresenham.h"

class elipse{
	public:
		point C;
		float rx,ry;
		float color[3];
		float colorB[3];
		unsigned short raya;
		bool modo;//true primitiva false algoritmo
		float traslacionV;
		float traslacionH;
		float rotacion;
		float escalamiento;
		elipse(point c,point radios,bool modo,float r,float g,float b,unsigned short raya){
			C=c;
			this->rx=sqrt((radios.x-c.x)*(radios.x-c.x));
			this->ry=sqrt((radios.y-c.y)*(radios.y-c.y));
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
		void Setradios(float radiox,float radioy){
			rx=radiox;
			ry=radioy;
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
			float rx,ry;
			point P;
			P=C;
			rx=this->rx*escalamiento;
			ry=this->ry*escalamiento;

			glPointSize(escalamiento);
			glBegin(GL_POINTS);
			int cont=0;
			float x,y,auxY=ry;
			float rx2,ry2;
			float d;
			rx2=rx*rx;
			ry2=ry*ry;
			x=0,y=ry;
			d=ry*(4*ry-4*rx2)+rx2;
			if((raya==0xFFFF)||(raya==0xF0F0&&cont%300<150)||(raya==0x2727&&(cont%500<150||cont%500==300))){
				Draw4Pixels(x,y,P.x,P.y,modo,colorB,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
			}

			cont++;
			while(ry2*x<rx2*y){
				if(d<0){
					d=d+(ry2*(2*x+0.0001f))*4;
					x=x+0.0001f;
				}else{
					d=d+(ry2*(2*x+0.0001f)-2*rx2*y)*4;
					y=y-0.0001f;
					x=x+0.0001f;
					if(modo){
						if(y<ry-0.0003f&&auxY-0.001f>y){
							glColor3f(color[0],color[1],color[2]);
							DrawHorizonLine(-x+0.002f+P.x,x-0.002f+P.x,y+P.y-0.002f,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
							DrawHorizonLine(-x+0.002f+P.x,x-0.002f+P.x,-y+P.y+0.002f,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
							auxY=y;
						}
					}
				}
				if((raya==0xFFFF)||(raya==0xF0F0&&cont%250<125)||(raya==0x2727&&(cont%500<150||cont%500==300))){
					Draw4Pixels(x,y,P.x,P.y,modo,colorB,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
				}
				cont++;
			}

			d=(ry2)*(x+0.00005f)*(x+0.00005f)+(rx2)*(y-0.0001f)*(y-0.0001f)-(rx2*ry2);
			while(y>0.0f){
				if(d<0){
					d=d+(rx2*(2*y+0.0003f))*4;
					y=y-0.0001f;
				}else{
					d=d+(rx2*(2*y+0.0003f)+ry2*(-2*x+0.0002f))*4;
					x=x+0.0001f;
					y=y-0.0001f;
				}

				if(modo){
					if(auxY-0.001f>y){
						glColor3f(color[0],color[1],color[2]);
						DrawHorizonLine(-x+0.002f+P.x,x-0.002f+P.x,y+P.y-0.002f,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
						DrawHorizonLine(-x+0.002f+P.x,x-0.002f+P.x,-y+P.y+0.002f,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
						auxY=y;
					}
				}

				if((raya==0xFFFF)||(raya==0xF0F0&&cont%250<125)||(raya==0x2727&&(cont%500<150||cont%500==300))){
					Draw4Pixels(x,y,P.x,P.y,modo,colorB,rotacion,traslacionH,traslacionV,escalamiento,C.x,C.y);
				}
				cont++;
			
			}
			glEnd();
		}
		~elipse(){};

};