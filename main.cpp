#include<iostream>
using namespace std;

class Juego {
public:
	Juego(int, int, int, int);
	~Juego();
	int obtNumVidas();
	int obtTiempo();
	bool ubicarInicio(int);
	int obtPunt();
	int obtFilasAvanzadas();
	void numVidas(int);
	void tiempo(int);
	void lugarInicio(int, bool);
	void puntaje(int);
	void filasAvanzadas(int);
	
private:
	int vidas;
	int puntos;
	int filasAvanz;
	int tiempoRest;
	bool inicio[5];
};

class Rana {
public:
	Rana(double, double, int, int, double, double, char);
	~Rana();
	double obtCentroX();
	double obtCentroY();
	int obtLargo();
	int obtCuadriculaY();
	double obtDistIzq();
	double obtDistDer();
	char obtOrient();
	void estCentroX(double);
	void estCentroY(double);
	void estLargo(int);
	void estCuadriculaY(int);
	void estDistIzq(double);
	void estDistDer(double);
	void estOrient(char);
	void dibujarRana();
	void moverRana(char, Juego&);
	
private:
	double centroX;
	double centroY;
	int largo;
	int cuadriculaY;
	double distIzq;
	double distDer;
	char orientacion;
};


int main (int argc, char *argv[]) {
	
	
	
	return 0;
}

