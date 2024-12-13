#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<graphics.h>
#include"SQUARTLE2.h"
#include"CHARMANDER2.h"
#include"DISPAROS2.h"
#include"BOOM2.h"

#define B RGB(236, 189, 99) // NEGRO
#define C 3 // CIAN
#define R 4 // ROJO
#define D RGB(40, 37, 29) // GRIS OSCURO
#define W 15 // BLANCO
#define U RGB(80, 100, 255)
#define p RGB(196, 138, 60)
#define q RGB(249, 233, 199)
#define X RGB(240, 115, 115) // COLOR PARA LA REAPARICION DE CHARMANDER
//#define color1 RGB(18, 28, 16)
#define color1 RGB(3, 1, 15)

void POKEBOLAS();
void AMBIENTACION();

void far setbkcolor(int color);

int copia_squirtle[200][500], copia_charmander[200][500], squirtle[200][500], charmander[200][500];

int main(){
	
	int gd = DETECT, gm, angle = 0, RX, RY;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	
	setbkcolor(color1); // ESTA FUNCION SIRVE PARA CAMBIAR EL COLOR DE FONDO
	cleardevice(); // ESTA FUNCION ES PARA DESPEJAR UNA PANTALLA GRAFICA Y PODER VER LOS SIGUIENTES CAMBIOS QUE SE DEN GRACiAS A LA FUNCION SETBKCOLOR
	
	
	int i, k=1050, h=390, j=0;
	
	int fin=0, n=50;	
	
	delay(1500);
	
	for(fin=0; fin<1000; fin++){
		
		// ESCENARIO
		AMBIENTACION();
		
		COPIA_SQUIRTLE(copia_squirtle); // EN ESTA FUNCION LA MATRIZ SE PASA COMO PARAMAETRO Y LUEGO SE LLENA LA MATRIZ DE VALORES (DIBUJO 
		COPIA_CHARMANDER(copia_charmander);
		
		// SALIDA DE LA POKEBOLA
		for(i=0; i<160; i++){ // ESTE ES PARA EOVER LAS COLUENAS DEL DIBUJO
			for(j=0; j<125; j++){ // ESTE ES PARA EOVER LAS FILAS DEL DIBUJO
				if(copia_squirtle[j][i]!=0){ // DIBUJO DE UN SOLO COLOR DEL SQUIRTLE	
					putpixel(n+i, h+j, copia_squirtle[j][i]); // DIBUJO EN BLAMCO DE SQUIRTLE
				}
				
				if(*(*(copia_charmander+j)+i)==X){ // DIBUJO DE UN SOLO COLOR DEL SQUIRTLE	
					putpixel(k+i, h+j, *(*(copia_charmander+j)+i));
				}
      	}	
		}
	
		delay(1000);
		
		SQUIRTLE(squirtle);
		CHARMANDER(charmander);
		
		for(i=0; i<160; i++){ // ESTE ES PARA EOVER LAS COLUENAS DEL DIBUJO
			for(j=0; j<125; j++){ // ESTE ES PARA EOVER LAS FILAS DEL DIBUJO
				if(*(*(squirtle+j)+i)!=0){ // DIBUJO DE UN SOLO COLOR DEL SQUIRTLE	
					putpixel(n+i, h+j, *(*(squirtle+j)+i));
				}
				
				if(*(*(charmander+j)+i)!=0){ // DIBUJO DE UN SOLO COLOR DEL SQUIRTLE	
					putpixel(k+i, h+j, *(*(charmander+j)+i));
				}
      	}	
		}
		
		delay(500);
		
		CUERPO_SQUIRTLE();
		COLA();
		
		delay(1000);
		
		PODER(); // ATAQUES LIBRERIA DISPAROS
		
		EXPLOSION(); // EXPLOSION\ LIBRERIA BOOM
		//BOOM();
		
		cleardevice(); // SE ENCARGA DE LIMPIAR LA PANTALLA GRAFICA

		delay(500);
		fin++;

	}
	
	getch();
	closegraph();
	return 0;
}

void CUERPOS(){
	COLA();
}

void POKEBOLAS(){
	
   int poke_dere[200][500]={
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0, 0, 0 },
		{ 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0 },
		{ 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0 },
		{ 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0 },
		{ 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0 },
		{ R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
		{ R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
   	{ R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
      { R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
		{ R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
		{ R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
		{ R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
		{ R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
		{ D, D, R, R, R, R, R, R, D, D, D, D, D, D, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, D, D },
		{ D, D, R, R, R, R, R, R, D, D, D, D, D, D, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, D, D },
		{ D, D, D, D, D, D, D, D, W, W, W, W, W, W, D, D, R, R, R, R, R, R, R, R, D, D, D, D, D, D, D, D },
		{ D, D, D, D, D, D, D, D, W, W, W, W, W, W, D, D, R, R, R, R, R, R, R, R, D, D, D, D, D, D, D, D },
		{ 0, 0, D, D, D, D, D, D, W, W, W, W, W, W, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, 0, 0 },
		{ 0, 0, D, D, D, D, D, D, W, W, W, W, W, W, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, 0, 0 },
		{ 0, 0, W, W, W, W, D, D, W, W, W, W, W, W, D, D, D, D, D, D, D, D, D, D, D, D, W, W, W, W, 0, 0 },
		{ 0, 0, W, W, W, W, D, D, W, W, W, W, W, W, D, D, D, D, D, D, D, D, D, D, D, D, W, W, W, W, 0, 0 },
		{ 0, 0, 0, 0, W, W, W, W, D, D, D, D, D, D, W, W, W, W, W, W, W, W, W, W, W, W, W, W, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, W, W, W, W, D, D, D, D, D, D, W, W, W, W, W, W, W, W, W, W, W, W, W, W, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, W, W, W, W, W, W, W, W, W, W, W, W, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, W, W, W, W, W, W, W, W, W, W, W, W, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	
   int poke_izqui[200][500]={
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0, 0, 0 },
		{ 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0 },
		{ 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0 },
		{ 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0 },
		{ 0, 0, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, 0, 0 },
		{ R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
		{ R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
      { R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
      { R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
		{ R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
		{ R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
		{ R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
		{ R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R },
		{ D, D, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, D, D, D, D, D, D, R, R, R, R, R, R, D, D },
		{ D, D, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, R, D, D, D, D, D, D, R, R, R, R, R, R, D, D },
		{ D, D, D, D, D, D, D, D, R, R, R, R, R, R, R, R, D, D, W, W, W, W, W, W, D, D, D, D, D, D, D, D },
		{ D, D, D, D, D, D, D, D, R, R, R, R, R, R, R, R, D, D, W, W, W, W, W, W, D, D, D, D, D, D, D, D },
		{ 0, 0, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, W, W, W, W, W, W, D, D, D, D, D, D, 0, 0 },
		{ 0, 0, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, D, W, W, W, W, W, W, D, D, D, D, D, D, 0, 0 },
		{ 0, 0, W, W, W, W, D, D, D, D, D, D, D, D, D, D, D, D, W, W, W, W, W, W, D, D, W, W, W, W, 0, 0 },
		{ 0, 0, W, W, W, W, D, D, D, D, D, D, D, D, D, D, D, D, W, W, W, W, W, W, D, D, W, W, W, W, 0, 0 },
		{ 0, 0, 0, 0, W, W, W, W, W, W, W, W, W, W, W, W, W, W, D, D, D, D, D, D, W, W, W, W, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, W, W, W, W, W, W, W, W, W, W, W, W, W, W, D, D, D, D, D, D, W, W, W, W, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, W, W, W, W, W, W, W, W, W, W, W, W, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, W, W, W, W, W, W, W, W, W, W, W, W, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	
	int j, i, n=0, k;
	
	for(i=0; i<42; i++){ 
		for(j=0; j<34; j++){
			if(poke_izqui[j][i]!=0){
				putpixel(50+i, 300+j, poke_izqui[j][i]);	
				putpixel(1200+i, 300+j, poke_dere[j][i]);
			}
		}		
	}

}

void AMBIENTACION(){
	
   int fondo[200][500]={
		{ 0, 0, 0, q, q, q, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, q, q, q, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, q, q, q, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ p, p, p, p, p, p, p, p, p, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ p, p, p, p, p, p, p, p, p, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ p, p, p, p, p, p, p, p, p, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ p, p, p, p, p, p, p, p, p, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ p, p, p, p, p, p, p, p, p, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ p, p, p, p, p, p, p, p, p, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	
	
	int XM , YM , Zise=2,MaxX,MaxY,contX,contY;
	// LA VARIABLR SIZE SERA LA VARIABLE QUE MULTIPLICARA EL TAMANIO DEL DIBUJO
	MaxX= 9*Zise;
	MaxY= 6*Zise;
	// PERSONAJE NORMAL
		
	int i, j, POSX=15, POSY=3, k, g, u;
	
	// ESTO ES PARA DIBUJAR LA TELEVISION
	
	j=0;
	
	for(k=0; k<16; k++){ // ESTO ES PARA DUBUJAR LAS LINEAS BLANCAS HORIZONTALES
		for(i=0; i<410; i++){
			putpixel(450+i, 3+j, 15);
		}
		j++;
		if(k==7){
			j=200;
		}
	}
	
	j=0;
	
	for(k=0; k<16; k++){ // ESTO ES PARA DUBUJAR LAS LINEAS BLANCAS VERTICALES
		for(i=0; i<208; i++){
			putpixel(442+j, 3+i, 15);
		}
		j++;
		if(k==7){
			j=414;
		}
	}
	
	for(g=0; g<9; g++){ // ESTE BUCLE SE ENCARGA DE DIBUJAR UNA FILA COMPLETA DE PERSONAS, EN ESTE CASO SERIAN 9 FILAS
		for(k=0; k<42; k++){ // ESNTE SE ENCARGA DE DIBUJAR LA CANTIDAD DE PERSONAS POR FILA
			for(XM=0,contX=0; XM<MaxX; XM+=Zise,contX++) { // ESTE BUCLE SE ENCARGA DE LAS POSICIONES (COLUMNAS) DE CADA PIXEL DE LA MATRIZ, ADEMAS PODRIA DECIRSE QUE ES MULTIPLICADOR DE PIEXELES
				for(YM=0,contY=0; YM<MaxY; YM+=Zise,contY++) { // ESTE BUCLE SE ENCARGA DE LAS POSICIONES (FILAS) DE CADA PIXEL DE LA MATRIZ, ADEMAS PODRIA DECIRSE QUE ES MULTIPLICADOR DE PIEXELES
					for(i=0; i<Zise; i++){ // ESTE SE ENCARGA DE DIBUJAR UN SOLO PIXEL DEPENDIENDO DE LA POSICION (COLUMNA) DEL MISMO EN LA MATRIZ
						for(j=0; j<Zise; j++){ // ESTE SE ENCARGA DE DIBUJAR UN SOLO PIXEL DEPENDIENDO DE LA POSICION (FILAS) DEL MISMO EN LA MATRIZ
							if(k<=13 || k>=29){ // ESTE CONDICIONAL HACE QUE SOLO SE DIBUJE LA MATRIZ CUANDO LLEGUE A UNA CANTIDAD DE PERSONAS PARA QUE SE PUEDA LA TV DESPUES
								if(fondo[contY][contX]!=0){
									putpixel(POSX+i+XM, POSY+j+YM, fondo[contY][contX]);	
								}
							}
						}
					}
				}
			}
			POSX+=30; // ESTO AYUDA A QUE LA MATRIZ SE EMPIECE A IMPRIMIR EN OTRO LUGAR EN EL EJE DE LAS X
		}
		POSY+=24, POSX=15; // ESTO AYUDA A QUE LA MATRIZ SE EMPIECE A IMPRIMIR EN OTRO LUGAR EN EL EJE DE LAS Y
	}	
	
	for(k=0; k<16; k++){ // ESTO ES PARA DUBUJAR LAS LINEAS BLANCAS
		for(i=0; i<1300; i++){
			putpixel(0+i, 250+j, 15);
		}
		j++;
		if(k==7){
			j=450;
		}
	}
	
	j=0;
	
	for(k=0; k<16; k++){ // ESTO ES PARA DUBUJAR LAS LINEAS BLANCAS (VERTICALES)
		for(i=0; i<448; i++){
			putpixel(0+j, 252+i, 15);
		}
		j++;
		if(k==7){
			j=1272;
		}
	}
	
	delay(2000);
	
	outtextxy(626, 100, "POKEMON");
	
	delay(2000);
	
	outtextxy(626, 100, "            ");
	
	outtextxy(560, 100, "SQUIRTLE VS CHARMANDER");
	
	delay(500);
	
	MaxX= 9*Zise;
	MaxY= 9*Zise;
	POSX=15, POSY=3;
	int POSX2=15, POSY2=20;
	
	for(u=0; u<4; u++){ // ESTA BUCLE SERVARA PARA INTERCALAR EL MOVIEMIENTO DE LAS PERSONAS
		POSX=15, POSY=3; // PARA QUE EN CADA CICLO INICIE DESDE SU POSICION INICIAIL
		for(g=0; g<9; g++){ // ESTE BUCLE SE ENCARGA DE DIBUJAR UNA FILA COMPLETA DE PERSONAS, EN ESTE CASO SERIAN 9 FILAS
			for(k=0; k<42; k++){ // ESNTE SE ENCARGA DE DIBUJAR LA CANTIDAD DE PERSONAS POR FILA
				for(XM=0,contX=0; XM<MaxX; XM+=Zise,contX++) { // ESTE BUCLE SE ENCARGA DE LAS POSICIONES (COLUMNAS) DE CADA PIXEL DE LA MATRIZ, ADEMAS PODRIA DECIRSE QUE ES MULTIPLICADOR DE PIEXELES
					for(YM=0,contY=0; YM<MaxY; YM+=Zise,contY++) { // ESTE BUCLE SE ENCARGA DE LAS POSICIONES (FILAS) DE CADA PIXEL DE LA MATRIZ, ADEMAS PODRIA DECIRSE QUE ES MULTIPLICADOR DE PIEXELES
						for(i=0; i<Zise; i++){ // ESTE SE ENCARGA DE DIBUJAR UN SOLO PIXEL DEPENDIENDO DE LA POSICION (COLUMNA) DEL MISMO EN LA MATRIZ
							for(j=0; j<Zise; j++){ // ESTE SE ENCARGA DE DIBUJAR UN SOLO PIXEL DEPENDIENDO DE LA POSICION (FILAS) DEL MISMO EN LA MATRIZ
								if(k<=13 || k>=29){ // ESTE CONDICIONAL HACE QUE SOLO SE DIBUJE LA MATRIZ CUANDO LLEGUE A UNA CANTIDAD DE PERSONAS PARA QUE SE PUEDA LA TV DESPUES
									if(u==1 && contY>5 || u==3 && contY>5){ 
										putpixel(POSX+i+XM, POSY+j+YM, fondo[contY+12][contX]);	// SENTAR A LAS PERSONAS
										continue;
									}
									if(fondo[contY][contX]!=0){
										putpixel(POSX+i+XM, POSY+j+YM, fondo[contY][contX]);	// PERSONAS ALZADAS
									}
								}
							}
						}
					}
				}
				POSX+=30; // ESTO AYUDA A QUE LA MATRIZ SE EMPIECE A IMPRIMIR EN OTRO LUGAR EN EL EJE DE LAS X
			}
			POSY+=24, POSX=15; // ESTO AYUDA A QUE LA MATRIZ SE EMPIECE A IMPRIMIR EN OTRO LUGAR EN EL EJE DE LAS Y
		}	
		delay(100);
	}
			
	POKEBOLAS(); // FUNCION QUE DIBUJA LAS POKEBOLAS
	
	
}

