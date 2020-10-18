#include <stdio.h>
#include "main.h"

//Dibuja las simetrías de cada punto en OpenGL

int window_w = 1024;
int window_h = 600;

void ochopuntos(int Xc, int Yc, int x, int y) {
	int i, j;
	float aux1, aux2;
	int sim[8][2] = { {x,y},{x,-y},{-x,y},{-x,-y},{y,x},{y,-x},{-y,x},{-y,-x} };//Arreglo de puntos de simetría
	//imprimir simetrías (Se dibujan los puntos simetricos deplazados
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 2; j++) {
			if (j == 0) {
				aux1 = sim[i][j]+ Xc;
			}
			else {
				aux2 = sim[i][j]+Yc;
			}
		}
		glPointSize(1);//Tamaño de punto a dibujar
		glBegin(GL_POINTS);
		glColor3f(1.0f, 1.0f, 1.0f);//Color blanco
		glVertex3f(aux1+Xc, aux2+Yc, -1.0f);
		glEnd();
	}
}

void Bresenham_c(int Xc, int Yc, int r) {
	int i, j, pk, xk, yk, a, b;
	float aux1, aux2;
	ochopuntos(Xc, Yc, 0, r);
	pk = 1 - r;
	//Hacemos que el punto de partida sea (xk,yk)=(0,r)
	xk = 0;
	yk = r;
	//El ciclo while siguiente calculará cada punto del primer octante, y a su vez las 8 simetrías de cada uno
	while (yk > xk) {
		if (pk < 0) {
			pk = pk + 2 * xk + 3;
			xk++;
			ochopuntos(Xc,Yc,xk, yk);//Sustituir por el dibujo del punto en OpenGL				
		}
		else {
			pk = pk + 2 * (xk - yk) + 5;
			xk++;
			yk--;
			ochopuntos(Xc, Yc,xk, yk);//Sustituir por el dibujo del punto en OpenGL
		}
	}
}

void marco() {
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-512, 300, -1);
	glVertex3f(512, 300, -1);
	glVertex3f(512, -276, -1);
	glVertex3f(-512, -276, -1);
	glEnd();
}
void pelo() {
	
	//Relleno mechon grande
	glColor3f(0.79, 0.69, 0.65);
	glBegin(GL_POLYGON);
	glVertex3f(111, 153, -1);
	glVertex3f(97, 65, -1);
	glVertex3f(88, 25, -1);
	glVertex3f(71, -80, -1);
	glVertex3f(61, -145, -1);
	glVertex3f(47, -195, -1);
	glVertex3f(45, -217, -1);
	glVertex3f(39, -276, -1);
	glVertex3f(98, -276, -1);
	glVertex3f(115, -263, -1);
	glVertex3f(146, -144, -1);
	glVertex3f(155, -68, -1);
	glVertex3f(162, -22, -1);//Union con la oreja
	glVertex3f(193, 71, -1);
	glVertex3f(200, 94, -1);
	glVertex3f(214, 143, -1);
	glVertex3f(223, 180, -1);
	glVertex3f(231, 219, -1);
	glVertex3f(239, 264, -1);
	glEnd();

	//Relleno resto del pelo (derecho)
	glBegin(GL_POLYGON);
	glVertex3f(60, 300, -1);
	glVertex3f(61, 270, -1);
	glVertex3f(63, 238, -1);
	glVertex3f(69, 208, -1);
	glVertex3f(81, 159, -1);
	glVertex3f(103, 101, -1);
	glVertex3f(200, 94, -1);
	glVertex3f(175, -21, -1);
	glVertex3f(190, -11, -1);
	glVertex3f(214, 6, -1);
	glVertex3f(224, 15, -1);
	glVertex3f(237, 35, -1);
	glVertex3f(244, 73, -1);
	glVertex3f(241, 84, -1);
	glVertex3f(220, 94, -1);
	glVertex3f(207, 95, -1);
	glVertex3f(200, 94, -1);
	glVertex3f(162, -22, -1);//Union con la oreja
	glVertex3f(157, -56, -1);
	glVertex3f(160, -117, -1);
	glVertex3f(165, -157, -1);
	glVertex3f(174, -103, -1);
	glVertex3f(177, -205, -1);
	glVertex3f(187, -223, -1);
	glVertex3f(201, -219, -1);
	glVertex3f(208, -219, -1);
	glVertex3f(233, -208, -1);
	glVertex3f(241, -207, -1);
	glVertex3f(263, -204, -1);
	glVertex3f(272, -205, -1);
	glVertex3f(284, -206, -1);
	glVertex3f(296, -212, -1);
	glVertex3f(344, -259, -1);
	glVertex3f(357, -276, -1);
	glVertex3f(335, -164, -1);
	glVertex3f(337, -102, -1);
	glVertex3f(342, -61, -1);
	glVertex3f(350, 10, -1);
	glVertex3f(352, 25, -1);
	glVertex3f(361, 108, -1);
	glVertex3f(365, 156, -1);
	glVertex3f(367, 184, -1);
	glVertex3f(362, 214, -1);
	glVertex3f(355, 244, -1);
	glVertex3f(343, 271, -1);
	glVertex3f(327, 300, -1);
	glEnd();

	//Relleno mechon hombro
	glBegin(GL_POLYGON);
	glVertex3f(160, -119, -1);
	glVertex3f(155, -164, -1);
	glVertex3f(165, -165, -1);
	glVertex3f(167, -139, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(155, -164, -1);
	glVertex3f(165, -165, -1);
	glVertex3f(161, -206, -1);
	glVertex3f(162, -213, -1);
	glVertex3f(155, -215, -1);
	glVertex3f(154, -190, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(162, -213, -1);
	glVertex3f(155, -215, -1);
	glVertex3f(155, -221, -1);
	glVertex3f(163, -229, -1);
	glVertex3f(178, -230, -1);
	glEnd();

	//Relleno fleco
	glBegin(GL_POLYGON);
	glVertex3f(54, 300, -1);
	glVertex3f(42, 276, -1);
	glVertex3f(29, 250, -1);
	glVertex3f(18, 220, -1);
	glVertex3f(9, 189, -1);
	glVertex3f(3, 157, -1);
	glVertex3f(0, 174, -1);
	glVertex3f(2, 199, -1);
	glVertex3f(7, 227, -1);
	glVertex3f(17, 261, -1);//
	glVertex3f(20, 270, -1);
	glVertex3f(6, 241, -1);
	glVertex3f(-4, 217, -1);
	glVertex3f(-13, 193, -1);
	glVertex3f(-22, 163, -1);
	glVertex3f(-25, 176, -1);
	glVertex3f(-23, 193, -1);
	glVertex3f(-19, 212, -1);
	glVertex3f(-12, 229, -1);
	glVertex3f(-11, 240, -1);
	glVertex3f(-10, 248, -1);
	glVertex3f(-24, 211, -1);
	glVertex3f(-29, 194, -1);
	glVertex3f(-38, 167, -1);
	glVertex3f(-39, 150, -1);
	glVertex3f(-62, 164, -1);
	glVertex3f(-66, 170, -1);
	glVertex3f(-68, 162, -1);
	glVertex3f(-71, 167, -1);
	glVertex3f(-71, 194, -1);
	glVertex3f(-75, 182, -1);
	glVertex3f(-76, 160, -1);
	glVertex3f(-82, 164, -1);
	glVertex3f(-84, 180, -1);
	glVertex3f(-82, 209, -1);
	glVertex3f(-80, 231, -1);
	glVertex3f(-73, 258, -1);
	glVertex3f(-65, 275, -1);
	glVertex3f(-91, 213, -1);
	glVertex3f(-97, 182, -1);
	glVertex3f(-99, 154, -1);
	glVertex3f(-105, 158, -1);
	glVertex3f(-115, 180, -1);
	glVertex3f(-115, 167, -1);
	glVertex3f(-118, 171, -1);
	glVertex3f(-120, 195, -1);
	glVertex3f(-118, 229, -1);
	glVertex3f(-108, 273, -1);
	glVertex3f(-114, 249, -1);
	glVertex3f(-118, 229, -1);
	glVertex3f(-124, 216, -1);
	glVertex3f(-130, 195, -1);
	glVertex3f(-132, 175, -1);
	glVertex3f(-136, 185, -1);
	glVertex3f(-139, 191, -1);
	glVertex3f(-136, 236, -1);
	glVertex3f(-133, 249, -1);
	glVertex3f(-128, 271, -1);
	glVertex3f(-116, 300, -1);
	glVertex3f(-128, 271, -1);
	glVertex3f(-166, 148, -1);
	glVertex3f(-168, 133, -1);
	glVertex3f(-153, 181, -1);
	glVertex3f(-156, 170, -1);
	glVertex3f(-159, 148, -1);
	glVertex3f(-161, 133, -1);
	glVertex3f(-164, 118, -1);
	glVertex3f(-168, 65, -1);
	glVertex3f(-165, 64, -1);
	glEnd();
	//Sombras/detalles del cuello
	glColor3f(0.34, 0.33, 0.33);
	glBegin(GL_TRIANGLES);
	glVertex3f(151, -110, -1);
	glVertex3f(156, -64, -1);
	glVertex3f(160, -109, -1);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(151, -110, -1);
	glVertex3f(159, -108, -1);
	glEnd();

	glColor3f(0.35, 0.35, 0.35);
	glBegin(GL_POLYGON);
	glVertex3f(151, -110, -1);
	glVertex3f(159, -109, -1);
	glVertex3f(160, -125, -1);
	glVertex3f(149, -125, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(160, -125, -1);
	glVertex3f(149, -125, -1);
	glVertex3f(136, -189, -1);
	glVertex3f(155, -162, -1);
	glEnd();

	glColor3f(0.75, 0.75, 0.75);
	glBegin(GL_POLYGON);
	glVertex3f(136, -189, -1);
	glVertex3f(155, -162, -1);
	glVertex3f(154, -241, -1);
	glVertex3f(116, -261, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(165, -159, -1);
	glVertex3f(161, -202, -1);
	glVertex3f(162, -213, -1);
	glVertex3f(172, -214, -1);
	glVertex3f(181, -215, -1);
	glVertex3f(173, -195, -1);
	glEnd();

	glColor3f(0.56, 0.58, 0.46);
	glBegin(GL_POLYGON);
	glVertex3f(124, -233, -1);
	glVertex3f(154, -217, -1);
	glVertex3f(158, -239, -1);
	glVertex3f(116, -262, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(154, -241, -1);
	glVertex3f(154, -221, -1);
	glVertex3f(170, -231, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(164, -214, -1);
	glVertex3f(167, -221, -1);
	glVertex3f(177, -227, -1);
	glVertex3f(186, -223, -1);
	glVertex3f(182, -216, -1);
	glVertex3f(174, -214, -1);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(124, -233, -1);
	glVertex3f(154, -217, -1);
	glVertex3f(182, -216, -1);
	glVertex3f(174, -214, -1);
	glVertex3f(174, -214, -1);
	glVertex3f(164, -214, -1);
	glEnd();

	//Sombra pelo
	glColor3f(0.33, 0.3, 0.33);
	glBegin(GL_POLYGON);
	glVertex3f(-168, 65, -1);
	glVertex3f(-169, 25, -1);
	glVertex3f(-172, -54, -1);
	glVertex3f(-175, -89, -1);
	glVertex3f(-177, -156, -1);
	glVertex3f(-179, -229, -1);
	glVertex3f(-180, -276, -1);
	glVertex3f(-126, -276, -1);
	glVertex3f(-89, -99, -1);
	glVertex3f(-94, -124, -1);
	glVertex3f(-94, -148, -1);
	glVertex3f(-89, -163, -1);
	glVertex3f(-86, -210, -1);
	glVertex3f(-81, -251, -1);
	glVertex3f(-76, -276, -1);
	glVertex3f(-26, -276, -1);
	glVertex3f(-19, -261, -1);
	glVertex3f(-18, -251, -1);
	glVertex3f(-18, -234, -1);
	glVertex3f(-21, -216, -1);
	glVertex3f(-24, -197, -1);
	glVertex3f(-27, -182, -1);
	glVertex3f(-27, -173, -1);
	glVertex3f(-23, -167, -1);
	glVertex3f(-36, -141, -1);
	glVertex3f(-48, -110, -1);
	glVertex3f(-60, -99, -1);
	glVertex3f(-116, -98, -1);
	glVertex3f(-143, -92, -1);
	glVertex3f(-151, -82, -1);
	glVertex3f(-151, -71, -1);
	glVertex3f(-151, -34, -1);
	glVertex3f(-160, 3, -1);
	glVertex3f(-163, 19, -1);
	glVertex3f(-166, 46, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(160, -113, -1);
	glVertex3f(155, -57, -1);
	glVertex3f(162, -23, -1);
	glVertex3f(174, -22, -1);
	glVertex3f(167, -70, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(193, -33, -1);
	glVertex3f(185, -74, -1);
	glVertex3f(181, -128, -1);
	glVertex3f(182, -167, -1);
	glVertex3f(187, -188, -1);
	glVertex3f(195, -208, -1);
	glVertex3f(201, -219, -1);
	glVertex3f(208, -218, -1);
	glVertex3f(192, -156, -1);
	glVertex3f(189, -113, -1);
	glVertex3f(190, -67, -1);
	glVertex3f(191, -49, -1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(265, -30, -1);
	glVertex3f(263, -203, -1);
	glVertex3f(273, -204, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(214, 6, -1);
	glVertex3f(212, -25, -1);
	glVertex3f(212, -87, -1);
	glVertex3f(222, 11, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-139, 170, -1);
	glVertex3f(-146, 171, -1);
	glVertex3f(-155, 134, -1);
	glVertex3f(-132, 131, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-155, 134, -1);
	glVertex3f(-164, 68, -1);
	glVertex3f(-133, 128, -1);
	glVertex3f(-132, 131, -1);
	glEnd();

	//Contorno mechon de pelo grande
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(137, 280, -1);
	glVertex3f(113, 168, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(111, 153, -1);
	glVertex3f(97, 65, -1);
	glVertex3f(88, 25, -1);
	glVertex3f(71, -80, -1);
	glVertex3f(56, -145, -1);
	glVertex3f(47, -195, -1);
	glVertex3f(45, -217, -1);
	glVertex3f(39, -276, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(98, -276, -1);
	glVertex3f(115, -263, -1);
	glVertex3f(146, -144, -1);
	glVertex3f(155, -68, -1);
	glVertex3f(162, -22, -1);//Union con la oreja
	glVertex3f(175, 86, -1);
	glVertex3f(184, 133, -1);
	glVertex3f(189, 164, -1);
	glVertex3f(199, 226, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(162, -22, -1);//Union con la oreja
	glVertex3f(193, 71, -1);
	glVertex3f(200, 94, -1);
	glVertex3f(214, 143, -1);
	glVertex3f(223, 180, -1);
	glVertex3f(231, 219, -1);
	glVertex3f(239, 264, -1);
	glEnd();
	
	//Contorno externo de la cabeza lado derecho
	glBegin(GL_LINE_STRIP);
	glVertex3f(344, -259, -1);
	glVertex3f(335, -164, -1);
	glVertex3f(337, -102, -1);
	glVertex3f(342, -61, -1);
	glVertex3f(350, 10, -1);
	glVertex3f(352, 25, -1);
	glVertex3f(361, 108, -1);
	glVertex3f(365, 156, -1);
	glVertex3f(367, 184, -1);
	glVertex3f(362, 214, -1);
	glVertex3f(355, 244, -1);
	glVertex3f(343, 271, -1);
	glVertex3f(327, 300, -1);
	glEnd();
	//Hombro derecho
	glBegin(GL_LINE_STRIP);
	glVertex3f(187, -223, -1);
	glVertex3f(115, -263, -1);
	glEnd();
	//Fleco derecho-Mechon largo
	glBegin(GL_LINE_STRIP);
	glVertex3f(60, 300, -1);
	glVertex3f(61, 270, -1);
	glVertex3f(63, 238, -1);
	glVertex3f(69, 208, -1);
	glVertex3f(81, 159, -1);
	glVertex3f(103, 101, -1);
	glEnd();
	//Punta 1 (izquierda a derecha) fleco
	glBegin(GL_LINE_STRIP);
	glVertex3f(54, 300, -1);
	glVertex3f(42, 276, -1);
	glVertex3f(29, 250, -1);
	glVertex3f(18, 220, -1);
	glVertex3f(9, 189, -1);
	glVertex3f(3, 157, -1);
	glVertex3f(0, 174, -1);
	glVertex3f(2, 199, -1);
	glVertex3f(7, 227, -1);
	glVertex3f(17, 261, -1);
	glEnd();
	//Punta 2 (izquierda a derecha) fleco
	glBegin(GL_LINE_STRIP);
	glVertex3f(20, 270, -1);
	glVertex3f(17, 261, -1);
	glVertex3f(6, 241, -1);
	glVertex3f(-4, 217, -1);
	glVertex3f(-13, 193, -1);
	glVertex3f(-22, 163, -1);
	glVertex3f(-25, 176, -1);
	glVertex3f(-23, 193, -1);
	glVertex3f(-19, 212, -1);
	glVertex3f(-12, 229, -1);
	glVertex3f(-11, 240, -1);
	glEnd();
	//Punta 3 (izquierda a derecha) fleco
	glBegin(GL_LINE_STRIP);
	glVertex3f(-10, 248, -1);
	glVertex3f(-11, 240, -1);
	glVertex3f(-24, 211, -1);
	glVertex3f(-29, 194, -1);
	glVertex3f(-38, 167, -1);
	glVertex3f(-39, 150, -1);
	glVertex3f(-62, 164, -1);
	glVertex3f(-66, 170, -1);
	glVertex3f(-68, 162, -1);
	glVertex3f(-71, 167, -1);
	glVertex3f(-71, 194, -1);
	glEnd();
	//Punta 4 (izquierda a derecha) fleco
	glBegin(GL_LINE_STRIP);
	glVertex3f(-71, 194, -1);
	glVertex3f(-75, 182, -1);
	glVertex3f(-76, 160, -1);
	glVertex3f(-82, 164, -1);
	glVertex3f(-84, 180, -1);
	glVertex3f(-82, 209, -1);
	glVertex3f(-80, 231, -1);
	glVertex3f(-73, 258, -1);
	glEnd();
	//Punta 5 (izquierda a derecha) fleco
	glBegin(GL_LINE_STRIP);
	glVertex3f(-65, 275, -1);
	glVertex3f(-73, 258, -1);
	glVertex3f(-91, 213, -1);
	glVertex3f(-97, 182, -1);
	glVertex3f(-99, 154, -1);
	glVertex3f(-105, 158, -1);
	glVertex3f(-115, 180, -1);
	glVertex3f(-115, 167, -1);
	glVertex3f(-118, 171, -1);
	glVertex3f(-120, 195, -1);
	glVertex3f(-118, 229, -1);
	glEnd();
	//Punta 6 (izquierda a derecha) fleco
	glBegin(GL_LINE_STRIP);
	glVertex3f(-108, 273, -1);
	glVertex3f(-114, 249, -1);
	glVertex3f(-118, 229, -1);
	glVertex3f(-124, 216, -1);
	glVertex3f(-130, 195, -1);
	glVertex3f(-132, 175, -1);
	glVertex3f(-136, 185, -1);
	glVertex3f(-139, 191, -1);
	glVertex3f(-136, 236, -1);
	glVertex3f(-133, 249, -1);
	glVertex3f(-128, 271, -1);
	glVertex3f(-116, 300, -1);
	glEnd();

	//Punta 7 (izquierda a derecha) fleco
	glBegin(GL_LINE_STRIP);
	glVertex3f(-128, 271, -1);
	glVertex3f(-166, 148, -1);
	glVertex3f(-168, 133, -1);
	glVertex3f(-153, 181, -1);
	glEnd();

	//Extremo izquierdo cabello
	glBegin(GL_LINE_STRIP);
	glVertex3f(-156, 170, -1);
	glVertex3f(-159, 148, -1);
	glVertex3f(-161, 133, -1);
	glVertex3f(-164, 118, -1);
	glVertex3f(-168, 65, -1);
	glVertex3f(-169, 25, -1);
	glVertex3f(-172, -54, -1);
	glVertex3f(-175, -89, -1);
	glVertex3f(-177, -156, -1);
	glVertex3f(-179, -229, -1);
	glVertex3f(-180, -276, -1);
	glVertex3f(-126, -276, -1);
	glVertex3f(-89, -99, -1);
	glEnd();

	//Contorno cabello trasero y parte frontal de la cara

	glBegin(GL_LINE_STRIP);
	glVertex3f(-94, -124, -1);
	glVertex3f(-94, -148, -1);
	glVertex3f(-89, -163, -1);
	glVertex3f(-86, -210, -1);
	glVertex3f(-81, -251, -1);
	glVertex3f(-76, -276, -1);
	glVertex3f(-26, -276, -1);
	glVertex3f(-19, -261, -1);
	glVertex3f(-18, -251, -1);
	glVertex3f(-18, -234, -1);
	glVertex3f(-21, -216, -1);
	glVertex3f(-24, -197, -1);
	glVertex3f(-27, -182, -1);
	glVertex3f(-27, -173, -1);
	glVertex3f(-23, -167, -1);
	glVertex3f(-36, -141, -1);
	glVertex3f(-48, -110, -1);
	glVertex3f(-60, -99, -1);
	glVertex3f(-116, -98, -1);
	glVertex3f(-143, -92, -1);
	glVertex3f(-151, -82, -1);
	glVertex3f(-151, -71, -1);
	glVertex3f(-151, -34, -1);
	glVertex3f(-160, 3, -1);
	glVertex3f(-163, 19, -1);
	glVertex3f(-166, 46, -1);
	glVertex3f(-165, 64, -1);
	glVertex3f(-159, 85, -1);
	glVertex3f(-153, 100, -1);
	glVertex3f(-152, 115, -1);
	glVertex3f(-149, 119, -1);
	glVertex3f(-145, 121, -1);
	glVertex3f(-138, 131, -1);
	glVertex3f(-137, 138, -1);
	glVertex3f(-140, 153, -1);
	glVertex3f(-140, 165, -1);
	glVertex3f(-140, 170, -1);
	glVertex3f(-149, 172, -1);
	glVertex3f(-146, 175, -1);
	glVertex3f(-151, 178, -1);
	glVertex3f(-138, 186, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(334, -166, -1);
	glVertex3f(329, -130, -1);
	glVertex3f(320, 20, -1);
	glVertex3f(319, 107, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(259, 184, -1);
	glVertex3f(252, 105, -1);
	glVertex3f(243, -133, -1);
	glVertex3f(241, -206, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(226, -87, -1);
	glVertex3f(225, -127, -1);
	glVertex3f(228, -177, -1);
	glVertex3f(233, -208, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-86, 300, -1);
	glVertex3f(-101, 265, -1);
	glVertex3f(-108, 242, -1);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-105, -98, -1);
	glVertex3f(-142, -276, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-69, -98, -1);
	glVertex3f(-69, -150, -1);
	glVertex3f(-66, -173, -1);
	glVertex3f(-64, -186, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-58, -130, -1);
	glVertex3f(-59, -228, -1);
	glVertex3f(-57, -250, -1);
	glVertex3f(-52, -267, -1);
	glEnd();


}
void cara() {

	//Pestañas izquierdas
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-138, 186, -1);
	glVertex3f(-142, 181, -1);
	glVertex3f(-147, 179, -1);
	glVertex3f(-151, 178, -1);
	glVertex3f(-146, 174, -1);
	glVertex3f(-150, 173, -1);
	glVertex3f(-145, 172, -1);
	glVertex3f(-139, 171, -1);
	glVertex3f(-135, 178, -1);
	glVertex3f(-138, 182, -1);
	glEnd();

	//Delineado izquierdo superior
	glBegin(GL_POLYGON);
	glVertex3f(-131, 189, -1);
	glVertex3f(-131, 181, -1);
	glVertex3f(-119, 173, -1);
	glVertex3f(-120, 181, -1);
	glEnd();
	//Delineado izquierdo inferior
	glBegin(GL_POLYGON);
	glVertex3f(-137, 138, -1);
	glVertex3f(-139, 133, -1);
	glVertex3f(-134, 130, -1);
	glVertex3f(-135, 125, -1);
	glVertex3f(-129, 128, -1);
	glVertex3f(-123, 131, -1);
	glVertex3f(-117, 135, -1);
	glVertex3f(-125, 134, -1);
	glVertex3f(-132, 134, -1);
	glVertex3f(-134, 135, -1);
	glEnd();

	//pupila izquierdo
	glColor3f(0.2, 0.46, 0.37);
	glBegin(GL_POLYGON);
	glVertex3f(-118, 172, -1);
	glVertex3f(-123, 168, -1);
	glVertex3f(-126, 164, -1);
	glVertex3f(-127, 159, -1);
	glVertex3f(-128, 147, -1);
	glVertex3f(-127, 139, -1);
	glVertex3f(-125, 135, -1);
	glVertex3f(-116, 135, -1);
	glVertex3f(-114, 137, -1);
	glVertex3f(-110, 144, -1);
	glVertex3f(-109, 153, -1);
	glVertex3f(-109, 164, -1);
	glEnd();

	//Ojo izquierdo

	glColor3f(0.65, 0.65, 0.65);
	glBegin(GL_POLYGON);
	glVertex3f(-135, 178, -1);
	glVertex3f(-139, 171, -1);
	glVertex3f(-139, 158, -1);
	glVertex3f(-139, 149, -1);
	glVertex3f(-136, 138, -1);
	glVertex3f(-134, 136, -1);
	glVertex3f(-131, 134, -1);
	glVertex3f(-125, 134, -1);
	glVertex3f(-127, 139, -1);
	glVertex3f(-128, 147, -1);
	glVertex3f(-127, 159, -1);
	glVertex3f(-126, 164, -1);
	glVertex3f(-123, 168, -1);
	glVertex3f(-118, 172, -1);
	glVertex3f(-132, 181, -1);
	glVertex3f(-133, 173, -1);
	glVertex3f(-136, 180, -1);
	glEnd();

	//Relleno cara
	glColor3f(0.9, 0.85, 0.7);
	glBegin(GL_POLYGON);

	glVertex3f(-120, 132, -1);
	glVertex3f(-132, 126, -1);
	glVertex3f(-141, 122, -1);
	glVertex3f(-150, 117, -1);
	glVertex3f(-152, 116, -1);
	glVertex3f(-152, 101, -1);
	glVertex3f(-145, 77, -1);
	glVertex3f(-144, 71, -1);
	glVertex3f(-146, 76, -1);
	glVertex3f(-150, 76, -1);
	glVertex3f(-155, 69, -1);
	glVertex3f(-159, 57, -1);
	glVertex3f(-157, 42, -1);
	glVertex3f(-155, 29, -1);
	glVertex3f(-150, 18, -1);
	glVertex3f(-146, 15, -1);
	glVertex3f(-138, 14, -1);
	glVertex3f(-124, 9, -1);
	glVertex3f(-109, -6, -1);
	glVertex3f(-129, 3, -1);
	glVertex3f(-138, 6, -1);
	glVertex3f(-143, -7, -1);
	glVertex3f(-134, -26, -1);
	glVertex3f(-140, -45, -1);
	glVertex3f(-141, -78, -1);
	glVertex3f(-136, -84, -1);
	glVertex3f(-124, -89, -1);
	glVertex3f(-100, -90, -1);
	glVertex3f(4, -84, -1);
	glVertex3f(44, -68, -1);
	glVertex3f(77, -38, -1);
	glVertex3f(100, 80, -1);
	glVertex3f(84, 129, -1);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-109, 144, -1);
	glVertex3f(-114, 137, -1);
	glVertex3f(-120, 132, -1);
	glVertex3f(-91, 105, -1);
	glVertex3f(-99, 153, -1);
	glVertex3f(-107, 158, -1);
	glVertex3f(-109, 163, -1);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3f(84, 129, -1);
	glVertex3f(42, 268, -1);
	glVertex3f(11, 185, -1);
	glVertex3f(5, 145, -1);
	glVertex3f(-40, 135, -1);
	glVertex3f(-98, 135, -1);
	glVertex3f(-98, 88, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-98, 88, -1);
	glVertex3f(-91, 170, -1);
	glVertex3f(-83, 145, -1);
	glVertex3f(-78, 140, -1);
	glVertex3f(-72, 151, -1);
	glVertex3f(-67, 143, -1);
	glVertex3f(-39, 134, -1);
	glVertex3f(-16, 129, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-39, 134, -1);
	glVertex3f(-26, 173, -1);
	glVertex3f(-23, 164, -1);
	glVertex3f(-28, 157, -1);
	glVertex3f(-27, 151, -1);
	glVertex3f(-21, 138, -1);
	glVertex3f(-16, 129, -1);
	glEnd();

	//Ojo derecho

	glColor3f(0.65, 0.65, 0.65);
	glBegin(GL_POLYGON);
	glVertex3f(0, 175, -1);
	glVertex3f(-28, 157, -1);
	glVertex3f(-27, 151, -1);
	glVertex3f(-23, 141, -1);
	glVertex3f(-21, 138, -1);
	glVertex3f(-16, 129, -1);
	glVertex3f(-8, 128, -1);
	glVertex3f(-12, 135, -1);
	glVertex3f(-12, 142, -1);
	glVertex3f(1, 156, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(6, 175, -1);
	glVertex3f(4, 160, -1);
	glVertex3f(5, 147, -1);
	glVertex3f(7, 159, -1);
	glVertex3f(12, 162, -1);
	glVertex3f(26, 162, -1);
	glVertex3f(29, 165, -1);
	glVertex3f(33, 169, -1);
	glVertex3f(38, 173, -1);
	glVertex3f(23, 175, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(63, 165, -1);
	glVertex3f(66, 157, -1);
	glVertex3f(68, 148, -1);
	glVertex3f(67, 140, -1);
	glVertex3f(66, 135, -1);
	glVertex3f(64, 130, -1);
	glVertex3f(73, 134, -1);
	glVertex3f(80, 140, -1);
	glVertex3f(84, 144, -1);
	glVertex3f(82, 156, -1);
	glVertex3f(65, 165, -1);
	glEnd();

	glColor3f(0.77, 0.77, 0.77);
	glBegin(GL_POLYGON);
	glVertex3f(27, 123, -1);
	glVertex3f(-7, 128, -1);
	glVertex3f(-12, 135, -1);
	glVertex3f(-12, 142, -1);
	glVertex3f(1, 156, -1);
	glVertex3f(3, 147, -1);
	glVertex3f(7, 159, -1);
	glVertex3f(12, 162, -1);
	glVertex3f(26, 162, -1);
	glVertex3f(23, 151, -1);
	glVertex3f(22, 144, -1);
	glVertex3f(22, 133, -1);
	glVertex3f(23, 128, -1);
	glEnd();



	//pupila Derecha
	glColor3f(0.2, 0.46, 0.37);
	glBegin(GL_POLYGON);
	glVertex3f(38, 171, -1);
	glVertex3f(33, 168, -1);
	glVertex3f(27, 161, -1);
	glVertex3f(23, 151, -1);
	glVertex3f(22, 144, -1);
	glVertex3f(22, 133, -1);
	glVertex3f(23, 128, -1);
	glVertex3f(27, 123, -1);
	glVertex3f(37, 122, -1);
	glVertex3f(50, 124, -1);
	glVertex3f(63, 129, -1);
	glVertex3f(66, 135, -1);
	glVertex3f(67, 140, -1);
	glVertex3f(68, 148, -1);
	glVertex3f(66, 157, -1);
	glVertex3f(63, 165, -1);
	glVertex3f(54, 171, -1);
	glVertex3f(45, 173, -1);
	glEnd();


	//Pestañas derechas
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-18, 179, -1);
	glVertex3f(-22, 164, -1);
	glVertex3f(-27, 158, -1);
	glVertex3f(0, 173, -1);
	glVertex3f(1, 180, -1);
	glVertex3f(1, 185, -1);
	glVertex3f(-7, 181, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(1, 180, -1);
	glVertex3f(1, 185, -1);
	glVertex3f(-9, 188, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(7, 184, -1);
	glVertex3f(6, 175, -1);
	glVertex3f(14, 175, -1);
	glVertex3f(27, 174, -1);
	glVertex3f(40, 174, -1);
	glVertex3f(49, 172, -1);
	glVertex3f(62, 167, -1);
	glVertex3f(81, 156, -1);
	glVertex3f(80, 162, -1);
	glVertex3f(54, 176, -1);
	glVertex3f(38, 181, -1);
	glVertex3f(22, 185, -1);
	glEnd();

	//Contorno pupilas
	glBegin(GL_LINE_LOOP);
	glVertex3f(-118, 172, -1);
	glVertex3f(-123, 168, -1);
	glVertex3f(-126, 164, -1);
	glVertex3f(-127, 159, -1);
	glVertex3f(-128, 147, -1);
	glVertex3f(-127, 139, -1);
	glVertex3f(-125, 135, -1);
	glVertex3f(-116, 135, -1);
	glVertex3f(-114, 137, -1);
	glVertex3f(-110, 144, -1);
	glVertex3f(-109, 153, -1);
	glVertex3f(-109, 164, -1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(38, 171, -1);
	glVertex3f(33, 168, -1);
	glVertex3f(27, 161, -1);
	glVertex3f(23, 151, -1);
	glVertex3f(22, 144, -1);
	glVertex3f(22, 133, -1);
	glVertex3f(23, 128, -1);
	glVertex3f(27, 123, -1);
	glVertex3f(37, 122, -1);
	glVertex3f(50, 124, -1);
	glVertex3f(63, 129, -1);
	glVertex3f(66, 135, -1);
	glVertex3f(67, 140, -1);
	glVertex3f(68, 148, -1);
	glVertex3f(66, 157, -1);
	glVertex3f(63, 165, -1);
	glVertex3f(54, 171, -1);
	glVertex3f(45, 173, -1);
	glEnd();

	//Interior pupilas
	glBegin(GL_LINE_STRIP);
	glVertex3f(-122, 143, -1);
	glVertex3f(-123, 150, -1);
	glVertex3f(-122, 156, -1);
	glVertex3f(-118, 160, -1);
	glVertex3f(-115, 161, -1);
	glVertex3f(-110, 158, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(34, 136, -1);
	glVertex3f(34, 144, -1);
	glVertex3f(35, 150, -1);
	glVertex3f(39, 155, -1);
	glVertex3f(45, 158, -1);
	glVertex3f(50, 158, -1);
	glVertex3f(54, 155, -1);
	glVertex3f(57, 151, -1);
	glVertex3f(58, 143, -1);
	glVertex3f(58, 138, -1);
	glVertex3f(57, 136, -1);
	glEnd();

	//Retina derecha
	glBegin(GL_POLYGON);
	glVertex3f(44, 141, -1);
	glVertex3f(44, 145, -1);
	glVertex3f(46, 148, -1);
	glVertex3f(47, 149, -1);
	glVertex3f(49, 147, -1);
	glVertex3f(50, 144, -1);
	glVertex3f(49, 141, -1);
	glVertex3f(47, 140, -1);
	glEnd();

	//Retina izquierda
	glBegin(GL_POLYGON);
	glVertex3f(-116, 147, -1);
	glVertex3f(-117, 150, -1);
	glVertex3f(-117, 153, -1);
	glVertex3f(-114, 156, -1);
	glVertex3f(-113, 153, -1);
	glVertex3f(-113, 149, -1);
	glEnd();

	//Delineado izquierdo
	glBegin(GL_TRIANGLES);
	glVertex3f(-15, 131, -1);
	glVertex3f(-12, 123, -1);
	glVertex3f(-3, 127, -1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-3, 127, -1);
	glVertex3f(1, 118, -1);
	glVertex3f(13, 124, -1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(13, 124, -1);
	glVertex3f(17, 117, -1);
	glVertex3f(34, 122, -1);
	glEnd();

	//Sombra color carne
	glColor3f(0.34, 0.33, 0.33);
	glBegin(GL_POLYGON);
	glVertex3f(-63, -87, -1);
	glVertex3f(-63, -97, -1);
	glVertex3f(-55, -101, -1);
	glVertex3f(-49, -107, -1);
	glVertex3f(-44, -117, -1);
	glVertex3f(-40, -128, -1);
	glVertex3f(-35, -140, -1);
	glVertex3f(-29, -153, -1);
	glVertex3f(-25, -162, -1);
	glVertex3f(-20, -170, -1);
	glVertex3f(-14, -180, -1);
	glVertex3f(-9, -189, -1);
	glVertex3f(-8, -195, -1);
	glVertex3f(-4, -185, -1);
	glVertex3f(-1, -178, -1);
	glVertex3f(7, -170, -1);
	glVertex3f(40, -149, -1);
	glVertex3f(58, -140, -1);
	glVertex3f(70, -85, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(70, -85, -1);
	glVertex3f(77, -38, -1);
	glVertex3f(33, -68, -1);
	glVertex3f(27, -160, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(27, -160, -1);
	glVertex3f(33, -68, -1);
	glVertex3f(-1, -79, -1);
	glVertex3f(-12, -113, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-12, -113, -1);
	glVertex3f(-1, -79, -1);
	glVertex3f(-65, -88, -1);
	glVertex3f(-72, -98, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-72, -98, -1);
	glVertex3f(-65, -88, -1);
	glVertex3f(-111, -91, -1);
	glVertex3f(-121, -97, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-121, -97, -1);
	glVertex3f(-111, -91, -1);
	glVertex3f(-140, -82, -1);
	glVertex3f(-150, -73, -1);
	glVertex3f(-150, -82, -1);
	glVertex3f(-148, -87, -1);
	glVertex3f(-144, -91, -1);
	glVertex3f(-138, -94, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-150, -73, -1);
	glVertex3f(-140, -82, -1);
	glVertex3f(-139, -39, -1);
	glVertex3f(-150, -37, -1);
	glVertex3f(-149, -53, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-150, -37, -1);
	glVertex3f(-139, -39, -1);
	glVertex3f(-134, -25, -1);
	glVertex3f(-143, -6, -1);
	glVertex3f(-161, 9, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-161, 9, -1);
	glVertex3f(-143, -6, -1);
	glVertex3f(-138, 7, -1);
	glVertex3f(-147, 15, -1);
	glVertex3f(-152, 19, -1);
	glVertex3f(-164, 23, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-138, 7, -1);
	glVertex3f(-110, -6, -1);
	glVertex3f(-119, 6, -1);
	glVertex3f(-137, 15, -1);
	glVertex3f(-147, 15, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-164, 23, -1);
	glVertex3f(-152, 19, -1);
	glVertex3f(-159, 43, -1);
	glVertex3f(-159, 60, -1);
	glVertex3f(-165, 60, -1);
	glVertex3f(-166, 42, -1);
	glVertex3f(-164, 30, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-165, 60, -1);
	glVertex3f(-159, 60, -1);
	glVertex3f(-152, 74, -1);
	glVertex3f(-146, 78, -1);
	glVertex3f(-153, 98, -1);
	glVertex3f(-160, 83, -1);
	glVertex3f(-163, 76, -1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-131, 127, -1);
	glVertex3f(-137, 130, -1);
	glVertex3f(-144, 122, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-131, 189, -1);
	glVertex3f(-118, 229, -1);
	glVertex3f(-120, 206, -1);
	glVertex3f(-120, 182, -1);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(-109, 166, -1);
	glVertex3f(-110, 144, -1);
	glVertex3f(-95, 137, -1);
	glVertex3f(-92, 135, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-92, 154, -1);
	glVertex3f(-98, 154, -1);
	glVertex3f(-98, 175, -1);
	glVertex3f(-92, 172, -1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-92, 135, -1);
	glVertex3f(-106, 158, -1);
	glVertex3f(-92, 154, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-91, 170, -1);
	glVertex3f(-98, 175, -1);
	glVertex3f(-91, 210, -1);
	glVertex3f(-84, 204, -1);
	glVertex3f(-85, 178, -1);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(-84, 204, -1);
	glVertex3f(-91, 210, -1);
	glVertex3f(-76, 247, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-90, 170, -1);
	glVertex3f(-85, 178, -1);
	glVertex3f(-81, 163, -1);
	glVertex3f(-84, 146, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-84, 146, -1);
	glVertex3f(-81, 163, -1);
	glVertex3f(-76, 159, -1);
	glVertex3f(-72, 152, -1);
	glVertex3f(-77, 139, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-76, 159, -1);
	glVertex3f(-72, 151, -1);
	glVertex3f(-71, 165, -1);
	glVertex3f(-72, 188, -1);
	glVertex3f(-76, 174, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-72, 151, -1);
	glVertex3f(-71, 165, -1);
	glVertex3f(-68, 162, -1);
	glVertex3f(-64, 142, -1);
	glVertex3f(-69, 142, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-64, 142, -1);
	glVertex3f(-68, 162, -1);
	glVertex3f(-66, 170, -1);
	glVertex3f(-63, 163, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-64, 142, -1);
	glVertex3f(-63, 163, -1);
	glVertex3f(-34, 149, -1);
	glVertex3f(-39, 134, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-90, 170, -1);
	glVertex3f(-83, 168, -1);
	glVertex3f(-86, 182, -1);
	glVertex3f(-97, 176, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-34, 149, -1);
	glVertex3f(-26, 173, -1);
	glVertex3f(-24, 190, -1);
	glVertex3f(-30, 193, -1);
	glVertex3f(-40, 152, -1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-24, 190, -1);
	glVertex3f(-30, 193, -1);
	glVertex3f(-11, 240, -1);
	glVertex3f(-20, 209, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-24, 190, -1);
	glVertex3f(-30, 193, -1);
	glVertex3f(-11, 240, -1);
	glVertex3f(-20, 209, -1);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-17, 179, -1);
	glVertex3f(-5, 183, -1);
	glVertex3f(-10, 201, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-14, 191, -1);
	glVertex3f(-9, 188, -1);
	glVertex3f(-1, 185, -1);
	glVertex3f(3, 208, -1);
	glVertex3f(-7, 208, -1);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(3, 208, -1);
	glVertex3f(-7, 208, -1);
	glVertex3f(14, 256, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(42, 268, -1);
	glVertex3f(11, 185, -1);
	glVertex3f(7, 185, -1);
	glVertex3f(36, 265, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(42, 268, -1);
	glVertex3f(36, 265, -1);
	glVertex3f(55, 300, -1);
	glVertex3f(61, 300, -1);
	glVertex3f(60, 284, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(60, 284, -1);
	glVertex3f(42, 268, -1);
	glVertex3f(49, 239, -1);
	glVertex3f(63, 241, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(49, 239, -1);
	glVertex3f(63, 241, -1);
	glVertex3f(71, 194, -1);
	glVertex3f(63, 197, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(71, 194, -1);
	glVertex3f(63, 197, -1);
	glVertex3f(73, 165, -1);
	glVertex3f(80, 162, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(81, 140, -1);
	glVertex3f(85, 144, -1);
	glVertex3f(103, 103, -1);
	glVertex3f(99, 83, -1);
	glEnd();

	//Cejas
	glColor3f(0.33, 0.3, 0.33);
	glBegin(GL_POLYGON);
	glVertex3f(16, 214, -1);
	glVertex3f(14, 206, -1);
	glVertex3f(42, 200, -1);
	glVertex3f(64, 192, -1);
	glVertex3f(72, 188, -1);
	glVertex3f(71, 193, -1);
	glVertex3f(54, 200, -1);
	glVertex3f(31, 209, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(6, 216, -1);
	glVertex3f(-4, 217, -1);
	glVertex3f(-7, 208, -1);
	glVertex3f(4, 207, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-17, 218, -1);
	glVertex3f(-21, 219, -1);
	glVertex3f(-24, 210, -1);
	glVertex3f(-20, 209, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-119, 211, -1);
	glVertex3f(-124, 214, -1);
	glVertex3f(-126, 210, -1);
	glVertex3f(-120, 208, -1);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(16, 214, -1);
	glVertex3f(14, 206, -1);
	glVertex3f(42, 200, -1);
	glVertex3f(64, 192, -1);
	glVertex3f(73, 188, -1);
	glVertex3f(72, 193, -1);
	glVertex3f(54, 200, -1);
	glVertex3f(31, 209, -1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(6, 216, -1);
	glVertex3f(-4, 217, -1);
	glVertex3f(-7, 208, -1);
	glVertex3f(4, 207, -1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-17, 218, -1);
	glVertex3f(-21, 219, -1);
	glVertex3f(-24, 210, -1);
	glVertex3f(-20, 209, -1);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(-119, 211, -1);
	glVertex3f(-124, 214, -1);
	glVertex3f(-126, 210, -1);
	glVertex3f(-120, 208, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(54, 179, -1);
	glVertex3f(35, 186, -1);
	glVertex3f(19, 190, -1);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-5, 192, -1);
	glVertex3f(-13, 191, -1);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-130, 195, -1);
	glVertex3f(-120, 188, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-137, 6, -1);
	glVertex3f(-126, 2, -1);
	glVertex3f(-110, -6, -1);
	glEnd();

	//linea del menton

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(-39, -97, -1);
	glVertex3f(-5, -97, -1);
	glEnd();

	//contorno nariz
	glColor3f(0.313, 0.266, 0.247);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-109, 164, -1);
	glVertex3f(-109, 153, -1);
	glVertex3f(-110, 144, -1);
	glVertex3f(-114, 137, -1);
	glVertex3f(-120, 132, -1);
	glVertex3f(-132, 126, -1);
	glVertex3f(-141, 122, -1);
	glVertex3f(-150, 116, -1);
	glVertex3f(-152, 116, -1);
	glVertex3f(-152, 101, -1);
	glVertex3f(-145, 77, -1);
	glVertex3f(-144, 71, -1);
	glEnd();


	//Contorno ojo derecho
	
	glBegin(GL_LINE_STRIP);
	glVertex3f(-15, 131, -1);
	glVertex3f(-3, 127, -1);
	glVertex3f(-3, 127, -1);
	glVertex3f(13, 124, -1);
	glVertex3f(13, 124, -1);
	glVertex3f(34, 122, -1);
	glVertex3f(47, 123, -1);
	glVertex3f(58, 127, -1);
	glVertex3f(70, 132, -1);
	glVertex3f(76, 137, -1);
	glEnd();

	glColor3f(0.67, 0.33, 0.25);
	glBegin(GL_TRIANGLES);
	glVertex3f(39, 121, -1);
	glVertex3f(52, 124, -1);
	glVertex3f(52, 119, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(51, 124, -1);
	glVertex3f(52, 119, -1);
	glVertex3f(67, 120, -1);
	glVertex3f(68, 131, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(68, 131, -1);
	glVertex3f(86, 145, -1);
	glVertex3f(91, 130, -1);
	glVertex3f(67, 120, -1);
	glEnd();

	glColor3f(0.33, 0.18, 0.15);
	glBegin(GL_POLYGON);
	glVertex3f(81, 140, -1);
	glVertex3f(84, 127, -1);
	glVertex3f(91, 130, -1);
	glVertex3f(86, 145, -1);
	glEnd();


}
void oreja() {

	//Relleno
	glColor3f(0.9, 0.85, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(162, -22, -1);//Union con la oreja
	glVertex3f(175, -21, -1);
	glVertex3f(190, -11, -1);
	glVertex3f(214, 6, -1);
	glVertex3f(224, 15, -1);
	glVertex3f(237, 35, -1);
	glVertex3f(244, 73, -1);
	glVertex3f(241, 84, -1);
	glVertex3f(220, 94, -1);
	glVertex3f(207, 95, -1);
	glVertex3f(200, 94, -1);
	glEnd();

	//Sombra color carne
	glColor3f(0.34, 0.33, 0.33);
	glBegin(GL_POLYGON);
	glVertex3f(172, 4, -1);
	glVertex3f(180, 4, -1);
	glVertex3f(193, 12, -1);
	glVertex3f(200, 22, -1);
	glVertex3f(200, 50, -1);
	glVertex3f(196, 59, -1);
	glVertex3f(191, 62, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(220, 76, -1);
	glVertex3f(224, 70, -1);
	glVertex3f(226, 59, -1);
	glVertex3f(224, 41, -1);
	glVertex3f(226, 38, -1);
	glVertex3f(229, 39, -1);
	glVertex3f(233, 43, -1);
	glVertex3f(238, 56, -1);
	glVertex3f(235, 70, -1);
	glVertex3f(228, 75, -1);
	glEnd();
	//contorno oreja
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(162, -22, -1);//Union con la oreja
	glVertex3f(175, -21, -1);
	glVertex3f(190, -11, -1);
	glVertex3f(214, 6, -1);
	glVertex3f(224, 15, -1);
	glVertex3f(237, 35, -1);
	glVertex3f(244, 73, -1);
	glVertex3f(241, 84, -1);
	glVertex3f(220, 94, -1);
	glVertex3f(207, 95, -1);
	glVertex3f(200, 94, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(193, 71, -1);//Union oreja interior
	glVertex3f(193, 71, -1);
	glVertex3f(204, 75, -1);
	glVertex3f(221, 76, -1);
	glVertex3f(228, 75, -1);
	glVertex3f(236, 69, -1);
	glVertex3f(238, 56, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(173, 8, -1);
	glVertex3f(181, 10, -1);
	glVertex3f(191, 16, -1);
	glVertex3f(195, 31, -1);
	glVertex3f(196, 50, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(157, -56, -1);
	glVertex3f(160, -117, -1);
	glVertex3f(155, -161, -1);
	glVertex3f(154, -216, -1);
	glVertex3f(156, -223, -1);
	glVertex3f(169, -231, -1);
	glVertex3f(177, -227, -1);
	glVertex3f(169, -223, -1);
	glVertex3f(163, -213, -1);
	glVertex3f(162, -188, -1);
	glVertex3f(165, -157, -1);
	glVertex3f(174, -103, -1);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(165, -157, -1);
	glVertex3f(177, -205, -1);
	glVertex3f(187, -223, -1);
	glVertex3f(201, -219, -1);
	glVertex3f(208, -219, -1);
	glVertex3f(233, -208, -1);
	glVertex3f(241, -207, -1);
	glVertex3f(263, -204, -1);
	glVertex3f(272, -205, -1);
	glVertex3f(284, -206, -1);
	glVertex3f(296, -212, -1);
	glVertex3f(344, -259, -1);
	glVertex3f(357, -276, -1);
	glEnd();
}
void Cuello() {

	//Relleno corbata
	glColor3f(0.15, 0.08, 0.08);
	glBegin(GL_TRIANGLES);
	glVertex3f(-7, -212, -1);
	glVertex3f(2, -276, -1);
	glVertex3f(-25, -276, -1);
	glEnd();

	//Sombra cuello camisa
	glColor3f(0.35, 0.35, 0.35);
	glBegin(GL_POLYGON);
	glVertex3f(-22, -167, -1);
	glVertex3f(-10, -191, -1);
	glVertex3f(-8, -197, -1);
	glVertex3f(-8, -213, -1);
	glVertex3f(-17, -250, -1);
	glVertex3f(-19, -224, -1);
	glVertex3f(-28, -182, -1);
	glVertex3f(-27, -172, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-8, -197, -1);
	glVertex3f(-8, -213, -1);
	glVertex3f(2, -276, -1);
	glVertex3f(39, -276, -1);
	glVertex3f(46, -210, -1);
	glVertex3f(59, -139, -1);
	glVertex3f(37, -149, -1);
	glVertex3f(3, -172, -1);
	glVertex3f(-2, -181, -1);
	glEnd();

	glBegin(GL_POLYGON);

	glEnd();


	//Contorno cuello camisa
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-24, -168, -1);
	glVertex3f(-27, -172, -1);
	glVertex3f(-28, -182, -1);
	glVertex3f(-19, -224, -1);
	glVertex3f(-17, -250, -1);
	glVertex3f(-8, -213, -1);
	glVertex3f(2, -276, -1);
	glVertex3f(39, -276, -1);
	glVertex3f(46, -210, -1);
	glVertex3f(59, -140, -1);
	glVertex3f(37, -151, -1);
	glVertex3f(3, -174, -1);
	glVertex3f(-2, -181, -1);
	glVertex3f(-8, -197, -1);
	glVertex3f(-10, -191, -1);
	glVertex3f(-23, -168, -1);
	glEnd();

	glColor3f(0.33, 0.18, 0.18);
	glBegin(GL_POLYGON);
	glVertex3f(97, -276, -1);
	glVertex3f(140, -248, -1);
	glVertex3f(177, -228, -1);
	glVertex3f(203, -218, -1);
	glVertex3f(356, -276, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(203, -218, -1);
	glVertex3f(201, -218, -1);
	glVertex3f(233, -208, -1);
	glVertex3f(256, -204, -1);
	glVertex3f(274, -205, -1);
	glVertex3f(289, -208, -1);
	glVertex3f(296, -211, -1);
	glVertex3f(333, -245, -1);
	glVertex3f(356, -276, -1);
	glEnd();

}
void Brillos() {
	glColor3f(0.79, 0.79, 0.79);
	glBegin(GL_POLYGON);
	glVertex3f(-134, 155, -1);
	glVertex3f(-131, 153, -1);
	glVertex3f(-125, 153, -1);
	glVertex3f(-122, 155, -1);
	glVertex3f(-125, 157, -1);
	glVertex3f(-130, 157, -1);
	glEnd();

	glColor3f(0.81, 0.92, 0.92);
	glBegin(GL_POLYGON);
	glVertex3f(-113, 140, -1);
	glVertex3f(-118, 141, -1);
	glVertex3f(-122, 140, -1);
	glVertex3f(-125, 138, -1);
	glVertex3f(-123, 135, -1);
	glVertex3f(-117, 137, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(57, 127, -1);
	glVertex3f(53, 131, -1);
	glVertex3f(45, 133, -1);
	glVertex3f(38, 132, -1);
	glVertex3f(31, 129, -1);
	glVertex3f(27, 125, -1);
	glVertex3f(28, 123, -1);
	glVertex3f(37, 123, -1);
	glVertex3f(49, 124, -1);
	glEnd();

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_POLYGON);
	glVertex3f(15, 149, -1);
	glVertex3f(20, 146, -1);
	glVertex3f(32, 147, -1);
	glVertex3f(37, 149, -1);
	glVertex3f(33, 151, -1);
	glVertex3f(24, 153, -1);
	glVertex3f(19, 152, -1);
	glEnd();

	glColor3f(1, 0.93, 0.98);

	glBegin(GL_POLYGON);
	glVertex3f(174, 274, -1);
	glVertex3f(169, 267, -1);
	glVertex3f(167, 237, -1);
	glVertex3f(173, 242, -1);
	glVertex3f(175, 266, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(291, 240, -1);
	glVertex3f(289, 220, -1);
	glVertex3f(292, 197, -1);
	glVertex3f(295, 211, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(331, 224, -1);
	glVertex3f(332, 201, -1);
	glVertex3f(337, 184, -1);
	glVertex3f(339, 188, -1);
	glVertex3f(337, 217, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(315, 300, -1);
	glVertex3f(331, 272, -1);
	glVertex3f(344, 237, -1);
	glVertex3f(354, 238, -1);
	glVertex3f(342, 271, -1);
	glVertex3f(334, 288, -1);
	glVertex3f(326, 300, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(354, 238, -1);
	glVertex3f(344, 237, -1);
	glVertex3f(342, 230, -1);
	glVertex3f(345, 179, -1);
	glVertex3f(352, 158, -1);
	glVertex3f(365, 163, -1);
	glVertex3f(365, 182, -1);
	glVertex3f(363, 203, -1);
	glVertex3f(357, 231, -1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(365, 163, -1);
	glVertex3f(352, 158, -1);
	glVertex3f(347, 11, -1);
	glVertex3f(351, 17, -1);
	glVertex3f(362, 120, -1);
	glEnd();

	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex3f(-133, 245, -1);
	glVertex3f(-125, 273, -1);
	glVertex3f(-15, 295, -1);
	glVertex3f(-13, 300, -1);
	glVertex3f(216, 250, -1);
	glVertex3f(213, 235, -1);
	glVertex3f(116, 282, -1);
	glVertex3f(116, 271, -1);
	glVertex3f(137, -102, -1);
	glVertex3f(134, -121, -1);
	glVertex3f(321, 216, -1);
	glVertex3f(321, 207, -1);
	glEnd();

	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(-125, 273, -1);
	glVertex3f(-113, 300, -1);
	glEnd();

}

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glScalef(1.8,1.8,1.0);
	marco();
	Cuello();
	pelo();
	oreja();
	cara();
	Brillos();

	

	glutSwapBuffers();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	glOrtho(-window_w, window_w, -window_h, window_h, 0.1, 20);
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	//glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(window_w, window_h);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Dibujo 2D"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	//glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
	//glutSpecialFunc     ( arrow_keys );	//Otras
	glutMainLoop();          // 

	return 0;
}
