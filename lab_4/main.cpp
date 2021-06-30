//Текст подано у вигляді вектора, елементи якого є окремими рядками тексту
// Відомо, що текст складається з частин, кожна з яких починається словом
// «Розділ», розміщеним в окремому рядку.Перетворити вказаний текст на
// стільки окремих списків, скільки у ньому міститься розділів.
 //                                Варіант 2
// Відсортувати елементи вектора(з варіанта 1) і перетворити на два списки
// так, щоб у першому були тільки ті елементи, значення яких не повторюється,
// а в другому тільки ті, що мають дублікати(але без повторень), наприклад:
// вектор з елементами{ a, b, c, b, d, e, d, d }, перетвориться на списки : список 1
// –{ а, с, е }, список 2 –{ b, d }
// Реалізувати функції :
// -визначення довжини списку;
// -перетворення списку в дзеркально відображений;
// -виведення на екран i - го елемента(передбачити виняткову ситуацію,
//     якщо i лежатиме за межами списку).
#include <Windows.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <clocale>
#include <algorithm>
#include "Sort.h"
using namespace std;

// Доступ до конкретного елемента
void element_list(int element, list<string> list_str) {  
    element--; // для точного рядка
    int size = list_str.size();
    int i = 0;
    cout << endl;
    for (auto iter = list_str.begin(); iter != list_str.end(); iter++) // SORT2 print 
    {
        if (element < size && element > 0) {
            if (element == i) {
                cout << " Елемент під номером " << i + 1 << endl;
                cout << "  " << *iter << endl;

            }
        }
        else {
           // cout <<  << endl;
            throw " Значення що ви вибрали занадто велике!";
            
        }
        i++;
    }

}
 // Дзеркальне відображення списку 
list<string> dzerkal_list(list<string> list_str) {
    int size = list_str.size();
    cout << endl;
    for (auto iter = list_str.begin(); iter != list_str.end(); iter++)
    {
        list_str.push_front(*iter);
    }
    list_str.resize(size);
    return list_str;
}

// Прінт ліст
void print_list(list<string> list_str) {
    cout << endl;
    for (auto iter = list_str.begin(); iter != list_str.end(); iter++)
    {
        cout << "  " << *iter << endl;
    }
}

// Прінт вектор
void print_vector(vector<string> vector_str) {
    cout << endl;
    for (auto iter = vector_str.begin(); iter != vector_str.end(); iter++)
    {
        cout << "  " << *iter << endl;
    }
}
////////////////////////////////////////////////////////////////////////////////
int main() {
    // --------------------------налаштування--------------------
    system("chcp 1251");
    setlocale(LC_ALL, " ");
    int i = 0, j = 0;
    char alfavit[26] = { 'q','w','e', 'r', 't', 'y', 'u', 'i', 'o',  
    'p', 'a', 's', 'd', 'f', 'g', 'h', 'j','k','l','z','x','c',
    'v', 'b', 'n', 'm'};
    vector<string> vec_str; // Вектор з текстом
    string buffer = "";     // локальний буфер
    
    // заповнення вектору
    for (i = 1; i <= 15; i++) {  
        buffer = "Розділ ";
        for (j = 0; j < 1; j++) { 
            buffer += rand() % 9 + '0' ; buffer += ' '; // Нумерація строки
           
            buffer += alfavit[rand() % 26]; //26
        } 
        vec_str.push_back(buffer);
        buffer = "";
    } 

    
/////////////////////////////////////////////////////////////////////////////////////                                       
    
    unsigned int vector_size = vec_str.size(); // Зберігаємо розмір вектора
    list<string> sort1; // Повторювані
    list<string> sort2; // Не повторювані
    
    cout << "\n\nРозділи Вектора\n"; 
    print_vector(vec_str);

    sort(vec_str.begin(), vec_str.end()); // сортування вектору по нарощуванню
    
    cout << "\n\nВідсортований Вектор довжиною : " << vec_str.size() << endl;
    print_vector(vec_str);


    // -------------------Сортування-------------------------------------

    for (i = 0; i < vector_size; i++) {    
        // Виключна ситуація коли значення більше розміру масиву
        int local = i + 1;     
        if (local == vector_size) { 
            local = 0;
        }
        // Сортування по двом спискам 
        if (vec_str[i] == vec_str[local]) {
            vec_str[local].clear();  // очищення наступної строки
            sort1.push_back(vec_str[i]); // запис до списку 1 (посторень)
            i++; // збільшення і для того, щоб пропустити пусту строку і навмисно
                 // не перемістити її до списку 2 (унікальних строк)
        }
        else{
            sort2.push_back(vec_str[i]); // запис до списку 2
        }
    }

  // ----------------------Підсумки cортування ------------------------------


    cout << "\n\nСписок 1 Довжиною : " << sort1.size() << endl;
    print_list(sort1);
    
    cout << "\n\nСписок 2 Довжиною : " << sort2.size() << endl;
    print_list(sort2);
    
    cout << "Дзеркальне відображення списку 2";
    sort2  = dzerkal_list(sort2);      // перетворення списку в дзеркально відображений
    print_list(sort2);
    try
    {
      element_list(28, sort2); // доступ до конкретного елемента списку
  
    }
    catch (const char* name)
    {
        cout << name << endl;
    }
    
        return 0;
}
