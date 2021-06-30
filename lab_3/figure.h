#include <iostream>
#include <windows.h>
using namespace std;
class Figure {
protected:
	int x, y;      // ����������
	bool color;    // white = true, black = false
public:      // ��������� ��������� ����� ������--------------------
	Figure() {  // �����������
		// ���������� ����� �� ����������
		x = 0;
		y = 0;
		//cout << "New Figura" << endl;
	};
	Figure(const Figure & figure) : // ����������� �����������
		color(figure.color) {
		//x = rand() % 8;
		//y = rand() % 8;
		cout << "\n Cepid figure color";
	}; 
	~Figure() { // �������������
		// ��������� ������ ���� ��������
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
	Figure & operator = (const Figure  other) { // �������� ���������
		Figure temp;
		this->x = other.x;
		this->y = other.y;
	}
	Figure operator - (const Figure ); //
};

Figure Figure::operator - (const Figure other) { // �������� ���
	Figure temp;
	temp.x = this->x - other.x;
	temp.y = this->y - other.y;
	return temp;
}
// pawn, horse, queen; 
class pawn :public Figure { //---------------------------------------------------------
public:
	virtual int move(int _x, int _y, int _direction) { // ������ ���� ����
		switch (_direction) {
			//������ 
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
		// ��������� ������ ���� ��������
		cout << "\n  ---(Figure Pawn Delete)---\n";
		x = 0;
		y = 0;
	}
}; 
class hourse : public Figure {
public:
	virtual int move(int _x, int _y, int _direction) { // ������ ���� ���� 
		switch (_direction) {
		//������
			//y = (y - _y < 1 || y - _y > 8) ? y : y - _y; -
			//x = (x - _x < 1 || y - _y > 8) ? x : x - _x; -
			//y = (y + _y < 1 || y + _y > 8) ? y : y + _y; +
			//x = (x + _x < 1 || y + _y > 8) ? x : x + _x; +
			//������ + 3
			//y = (y - 3 < 1 || y - 3 > 8) ? y : y - 3;   -
			//x = (x - 3 < 1 || y - 3 > 8) ? x : x - 3;   -
			//y = (y + 3 < 1 || y + 3 > 8) ? y : y + 3;   +
			//x = (x + 3 < 1 || y + 3 > 8) ? x : x + 3;   +
		case 1: // ������ 
			y = (y - 3 < 1 || y - 3 > 8) ? y : y - 3;
			x = (x - _x < 1 || y - _y > 8) ? x : x - _x;
			break;
		case 2: // �����
			y = (y - 3 < 1 || y - 3 > 8) ? y : y - 3;
			x = (x + _x < 1 || y + _y > 8) ? x : x + _x;
			break;
		case 3: // ��������
			x = (x + 3 < 1 || y + 3 > 8) ? x : x + 3;
			y = (y - _y < 1 || y - _y > 8) ? y : y - _y;
			break;
		case 4: // �����
			x = (x + 3 < 1 || y + 3 > 8) ? x : x + 3;
			y = (y + _y < 1 || y + _y > 8) ? y : y + _y;
			break;
		case 5: // ������
			y = (y + 3 < 1 || y + 3 > 8) ? y : y + 3;
			x = (x + _x < 1 || y + _y > 8) ? x : x + _x;
			break;
		case 6: // �����
			y = (y + 3 < 1 || y + 3 > 8) ? y : y + 3;
			x = (x - _x < 1 || y - _y > 8) ? x : x - _x;
			break;
		case 7: // ��������
			x = (x - 3 < 1 || y - 3 > 8) ? x : x - 3;
			y = (y + _y < 1 || y + _y > 8) ? y : y + _y;
			break;
		case 8: // �����
			x = (x - 3 < 1 || y - 3 > 8) ? x : x - 3;
			y = (y - _y < 1 || y - _y > 8) ? y : y - _y;
			break;
		default:
			return 0;
		}
		return 1;
	} 
	~hourse() {
		// ��������� ������ ���� ��������
		cout << "\n  ---(Figure Hourse Delete)---\n";
		x = 0;
		y = 0;
	}
};
class queen : public Figure { //------------------------------------------------------
public:
	virtual int move(int _x, int _y, int _direction) { // ����� �����	
		switch (_direction) {
			//������ 
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
		// ��������� ������ ���� ��������
		cout << "\n  ---(Figure Queen Delete)---\n";
		x = 0;
		y = 0;
	}
}; 
 

