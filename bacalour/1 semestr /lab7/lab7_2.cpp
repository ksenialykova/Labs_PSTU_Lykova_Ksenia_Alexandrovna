#include <iostream>
#include <cstdarg>   // va_list, va_start, va_arg, va_end
#include <cstdlib>   // abs
using namespace std;

struct Fraction {
    int num;   // числитель
    int den;   // знаменатель
};

// Наибольший общий делитель (алгоритм Евклида)
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// Конструктор дроби
Fraction F(int n, int d) {
    Fraction f = {n, d};
    return f;
}

// Функция с переменным числом параметров:
// k - обязательный параметр, количество дробей, далее идут сами дроби
Fraction sum(int k, ...) {
    va_list args;
    va_start(args, k);          // встали на список после параметра k

    Fraction res = {0, 1};      // результат, пока 0/1

    for (int i = 0; i < k; i++) {
        Fraction f = va_arg(args, Fraction);   // берём следующую дробь

        // a/b + c/d = (a*d + c*b) / (b*d)
        res.num = res.num * f.den + f.num * res.den;
        res.den = res.den * f.den;

        // сокращаем, чтобы числа не росли
        int g = gcd(res.num, res.den);
        if (g != 0) {
            res.num /= g;
            res.den /= g;
        }
    }

    va_end(args);               // завершаем работу со списком
    return res;
}

int main() {
    // 5 параметров
    Fraction r1 = sum(5, F(1,2), F(1,3), F(1,6), F(1,4), F(1,12));
    cout << "\nСумма 5 дробей = " << r1.num << "/" << r1.den;

    // 10 параметров
    Fraction r2 = sum(10,
        F(1,2), F(1,3), F(1,6), F(1,4), F(1,12),
        F(1,2), F(1,3), F(1,6), F(1,4), F(1,12));
    cout << "\nСумма 10 дробей = " << r2.num << "/" << r2.den;

    // 12 параметров
    Fraction r3 = sum(12,
        F(1,12), F(1,12), F(1,12), F(1,12), F(1,12), F(1,12),
        F(1,12), F(1,12), F(1,12), F(1,12), F(1,12), F(1,12));
    cout << "\nСумма 12 дробей = " << r3.num << "/" << r3.den << endl;

    return 0;
}