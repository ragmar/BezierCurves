//algoritmos de pintar
//puntos

void PintarPunto(unsigned int pos){

	puntos[pos].Pintar();
}
//lineas
void PintarLinea(unsigned int pos){

	lineas[pos].Pintar();
}
//triangulos
void PintarTriangulo(unsigned int pos){

	triangulos[pos].Pintar();
}
//rectangulos
void PintarRectangulo(unsigned int pos){

	rectangulos[pos].Pintar();
}
//circulos
void PintarCirculo(unsigned int pos){

	circulos[pos].Pintar();
}
//elipses
void PintarElipse(unsigned int pos){

	elipses[pos].Pintar();
}
void PintarBezier(unsigned int pos){

	Beziers[pos].Pintar();

}
//transformaciones
void TransformacionFigura(int i,int Pos){
	point X;
	if(Dibujar[i].figura==0){
		X=puntos[Pos].MedioFigura();
		puntos[Pos].Setcolor(color[0],color[1],color[2]);
		puntos[Pos].setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);
	}
	if(Dibujar[i].figura==1){
		X=lineas[Pos].MedioFigura();
		lineas[Pos].Setraya(raya);
		lineas[Pos].Setcolor(color[0],color[1],color[2]);
		lineas[Pos].setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);
	}
	if(Dibujar[i].figura==2){
		X=triangulos[Pos].MedioFigura();
		triangulos[Pos].Setmodo(modo);
		triangulos[Pos].Setraya(raya);
		triangulos[Pos].Setcolor(color[0],color[1],color[2]);
		triangulos[Pos].SetcolorB(colorB[0],colorB[1],colorB[2]);
		triangulos[Pos].setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);
	}
	if(Dibujar[i].figura==3){
		X=rectangulos[Pos].MedioFigura();
		rectangulos[Pos].Setmodo(modo);
		rectangulos[Pos].Setraya(raya);
		rectangulos[Pos].Setcolor(color[0],color[1],color[2]);
		rectangulos[Pos].SetcolorB(colorB[0],colorB[1],colorB[2]);
		rectangulos[Pos].setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);
	}
	if(Dibujar[i].figura==4){
		X=circulos[Pos].MedioFigura();
		circulos[Pos].Setmodo(modo);
		circulos[Pos].Setraya(raya);
		circulos[Pos].Setcolor(color[0],color[1],color[2]);
		circulos[Pos].SetcolorB(colorB[0],colorB[1],colorB[2]);
		circulos[Pos].setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);
	}
	if(Dibujar[i].figura==5){
		X=elipses[Pos].MedioFigura();
		elipses[Pos].Setmodo(modo);
		elipses[Pos].Setraya(raya);
		elipses[Pos].Setcolor(color[0],color[1],color[2]);
		elipses[Pos].SetcolorB(colorB[0],colorB[1],colorB[2]);
		elipses[Pos].setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);
	}
	if(Dibujar[i].figura==6){
		X=Beziers[Pos].MedioFigura();
		Beziers[Pos].Setcolor(color[0],color[1],color[2]);
		Beziers[Pos].Setcolorcontrol(colorC[0],colorC[1],colorC[2]);
		Beziers[Pos].setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);
	}



}

void PintarFigura(){
	if(!Dibujar.empty()){
		for(unsigned int i=0;i<Dibujar.size();i++){
			glLoadIdentity();
			if(Dibujar.size()-1==i){
				TransformacionFigura(i,Dibujar[i].PosicionVector);
			}
			if(Dibujar[i].figura==0){
				PintarPunto(Dibujar[i].PosicionVector);
			}
			if(Dibujar[i].figura==1){
				PintarLinea(Dibujar[i].PosicionVector);
			}
			if(Dibujar[i].figura==2){
				PintarTriangulo(Dibujar[i].PosicionVector);
			}
			if(Dibujar[i].figura==3){
				PintarRectangulo(Dibujar[i].PosicionVector);
			}
			if(Dibujar[i].figura==4){
				PintarCirculo(Dibujar[i].PosicionVector);
			}
			if(Dibujar[i].figura==5){
				PintarElipse(Dibujar[i].PosicionVector);
			}
			if(Dibujar[i].figura==6){
				PintarBezier(Dibujar[i].PosicionVector);
			}
		}
	}
}