#include <iostream>
#include <windows.h>
using namespace std;
void graf(int _x, int _y, char _view){ // �����: �������� ����������� ���������� ����
 	int i=1,j=1;
 	for(i=1; i <= 8; i++){
 		cout << "|" << i;
 	}
 	cout << endl;
	 for (i=1; i <= 8; i++){
	 	for (j=1; j <= 8; j++){
	 		 if(_x == j && _y == i){
	 		     switch(_view){ // ����������� ������ � ��������� �� �� ����
		   	        case 'P': 
		   	   	     cout << " P";
		   		     break;
		   	        case 'Q':
		   		     cout << " Q";
		   		     break;
		   	        case 'H': 
		   		     cout << " H";
		   		     break;
		   	        default:
		   		     break;
	              }
	         }
			 else{
			 	cout << " +"; // ���������� ������ �������
			 	/*
	 	         if (i % 2 == 0){ // �������� ������� ��� ���� o#o#o#o#
	 	            if(j%2)       // (�� ��������������� ����� ��� :/ )
			          cout << " o";
			        else
			          cout << " #";
	 	          }
	 	         else{
	 	            if(j%2)
			          cout << " #";
			        else
			          cout << " o";
	 	          }      //*/
	 	    }
	     }
		 cout << "\n";
	 }
 }
 
