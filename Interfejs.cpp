#include "pch.h"
#include "Interfejs.h"
using namespace std;

//FUNKCJA WCZYTUJE GRAF Z PLIKU
void Wczytaj(Graf *&_Graf)
{
	int Krawedzie;
	int Wierzcholki;
	int Start;
	int wierz_poccz;
	int wierz_kon;
	int waga;
	string nazwa_pliku;
	
	ifstream plik;
	printf("podaj nazwe pliku \n");
	cin >> nazwa_pliku;


	plik.open(nazwa_pliku.c_str());

	if (plik.good())
	{
		plik >> Krawedzie;
		plik >> Wierzcholki;
		plik >> Start;
		_Graf = new Graf(Wierzcholki, Krawedzie, Start);
		while (!plik.eof())
		{
			plik >> wierz_poccz;
			plik >> wierz_kon;
			plik >> waga;

			_Graf->dodaj_krawedz(wierz_poccz, wierz_kon, waga);
		}

	}
	else
	{
		printf("zla nazwa pliku \n");
	}
	plik.close();


}

//FUNKCJA ODPOWIADAJACA ZA TWORZENIE GRAFU
//NALEZY PODAC ILOSC WIERZCHOLKOW, GESTOSC, ORAZ WIERZCHOLEK STARTOWY
void generuj()
{
	int Krawedzie;
	int Wierzcholki;
	int Start;
	int licznik=0;
	double gestosc;
	string nazwa_pliku;
	ofstream plik;
	int waga;
	printf("podaj nazwe pliku \n");
	cin >> nazwa_pliku;

	plik.open(nazwa_pliku.c_str());
	printf("podaj liczbe wierzcholkow , gestosc (0-1) np 0.2, wierzcholek startowy \n");
	cin >>Wierzcholki >> gestosc>> Start;
	Krawedzie = ((Wierzcholki*(Wierzcholki - 1)) / 2)*gestosc;

		plik << Krawedzie << " " << Wierzcholki << " " << Start << endl;

		for (int i = 0; i < Wierzcholki; i++)
			for (int j = i; j < Wierzcholki; j++)
			{

				if (i != j && licznik< Krawedzie)
				{
					waga = rand() % 50 + 1;
					plik << i << " " << j << " " << waga << endl;
					plik << j << " " << i << " " << waga << endl;
					licznik++;
				}
			}

	plik.close();

}

//MENU UZYTKOWNKIA DO KOMUNIKACJI Z PROGRAMEM
//MOZNA WYBIERAC CO CHCEMY ZROBIC Z PROGRAMEM
// STWORZYC GRAF, WCZYTAC Z PLIKU, WYSWIETLIC, ALBO PODDAC ALGORYTMOWI DIJKSTRA DLA LISTY I MACIERZY
void menu()
{
	clock_t start, stop;
	char opcja;
	Graf *_Graf = NULL;
	dane* tab;
	cout.precision(6);
	while (1)
	{
		cout << "G - Generuj" << endl;
		cout << "W - Wczytaj" << endl;
		cout << "O - Wyswietlanie grafu" << endl;
		cout << "D - Dijkstra macierz" << endl;
		cout << "L - Dijkstra lista" << endl;
		cout << "K - Aby zakonczyc" << endl;

		cout << "podaj opcje" << endl;

		cin >> opcja;

		switch (opcja)
		{
		case 'K':
			return;
		case 'O':
			cout << "Macierz:" << endl;
			_Graf->wyswietl();

			cout << endl << "Lista:" << endl;
			_Graf->wyswietl_liste();
			break;
		case 'G':
			generuj();
			break;
		case 'W':
			Wczytaj(_Graf);
			break;
		case 'D':
		{
			start = clock();								//POCZATEK ZLICZANIA CZASU DZIALANIA ALGORYTMU
			
			for (int i = 0; i < 100; i++)
			{
				 tab = _Graf->Dijkstra();
				
				
			}
			stop = clock();									//KONIEC ZLICZANIA CZASU DZIALANIA ALGORYTMU
			cout << " ms: " << stop - start << endl;		
			_Graf->zapisz(tab);
		}
		break;
		case 'L':
		{

			start = clock();								//POCZATEK ZLICZANIA CZASU DZIALANIA ALGORYTMU
		

			for (int i = 0; i < 100; i++)
			{
				 tab = _Graf->Dijkstra_Lista();
			
			}
			stop = clock();									//KONIEC ZLICZANIA CZASU DZIALANIA ALGORYTMU
			cout << " ms: " << stop - start << endl;	
			_Graf->zapisz(tab);
		}
		break;
		}
	}
}
