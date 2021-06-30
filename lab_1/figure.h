#include <iostream>
#include <windows.h>
class Figure{ // ���� ������
    public:
    int x, y; // ����������
	//int direction; // ��������: 1 - ����,2 - �����,3 - �����,4 - �����.
	bool color; // white = true, black = false
        Figure(){ // �����������
			x = 0;
        	y = 0;
        };/*
        Figure(const Figure &name){
              *this = name;
        } */
   	    int move(int,int,int); // ����� ���� � ������ � �������� ��������.
		~Figure(){ // �������������
	    	//*
	    	if(!color){
 			   std::cout << "Figure Black Delete\n";
 		    }
		    else{
		 	   std::cout << "Figure White Delete\n";
		    } //*/
	    };
 };
 int Figure::move(int _x, int _y, int _direction ){ // ���������� ������ �� ������
			 switch(_direction){
		   	   case 1: // ������
		   	   	  x-=_x;
		   		  break;
		   	   case 2: // �����
		   		  y+=_y;
		   		  break;
		   	   case 3: // ��������
		   		  x+=_x;
		   		  break;
		   	   case 4: // �����
		   		  y-=_y;
		   		  break;
		   	   default:
		   		  return 0;
	         }
	        return 1;    
 }
