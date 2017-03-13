#pragma once



//Funciones de botones

void TW_CALL PressAgregar(void *clientData){
	Beziers[Beziers.size()-1].agregarPunto(0.0f,0.0f);
	TwDefine("Puntos/Eliminar readonly=false \n");
}

void TW_CALL PressEliminar(void *clientData){
	if(Beziers[Beziers.size()-1].NumPuntos()>1){
		Beziers[Beziers.size()-1].eliminarPunto();
	}
	if(Beziers[Beziers.size()-1].NumPuntos()==1){
		TwDefine("Puntos/Eliminar readonly=true \n");
	}

}

void TW_CALL PressFinalizar(void *clientData){
	TwRemoveAllVars(TwGetTopBar());
	TwBar *aux;
	aux=TwGetBottomBar();
	TwSetBottomBar(TwGetTopBar());
	TwSetTopBar(aux);

	TwDefine("Opciones visible=true \n"
			"Puntos visible=false \n"
			"Opciones/Punto  readonly=true \n"
			"Opciones/Linea  readonly=false \n"
			"Opciones/Triangulo  readonly=false \n"
			"Opciones/Rectangulo  readonly=false \n"
			"Opciones/Circulo  readonly=false \n"
			"Opciones/Elipse  readonly=false \n"
			"Opciones/Bezier  readonly=false \n");

	clic=0;
	dibujo=49;
	Beziers[Beziers.size()-1].cambiarEstado();
}

void BarraBezier(){
		TwAddButton(TwGetTopBar(),"Agregar",PressAgregar,NULL,"label=Agregar");
		TwAddButton(TwGetTopBar(),"Eliminar",PressEliminar,NULL,"label=Eliminar");
		TwAddButton(TwGetTopBar(),"Finalizar",PressFinalizar,NULL,"label=Finalizar");
		TwAddVarRW(TwGetTopBar(),"ColorC",TW_TYPE_COLOR3F,colorC, "label='Color Puntos' group=Estilo");
		TwAddVarRW(TwGetTopBar(),"ColorF",TW_TYPE_COLOR3F,color, "label='Color Figura' group=Estilo");


		TwDefine("Puntos alpha=255 \n " //la barra no es trasparente (opaca)
				"Puntos size='250 500' \n"//ajusto el tamaño de la barra
				"Puntos/Eliminar readonly=true \n"
				"Opciones visible=false \n"
				"Puntos visible=true \n"
		);

}

void TW_CALL pressPoint(void *clientData)
{ 
	TwDefine("Opciones/Punto  readonly=true \n"
		"Opciones/Linea  readonly=false \n"
		"Opciones/Triangulo  readonly=false \n"
		"Opciones/Rectangulo  readonly=false \n"
		"Opciones/Circulo  readonly=false \n"
		"Opciones/Elipse  readonly=false \n"
		"Opciones/Bezier  readonly=false \n");
	clic=0;
	dibujo=49;
}
void TW_CALL pressLine(void *clientData)
{ 
	TwDefine("Opciones/Punto  readonly=false \n"
		"Opciones/Linea  readonly=true \n"
		"Opciones/Triangulo  readonly=false \n"
		"Opciones/Rectangulo  readonly=false \n"
		"Opciones/Circulo  readonly=false \n"
		"Opciones/Elipse  readonly=false \n"
		"Opciones/Bezier  readonly=false \n");
	clic=0;
	dibujo=50;
}
void TW_CALL pressTriangle(void *clientData)
{ 
		TwDefine("Opciones/Punto  readonly=false \n"
		"Opciones/Linea  readonly=false \n"
		"Opciones/Triangulo  readonly=true \n"
		"Opciones/Rectangulo  readonly=false \n"
		"Opciones/Circulo  readonly=false \n"
		"Opciones/Elipse  readonly=false \n"
		"Opciones/Bezier  readonly=false \n");
	clic=0;
	dibujo=52;
}
void TW_CALL pressRectangle(void *clientData)
{ 
			TwDefine("Opciones/Punto  readonly=false \n"
		"Opciones/Linea  readonly=false \n"
		"Opciones/Triangulo  readonly=false \n"
		"Opciones/Rectangulo  readonly=true \n"
		"Opciones/Circulo  readonly=false \n"
		"Opciones/Elipse  readonly=false \n"
		"Opciones/Bezier  readonly=false \n");
	clic=0;
	dibujo=54;
}
void TW_CALL pressCircle(void *clientData)
{ 
			TwDefine("Opciones/Punto  readonly=false \n"
		"Opciones/Linea  readonly=false \n"
		"Opciones/Triangulo  readonly=false \n"
		"Opciones/Rectangulo  readonly=false \n"
		"Opciones/Circulo  readonly=true \n"
		"Opciones/Elipse  readonly=false \n"
		"Opciones/Bezier  readonly=false \n");
	clic=0;
	dibujo=56;
}
void TW_CALL pressEllipse(void *clientData)
{ 
	TwDefine("Opciones/Punto  readonly=false \n"
		"Opciones/Linea  readonly=false \n"
		"Opciones/Triangulo  readonly=false \n"
		"Opciones/Rectangulo  readonly=false \n"
		"Opciones/Circulo  readonly=false \n"
		"Opciones/Elipse  readonly=true \n"
		"Opciones/Bezier  readonly=false \n");
	clic=0;
	dibujo=57;
}
void TW_CALL pressBezier(void *clientData)
{ 

	Figura Fig;
	traslacionV=0;
	traslacionH=0;
	rotacion=0;
	escalamiento=1.0f;

	Bezier B(modo,color[0],color[1],color[2],raya);
	Beziers.push_back(B);
	Fig.figura=6;
	Fig.PosicionVector=Beziers.size()-1;
	Dibujar.push_back(Fig);
	TwDefine("Opciones/Transformacion  readonly=false \n");

	TwBar *aux;
	aux=TwGetBottomBar();
	TwSetBottomBar(TwGetTopBar());
	TwSetTopBar(aux);

	BarraBezier();


	clic=0;
	dibujo=58;
}
void TW_CALL pressContinuo(void *clientData)
{
	TwDefine("Opciones/Continuo  readonly=true \n"
		"Opciones/Discontinuo  readonly=false \n"
		"Opciones/Punto-Raya  readonly=false \n");
	raya=0xFFFF;
}
void TW_CALL pressDiscontinuo(void *clientData)
{ 
	TwDefine("Opciones/Continuo  readonly=false \n"
		"Opciones/Discontinuo  readonly=true \n"
		"Opciones/Punto-Raya  readonly=false \n");
	raya=0xF0F0;
}
void TW_CALL pressPuntoRaya(void *clientData)
{ 
	TwDefine("Opciones/Continuo  readonly=false \n"
		"Opciones/Discontinuo  readonly=false \n"
		"Opciones/Punto-Raya  readonly=true \n");
	raya=0x2727;
}
void TW_CALL pressModoR(void *clientData)
{ 
	TwDefine("Opciones/Relleno  readonly=true \n"
			"Opciones/Without  readonly=false \n"
			);
	modo=true;
}
void TW_CALL pressModoSR(void *clientData)
{ 
	TwDefine(" Opciones/Relleno  readonly=false \n"
	"Opciones/Without  readonly=true \n"
	);
	modo=false;
}



void TW_CALL pressClear(void *clientData)
{ 
	TwDefine("Opciones/Transformacion  readonly=true \n");
	traslacionV=0.0f;
	traslacionH=0.0f;
	rotacion=0.0f;
	escalamiento=1.0f;

	clic=0;
	puntos.clear();
	lineas.clear();
	triangulos.clear();
	rectangulos.clear();
	circulos.clear();
	elipses.clear();
	Beziers.clear();
	Dibujar.clear();
	glutPostRedisplay();
}

void TW_CALL pressOpen(void *clientData){
	FILE *Abrir;
	char abrir[90];
	strcpy_s(abrir,"../files/archivos/");
	strcat_s(abrir,open);
	strcat_s(abrir,".42");
	Abrir=fopen (abrir,"r");
	int figuras;

	if(Abrir){

		clic=0;
		puntos.clear();
		lineas.clear();
		triangulos.clear();
		rectangulos.clear();
		circulos.clear();
		elipses.clear();
		Beziers.clear();
		Dibujar.clear();

		fscanf_s (Abrir, "%f %f %f"
			"%d"
			, &colorLienzo[0],&colorLienzo[1],&colorLienzo[2]
			,&figuras);

		Figura Fig;
		for(int i=0;i<figuras;i++){
			fscanf_s (Abrir, "%d",&Fig.figura);
			if(Fig.figura==0){
				point P;
				fscanf_s (Abrir, "%f %f",&P.x,&P.y);
				fscanf_s (Abrir, "%f %f %f",&color[0],&color[1],&color[2]);
				fscanf_s (Abrir, "%f %f %f %f",&traslacionV,&traslacionH,&rotacion,&escalamiento);
				P.Setcolor(color[0],color[1],color[2]);
				P.setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);

				puntos.push_back(P);
				Fig.PosicionVector=puntos.size()-1;
			
			}
			if(Fig.figura==1){
				point P1,P2;
				fscanf_s (Abrir, "%f %f",&P1.x,&P1.y);
				fscanf_s (Abrir, "%f %f",&P2.x,&P2.y);
				fscanf_s (Abrir, "%x",&raya);
				fscanf_s (Abrir, "%f %f %f",&color[0],&color[1],&color[2]);
				fscanf_s (Abrir, "%f %f %f %f",&traslacionV,&traslacionH,&rotacion,&escalamiento);
				linea L(P1,P2,1,color[0],color[1],color[2],raya);
				L.setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);
				L.Setcolor(color[0],color[1],color[2]);
				lineas.push_back(L);
				Fig.PosicionVector=lineas.size()-1;

			}
			if(Fig.figura==2){
				point P1,P2,P3;
				fscanf_s (Abrir, "%f %f",&P1.x,&P1.y);
				fscanf_s (Abrir, "%f %f",&P2.x,&P2.y);
				fscanf_s (Abrir, "%f %f",&P3.x,&P3.y);
				fscanf_s (Abrir, "%x %d",&raya,&modo);
				fscanf_s (Abrir, "%f %f %f",&color[0],&color[1],&color[2]);
				fscanf_s (Abrir, "%f %f %f",&colorB[0],&colorB[1],&colorB[2]);
				fscanf_s (Abrir, "%f %f %f %f",&traslacionV,&traslacionH,&rotacion,&escalamiento);

				triangulo T(P1,P2,P3,1,color[0],color[1],color[2],raya);
				T.setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);
				T.Setmodo(modo);
				T.Setcolor(color[0],color[1],color[2]);
				T.SetcolorB(colorB[0],colorB[1],colorB[2]);
				triangulos.push_back(T);

				Fig.PosicionVector=triangulos.size()-1;
			
			}
			if(Fig.figura==3){
				point P1,P2;
				fscanf_s (Abrir, "%f %f",&P1.x,&P1.y);
				fscanf_s (Abrir, "%f %f",&P2.x,&P2.y);
				fscanf_s (Abrir, "%x %d",&raya,&modo);
				fscanf_s (Abrir, "%f %f %f",&color[0],&color[1],&color[2]);
				fscanf_s (Abrir, "%f %f %f",&colorB[0],&colorB[1],&colorB[2]);
				fscanf_s (Abrir, "%f %f %f %f",&traslacionV,&traslacionH,&rotacion,&escalamiento);

				rectangulo R(P1,P2,1,color[0],color[1],color[2],raya);
				R.setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);
				R.Setmodo(modo);
				R.Setcolor(color[0],color[1],color[2]);
				R.SetcolorB(colorB[0],colorB[1],colorB[2]);
				rectangulos.push_back(R);

				Fig.PosicionVector=rectangulos.size()-1;
			
			}
			if(Fig.figura==4){
				point Centro,P;
				float radio;
				fscanf_s (Abrir, "%f %f %f",&Centro.x,&Centro.y,&radio);
				fscanf_s (Abrir, "%x %d",&raya,&modo);
				fscanf_s (Abrir, "%f %f %f",&color[0],&color[1],&color[2]);
				fscanf_s (Abrir, "%f %f %f",&colorB[0],&colorB[1],&colorB[2]);
				fscanf_s (Abrir, "%f %f %f %f",&traslacionV,&traslacionH,&rotacion,&escalamiento);

				circulo C(Centro,P,1,color[0],color[1],color[2],raya);
				C.setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);
				C.Setradio(radio);
				C.Setmodo(modo);
				C.Setcolor(color[0],color[1],color[2]);
				C.SetcolorB(colorB[0],colorB[1],colorB[2]);
				circulos.push_back(C);


				Fig.PosicionVector=circulos.size()-1;
			
			}
			if(Fig.figura==5){
				point Centro,P;
				float radiox,radioy;
				fscanf_s (Abrir, "%f %f %f %f",&Centro.x,&Centro.y,&radiox,&radioy);
				fscanf_s (Abrir, "%x %d",&raya,&modo);
				fscanf_s (Abrir, "%f %f %f",&color[0],&color[1],&color[2]);
				fscanf_s (Abrir, "%f %f %f",&colorB[0],&colorB[1],&colorB[2]);
				fscanf_s (Abrir, "%f %f %f %f",&traslacionV,&traslacionH,&rotacion,&escalamiento);

				elipse E(Centro,P,1,color[0],color[1],color[2],raya);
				E.setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);
				E.Setradios(radiox,radioy);
				E.Setmodo(modo);
				E.Setcolor(color[0],color[1],color[2]);
				E.SetcolorB(colorB[0],colorB[1],colorB[2]);
				elipses.push_back(E);

				Fig.PosicionVector=elipses.size()-1;
			
			}
			if(Fig.figura==6){
				int puntos;
				point P;
				Bezier B(0,1,1,1,0xFFFF);
				B.estado=false;
				B.puntos=0;
				B.B.clear();
				fscanf_s (Abrir, "%d",&puntos);
				for(int i=0;i<puntos;i++){
					fscanf_s (Abrir, "%f %f",&P.x,&P.y);
					B.agregarPunto(P.x,P.y);
				}
				fscanf_s (Abrir, "%f %f %f",&color[0],&color[1],&color[2]);
				fscanf_s (Abrir, "%f %f %f %f",&traslacionV,&traslacionH,&rotacion,&escalamiento);
				B.Setcolor(color[0],color[1],color[2]);
				B.setTransformacion(rotacion,traslacionV,traslacionH,escalamiento);
				Beziers.push_back(B);
				Fig.PosicionVector=Beziers.size()-1;
			
			}

			Dibujar.push_back(Fig);
			
		
		}

		fclose(Abrir);
	}

	glutPostRedisplay();
	TwDefine(
		"Opciones/Punto  readonly=true \n"
		"Opciones/Linea  readonly=false \n"
		"Opciones/Triangulo  readonly=false \n"
		"Opciones/Rectangulo  readonly=false \n"
		"Opciones/Circulo  readonly=false \n"
		"Opciones/Elipse  readonly=false \n"
		"Opciones/Bezier  readonly=false \n"
		"Opciones/Transformacion  readonly=true \n"
		);
	if(modo){
		TwDefine(
		"Opciones/Relleno readonly=true \n"
		"Opciones/Without readonly=false \n"
		);
	}else{
		TwDefine(
		"Opciones/Relleno readonly=false \n"
		"Opciones/Without readonly=true \n"
		);
	}
	if(raya==0xFFFF){
		TwDefine(
		"Opciones/Continuo readonly=true \n"
		"Opciones/Discontinuo readonly=false \n"
		"Opciones/Punto-Raya readonly=false \n"
		);
	}else if(raya==0xF0F0){
			TwDefine(
		"Opciones/Continuo readonly=false \n"
		"Opciones/Discontinuo readonly=true \n"
		"Opciones/Punto-Raya readonly=false \n"
		);
	}else{
		TwDefine(
		"Opciones/Continuo readonly=false \n"
		"Opciones/Discontinuo readonly=false \n"
		"Opciones/Punto-Raya readonly=true \n"
		);
	}

	clic=0;
	dibujo=49;
}

void TW_CALL pressSave(void *clientData){
	FILE * Abrir;
	char salvar[90];
	strcpy_s(salvar,"../files/archivos/");
	strcat_s(salvar,save);
	strcat_s(salvar,".42");
	Abrir=fopen (salvar,"w");
	if(Abrir){
		fprintf(Abrir,"%f %f %f\n",colorLienzo[0],colorLienzo[1],colorLienzo[2]);
		fprintf(Abrir,"%i\n",Dibujar.size());
		for(unsigned int i=0;i<Dibujar.size();i++){
			if(Dibujar[i].figura==0){
				fprintf(Abrir,"0\n"//tipo figura
					"%f %f\n"//x y
					"%f %f %f\n"//color
					"%f %f %f %f\n" //traslacionV,traslacionH, rotacion,escalamiento
					,puntos[Dibujar[i].PosicionVector].x,puntos[Dibujar[i].PosicionVector].y
					,puntos[Dibujar[i].PosicionVector].color[0],puntos[Dibujar[i].PosicionVector].color[1],puntos[Dibujar[i].PosicionVector].color[2]
					,puntos[Dibujar[i].PosicionVector].traslacionV,puntos[Dibujar[i].PosicionVector].traslacionH,puntos[Dibujar[i].PosicionVector].rotacion,puntos[Dibujar[i].PosicionVector].escalamiento
					);
				
			}

			if(Dibujar[i].figura==1){
				fprintf(Abrir,"1\n"//tipo figura
					"%f %f\n"//x0 y0
					"%f %f\n"//x1 1
					"%x\n"//raya
					"%f %f %f\n"//color
					"%f %f %f %f\n" //traslacionV,traslacionH, rotacion,escalamiento
					,lineas[Dibujar[i].PosicionVector].P0.x,lineas[Dibujar[i].PosicionVector].P0.y
					,lineas[Dibujar[i].PosicionVector].P1.x,lineas[Dibujar[i].PosicionVector].P1.y
					,lineas[Dibujar[i].PosicionVector].raya
					,lineas[Dibujar[i].PosicionVector].color[0],lineas[Dibujar[i].PosicionVector].color[1],lineas[Dibujar[i].PosicionVector].color[2]
					,lineas[Dibujar[i].PosicionVector].traslacionV,lineas[Dibujar[i].PosicionVector].traslacionH,lineas[Dibujar[i].PosicionVector].rotacion,lineas[Dibujar[i].PosicionVector].escalamiento
					);

			}

			if(Dibujar[i].figura==2){
				fprintf(Abrir,"2\n"//tipo figura
					"%f %f\n"//x0 y0
					"%f %f\n"//x1 y1
					"%f %f\n"//x2 y2
					"%x %d\n"//raya modo
					"%f %f %f\n"//color
					"%f %f %f\n"//color B
					"%f %f %f %f\n" //traslacionV,traslacionH, rotacion,escalamiento
					,triangulos[Dibujar[i].PosicionVector].P0.x,triangulos[Dibujar[i].PosicionVector].P0.y
					,triangulos[Dibujar[i].PosicionVector].P1.x,triangulos[Dibujar[i].PosicionVector].P1.y
					,triangulos[Dibujar[i].PosicionVector].P2.x,triangulos[Dibujar[i].PosicionVector].P2.y
					,triangulos[Dibujar[i].PosicionVector].raya,triangulos[Dibujar[i].PosicionVector].modo
					,triangulos[Dibujar[i].PosicionVector].color[0],triangulos[Dibujar[i].PosicionVector].color[1],triangulos[Dibujar[i].PosicionVector].color[2]
					,triangulos[Dibujar[i].PosicionVector].colorB[0],triangulos[Dibujar[i].PosicionVector].colorB[1],triangulos[Dibujar[i].PosicionVector].colorB[2]
					,triangulos[Dibujar[i].PosicionVector].traslacionV,triangulos[Dibujar[i].PosicionVector].traslacionH,triangulos[Dibujar[i].PosicionVector].rotacion,triangulos[Dibujar[i].PosicionVector].escalamiento
					);

			
			}
			if(Dibujar[i].figura==3){
				fprintf(Abrir,"3\n"//tipo figura
					"%f %f\n"//x1 y1
					"%f %f\n"//x2 y2
					"%x %d\n"//raya modo
					"%f %f %f\n"//color
					"%f %f %f\n"//colorB
					"%f %f %f %f\n" //traslacionV,traslacionH, rotacion,escalamiento
					,rectangulos[Dibujar[i].PosicionVector].P1.x,rectangulos[Dibujar[i].PosicionVector].P1.y
					,rectangulos[Dibujar[i].PosicionVector].P2.x,rectangulos[Dibujar[i].PosicionVector].P2.y
					,rectangulos[Dibujar[i].PosicionVector].raya,rectangulos[Dibujar[i].PosicionVector].modo
					,rectangulos[Dibujar[i].PosicionVector].color[0],rectangulos[Dibujar[i].PosicionVector].color[1],rectangulos[Dibujar[i].PosicionVector].color[2]
					,rectangulos[Dibujar[i].PosicionVector].colorB[0],rectangulos[Dibujar[i].PosicionVector].colorB[1],rectangulos[Dibujar[i].PosicionVector].colorB[2]
					,rectangulos[Dibujar[i].PosicionVector].traslacionV,rectangulos[Dibujar[i].PosicionVector].traslacionH,rectangulos[Dibujar[i].PosicionVector].rotacion,rectangulos[Dibujar[i].PosicionVector].escalamiento
					);
			}
			if(Dibujar[i].figura==4){
				fprintf(Abrir,"4\n"//tipo figura
					"%f %f %f\n"//cx cy radio
					"%x %d\n"//raya modo
					"%f %f %f\n"//color
					"%f %f %f\n"//colorB
					"%f %f %f %f\n" //traslacionV,traslacionH, rotacion,escalamiento
					,circulos[Dibujar[i].PosicionVector].C.x,circulos[Dibujar[i].PosicionVector].C.y,circulos[Dibujar[i].PosicionVector].radio
					,circulos[Dibujar[i].PosicionVector].raya,circulos[Dibujar[i].PosicionVector].modo
					,circulos[Dibujar[i].PosicionVector].color[0],circulos[Dibujar[i].PosicionVector].color[1],circulos[Dibujar[i].PosicionVector].color[2]
					,circulos[Dibujar[i].PosicionVector].colorB[0],circulos[Dibujar[i].PosicionVector].colorB[1],circulos[Dibujar[i].PosicionVector].colorB[2]
					,circulos[Dibujar[i].PosicionVector].traslacionV,circulos[Dibujar[i].PosicionVector].traslacionH,circulos[Dibujar[i].PosicionVector].rotacion,circulos[Dibujar[i].PosicionVector].escalamiento
					);
			
			}
			if(Dibujar[i].figura==5){
				fprintf(Abrir,"5\n"//tipo figura
					"%f %f %f %f\n"//cx cy radiox radioy
					"%x %d\n"//raya modo
					"%f %f %f\n"//color
					"%f %f %f\n"//colorB
					"%f %f %f %f\n" //traslacionV,traslacionH, rotacion,escalamiento
					,elipses[Dibujar[i].PosicionVector].C.x,elipses[Dibujar[i].PosicionVector].C.y,elipses[Dibujar[i].PosicionVector].rx,elipses[Dibujar[i].PosicionVector].ry
					,elipses[Dibujar[i].PosicionVector].raya,elipses[Dibujar[i].PosicionVector].modo
					,elipses[Dibujar[i].PosicionVector].color[0],elipses[Dibujar[i].PosicionVector].color[1],elipses[Dibujar[i].PosicionVector].color[2]
					,elipses[Dibujar[i].PosicionVector].colorB[0],elipses[Dibujar[i].PosicionVector].colorB[1],elipses[Dibujar[i].PosicionVector].colorB[2]
					,elipses[Dibujar[i].PosicionVector].traslacionV,elipses[Dibujar[i].PosicionVector].traslacionH,elipses[Dibujar[i].PosicionVector].rotacion,elipses[Dibujar[i].PosicionVector].escalamiento
					);
			
			}
			if(Dibujar[i].figura==6){
				fprintf(Abrir,"6\n%i\n"
					,Beziers[Dibujar[i].PosicionVector].puntos);//tipo figura

				for(unsigned int j=0;j<Beziers[Dibujar[i].PosicionVector].puntos;j++){
					fprintf(Abrir,"%f %f\n",Beziers[Dibujar[i].PosicionVector].B[j].x,Beziers[Dibujar[i].PosicionVector].B[j].y);

				}
				fprintf(Abrir,"%f %f %f\n"//color
					"%f %f %f %f\n" //traslacionV,traslacionH, rotacion,escalamiento
					,Beziers[Dibujar[i].PosicionVector].color[0],Beziers[Dibujar[i].PosicionVector].color[1],Beziers[Dibujar[i].PosicionVector].color[2]
					,Beziers[Dibujar[i].PosicionVector].traslacionV,Beziers[Dibujar[i].PosicionVector].traslacionH,Beziers[Dibujar[i].PosicionVector].rotacion,Beziers[Dibujar[i].PosicionVector].escalamiento
					);
			}
		}
		fclose (Abrir);		
	}
	glutPostRedisplay();
}

void TW_CALL pressExit(void *clientData)
{ 
	TwTerminate();
	exit(0);
}

void AntTweakMain(){
	TwInit(TW_OPENGL, NULL);
	TwWindowSize(w,h);
	glutPassiveMotionFunc((GLUTmousemotionfun)TwEventMouseMotionGLUT);
	TwGLUTModifiersFunc(glutGetModifiers);

	TwBar *myBar,*Control;
	myBar = TwNewBar("Opciones");
	Control = TwNewBar("Puntos");
	TwSetTopBar(myBar);
	TwSetBottomBar(Control);
	//Botones de Figura
	TwAddButton(myBar,"Punto", pressPoint,NULL,"label='Punto' group=Figura");
	TwAddButton(myBar,"Linea", pressLine,NULL,"label='Linea' group=Figura");
	TwAddButton(myBar,"Triangulo", pressTriangle,NULL,"label='Triangulo' group=Figura");
	TwAddButton(myBar,"Rectangulo", pressRectangle,NULL,"label='Rectangulo' group=Figura");
	TwAddButton(myBar,"Circulo", pressCircle,NULL,"label='Circulo' group=Figura");
	TwAddButton(myBar,"Elipse", pressEllipse,NULL,"label='Elipse' group=Figura");
	TwAddButton(myBar,"Bezier", pressBezier,NULL,"label='Curva de Bezier' group=Figura");

	TwAddSeparator(myBar, "FinDeOpciones",NULL);

	//Botones de Estilo de las figuras
	TwAddVarRW(myBar,"Color",TW_TYPE_COLOR3F,color, "label='Color Figura' group=Estilo");
	TwAddVarRW(myBar,"ColorB",TW_TYPE_COLOR3F,colorB, "label='Color Borde' group=Estilo");
	TwAddVarRW(myBar,"ColorL",TW_TYPE_COLOR3F,colorLienzo, "label='Color Lienzo' group=Estilo");
	TwAddButton(myBar,"Continuo", pressContinuo,NULL,"label='Continuo' group=Lineado");
	TwAddButton(myBar,"Discontinuo", pressDiscontinuo,NULL,"label='Discontinuo' group=Lineado");
	TwAddButton(myBar,"Punto-Raya", pressPuntoRaya,NULL,"label='Punto-raya' group=Lineado");
	TwAddButton(myBar,"Relleno", pressModoR,NULL,"label='Rellena' group=Modo");
	TwAddButton(myBar,"Without", pressModoSR,NULL,"label='Sin Relleno' group=Modo");

	TwAddSeparator(myBar, "FinDeEstilo",NULL);
	//Transformaciones
	TwAddVarRW(myBar,"Rotacion",TW_TYPE_FLOAT,&rotacion,"label='Rotacion' group=Transformacion min=0 max=360 step=1");
	TwAddVarRW(myBar,"TraslacionV",TW_TYPE_FLOAT,&traslacionV,"label='Traslacion Vertical' group=Transformacion step=0.01");
	TwAddVarRW(myBar,"TraslacionH",TW_TYPE_FLOAT,&traslacionH,"label='Traslacion Horizontal' group=Transformacion step=0.01");
	TwAddVarRW(myBar,"Escalamiento",TW_TYPE_FLOAT,&escalamiento,"label='Escalamiento' group=Transformacion min=0 step=0.01");

	TwAddSeparator(myBar, "FinDeTransformacion",NULL);

	//Botones de Salir, Abrir, Guardar y Limpiar
	TwAddButton(myBar,"Open", pressOpen,NULL,"label='Abrir' group=Abrir");
	TwAddVarRW(myBar,"AbrirN",TW_TYPE_CSSTRING(sizeof(open)),open,"label='Nombre' group=Abrir");
	TwAddSeparator(myBar, "Guar",NULL);
	TwAddButton(myBar,"Guardar", pressSave,NULL,"label='Guardar' group=Salvar");
	TwAddVarRW(myBar,"GuardarN",TW_TYPE_CSSTRING(sizeof(save)),save,"label='Nombre' group=Salvar");
	TwAddSeparator(myBar, "FIN",NULL);
	TwAddButton(myBar,"Limpiar", pressClear,NULL,"label='Limpiar'");
	TwAddButton(myBar,"Salir", pressExit,NULL,"label='Salir'");
	TwDefine( "GLOBAL contained=true \n" //las barras no saldra de la ventana
			"Puntos visible=false \n"
			"Opciones/Transformacion  readonly=true \n"
			"Opciones/Punto  readonly=true \n"
			"Opciones/Continuo  readonly=true \n"
			"Opciones/Without  readonly=true \n"
			"Opciones alpha=255 \n " //la barra no es trasparente (opaca)
			"Opciones size='250 600' \n"//ajusto el tamaño de la barra
			"Opciones/Lineado	group=Estilo \n" 
			"Opciones/Modo	group=Estilo \n"
			);

}
