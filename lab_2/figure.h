#include <iostream>
#include <windows.h>
using namespace std;
class Figure{
    public:      // Стандартні параметри кожної фігури--------------------
      int x, y;      // координати
	  bool color;    // white = true, black = false
        Figure(){  // Конструктор
        	// Координати фігур за умовчанням
			x = 4;
        	y = 8;
        };
        Figure(const Figure &figure): // конструктлор копирования
        color(figure.color){ 
        	cout << "\n Cepid figure color";
		};
		~Figure(){ // Деконструктор
	    	// Видалення фігури після програшу
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
 	int move(int _x, int _y, int _direction ){ // методу ходу пішки
			switch(_direction){
		   	   case 1: // ліворуч
		   	   	  y=(y-_y < 1 || y - _y > 8)? y:y - _y; /////
		   	   	  x-=_x;
		   		  break;
		   	   case 2: // прямо +1
		   		  y-=_y;
		   		  break;
		   	   case 3: // прямо +2 
		   		  y-=2;
		   		  break;
		   	   case 4: // праворуч
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
 	int move(int _x, int _y, int _direction ){ // методу ходу коня 
			 switch(_direction){
		   	   case 1: // ліворуч
		   	   	  x-=2;
		   	   	  y-=_y;
		   		  break;
		   	   case 2: // прямо
		   		  y-=2;
		   		  x-=_x;
		   		  break;
		   	   case 3: // праворуч
		   		  y-=2;
		   		  x+=_x;
		   		  break;
		   	   case 4: // назад
		   		  x+=2;
		   		  y-=_y;
		   		  break;
		   	   case 5: // ліворуч
		   	   	  x+=2;
		   	   	  y+=_y;
		   		  break;
		   	   case 6: // прямо
		   		  y+=2;
		   		  x+=_x;
		   		  break;
		   	   case 7: // праворуч
		   		  y+=2;
		   		  x-=_x;
		   		  break;
		   	   case 8: // назад
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
 	int move(int _x, int _y, int _direction ){ // методу ферзи	
 	          switch(_direction){
		   	   case 1: // ліворуч
		   	   	  x-=_x;
		   		  break;
		   	   case 2: // прямо
		   		  x-=_x;
				  y-=_y;
		   		  break;
		   	   case 3: // праворуч
		   		  y-=_x;
		   		  break;
		   	   case 4: // назад
		   		  y-=_y;
		   		  x+=_x;
		   		  break;
		   	   case 5: // ліворуч
		   	   	  x+=_x;
		   		  break;
		   	   case 6: // прямо
		   		  x+=_x;
		   		  y+=_y;
		   		  break;
		   	   case 7: // праворуч
		   		  y+=_x;
		   		  break;
		   	   case 8: // назад
		   		  x-=_x;
		   		  y+=_y;
		   		  break;
		   	   default:
		   		  return 0;
	          }
	        return 1;  
	 }
 }; 
 
