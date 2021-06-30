#include <iostream>
#include <windows.h>
#include "figure.h" // �������� �����
#include "grafika.h" // �������� ������� � ����� �����
using namespace std;
   int main() {
	pawn P; // ��'����
 	gueen Q;
 	hourse H;
 	int dir,dl = 1; // ������ �� ������� �����������
	bool game = false;
	//system("color DF");
	
 	while(!game){ // ���� ������������
	    /*
		graf(P.x, P.y, 'P'); // �������
	    cout << "\n        3";
 		cout << "\n      1 2 4";
 		cout << "\n       [P]  ";
 		cout << "\n         " << endl;
 	    cout << "\nDirection Pawn: "; cin >> dir; // �������
 		P.move(1, 1, dir); // ������ � ������������
 		system("cls");  // ��������
 		//*/
 		//*
 		
 		graf(Q.x, Q.y, 'Q');
 		cout << "\n    2    3    4";
 		cout << "\n     x   X   x ";
 		cout << "\n       x X x   ";
 		cout << "\n    1 XX[Q]XX 5";
 	    cout << "\n       x X x   ";
 		cout << "\n     x   X   x ";
 		cout << "\n    8    7    6" << endl;
 	    cout << "\nDirection Queen: "; cin >> dir;
 	    cout << "\nTravel length Queen: "; cin >> dl;
 		//Q.move(dl, dl, dir);
 		Q.Figure::move(4,5,0);
 		system("cls");
 		//*/
 		/*
 		graf(H.x, H.y, 'H');
 		cout << "\n       2 X 3";
 		cout << "\n         X ";
 		cout << "\n     1   X   4";
 		cout << "\n     XXX[H]XXX";
 	    cout << "\n     8   X   5";
 		cout << "\n         X ";
 		cout << "\n       7 X 6" << endl;
 	    cout << "\nDirection Hourse: "; cin >> dir;
 		H.move(1, 1, dir);
 		system("cls");
 		*/
 	}
 }
