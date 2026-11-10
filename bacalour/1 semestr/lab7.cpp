#include <iostream>
#include <clocale>
using namespace std;

// а) Умножение десятичных дробей
// Принимает 2 аргумента типа double
double multiply(double a, double b) 
{
    return a * b;
}

// б) Умножение обыкновенных дробей
// Принимает 4 аргумента типа int: num1, den1, num2, den2
void multiply(int num1, int den1, int num2, int den2) 
{
    // Умножаем числители и знаменатели
    int res_num = num1 * num2;
    int res_den = den1 * den2;
    
    // Выводим результат
    cout << "Результат: " 
         << num1 << "/" << den1 << " * " 
         << num2 << "/" << den2 << " = " 
         << res_num << "/" << res_den << endl;
}


int main() 
{
    setlocale(LC_ALL, "65.001");

    // a) Десятичные дроби
    cout << "1. Умножение десятичных дробей" << endl;
    double dec1, dec2;
    
    cout << "Введите первую десятичную дробь: ";
    cin >> dec1;
    cout << "Введите вторую десятичную дробь: ";
    cin >> dec2;

    // Вызывается первая функция multiply (2 аргумента)
    double dec_result = multiply(dec1, dec2);
    cout << "Результат: " << dec1 << " * " << dec2 << " = " << dec_result << endl << endl;


    // б) Обыкновенные дроби
    cout << "2. Умножение обыкновенных дробей" << endl;
    
    int n1, d1, n2, d2;
    
    cout << "Введите числитель первой дроби: ";
    cin >> n1;
    cout << "Введите знаменатель первой дроби: ";
    cin >> d1;

    cout << "Введите числитель второй дроби: ";
    cin >> n2;
    cout << "Введите знаменатель второй дроби: ";
    cin >> d2;

    // Проверка на ноль в знаменателе
    if (d1 == 0 || d2 == 0) 
    {
        cout << "Ошибка: знаменатель не может быть равен нулю!" << endl;
    } else 
    {
        // Вызывается вторая функция multiply (4 аргумента)
        multiply(n1, d1, n2, d2); 
    }

    return 0;
}