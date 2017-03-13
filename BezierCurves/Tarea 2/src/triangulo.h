#pragma once
#include "Bresenham.h"

class triangulo{
	public:
		point P0,P1,P2;
		float color[3];
		float colorB[3];
		unsigned short raya;
		bool modo;//true primitiva false algoritmo
		float traslacionV;
		float traslacionH;
		float rotacion;
		float escalamiento;

		triangulo(point p0,point p1,point p2,bool modo,float r,float g,float b,unsigned short raya){
			P0=p0;
			P1=p1;
			P2=p2;
			color[0]=r;
			color[1]=g;
			color[2]=b;
			this->raya=raya;
			this->modo=modo;
			traslacionV=0.0f;
			traslacionH=0.0f;
			rotacion=0.0f;
			escalamiento=1.0f;
			ordenar();
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
		point MedioFigura(){
			float xmin=1.0f,ymin=1.0f,xmax=-1.0f,ymax=-1.0f;
			if(xmin>P0.x)	xmin=P0.x;
			if(xmin>P1.x)	xmin=P1.x;
			if(xmin>P2.x)	xmin=P2.x;

			if(xmax<P0.x)	xmax=P0.x;
			if(xmax<P1.x)	xmax=P1.x;
			if(xmax<P2.x)	xmax=P2.x;

			if(ymin>P0.y)	ymin=P0.y;
			if(ymin>P1.y)	ymin=P1.y;
			if(ymin>P2.y)	ymin=P2.y;

			if(ymax<P0.y)	ymax=P0.y;
			if(ymax<P1.y)	ymax=P1.y;
			if(ymax<P2.y)	ymax=P2.y;


			point A;
			A.x=(xmin+xmax)/2;
			A.y=(ymin+ymax)/2;
			return A;
		}
		void ordenar(){
			point Aux0,Aux1,Aux2;
			Aux0=P0;
			Aux1=P1;
			Aux2=P2;
			if(Aux0.y<=P0.y){
				Aux0=P0;
				Aux1=P1;
				Aux2=P2;
				if(Aux1.x>P1.x){
					Aux1=P1;
					Aux2=P2;
				}
				if(Aux1.x>P2.x){
					Aux1=P2;
					Aux2=P1;
				}
			}

			if(Aux0.y<=P1.y){
				Aux0=P1;
				Aux1=P0;
				Aux2=P2;
				if(Aux1.x>P0.x){
					Aux1=P0;
					Aux2=P2;
				}
				if(Aux1.x>P2.x){
					Aux1=P2;
					Aux2=P0;
				}
			}

			if(Aux0.y<=P2.y){
				Aux0=P2;
				Aux1=P0;
				Aux2=P1;
				if(Aux1.x>=P0.x){
					Aux1=P0;
					Aux2=P1;
				}
				if(Aux1.x>=P1.x){
					Aux1=P1;
					Aux2=P0;
				}
			}
			P0=Aux0;
			P1=Aux1;
			P2=Aux2;

			if(P1.x==P0.x){
				P0.x+=0.000001f;
			}
			if(P1.x==P2.x){
				P2.x+=0.000001f;
			}
			if(P0.x==P2.x){
				P2.x+=0.000001f;
			}
			if(P1.y==P0.y){
				P0.y+=0.000001f;
			}
			if(P1.y==P2.y){
				P2.y+=0.000001f;
			}
			if(P2.y==P0.y){
				P0.y+=0.000001f;
			}
		}

		void setTransformacion(float rotacion,float traslacionV, float traslacionH, float escalamiento){
			this->rotacion=rotacion;
			this->traslacionV=traslacionV;
			this->traslacionH=traslacionH;
			this->escalamiento=escalamiento;
		};
		
		void Pintar(){
			point P0,P1,P2,PM;
			P0=this->P0;
			P1=this->P1;
			P2=this->P2;

			PM=this->MedioFigura();


			if(modo){
				glColor3f(color[0],color[1],color[2]);
				glBegin(GL_POINTS);
				float m0,b0,m1,b1,m2,b2;
			
				m0=(P1.y-P0.y)/(P1.x-P0.x);
				b0=-P0.x*m0+P0.y;


				m1=(P2.y-P1.y)/(P2.x-P1.x);
				b1=-P1.x*m1+P1.y;
	

				m2=(P2.y-P0.y)/(P2.x-P0.x);
				b2=-P2.x*m2+P2.y;

				float y=0;

				if(P1.y<P2.y){
					for(y=P1.y+0.002f;y<P2.y-0.001f;y=y+0.001f){
						if((y-b0)/m0<(y-b1)/m1){
							DrawHorizonLine((y-b0)/m0+0.003f,(y-b1)/m1-0.002f,y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
						}else{
							DrawHorizonLine((y-b1)/m1+0.003f,(y-b0)/m0-0.002f,y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
						}
					}

					for(y=P2.y;y<P0.y-0.002f;y=y+0.001f){
						if((y-b0)/m0<(y-b2)/m2){
							DrawHorizonLine((y-b0)/m0+0.003f,(y-b2)/m2-0.002f,y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
						}else{
							DrawHorizonLine((y-b2)/m2+0.003f,(y-b0)/m0-0.002f,y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
						}
					}
				
				}else{
					for(y=P1.y-0.001f;y>P2.y+0.002f;y=y-0.001f){
						if((y-b1)/m1<(y-b2)/m2){
							DrawHorizonLine((y-b1)/m1+0.003f,(y-b2)/m2-0.003f,y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
						}else{
							DrawHorizonLine((y-b2)/m2+0.003f,(y-b1)/m1-0.003f,y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
						}
					}
					for(y=P1.y+0.001f;y<P0.y-0.002f;y=y+0.001f){
						if((y-b0)/m0<(y-b2)/m2){
							DrawHorizonLine((y-b0)/m0+0.003f,(y-b2)/m2-0.003f,y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
						}else{
							DrawHorizonLine((y-b2)/m2+0.003f,(y-b0)/m0-0.003f,y,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
						}
					}
				}
				glEnd();
			}
				glColor3f(colorB[0],colorB[1],colorB[2]);
				DrawLine(P0.x,P0.y,P2.x,P2.y,raya,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
				DrawLine(P1.x,P1.y,P2.x,P2.y,raya,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
				DrawLine(P0.x,P0.y,P1.x,P1.y,raya,rotacion,traslacionH,traslacionV,escalamiento,PM.x,PM.y);
			
		}
		~triangulo(){};

};