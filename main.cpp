#include<iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<time.h>

using namespace std;

const int ANCHO=600, ALTO=200;

const int dAnc=10, dAlt=5;

void gotoxy(int x, int y) {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void dibujar(char plano[ALTO/dAlt][ANCHO/dAnc+1], int A, int B, char C) {
	
	B = ALTO/dAlt-1-B;
	if(A<0 || B<0 || A >= ANCHO/dAnc || B >= ALTO/dAlt) return;
	plano[B][A] = C;
}

class Mapa{
	
private:
	
	
	
	
public:
	void pintarMapa(char plano[ALTO/dAlt][ANCHO/dAnc+1]) {
		for(int i=0; i<ANCHO/dAnc;i++) {
			for(int j=0;j>ALTO/dAlt;j++) {
				if(i==0 || i==59 || j==0 || j==39)
					dibujar(plano,i,j,'*');
				if(j%3==0)
					dibujar(plano,i,j,'_');
			}
		}
	}
};


main() {
	
	char plano[ALTO/dAlt][ANCHO/dAnc+1];
	for(int i=0; i<ALTO/dAlt; i++)
		plano[i][ANCHO/dAnc] = '\n';
	plano[ALTO/dAlt+1][ANCHO/dAnc] = '\o';
	
	mapa j1;
	
	bool juego=true;
	
	while(juego){
		for(int i=0; i<ALTO/dAlt; i++){
			for(int j=0; j<ANCHO/dAnc; j++) {
				plano[i][j]= ' ';
			}
		}
		
		j1.pintarMapa(plano);
		
		gotoxy(0,0);
		puts(plano[0]);
	}
	
	return 0;
};
