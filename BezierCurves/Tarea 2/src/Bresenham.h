#pragma once

#include <math.h>
#define PI 3.14159265


void WritePixel(float x,float y,float rotacion,float traslacionH,float traslacionV,float escalamiento, float Xc, float Yc){//dibujo pixel

	x=x-Xc;
	y=y-Yc;

	x=x*escalamiento;	
	y=y*escalamiento;
	float auxx=x;
	float auxy=y;

	x=(float)auxx*(float)cos(rotacion*PI/180)-(float)auxy*(float)sin(rotacion*PI/180);
	y=(float)auxx*(float)sin(rotacion*PI/180)+(float)auxy*(float)cos(rotacion*PI/180);

	x=x+Xc;
	y=y+Yc;

	x=x+traslacionH;
	y=y+traslacionV;

	glVertex2f(x,y);
};

void HorizonLine(float xmin,float xmax,float y,float cx,float cy,float rotacion,float desH,float desV,float escalamiento, float Xc, float Yc){
	while(xmin<xmax){
		WritePixel(cx+xmin,cy+y,rotacion,desH,desV,escalamiento,Xc,Yc);
		xmin+=0.0001f;
	}

}

void DrawHorizonLine(float ini,float fin, float y,float rotacion,float desH,float desV,float escalamiento, float Xc, float Yc){
	for(float i=ini; i<fin-0.001f;i+=0.001f){
		WritePixel(i,y,rotacion,desH,desV,escalamiento,Xc,Yc);
	}
}

void Draw8Pixels(float x,float y,float cx, float cy,bool modo,unsigned short raya,int cont,float *colorB,float rotacion,float desH,float desV,float escalamiento, float Xc, float Yc){//dibujo 8 pixeles en los distintos cuadrantes
	if((raya==0xFFFF)||(raya==0xF0F0&&cont%300<150)||(raya==0x2727&&(cont%500<150||cont%500==300))){
			glColor3f(colorB[0],colorB[1],colorB[2]);
			WritePixel(cx+x,cy+y,rotacion,desH,desV,escalamiento,Xc,Yc);
			WritePixel(cx-x,cy+y,rotacion,desH,desV,escalamiento,Xc,Yc);
			WritePixel(cx+x,cy-y,rotacion,desH,desV,escalamiento,Xc,Yc);
			WritePixel(cx-x,cy-y,rotacion,desH,desV,escalamiento,Xc,Yc);
			WritePixel(cx+y,cy+x,rotacion,desH,desV,escalamiento,Xc,Yc);
			WritePixel(cx-y,cy+x,rotacion,desH,desV,escalamiento,Xc,Yc);
			WritePixel(cx+y,cy-x,rotacion,desH,desV,escalamiento,Xc,Yc);
			WritePixel(cx-y,cy-x,rotacion,desH,desV,escalamiento,Xc,Yc);
	}
};

void Draw4Pixels(float x,float y,float cx,float cy,bool modo,float *colorB,float rotacion,float desH,float desV,float escalamiento, float Xc, float Yc){//dibujo 4 pixeles en los distintos cuadrantes

		glColor3f(colorB[0],colorB[1],colorB[2]);
		WritePixel(cx+x,cy+y,rotacion,desH,desV,escalamiento,Xc,Yc);
		WritePixel(cx-x,cy+y,rotacion,desH,desV,escalamiento,Xc,Yc);
		WritePixel(cx+x,cy-y,rotacion,desH,desV,escalamiento,Xc,Yc);
		WritePixel(cx-x,cy-y,rotacion,desH,desV,escalamiento,Xc,Yc);
}

void DrawLine(float x0,float y0,float x1,float y1,unsigned short raya,float rotacion,float desH,float desV,float escalamiento, float Xc, float Yc){//realizo una linea con el algoritmo del punto medio
	glBegin(GL_POINTS);
		int cont=0;
		float aux;
		bool negy=false;
		if(x0>x1){
			aux=x0;
			x0=x1;
			x1=aux;
			aux=y0;
			y0=y1;
			y1=aux;
		}
		float xc=x0,yc=y0;
		x0=0;
		y0=0;
		x1=x1-xc;
		y1=y1-yc;
		if(y1<0){
			y1=-y1;
			negy=true;
		}
		float dx=abs(x1-x0),dy=abs(y1-y0);
		float x,y;
		
		x=x0;y=y0;
		if(negy){
			if((raya==0xFFFF)||(raya==0xF0F0&&cont%300<150)||(raya==0x2727&&(cont%500<150||cont%500==300))){
				WritePixel(x+xc,-y+yc,rotacion,desH,desV,escalamiento,Xc,Yc);
			}
			
		}else{
			if((raya==0xFFFF)||(raya==0xF0F0&&cont%300<150)||(raya==0x2727&&(cont%500<150||cont%500==300))){
				WritePixel(x+xc,y+yc,rotacion,desH,desV,escalamiento,Xc,Yc);
			}
		}
		cont++;
		if(x1>=y1||-x1>=y1){
			float d=dx+2*dy;
			float IncE=-2*dy;
			float IncNE=-2*(dy-dx);
			while(x<x1){
				x=x+0.0001f;
				if(d>=0){
					d=d+IncE;
				}else{
					y=y+0.0001f;
					d=d+IncNE;
				}
				if(negy){
					if((raya==0xFFFF)||(raya==0xF0F0&&cont%300<150)||(raya==0x2727&&(cont%500<150||cont%500==300))){
						WritePixel(x+xc,-y+yc,rotacion,desH,desV,escalamiento,Xc,Yc);
					}
				}else{
					if((raya==0xFFFF)||(raya==0xF0F0&&cont%300<150)||(raya==0x2727&&(cont%500<150||cont%500==300))){
						WritePixel(x+xc,y+yc,rotacion,desH,desV,escalamiento,Xc,Yc);
					}
				}
				cont++;
			}
		}else{
			float d=dy+2*dx;
			float IncE=-2*dx;
			float IncNE=-2*(dx-dy);
			while(y<y1){
				y=y+0.0001f;
				if(d>=0)
					d=d+IncE;
				else{
					x=x+0.0001f;
					d=d+IncNE;
				}
				if(negy){
					if((raya==0xFFFF)||(raya==0xF0F0&&cont%300<150)||(raya==0x2727&&(cont%500<150||cont%500==300))){
						WritePixel(x+xc,-y+yc,rotacion,desH,desV,escalamiento,Xc,Yc);
					}
				}else{
					if((raya==0xFFFF)||(raya==0xF0F0&&cont%300<150)||(raya==0x2727&&(cont%500<150||cont%500==300))){
						WritePixel(x+xc,y+yc,rotacion,desH,desV,escalamiento,Xc,Yc);
					}
				}
				cont++;
			}
		}

	glEnd();
};
