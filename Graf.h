#pragma once
#include "struktury.h"

using namespace std;

//KLASA GRAFU ZAWIERA OBIEKTY I METODY POTRZEBNE DO STWORZENIA GRAFU I DZIALANIA ALGORYTMU DIJKSTRA
class Graf
{

private:

	int *droga;
	int **MacierzGrafu;
	Element *element;
	Element **Lista;
	int Wierzcholki;
	int Krawedzie; 
	int Start;
public:
	Graf() {};
	Graf(int Wierzcholki , int Krawedzie, int Start);
	~Graf();
	int dodaj_krawedz(int i, int j, int waga);
	void wyswietl();
	void wyswietl_liste();
	int Minimum(dane* tab);
	dane* Dijkstra();
	dane* Dijkstra_Lista();
	void zapisz( dane *tab);


};




