#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;
void graf(int Px, int Py, char Pview,
	      int Qx,int Qy, char Qview,
	      int Hx, int Hy, char Hview) { // метод: візуальне відображення
	int i = 1, j = 1;	
	for (i = 1; i <= 8; i++) {
		for (j = 0; j <= 8; j++) {
			if (Qx == j && Qy == i)  // Прінт фігури
				cout << " " << Qview; 
			else if (Px == j && Py == i) //Прінт фігури противника
				cout << " " << Pview;
			else if (Hx == j && Hy == i) //Прінт фігури противника
				cout << " " << Hview;
			else if (0 == j) // стінка координат
				cout << i << "|";
			else {/*
				if (i % 2 == 0) { // шахматна графіка для поля
					if (j % 2)       
						cout << " +";
					else
						cout << " .";
				}
				else {
					if (j % 2)
						cout << " .";
					else
						cout << " +";
				} */
				cout << " .";
			}
		}
		cout << "\n";
	}
	cout << "@||A|B|C|D|E|F|G|H|";
	cout << endl;
}