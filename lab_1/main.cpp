#include <iostream>
#include <windows.h>
#include "figure.h"
using namespace std;
 int main() {
 	Figure a; // ����� ����
 	a.color = true; // ���� ������
	// /* �������� ������
	bool game = false;
 	while(!game){
 		cout << "X = " << a.x << " Y = " << a.y << endl;
 		if(!a.color){
 			cout << "Black Figure" << endl;
 		}
		else{
		 	cout << "White Figure" << endl;
		}
		int direction;
 		cin >> direction;
 		a.move(1, 1, direction);
 	 }
	// */
 }
