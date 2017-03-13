INSTRUCCIONES DE LA COMPILACION DE LA APLICACION


Para compilar esta aplicacion, necesita las librerias de freegluth y AntTweakBar localizadas en "lib"
Necesita tambien tener en la carpeta de compilacion los archivos "Barras.h", "Bezier.h", "Bresenham.h","circulo.h", "elipse.h", "linea.h", "main.cpp", "Pintar.h", "punto.h", "rectangulo.h" y "triangulo.h".
Necesita tener incluido las cabezeras de OpenGL localizadas en "tools/GL/"
Necesita tener incluido las cabezeras de AntTweakBar localizadas en "tools/AntTweakBar/"
Por último, debe tener las librerias dinámicas "freeglut.dll" y "AntTweakBar.dll" en la misma carpeta donde este el ejecutable (lozalizado en bin)

Para ejecutar el compilado, necesita tener el "Tarea 2.exe" junto con los archivos "freeglut.dll" y "AntTweakBar.dll" en la misma carpeta (localizado en bin)


INSTRUCCIONES DE USO DE LA APLICACION


Está aplicación funciona con el mouse y la barra que se presenta del lado izquierdo

Los botones con los nombres a mencionar realizan lo siguientes:

Seccion Figuras:

	Punto: Permite dibujar puntos con la primitiva de OpenGL haciendo click en la pantalla
	Linea: Permite dibujar líneas con el algoritmo del punto medio haciendo 2 click en la pantalla (punto inicial, punto final)
	Triangulo: Permite dibujar triángulos con el algoritmo de trazado de líneas usando punto medio haciendo 3 click en la pantalla (los tres vertices del triangulo)
	Rectangulo: Permite dibujar rectángulos con el algoritmo de trazado de líneas haciendo 2 click (el segundo click es la esquina opuesta del rectangulo de donde hizo el primer click)
	Circulo: Permite dibujar un círculo haciendo dos click (el primero es el centro y el segundo indicará es el radio)
	Elipse: Permite dibujar elipses haciendo dos click(el primero es el centro de la elipse y el segundo indicara el ancho de "a" y al altura de "b" con respecto al centro de la elipse)
	Bezier: Al darle este botón, aparecera otra ventana y desaparecera la primera que se podra hacer lo siguiente:
		- Mientras la ventana este enfrente, se podra clickear los puntos de control y clickear en otro lado y los pondra en esa posicion.
		- Agregar: Agregara un punto (el ultimo) a la curva de bezier en la posicion (0,0).
		- Eliminar: Si hay mas de un punto, s epodra presionar este boton y eliminara el ultimo punto agregado.
		- Finalizar: Se terminara la edicion de la curva de bezier sin poder agregar, eliminar ni mover puntos de control y volvera a la ventana anterior.
		- Color Puntos: Permite cambiar el color de los puntos de control.
		- Color Figuras: Permite cambiar el color de la figura Bezier actualmente dibujada.

Seccion de Estilo:
	
Color Figura: Permite cambiar el color del relleno de la ultima figura dibujada y las siguientes a dibujar. Si la figura no puede poseer relleno (punto, linea, bezier) cambiara el color de la linea
Color Borde: Permite cambiar el color del borde de la ultima figura dibujada (Si posee borde) y las siguientes a dibujar.
Color Linezo: Permite cambiar el color de fondo de la aplicacion.
	Seccion Lineado (aplica a la ultima figura dibujada y a las siguientes a dibujar) (linea,triangulo,rectangulo,circulo y elipse)
		- Continuo: Permite dibujar los bordes de manera continua
		- Discontinuo: Permite dibujar los bordes de manera discontinua
		- Punto-Raya: Permite dibujar los bordes de manera Raya-punto.

	Seccion Modo (aplica a la ultima figura dibujada y a las siguientes a dibujar) (triangulo,rectangulo,circulo y elipse).
		- Relleno: Dibuja el relleno a la ultima figura.
		- Sin Relleno: Dibuja las figuras sin relleno (solo el borde).

Seccion Transformacion (aplica a la ultima figura dibujada) (todas).
	Rotacion: rota la figura de 0 a 360 grados.
	Traslacion Vertical: traslada la figura en el eje Y
	Traslacion Horizontal: traslada la figura en el eje X
	Escalamiento: escala la figura dependiendo del valor dado (limite inferior 0).

Seccion Abrir:
	- Abrir: Abrira un archivo <nombre indicado>.42 ubicado en la carpeta /tools/archivos
	- Nombre: Permite escribir el nombre del archivo a abrir

Seccion Salvar:
	- Guardar: Guarda un archivo <nombre indicado>.42 en al carpeta /tools/archivos
	- Nombre: Permite escribir el nombre del archivo a guardar

Limpiar: Elimina todas las figuras actualmente dibujadas
Salir: Sale de la aplicacion (si no esta guardado se pierde)



Autor: Alejandro Sans
C.I: 18359524
All Rigths Reserved 