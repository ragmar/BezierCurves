#pragma once
#include "punto.h"
#include "linea.h"
#include "Bresenham.h"


class Bezier{

	public:
		float color[3];
		float colorC[3];
		unsigned short raya;
		vector<point> B;
		unsigned int puntos;
		float traslacionV;
		float traslacionH;
		float rotacion;
		float escalamiento;
		point Aux1,Aux2;
		bool primera;
		vector<point> aux;
		bool estado;

		Bezier(bool modo,float r,float g,float b,unsigned short raya){
			this->puntos=1;
			B.resize(puntos);
			InicializarPuntos(puntos);
			color[0]=r;
			color[1]=g;
			color[2]=b;
			colorC[0]=1.0f;
			colorC[1]=0.0f;
			colorC[2]=0.0f;
			this->raya=0xFFFF;
			traslacionV=0.0f;
			traslacionH=0.0f;
			rotacion=0.0f;
			escalamiento=1.0f;
			estado=true;
		};

		void InicializarPuntos(int puntos){
			for(int i=0;i<puntos;i++){
				B[i].x=0;
				B[i].y=0;
			}

		};
		int PuntoTomado(float x,float y){
			for(unsigned char i=0;i<B.size();i++){
				if(x>B[i].x-0.015f&&x<B[i].x+0.015f){
					if(y>B[i].y-0.015f&&y<B[i].y+0.015f){
						return i+1;
					}
				}
			
			}
			return 0;
		}
		void modificarPunto(float x,float y,int pos){
			B[pos-1].x=x;
			B[pos-1].y=y;
		}
		void agregarPunto(float x,float y){
			point P;
			P.x=x;
			P.y=y;
			B.push_back(P);
			puntos++;
		}
		void eliminarPunto(){
			B.pop_back();
			puntos--;
		}

		point MedioFigura(){
			float xmin=1.0f,ymin=1.0f,xmax=-1.0f,ymax=-1.0f;
			for(int i=0;i<(int)puntos;i++){
				if(xmin>B[i].x) xmin=B[i].x;
				if(ymin>B[i].y) ymin=B[i].y;
				if(xmax<B[i].x) xmax=B[i].x;
				if(ymax<B[i].y) ymax=B[i].y;
			}


			point A;
			A.x=(xmin+xmax)/2;
			A.y=(ymin+ymax)/2;
			return A;
		}


		void Algoritmo(int puntos){
			float t=0;
			point PM;
			PM=MedioFigura();
			
			for(t=0;t<1;t+=0.01f){
				for(int i=0;i<puntos;i++){
					aux[i]=B[i];
				}
				Casteljaw(puntos,t,PM);
			}		
			DrawLine(Aux1.x,Aux1.y,aux[puntos-1].x,aux[puntos-1].y,0xFFFF,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
		};

		void Casteljaw(int puntos,float step,point PM){
			if(puntos<=1){
				Aux1=Aux2;
				Aux2=aux[0];
				if(primera){
					DrawLine(Aux1.x,Aux1.y,Aux2.x,Aux2.y,0xFFFF,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
				}
				primera=true;
			}else{
				for(int i=0;i<puntos-1;i++){
					aux[i].x=(1.0f-step)*aux[i].x+step*aux[i+1].x;
					aux[i].y=(1.0f-step)*aux[i].y+step*aux[i+1].y;
				}
				Casteljaw(puntos-1,step,PM);
			}
		}

		void Setcolor(float r,float g,float b){
			color[0]=r;
			color[1]=g;
			color[2]=b;
		}

		void Setcolorcontrol(float r,float g,float b){
			colorC[0]=r;
			colorC[1]=g;
			colorC[2]=b;
		}

		void cambiarEstado(){
			estado=false;
		}
		unsigned int NumPuntos(){
			return puntos;
		}

		void setTransformacion(float rotacion,float traslacionV, float traslacionH, float escalamiento){
			this->rotacion=rotacion;
			this->traslacionV=traslacionV;
			this->traslacionH=traslacionH;
			this->escalamiento=escalamiento;
		};


		void Pintar(){
			aux.clear();
			aux.resize(puntos);
			primera=false;
			Aux2=B[0];
			glPointSize(escalamiento);
			glColor3f(color[0],color[1],color[2]);
			glBegin(GL_POINTS);
				Algoritmo(puntos);
			glEnd();
			if(estado){//modo edicion
				glPointSize(10.0f);
				glColor3f(colorC[0],colorC[1],colorC[2]);
				glBegin(GL_POINTS);
				for(unsigned int i=0;i<puntos;i++){
					WritePixel(B[i].x,B[i].y,0,0,0,1,B[i].x,B[i].y);
				}
				glEnd();
			}
		};

		~Bezier(){
			B.clear();
			aux.clear();
		};

};