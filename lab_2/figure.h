#include <iostream>
#include <windows.h>
using namespace std;
class Figure{
    public:      // ��������� ��������� ����� ������--------------------
      int x, y;      // ����������
	  bool color;    // white = true, black = false
        Figure(){  // �����������
        	// ���������� ����� �� ����������
			x = 4;
        	y = 8;
        };
        Figure(const Figure &figure): // ������������ �����������
        color(figure.color){ 
        	cout << "\n Cepid figure color";
		};
		~Figure(){ // �������������
	    	// ��������� ������ ���� ��������
	    	cout << "\n~~~~~Figure Delete~~~~~ \n";
	    };
	    int move(int _x, int _y, int _direction){
		    x = _x;
		    y = _y;
		}
 };
 // pawn, horse, queen; 
 class pawn: public Figure{ 
  public:
 	int move(int _x, int _y, int _direction ){ // ������ ���� ����
			switch(_direction){
		   	   case 1: // ������
		   	   	  y=(y-_y < 1 || y - _y > 8)? y:y - _y; /////
		   	   	  x-=_x;
		   		  break;
		   	   case 2: // ����� +1
		   		  y-=_y;
		   		  break;
		   	   case 3: // ����� +2 
		   		  y-=2;
		   		  break;
		   	   case 4: // ��������
		   		  y-=_y;
		   		  x+=_x;
		   		  break;
		   	   default:
		   		  return 0;
	        }
	        return 1;  
	 } //*/
 };
 class hourse: public Figure{ 
  public:
 	int move(int _x, int _y, int _direction ){ // ������ ���� ���� 
			 switch(_direction){
		   	   case 1: // ������
		   	   	  x-=2;
		   	   	  y-=_y;
		   		  break;
		   	   case 2: // �����
		   		  y-=2;
		   		  x-=_x;
		   		  break;
		   	   case 3: // ��������
		   		  y-=2;
		   		  x+=_x;
		   		  break;
		   	   case 4: // �����
		   		  x+=2;
		   		  y-=_y;
		   		  break;
		   	   case 5: // ������
		   	   	  x+=2;
		   	   	  y+=_y;
		   		  break;
		   	   case 6: // �����
		   		  y+=2;
		   		  x+=_x;
		   		  break;
		   	   case 7: // ��������
		   		  y+=2;
		   		  x-=_x;
		   		  break;
		   	   case 8: // �����
		   		  x-=2;
		   		  y+=_y;
		   		  break;
		   	   default:
		   		  return 0;
	         }
	        return 1;  
	 } //*/
 };
 class gueen: public Figure{  
  public:
 	int move(int _x, int _y, int _direction ){ // ������ �����	
 	          switch(_direction){
		   	   case 1: // ������
		   	   	  x-=_x;
		   		  break;
		   	   case 2: // �����
		   		  x-=_x;
				  y-=_y;
		   		  break;
		   	   case 3: // ��������
		   		  y-=_x;
		   		  break;
		   	   case 4: // �����
		   		  y-=_y;
		   		  x+=_x;
		   		  break;
		   	   case 5: // ������
		   	   	  x+=_x;
		   		  break;
		   	   case 6: // �����
		   		  x+=_x;
		   		  y+=_y;
		   		  break;
		   	   case 7: // ��������
		   		  y+=_x;
		   		  break;
		   	   case 8: // �����
		   		  x-=_x;
		   		  y+=_y;
		   		  break;
		   	   default:
		   		  return 0;
	          }
	        return 1;  
	 }
 }; 
 
