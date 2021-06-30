//У похідних класах перевантажити бінарний мінус a - b як «a б’є b» і
//оператор «++»(наступне положення фігури – відповідно до класу) для
//виведення координат відповідної фігури.Функцію «хід» перетворити на
//віртуальну.

#include <iostream>
#include <windows.h>
#include "figure.h" // бібліотека класу
#include "grafika.h" // бібліотека графіки і деякої логіки
using namespace std;
int main() { 
    pawn P; // Об'єкти
    queen Q;
    hourse H;
    int dir, dl = 1; // напрям та довжина пересування
    bool game = false;
    P.move(4, 2); // Умовні координати
    H.move(2,1);
    Q.move(4,8);
    system("color 6");
    system("title Лаба 3 \ Шахмати");
    while (!game) { // цикл демонстрации
       
        graf(P.getX(), P.getY(), 'P', // графіка
             Q.getX(), Q.getY(), 'Q',
             H.getX(), H.getY(), 'H');  

       cout << endl << " Queen X = " << Q.getX() << " Y = " << Q.getY() << endl; // відображення коо..
       cout << " Pawn  X = " << P.getX() << " Y = " << P.getY() << endl;  // відображення коо...
       cout << " Hourse X = " << H.getX() << " Y = " << H.getY() << endl; // відображення коо...
       
       //Один із варіантів перевірки за допомогую тернального оператора
       //
       //(Q.getX() == P.getX() && Q.getY() == P.getY()) ? P - Q : Q;
       //(Q.getX() == H.getX() && Q.getY() == H.getY()) ? H - Q : Q;
       
       if (Q.getX() == P.getX() && Q.getY() == P.getY()) { // перевірка на пересічення   
           P - Q;
           //P.~pawn();
       }
       if (Q.getX() == H.getX() && Q.getY() == H.getY()) { // перевірка на пересічення
           //H - Q;
           H.~hourse();
       }
       
       cout << "\n Direction Queen: "; cin >> dir; // отримання напрямку
       cout << "\n Travel length Queen: "; cin >> dl; // відстання переміщення
       Q.move(dl, dl, dir); // функ. хід
      
       //Пешка
      // graf(P.getX(), P.getY(), 'P'); 
      // cout << "\nDirection Pawn: "; cin >> dir;
      // P.move(1, 1, dir);
       //Конь
      // graf(H.getX(), H.getY(), 'H');
      // cout << "\nDirection Hourse: "; cin >> dir;
      // H.move(1, 1, dir);
        system("cls");
    } 
}
