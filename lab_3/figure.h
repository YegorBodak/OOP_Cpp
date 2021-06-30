#include <iostream>
#include <windows.h>
using namespace std;
class Figure {
protected:
	int x, y;      // координати
	bool color;    // white = true, black = false
public:      // Стандартні параметри кожної фігури--------------------
	Figure() {  // Конструктор
		// Координати фігур за умовчанням
		x = 0;
		y = 0;
		//cout << "New Figura" << endl;
	};
	Figure(const Figure & figure) : // конструктор копирования
		color(figure.color) {
		//x = rand() % 8;
		//y = rand() % 8;
		cout << "\n Cepid figure color";
	}; 
	~Figure() { // Деконструктор
		// Видалення фігури після програшу
		cout << "\n   ---(Figure Delete)---";
		x = 0;
		y = 0;
	};
	virtual void move(int _x, int _y) {
		x = _x;
		y = _y;
	}
	void setX(int X) { // set
		x = X;
	}
	void setY(int Y) { // set
	    y = Y;
	}
	int getX() {   // get
		return x;
	}
	int getY() {  // get
		return y;
	}
	Figure & operator = (const Figure  other) { // Оператор присвоєння
		Figure temp;
		this->x = other.x;
		this->y = other.y;
	}
	Figure operator - (const Figure ); //
};

Figure Figure::operator - (const Figure other) { // Оператор бою
	Figure temp;
	temp.x = this->x - other.x;
	temp.y = this->y - other.y;
	return temp;
}
// pawn, horse, queen; 
class pawn :public Figure { //---------------------------------------------------------
public:
	virtual int move(int _x, int _y, int _direction) { // методу ходу пішки
		switch (_direction) {
			//шаблон 
			//y = (y - _y < 1 || y - _y > 8) ? y : y - _y;  
			//x = (x - _x < 1 || y - _y > 8) ? x : x - _x;
			//y = (y + _y < 1 || y + _y > 8) ? y : y + _y;  
			//x = (x + _x < 1 || y + _y > 8) ? x : x + _x;
		case 1:
			y = (y - _y < 1 || y - _y > 8) ? y : y - _y;  
			x = (x + _x < 1 || y + _y > 8) ? x : x + _x;
			break;
		case 2:
			y = (y - _y < 1 || y - _y > 8) ? y : y - _y;  
			x = (x - _x < 1 || y - _y > 8) ? x : x - _x; 
			break;
		case 3: 
			y = (y - _y < 1 || y - _y > 8) ? y : y - _y; 
			break;
		case 4: 
			y = (y - 2 < 1 || y - 2 > 8) ? y : y - 2;    
			break;
		default:
			return 0;
		}
		return 1;
	} 
	~pawn() {
		// Видалення фігури після програшу
		cout << "\n  ---(Figure Pawn Delete)---\n";
		x = 0;
		y = 0;
	}
}; 
class hourse : public Figure {
public:
	virtual int move(int _x, int _y, int _direction) { // методу ходу коня 
		switch (_direction) {
		//шаблон
			//y = (y - _y < 1 || y - _y > 8) ? y : y - _y; -
			//x = (x - _x < 1 || y - _y > 8) ? x : x - _x; -
			//y = (y + _y < 1 || y + _y > 8) ? y : y + _y; +
			//x = (x + _x < 1 || y + _y > 8) ? x : x + _x; +
			//шаблон + 3
			//y = (y - 3 < 1 || y - 3 > 8) ? y : y - 3;   -
			//x = (x - 3 < 1 || y - 3 > 8) ? x : x - 3;   -
			//y = (y + 3 < 1 || y + 3 > 8) ? y : y + 3;   +
			//x = (x + 3 < 1 || y + 3 > 8) ? x : x + 3;   +
		case 1: // ліворуч 
			y = (y - 3 < 1 || y - 3 > 8) ? y : y - 3;
			x = (x - _x < 1 || y - _y > 8) ? x : x - _x;
			break;
		case 2: // прямо
			y = (y - 3 < 1 || y - 3 > 8) ? y : y - 3;
			x = (x + _x < 1 || y + _y > 8) ? x : x + _x;
			break;
		case 3: // праворуч
			x = (x + 3 < 1 || y + 3 > 8) ? x : x + 3;
			y = (y - _y < 1 || y - _y > 8) ? y : y - _y;
			break;
		case 4: // назад
			x = (x + 3 < 1 || y + 3 > 8) ? x : x + 3;
			y = (y + _y < 1 || y + _y > 8) ? y : y + _y;
			break;
		case 5: // ліворуч
			y = (y + 3 < 1 || y + 3 > 8) ? y : y + 3;
			x = (x + _x < 1 || y + _y > 8) ? x : x + _x;
			break;
		case 6: // прямо
			y = (y + 3 < 1 || y + 3 > 8) ? y : y + 3;
			x = (x - _x < 1 || y - _y > 8) ? x : x - _x;
			break;
		case 7: // праворуч
			x = (x - 3 < 1 || y - 3 > 8) ? x : x - 3;
			y = (y + _y < 1 || y + _y > 8) ? y : y + _y;
			break;
		case 8: // назад
			x = (x - 3 < 1 || y - 3 > 8) ? x : x - 3;
			y = (y - _y < 1 || y - _y > 8) ? y : y - _y;
			break;
		default:
			return 0;
		}
		return 1;
	} 
	~hourse() {
		// Видалення фігури після програшу
		cout << "\n  ---(Figure Hourse Delete)---\n";
		x = 0;
		y = 0;
	}
};
class queen : public Figure { //------------------------------------------------------
public:
	virtual int move(int _x, int _y, int _direction) { // метод ферзи	
		switch (_direction) {
			//шаблон 
			//y = (y - _y < 1 || y - _y > 8) ? y : y - _y; 
			//x = (x - _x < 1 || y - _y > 8) ? x : x - _x;
			//y = (y + _y < 1 || y + _y > 8) ? y : y + _y;
			//x = (x + _x < 1 || y + _y > 8) ? x : x + _x; 
		case 1: 
			y = (y - _y < 1 || y - _y > 8) ? y : y - _y;
			break;
		case 2: 
			x = (x + _x < 1 || y + _y > 8) ? x : x + _x;
			break;
		case 3: 
			y = (y + _y < 1 || y + _y > 8) ? y : y + _y;
			break;
		case 4: 
			x = (x - _x < 1 || y - _y > 8) ? x : x - _x;
			break;
		case 5:
			y = (y - _y < 1 || y - _y > 8) ? y : y - _y;
			x = (x + _x < 1 || y + _y > 8) ? x : x + _x;
			break;
		case 6: 
			x = (x + _x < 1 || y + _y > 8) ? x : x + _x;
			y = (y + _y < 1 || y + _y > 8) ? y : y + _y;
			break;
		case 7:
			x = (x - _x < 1 || y - _y > 8) ? x : x - _x;
			y = (y + _y < 1 || y + _y > 8) ? y : y + _y;
			break;
		case 8:
			x = (x - _x < 1 || y - _y > 8) ? x : x - _x;
			y = (y - _y < 1 || y - _y > 8) ? y : y - _y;
			break;
		default:
			return 0;
		}
		return 1;
	}
	~queen() {
		// Видалення фігури після програшу
		cout << "\n  ---(Figure Queen Delete)---\n";
		x = 0;
		y = 0;
	}
}; 
 

